#include "stdafx.h"
#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

class CircularBuffer {

private:
	int *buf;
	int size;
	int top;
	int tail;
	int elems;

public:
	CircularBuffer(int);
	~CircularBuffer();
	void push(int);
	int pop();
	int head();
	int length();
	void deleteAllElems();
	bool isEmpty();

};
#endif;