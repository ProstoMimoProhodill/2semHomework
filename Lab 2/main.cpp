#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack <float> stack1;
	Stack <float> stack2;

	for (int i = 0; i < 5; i++) {
		stack1.push(i+0.1561);
		stack2.push(i+0.9822);
	}

	stack1.output();
	stack2.output();
    //sort(stack1).output();

    concatenation(stack1, stack2).output();



    return 0;
}

