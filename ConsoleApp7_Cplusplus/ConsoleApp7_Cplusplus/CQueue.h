#pragma once
#include"stdio.h"
#include<malloc.h>
struct QNode {
	int Key;
	struct QNode *next;
};

struct Queue {
	struct QNode *front, *rear;
};

//create new link list node
struct QNode* CreateNewNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->Key = k;
	temp->next = NULL;
	return temp;
}

struct Queue* CreateQueue() {

	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	temp->front = temp->rear = NULL;
	return temp;
}

void enqueue(struct Queue *q, int k)
{
	struct QNode* temp = CreateNewNode(k);
	if (q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;

}

struct QNode* dequeue(struct Queue* q) {

	if (q->front == NULL)
	{
		return NULL;
	}
	struct QNode* temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->rear == NULL;
	
	return temp;

}