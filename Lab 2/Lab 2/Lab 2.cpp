#include <iostream>
#include <conio.h>
#include "stdafx.h"

using namespace std;

template <typename Re_type, typename Im_type>
struct Complex
{
	Re_type Real;
	Im_type Imagine;
};

template <class Type>
class Stack
{
	private:
		int size;
		typedef struct Element
		{
			Type data;
			Element *next;
		};
		Element *head;
	public:
		Stack() : head(NULL), size(0) {}
		~Stack() { del(); }

		bool push(Type data);
		bool pop();
		Type get(int i);
		void output();
		void del();

		int getSize() {return size;}
};

template <class Type>
bool Stack<Type>::push(Type data)
{
	Element *elem = new Element;
	(head==NULL) ? (elem->next = NULL) : (elem->next = head);
	elem->data = data;
	head = elem;
	size++;
	return true;
}

template <class Type>
bool Stack<Type>::pop()
{
	if (size==0) return false;
	Element *elem = head;
	head = head->next;
	delete elem;
	size--;
	return true;
}

template <class Type>
Type Stack<Type>::get(int i)
{
	if (head != NULL) {
		Element *current;
		for (current = head; i>0; i--)
			current = current->next;
		return current->data;
	}
	else {
		printf("Stack is empty...\n");
		return 0;
	}
}

template <class Type>
void Stack<Type>::output()
{
	if (head != NULL) {
		Element *current = head;
		printf("%d\n", current->data);
		while (current->next != NULL) {
			current = current->next;
			printf("%d\n", current->data);
		}
	}
	else {
		printf("Stack is empty...\n");
	}
	printf("\n");
}

template <class Type>
void Stack<Type>::del()
{
	Element *current = head;
	Element *elem = head;
	while (elem != NULL)
	{
		current = current->next;
		delete elem;
		elem = current;
	}
	head = NULL;
	size = 0;
}

int main()
{
	Stack <int> stack;
	for (int i = 0; i < 5; i++) {
		stack.push(i);
	}

	stack.output();
    return 0;
}

