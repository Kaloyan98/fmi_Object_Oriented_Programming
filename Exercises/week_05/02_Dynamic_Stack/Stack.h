#pragma once

const int INITIAL_SIZE = 2;

class Stack {
private:
	int* arr;
	int topIndex;
	int maxSize;
public:
	Stack();
	Stack(const Stack&);
	~Stack();

	void push(int a);
	int pop();
	int peek() const;

	int getLength() const;
private:
	void resize();
};
