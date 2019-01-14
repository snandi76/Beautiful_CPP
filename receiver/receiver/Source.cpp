//#include <SDKDDKVer.h>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#define OUT_FILENAME "test.txt" 
HANDLE hEventA = ::CreateEvent(NULL, TRUE, FALSE, TEXT("WriteEvent"));//reading event
int main(int argc, char* argv[])
{
	int        shmem_size = 900;  // shared memory size
	HANDLE    shmem = INVALID_HANDLE_VALUE;
	HANDLE    mutex = INVALID_HANDLE_VALUE;
	std::fstream fs;
	fs.open(OUT_FILENAME, std::fstream::in | std::fstream::out | std::fstream::app);//open file for writing

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



	do {
		::WaitForSingleObject(hEventA, INFINITE);//waiting for the Write event to occur
		::ResetEvent(hEventA);
		// mutex lock
		WaitForSingleObject(mutex, INFINITE);

		//printf("read shared memory...c=%d\n", buf[0]);
		//printf("read shared memory...c=%s\n", buf);
		if (memcmp(buf, "END", 4))
			fs << buf;/*Write in a file*/
					  // mutex unlock

		::ReleaseMutex(mutex);

		//::Sleep(1000);
	} while (memcmp(buf, "END", 4));
	/*file close*/
	fs.close();

	printf("End of reading");
	// release
	::UnmapViewOfFile(buf);
	::CloseHandle(shmem);
	::ReleaseMutex(mutex);

	return 0;
}