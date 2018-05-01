#include <iostream>
#include <Windows.h>
#include "stdafx.h"

using namespace std;


class Stack
{
	private:
		int size;
		void *data;
		struct Stack *next;
	public:
		Stack();

		template <typename dataType>
		struct Stack *push(struct Stack *S, dataType data);
		struct Stack *pop(struct Stack *S, int *i);

		template <typename dataType>
		dataType get(struct Stack *S, int *i);
		void output(struct Stack *S);

		int getSize() 
		{
			return size;
		}
};

Stack::Stack()
{
	printf("constructor\n");
}

template <typename dataType>
struct Stack *Stack::push(struct Stack *S, dataType data)
{
	printf("push\n");
	if (S.getSize == 0) {
		S = realloc(S, _msize(S)+sizeof(int));
	}
	else {

	}
}

struct Stack *Stack::pop(struct Stack *S, int *i)
{
	printf("pop");
}

template <typename dataType>
dataType Stack::get(struct Stack *S, int *i)
{

}

void Stack::output(struct Stack *S)
{

}

int main()
{
	Stack stack;

    return 0;
}

