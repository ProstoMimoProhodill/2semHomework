#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>
#include <functional>
#include <algorithm>
#include <windows.h>

#include "Stack.h"
#include "Test.h"

using namespace std;

typedef enum {INT_t, FLOAT_t, COMPLEX_INT, COMPLEX_FLOAT} Type;
typedef enum {MAP, WHERE, REDUCE, CONCATENATION, RECOVERY, SEARCH_SUBSEQUENCE, MERGER, SEPARATION} Function;

Type choose_type()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int type = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input type: ";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.INT\n2.FLOAT\n3.COMPLEX<INT>\n4.COMPLEX<FLOAT>\n";
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
            return INT_t;
        case 2:
            return FLOAT_t;
        case 3:
            return COMPLEX_INT;
        case 4:
            return COMPLEX_FLOAT;
    }
}

Function choose_function()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.map\n2.where\n3.reduce\n4.concatenation\n5.recovery\n6.search for an entry subsequences\n7.merger\n8.separation\n";
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
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int map_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input map-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.sqrt\n2.squad\n3.number*2\n\n";
    while(flag==0){
        cin>>map_func;
        if((map_func<1)||(map_func>3)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with map:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    switch(map_func){
        case 1:
            output(*map(s, [](Type x){ return sqrt(x); } ));
            break;
        case 2:
            output(*map(s, [](Type x){ return x*x; } ));
            break;
        case 3:
            output(*map(s, [](Type x){ return x+x; } ));
            break;

    }
}

template <class Type> void map_procedure(Stack<Complex<Type>> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int map_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input map-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.3*number +2 \n2.number*2\n\n";
    while(flag==0){
        cin>>map_func;
        if((map_func<1)||(map_func>3)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with map:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    switch(map_func){
        case 1:
            output(*map(s, [](Complex<Type> x){
                       x.Real = 3*x.Real + 2;
                       x.Imagine = 3*x.Imagine;
                       return x; } ));
            break;
        case 2:
            output(*map(s, [](Complex<Type> x){
                       x.Real = 2*x.Real;
                       x.Imagine = 2*x.Imagine;
                       return x; } ));
            break;
    }
}

template <class Type> void where_procedure(Stack<Type> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int where_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input where-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.less than zero\n2.more than zero\n\n";
    while(flag==0){
        cin>>where_func;
        if((where_func<1)||(where_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with where:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    switch(where_func){
        case 1:
            output(*where(s, [](Type x){
                        bool b;
                        (x<0)?(b=true):(b=false);
                        return b; } ));
            break;
        case 2:
            output(*where(s, [](Type x){
                        bool b;
                        (x>0)?(b=true):(b=false);
                        return b; } ));
            break;
    }
}

template <class Type> void where_procedure(Stack<Complex<Type>> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int where_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input where-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.REAL less than zero\n2.REAL more than zero\n\n";
    while(flag==0){
        cin>>where_func;
        if((where_func<1)||(where_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with where:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    switch(where_func){
        case 1:
            output(*where(s, [](Complex<Type> x){
                        bool b;
                        (x.Real<0)?(b=true):(b=false);
                        return b; } ));
            break;
        case 2:
            output(*where(s, [](Complex<Type> x){
                        bool b;
                        (x.Real>0)?(b=true):(b=false);
                        return b; } ));
            break;
    }
}

template <class Type> void reduce_procedure(Stack<Type> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int reduce_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input reduce-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.3x1+2x2 \n2.5x1*x2+1\n\n";
    while(flag==0){
        cin>>reduce_func;
        if((reduce_func<1)||(reduce_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Reduce:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    switch(reduce_func){
        case 1:
            cout<<*reduce(s, [](Type x1, Type x2){ return 3*x1 + 2*x2; }, 0)<<"\n";
            break;
        case 2:
            cout<<*reduce(s, [](Type x1, Type x2){ return 5*x1*x2 + 2; }, 0)<<"\n";
            break;
    }
}

template <class Type> void reduce_procedure(Stack<Complex<Type>> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int reduce_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input reduce-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.Sum REAL numbers\n2.Sum IMAGINE numbers\n\n";
    while(flag==0){
        cin>>reduce_func;
        if((reduce_func<1)||(reduce_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Reduce:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    switch(reduce_func){
        case 1:
            cout<<*reduce(s, [](Complex<Type> x1, Type x2){ return (Type)(x1.Real+x2); }, 0)<<"\n";
            break;
        case 2:
            cout<<*reduce(s, [](Complex<Type> x1, Type x2){ return (Type)(x1.Imagine+x2); }, 0)<<"\n";
            break;
    }
}

template <class Type> void concatenation_procedure(Stack<Type> *s1, Stack<Type> *s2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack1:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s1);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack2:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s2);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with concatenation:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*concatenation(s1,s2));
}

template <class Type> void concatenation_procedure(Stack<Complex<Type>> *s1, Stack<Complex<Type>> *s2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack1:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s1);
    SetConsoleTextAttribute(hConsole, 12);
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"Stack2:  \n";
    output(*s2);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with concatenation:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*concatenation(s1,s2));
}

template <class Type> void recovery_procedure(Stack<Type> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int N =0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input N index: \n";
    SetConsoleTextAttribute(hConsole, 8);
    cin>>N;
    int index_arr[N];
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input index: \n";
    SetConsoleTextAttribute(hConsole, 8);
    for(int i=0;i<N;i++) cin>>index_arr[i];

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with recovery:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    output(*recovery(s, index_arr, N));
}

template <class Type> void recovery_procedure(Stack<Complex<Type>> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int N =0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input N index: \n";
    SetConsoleTextAttribute(hConsole, 8);
    cin>>N;
    int index_arr[N];
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input index: \n";
    SetConsoleTextAttribute(hConsole, 8);
    for(int i=0;i<N;i++) cin>>index_arr[i];

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack with recovery:  \n";
    SetConsoleTextAttribute(hConsole, 8);

    output(*recovery(s, index_arr, N));
}

template <class Type> void search_subsequence_procedure(Stack<Type> *s1, Stack<Type> *s2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack1:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s1);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack2:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s2);

    bool result = search_subsequence(s1, s2);
    SetConsoleTextAttribute(hConsole, 12);
    (result)?(cout<<"\nResult: true\n"):(cout<<"\nResult: true\n");
    SetConsoleTextAttribute(hConsole, 8);
}

template <class Type> void search_subsequence_procedure(Stack<Complex<Type>> *s1, Stack<Complex<Type>> *s2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack1:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s1);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack2:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s2);

    bool result = search_subsequence(s1, s2);
    SetConsoleTextAttribute(hConsole, 12);
    (result)?(cout<<"\nResult: true\n"):(cout<<"\nResult: true\n");
    SetConsoleTextAttribute(hConsole, 8);
}

template <class Type> void merger_procedure(Stack<Type> *s1, Stack<Type> *s2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int merger_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input merger-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.3x1+2x2 \n2.5x1*x2+1 \n\n";
    while(flag==0){
        cin>>merger_func;
        if((merger_func<1)||(merger_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack1:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s1);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack2:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s2);

    switch(merger_func){
        case 1:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"Merged stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output(*merger(s1, s2, [](Type x1, Type x2){ return 3*x1 + 2*x2; } ));
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"Merged stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output(*merger(s1, s2, [](Type x1, Type x2){ return 5*x1*x2 + 2; } ));
            break;
    }
}

template <class Type> void merger_procedure(Stack<Complex<Type>> *s1, Stack<Complex<Type>> *s2)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int merger_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input merger-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.Full sum numbers \n\n";
    while(flag==0){
        cin>>merger_func;
        if((merger_func<1)||(merger_func>1)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack1:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s1);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack2:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s2);

    switch(merger_func){
        case 1:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"Merged stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output(*merger(s1, s2, [](Complex<Type> x1, Complex<Type> x2){
                           Complex<Type> comp;
                           comp.Real = x1.Real + x2.Real;
                           comp.Imagine = x1.Imagine + x2.Imagine ;
                           return comp; } ));
            break;
    }
}

template <class Type> void separation_procedure(Stack<Type> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int separation_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input separation-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.less than zero\n2.Number%2 = 0\n\n";
    while(flag==0){
        cin>>separation_func;
        if((separation_func<1)||(separation_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);

    switch(separation_func){
        case 1:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"True stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation(s, [](Type x){
                        bool b;
                        (x<0)?(b=true):(b=false);
                        return b; } )).true_stack);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"False stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation(s, [](Type x){
                        bool b;
                        (x<0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"True stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation(s, [](Type x){
                        bool b;
                        ((int)x%2==0)?(b=true):(b=false);
                        return b; } )).true_stack);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"False stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation(s, [](Type x){
                        bool b;
                        ((int)x%2==0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
    }
}

