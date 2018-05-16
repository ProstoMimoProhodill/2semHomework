#include <iostream>
#include <functional>
#include <algorithm>
#include "Stack.h"

using namespace std;

template <typename F>
void map_little(F func)
{
    for(int i=0;i<10;i++){
        cout<<func(i)<<"\n";
    }
}

int main()
{
    /*
    int arr[] {1,2,3,4,5,6,7,8,9,10};
    auto sum = [](int x, int y){ return x+y; };
    for_each(arr, arr+10 , [](int x){ cout<<x<<"  "; } );


    function <int(int)> add_my = [](int x){ return x+100; };
    map_little(add_my);

    cout<<"sum:  "<<sum(2.5161, 3.156)<<"\n";
    system("pause");

    */


	Stack <int> stack1;
	Stack_Complex <int> stack3;
	Stack <int> *p = &stack3;
	Stack <float> stack2;
	for (int i = 0; i < 20; i++) {
        struct Complex<int> comp;
        comp.Real = i;
        comp.Imagine = i+100;
		stack1.push(i);
		stack2.push(i+0.9822);
		stack3.push(comp);
	}

	cout<<stack3.getSize()<<"\n";

	//stack3.del();
	stack3.output();
	stack3.pop();

	//cout<<stack3.getSize();

	cout<<"elem:  "<<(stack3.get()).Imagine<<"\n";

	/*
	stack1.output();
	(*map(&stack1, sqrt_f)).output();

	*/

    return 0;
}

