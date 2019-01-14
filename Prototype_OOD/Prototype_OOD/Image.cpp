#include "stdafx.h"
#include "Image.h"


Image::Image()
{
}


Image::~Image()
{
}

Image *Image::findAndClone(imageType type)
{
	for (int i = 0; i < _nextslot; i++)
		if (_prototypes[i]->returnType() == type)
			return _prototypes[i]->Clone();
	return NULL;
}
