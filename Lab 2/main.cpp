#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack <int> stack;
	for (int i = 0; i < 5; i++) {
		stack.push(i);
	}

	stack.output();
	stack.pop();
	stack.output();
	stack.del();
	stack.output();
    return 0;
}

