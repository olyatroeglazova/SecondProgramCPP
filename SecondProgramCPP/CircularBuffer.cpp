#include "stdafx.h"
#include "CircularBuffer.h"
#include <iostream>

CircularBuffer::CircularBuffer(int n) : size(n), top(0), tail(0), elems(0) {
	buf = new int[size];
}
CircularBuffer::~CircularBuffer() {
	this->size = 0;
	this->top = 0;
	this->tail = 0;
	this->elems = 0;
	delete [] buf;
	buf = nullptr;
}
//добавить элемент в конец очереди
void CircularBuffer::push(int elem) {
	if (elems == size) {
		throw "ќчередь заполнена!";
	}
	else {
		buf[tail] = elem;
		elems++;
		if (tail == size - 1) {
			tail = 0;
		}
		else {
			tail++;
		}
	}
}
//получить элемент в начале очереди(без изъ€ти€)
int CircularBuffer::head() {
	if (isEmpty()) {
		throw "ќчередь пуста! ";
	}
	return buf[top];
}
//вз€ть элемент в начале очереди
int CircularBuffer::pop() {
	int tmp = head();
	elems--;
	if (top == size - 1) {
		top = 0;
	}
	else {
		top++;
	}
	return tmp;
}

int CircularBuffer::length() {
	return elems;
}

void CircularBuffer::deleteAllElems() {
	for (int i = 0; i < size; i++) {
		buf[i] = 0;
	}
	elems = 0;
}

bool CircularBuffer::isEmpty() {
	return elems == 0;
}

