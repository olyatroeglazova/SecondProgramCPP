#include "stdafx.h"
#include "locale.h"
#include "conio.h"
#include "stdlib.h"
#include <iostream>
#include "Iterator.h"
#include "CircularBuffer.h"

#define SIZE 7


using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	CircularBuffer buf = CircularBuffer(SIZE);
		for (int i = 0; i < SIZE; i++) {
			buf.push(i);
		}		
		cout << "Размер: " << buf.length() << endl;
		cout << "Первый элемент: " << buf.head() << endl;
		try {
			buf.push(0);
		}
		catch (char const* e) {
			cout << e << endl;
		}
		Iterator test = Iterator(buf);
		test.start();
		while (!test.finish()) {
			cout << test.getValue() << " ";
			test.next();
		}
		buf.deleteAllElems();
		if (buf.isEmpty()) {
			cout << "Все элементы очереди удалены." << endl;
		}
		test.start();
		while (!test.finish()) {
			cout << test.getValue() << " ";
			test.next();
		}
		try {
			buf.pop();
		}
		catch (char const* e) {
			cout << e << std::endl;
		}
	system("pause");
	return 0;
}