template <class Type> void separation_procedure(Stack<Complex<Type>> *s)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int separation_func = 0, flag = 0;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Input separarion-function:";
    SetConsoleTextAttribute(hConsole, 8);
    cout<<"\n1.REAL less than zero\n2.REAL more than zero\n\n";
    while(flag==0){
        cin>>separation_func;
        if((separation_func<1)||(separation_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Stack:  \n";
    SetConsoleTextAttribute(hConsole, 8);
    output(*s);

    switch(separation_func){
        case 1:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"True stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation(s, [](Complex<Type> x){
                        bool b;
                        (x.Real<0)?(b=true):(b=false);
                        return b; } )).true_stack);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"True stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation(s, [](Complex<Type> x){
                        bool b;
                        (x.Real<0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"False stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation<Complex<Type>>(s, [](Complex<Type> x){
                        bool b;
                        (x.Real>0)?(b=true):(b=false);
                        return b; } )).true_stack);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"False stack:  \n";
            SetConsoleTextAttribute(hConsole, 8);
            output((*separation<Complex<Type>>(s, [](Complex<Type> x){
                        bool b;
                        (x.Real>0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
    }
}

void menu()
{
    Stack <int> *stack_int1 = new Stack <int>;
    Stack <float> *stack_float1 = new Stack <float>;
    Stack <Complex<int>> *stack_complex_int1 = new Stack <Complex<int>>;
    Stack <Complex<float>> *stack_complex_float1 = new Stack <Complex<float>>;

    Stack <int> *stack_int2 = new Stack <int>;
    Stack <float> *stack_float2 = new Stack <float>;
    Stack <Complex<int>> *stack_complex_int2 = new Stack <Complex<int>>;
    Stack <Complex<float>> *stack_complex_float2 = new Stack <Complex<float>>;

    Type type = choose_type();
    system("cls");
    Function func = choose_function();
    system("cls");

    switch(type){
        case INT_t:
            input(*stack_int1);
            switch(func){
                case MAP:
                    map_procedure(stack_int1);
                    break;
                case WHERE:
                    where_procedure(stack_int1);
                    break;
                case REDUCE:
                    reduce_procedure(stack_int1);
                    break;
                case CONCATENATION:
                    input(*stack_int2);
                    concatenation_procedure(stack_int1, stack_int2);
                    break;
                case RECOVERY:
                    recovery_procedure(stack_int1);
                    break;
                case SEARCH_SUBSEQUENCE:
                    input(*stack_int2);
                    search_subsequence_procedure(stack_int1, stack_int2);
                    break;
                case MERGER:
                    input(*stack_int2);
                    merger_procedure(stack_int1, stack_int2);
                    break;
                case SEPARATION:
                    separation_procedure(stack_int1);
                    break;
            }
            break;
        case FLOAT_t:
            input(*stack_float1);
            switch(func){
                case MAP:
                    map_procedure(stack_float1);
                    break;
                case WHERE:
                    where_procedure(stack_float1);
                    break;
                case REDUCE:
                    reduce_procedure(stack_float1);
                    break;
                case CONCATENATION:
                    input(*stack_float2);
                    concatenation_procedure(stack_float1, stack_float2);
                    break;
                case RECOVERY:
                    recovery_procedure(stack_float1);
                    break;
                case SEARCH_SUBSEQUENCE:
                    input(*stack_float2);
                    search_subsequence_procedure(stack_float1, stack_float2);
                    break;
                case MERGER:
                    input(*stack_float2);
                    merger_procedure(stack_float1, stack_float2);
                    break;
                case SEPARATION:
                    separation_procedure(stack_float1);
                    break;
            }
            break;
        case COMPLEX_INT:
            input(*stack_complex_int1);
            switch(func){
                case MAP:
                    map_procedure(stack_complex_int1);
                    break;
                case WHERE:
                    where_procedure(stack_complex_int1);
                    break;
                case REDUCE:
                    reduce_procedure(stack_complex_int1);
                    break;
                case CONCATENATION:
                    input(*stack_complex_int2);
                    concatenation_procedure(stack_complex_int1, stack_complex_int2);
                    break;
                case RECOVERY:
                    recovery_procedure(stack_complex_int1);
                    break;
                case SEARCH_SUBSEQUENCE:
                    input(*stack_complex_int2);
                    search_subsequence_procedure(stack_complex_int1, stack_complex_int2);
                    break;
                case MERGER:
                    input(*stack_complex_int2);
                    merger_procedure(stack_complex_int1, stack_complex_int2);
                    break;
                case SEPARATION:
                    separation_procedure(stack_complex_int1);
                    break;
            }
            break;
        case COMPLEX_FLOAT:
            input(*stack_complex_float1);
            switch(func){
                case MAP:
                    map_procedure(stack_complex_float1);
                    break;
                case WHERE:
                    where_procedure(stack_complex_float1);
                    break;
                case REDUCE:
                    reduce_procedure(stack_complex_float1);
                    break;
                case CONCATENATION:
                    input(*stack_complex_float2);
                    concatenation_procedure(stack_complex_float1, stack_complex_float2);
                    break;
                case RECOVERY:
                    recovery_procedure(stack_complex_float1);
                    break;
                case SEARCH_SUBSEQUENCE:
                    input(*stack_complex_float2);
                    search_subsequence_procedure(stack_complex_float1, stack_complex_float2);
                    break;
                case MERGER:
                    input(*stack_complex_float2);
                    merger_procedure(stack_complex_float1, stack_complex_float2);
                    break;
                case SEPARATION:
                    separation_procedure(stack_complex_float1);
                    break;
            }
            break;
    }

    system("pause");
    system("cls");
}


#endif // INTERFACE_H_INCLUDED
