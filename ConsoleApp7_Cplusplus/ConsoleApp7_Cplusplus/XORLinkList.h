#pragma once
#include<stdio.h>
#include<malloc.h>
struct LNode {
	int data;
	struct LNode* link;
};

struct LL {
	struct LNode* Head;
};

struct LNode* CreatNode(int k)
{
	struct LNode* temp = (struct LNode*)malloc(sizeof(struct LNode));
	temp->data = k;
	temp->link = NULL;
	return temp;
}

struct LL* CreateLL()
{
	struct LL* temp = (struct LL*)malloc(sizeof(struct LL));
	temp->Head = NULL;
	return temp;
}

void Insert(struct LL* pList, int k)
{
	if (pList->Head == NULL)
	{
		struct LNode* temp = CreatNode(k);
		pList->Head = temp;
		return;
	}
	struct LNode* traverse = pList->Head;
	while (traverse != NULL)
	{
		
		if (traverse->link == NULL)
		{
			struct LNode* temp = CreatNode(k);
			traverse->link = temp;
			return;
		}
		traverse = traverse->link;
	}


}

void show(struct LL *pList)
{
	struct LNode* temp = pList->Head;
	printf("\nData of LL\n");
	while (temp != NULL)
	{
		printf("%d->", temp->data);
		temp = temp->link;
	}
		

}