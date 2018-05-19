#include <iostream>
#include <functional>
#include <algorithm>
#include "Stack.h"

using namespace std;

typedef enum {INT, FLOAT, COMPLEX_INT, COMPLEX_FLOAT} Type;

void input()
{
    string str = "";
    Type dataType;
    cin>>str;
    for(int i=0;i<str.length();i++) (str[i]=='.')?(dataType = FLOAT):(dataType = INT);
}



int main()
{
	Stack <int> stack1;
    Stack <Complex<int>> stack_comp1;
	Stack <float> stack2;
	for (int i = 0; i < 5; i++) {
        struct Complex<int> comp;
        comp.Real = i;
        comp.Imagine = i+100;
        stack_comp1.push(comp);
	}

    output(stack_comp1);

    return 0;
}

