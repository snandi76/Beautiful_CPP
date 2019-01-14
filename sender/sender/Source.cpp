#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iosfwd>

HANDLE hEventA = ::CreateEvent(NULL, TRUE, FALSE, TEXT("WriteEvent"));//creating event
#define FILE_NAME "c:\\A.txt" //input file name

																	  /*unsigned int GetFileLength(std::string FileName)
																	  {
																	  std::ifstream InFile(FileName.c_str());
																	  unsigned int FileLength = 0;
																	  char buf;
																	  while (buf=InFile.get() != EOF)
																	  {
																	  FileLength++;
																	  printf("file char:%c",buf);
																	  }
																	  InFile.close();
																	  return FileLength;
																	  }*/
std::streampos fileSize(const std::string& filePath) {

	std::streampos fsize = 0;
	std::ifstream file(filePath.c_str(), std::ios::binary);

	fsize = file.tellg();
	file.seekg(0, std::ios::end);
	fsize = file.tellg() - fsize;
	file.close();

	return fsize;
}

/*void read(){
char     array[ 1500 ];        // Array to read into (at most 100 characters + ASCIIZ)
size_t   chars_read = 0;   // Number of characters read so far (used to index array)
std::ifstream input(FILE_NAME);  //  The input file

// Check 2 things: 1) file is still readable, and 2) I'm not going to overflow my array.
while( input && chars_read < 1500 ) {
input >> array[ chars_read ];    // TRY to read the character
if( input )                               // If I read successfully...
++chars_read;                  //     then increment # of characters read

if( array[ chars_read - 1 ] == '\n' )     // We'll stop reading at a newline in the file
break;                                      // Exit loop if we hit EOL (end of line)
}
}*/

/*void read_chunk()
{
size_t buffer_size = 900;
char *buffer = new char[buffer_size];
unsigned int nFileSize = fileSize(FILE_NAME);//getting file size

std::ifstream fin(FILE_NAME);
unsigned int nBytesRead = 0;

while (fin)
{
//unsigned int nBytes = nFileSize -
// Try to read next chunk of data
fin.read(buffer, buffer_size);
// Get the number of bytes actually read
size_t count = fin.gcount();
nBytesRead += count;
// If nothing has been read, break
if (!count)
break;
// Do whatever you need with first count bytes in the buffer
// ...
}

delete[] buffer;
}*/




int main(int argc, char* argv[])
{

	size_t buffer_size = 900;//File read buffer size
	char *buffer = new char[buffer_size];
	unsigned int nFileSize = fileSize(FILE_NAME);//Getting file size
	std::ifstream fin(FILE_NAME);//getting file handle for read
	unsigned int nBytesRead = 0;
	/*End init reading file*/
	int        shmem_size = 900;  // shared memory size
	HANDLE    shmem = INVALID_HANDLE_VALUE;//
	HANDLE    mutex = INVALID_HANDLE_VALUE;
	unsigned int FlieLen;
	char End[] = "END";

	FlieLen = fileSize("C:\\A.txt");//Getteing length of the input file
															  //read_chunk();
	mutex = ::CreateMutex(NULL, FALSE, TEXT("mutex_name"));

	shmem = ::CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		shmem_size,
		TEXT("shared_memory")
	);

	unsigned char *buf = (unsigned char*)::MapViewOfFile(shmem, FILE_MAP_ALL_ACCESS, 0, 0, shmem_size);


	/*start reading from input file and writing in shared memmory*/
	while (fin)
	{
		
		// Try to read next chunk of data
		fin.read(buffer, buffer_size);
		// mutex lock
		size_t count = fin.gcount();
		nBytesRead += count;
		WaitForSingleObject(mutex, INFINITE);
		// write shared memory
		//memset(buf, buffer, shmem_size);
		memcpy(buf, buffer, count);
		::SetEvent(hEventA);//Sending Write Event to receiver  
							//printf("write shared memory...c=%s\n",buffer);
							// mutex unlock
		::ReleaseMutex(mutex);
		::Sleep(1000);
		// If nothing has been read, break
		if (!count)
			break;

	}
	/*End reading from input file and writing in shared memmory*/
	/*start Sending Markup end of file*/
	//memset(buf, 0, shmem_size);
	WaitForSingleObject(mutex, INFINITE);
	// write shared memory

	memcpy(buf, End, 4);
	::SetEvent(hEventA);//Sending Write Event to receiver 
						//printf("write shared memory...c=%d\n",End);
						// mutex unlock
	::ReleaseMutex(mutex);
	::Sleep(1000);
	/*end Sending Markup end of file*/
	// release
	::UnmapViewOfFile(buf);
	::CloseHandle(shmem);
	::ReleaseMutex(mutex);

	return 0;
}