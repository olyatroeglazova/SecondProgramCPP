#include "stdafx.h"
#ifndef ITERATOR_H
#define ITERATOR_H
#include "CircularBuffer.h"

class Iterator {
private:
	CircularBuffer *buf=nullptr;
	CircularBuffer *work=nullptr;

public:
	Iterator(CircularBuffer&);
	~Iterator();
	void start();
	void next();
	bool finish();
	int getValue();

};

#endif;