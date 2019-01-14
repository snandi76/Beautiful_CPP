#pragma once
#include<stdio.h>
#include<malloc.h>
struct SNode {
	int data;
	struct SNode* link;
};

struct LL {
	struct SNode* m_Head;
};

struct SNode* CreateSNode()
{
	struct SNode* temp = (struct SNode*)malloc(sizeof(struct SNode));
	return temp;
}

struct LL* CreateLL()
{
	struct LL* temp = (struct LL*)malloc(sizeof(struct LL));
	temp->m_Head = NULL;
	return temp;
}

void Push(struct LL* pstackhead,  int iData)
{
	struct SNode* temp = CreateSNode();
	temp->data = iData;
	temp->link = NULL;
	if(pstackhead->m_Head == NULL)
	{
		pstackhead->m_Head = temp;
		return;
	}
	temp->link = pstackhead->m_Head;
	pstackhead->m_Head = temp;
}

int Pop(struct LL* pstackhead)
{
	struct SNode* temp = pstackhead->m_Head;
	pstackhead->m_Head = pstackhead->m_Head->link;
	int val = temp->data;
	delete temp;
	return val;
}

void show(struct LL* pstackhead)
{
	struct SNode* temp = pstackhead->m_Head;
	while (temp != NULL)
	{
		printf("%d\n",temp->data);
		temp = temp->link;
	}
}