// ConApp7_circle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Node{
	int data1;
	struct Node* next;
};


bool has_cycle(Node* head) {
	// Complete this function
	// Do not write the main method

	bool bRet = false;
	Node* nhandle1 = head;
	Node* nhandle2 = head;
	while (nhandle1 != NULL)
	{
		nhandle1 = nhandle1->next;
		nhandle2 = nhandle1->next;
		if (nhandle1->data == nhandle2->data)
		{
			bRet = true;
			break;
		}
	}

	return bRet;
}
int main()
{
    return 0;
}

