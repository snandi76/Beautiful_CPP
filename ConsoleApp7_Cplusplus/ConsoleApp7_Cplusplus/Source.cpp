#include "stdafx.h"
#include<iostream>

class Node{

public:
	int data;
	Node *link;
	Node() {}
	~Node() {}

	Node* operator=(Node& rhs){
	}
private:
	Node(Node& rhs) {

	}

};


