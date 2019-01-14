#pragma once
template<typename T>
class Node {
public:
	T data;
	Node<T>* link;
};
template<typename T>
class DNode {
public:
	T data;
	DNode<T>* next;
	DNode<T>* prev;
};