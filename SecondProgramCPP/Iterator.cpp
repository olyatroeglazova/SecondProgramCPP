#include "stdafx.h"
#include "Iterator.h"
#include "CircularBuffer.h"

Iterator::Iterator(CircularBuffer& buf) {
	this->buf = new CircularBuffer(buf);
	this->work = &buf;
}

Iterator::~Iterator() {
	delete this->buf;
	delete this->work;
}

void Iterator::start() { 
	this->work = new CircularBuffer(*buf);
}

void Iterator::next() {
	work->pop();
}

bool Iterator::finish() {
	return work->isEmpty();
}

int Iterator::getValue() {
	return work->head();
}