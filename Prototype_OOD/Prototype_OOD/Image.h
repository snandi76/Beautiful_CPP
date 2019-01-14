#pragma once
enum imageType
{
	LSAT,SPOT
};

class Image
{
public:
	Image();
	~Image();
	virtual void draw() = 0;
	static Image *findAndClone(imageType);
protected:
	virtual imageType returnType() = 0;
	virtual Image *Clone() = 0;
	//As each subclass of Image is declared it registers iits prototype
	static void addPrototype(Image *image)
	{
		_prototypes[_nextslot++] = image;
	}
private:
	static Image *_prototypes[10];
	static int _nextslot;
};

