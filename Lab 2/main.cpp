#include <iostream>
#include <functional>
#include <algorithm>

#include "Stack.h"

using namespace std;

typedef enum {INT, FLOAT, COMPLEX_INT, COMPLEX_FLOAT} Type;
typedef enum {MAP, WHERE, REDUCE, CONCATENATION, RECOVERY, SEARCH_SUBSEQUENCE, MERGER, SEPARATION} Function;

Type choose_type()
{
    int type = 0, flag = 0;
    cout<<"Input type: \n1.INT\n2.FLOAT\n3.COMPLEX<INT>\n4.COMPLEX<FLOAT>\n";
    while(flag==0){
        cin>>type;
        if((type<1)||(type>4)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    switch(type){
        case 1:
            return INT;
        case 2:
            return FLOAT;
        case 3:
            return COMPLEX_INT;
        case 4:
            return COMPLEX_FLOAT;
    }
}

Function choose_function()
{
    int func = 0, flag = 0;
    cout<<"Input function: \n1.map\n2.where\n3.reduce\n4.concatenation\n5.recovery\n6.search for an entry subsequences\n7.merger\n8.separation\n";
    while(flag==0){
        cin>>func;
        if((func<1)||(func>8)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    switch(func){
        case 1:
            return MAP;
        case 2:
            return WHERE;
        case 3:
            return REDUCE;
        case 4:
            return CONCATENATION;
        case 5:
            return RECOVERY;
        case 6:
            return SEARCH_SUBSEQUENCE;
        case 7:
            return MERGER;
        case 8:
            return SEPARATION;
    }
}

template <class Type> void map_procedure(Stack<Type> *s)
{
    int map_func = 0, flag = 0;
    cout<<"Input map-function: \n1.sqrt\n2.squad\n3.number*2\n\n";
    while(flag==0){
        cin>>map_func;
        if((map_func<1)||(map_func>3)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");


    switch(map_func){
        case 1:{
            auto sq = [](Type x){ return sqrt(x); };
            output(map(s, sq ));
            break;
        }
        case 2:
            output(map(s, [](Type x){ return x*x; } ));
            break;
        case 3:
            output(map(s, [](Type x){ return x+x; } ));
            break;

    }
}


template <class Type> void map_procedure(Stack<Complex<Type>> *s)
{
    int map_func = 0, flag = 0;
    cout<<"Input map-function: \n1.3*number +2 \n2.number*2\n\n";
    while(flag==0){
        cin>>map_func;
        if((map_func<1)||(map_func>3)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    switch(map_func){
        case 1:
            output(map(s, [](Complex<Type> x){
                       Complex<Type> comp;
                       comp.Real = 3*x.Real + 2;
                       comp.Imagine = 3*x.Imagine;
                       cout<<x.Real<<"    "<<x.Imagine<<"\n";
                       system("pause");
                       return comp; } ));
            break;
        case 2:
            output(map(s, [](Complex<Type> x){
                       x.Real = 2*x.Real;
                       x.Imagine = 2*x.Imagine;
                       return x; } ));
            break;
    }
}


void choose_task()
{
    Stack <int> *stack_int = new Stack <int>;
    Stack <float> *stack_float = new Stack <float>;
    Stack <Complex<int>> *stack_complex_int = new Stack <Complex<int>>;
    Stack <Complex<float>> *stack_complex_float = new Stack <Complex<float>>;

    Type type = choose_type();
    Function func = choose_function();


    switch(type){
        case INT:
            input(stack_int);
            switch(func){
                case MAP:
                    output(stack_int);
                    map_procedure(stack_int);
                    break;
                case WHERE:
                    break;
                case REDUCE:
                    break;
                case CONCATENATION:
                    break;
                case RECOVERY:
                    break;
                case SEARCH_SUBSEQUENCE:
                    break;
                case MERGER:
                    break;
                case SEPARATION:
                    break;
            }
            break;
        case FLOAT:
            input(stack_float);
            switch(func){
                case MAP:
                    output(stack_float);
                    map_procedure(stack_float);
                    break;
                case WHERE:
                    break;
                case REDUCE:
                    break;
                case CONCATENATION:
                    break;
                case RECOVERY:
                    break;
                case SEARCH_SUBSEQUENCE:
                    break;
                case MERGER:
                    break;
                case SEPARATION:
                    break;
            }
            break;
        case COMPLEX_INT:
            input(stack_complex_int);
            switch(func){
                case MAP:
                    output(stack_complex_int);
                    map_procedure(stack_complex_int);
                    break;
                case WHERE:
                    break;
                case REDUCE:
                    break;
                case CONCATENATION:
                    break;
                case RECOVERY:
                    break;
                case SEARCH_SUBSEQUENCE:
                    break;
                case MERGER:
                    break;
                case SEPARATION:
                    break;
            }
            break;
        case COMPLEX_FLOAT:
            input(stack_complex_float);
            switch(func){
                case MAP:
                    output(stack_complex_float);
                    map_procedure(stack_complex_float);
                    break;
                case WHERE:
                    break;
                case REDUCE:
                    break;
                case CONCATENATION:
                    break;
                case RECOVERY:
                    break;
                case SEARCH_SUBSEQUENCE:
                    break;
                case MERGER:
                    break;
                case SEPARATION:
                    break;
            }
            break;
    }

    system("pause");
    system("cls");
}

int main()
{
    while(true){
        choose_task();
    }
    return 0;
}

