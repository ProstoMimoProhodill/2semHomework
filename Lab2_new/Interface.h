#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

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
    int where_func = 0, flag = 0;
    cout<<"Input where-function: \n1.less than zero\n2.more than zero\n\n";
    while(flag==0){
        cin>>where_func;
        if((where_func<1)||(where_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

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
    int where_func = 0, flag = 0;
    cout<<"Input where-function: \n1.REAL less than zero\n2.REAL more than zero\n\n";
    while(flag==0){
        cin>>where_func;
        if((where_func<1)||(where_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

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
    int reduce_func = 0, flag = 0;
    cout<<"Input reduce-function: \n1.3x1+2x2 \n2.5x1*x2+1\n\n";
    while(flag==0){
        cin>>reduce_func;
        if((reduce_func<1)||(reduce_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

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
    int reduce_func = 0, flag = 0;
    cout<<"Input reduce-function: \n1.Sum REAL numbers\n2.Sum IMAGINE numbers\n\n";
    while(flag==0){
        cin>>reduce_func;
        if((reduce_func<1)||(reduce_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

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
    system("cls");
    output(*s1);
    output(*s2);
    output(*concatenation(s1,s2));
}

template <class Type> void concatenation_procedure(Stack<Complex<Type>> *s1, Stack<Complex<Type>> *s2)
{
    system("cls");
    output(*s1);
    output(*s2);
    output(*concatenation(s1,s2));
}

template <class Type> void recovery_procedure(Stack<Type> *s)
{
    int N =0;
    cout<<"Input N index: \n";
    cin>>N;
    int index_arr[N];
    cout<<"Input index: \n";
    for(int i=0;i<N;i++) cin>>index_arr[i];

    system("cls");

    output(*recovery(s, index_arr, N));
}

template <class Type> void recovery_procedure(Stack<Complex<Type>> *s)
{
    int N =0;
    cout<<"Input N index: \n";
    cin>>N;
    int index_arr[N];
    cout<<"Input index: \n";
    for(int i=0;i<N;i++) cin>>index_arr[i];

    system("cls");

    output(*recovery(s, index_arr, N));
}

template <class Type> void search_subsequence_procedure(Stack<Type> *s1, Stack<Type> *s2)
{
    system("cls");
    output(*s1);
    output(*s2);
    bool result = search_subsequence(s1, s2);
    (result)?(cout<<"\nResult: true\n"):(cout<<"\nResult: true\n");
}

template <class Type> void search_subsequence_procedure(Stack<Complex<Type>> *s1, Stack<Complex<Type>> *s2)
{
    system("cls");
    output(*s1);
    output(*s2);
    bool result = search_subsequence(s1, s2);
    (result)?(cout<<"\nResult: true\n"):(cout<<"\nResult: true\n");
}

template <class Type> void merger_procedure(Stack<Type> *s1, Stack<Type> *s2)
{
    int merger_func = 0, flag = 0;
    cout<<"Input merger-function: \n1.3x1+2x2 \n2.5x1*x2+1 \n\n";
    while(flag==0){
        cin>>merger_func;
        if((merger_func<1)||(merger_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    switch(merger_func){
        case 1:
            output(*merger(s1, s2, [](Type x1, Type x2){ return 3*x1 + 2*x2; } ));
            break;
        case 2:
            output(*merger(s1, s2, [](Type x1, Type x2){ return 5*x1*x2 + 2; } ));
            break;
    }
}

template <class Type> void merger_procedure(Stack<Complex<Type>> *s1, Stack<Complex<Type>> *s2)
{
    int merger_func = 0, flag = 0;
    cout<<"Input merger-function: \n1.Full sum numbers \n\n";
    while(flag==0){
        cin>>merger_func;
        if((merger_func<1)||(merger_func>1)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    switch(merger_func){
        case 1:
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
    int separation_func = 0, flag = 0;
    cout<<"Input separation-function: \n1.less than zero\n2.Number%2 = 0\n\n";
    while(flag==0){
        cin>>separation_func;
        if((separation_func<1)||(separation_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    switch(separation_func){
        case 1:
            output((*separation(s, [](Type x){
                        bool b;
                        (x<0)?(b=true):(b=false);
                        return b; } )).true_stack);
            output((*separation(s, [](Type x){
                        bool b;
                        (x<0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
        case 2:
            output((*separation(s, [](Type x){
                        bool b;
                        ((int)x%2==0)?(b=true):(b=false);
                        return b; } )).true_stack);
            output((*separation(s, [](Type x){
                        bool b;
                        ((int)x%2==0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
    }
}

template <class Type> void separation_procedure(Stack<Complex<Type>> *s)
{
    int separation_func = 0, flag = 0;
    cout<<"Input separarion-function: \n1.REAL less than zero\n2.REAL more than zero\n\n";
    while(flag==0){
        cin>>separation_func;
        if((separation_func<1)||(separation_func>2)){
            flag = 0;
        }else{
            flag = 1;
        }
    }

    system("cls");

    switch(separation_func){
        case 1:
            output((*separation(s, [](Complex<Type> x){
                        bool b;
                        (x.Real<0)?(b=true):(b=false);
                        return b; } )).true_stack);
            output((*separation(s, [](Complex<Type> x){
                        bool b;
                        (x.Real<0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
        case 2:
            output((*separation<Complex<Type>>(s, [](Complex<Type> x){
                        bool b;
                        (x.Real>0)?(b=true):(b=false);
                        return b; } )).true_stack);
            output((*separation<Complex<Type>>(s, [](Complex<Type> x){
                        bool b;
                        (x.Real>0)?(b=true):(b=false);
                        return b; } )).false_stack);
            break;
    }
}

void choose_task()
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
    Function func = choose_function();

    switch(type){
        case INT:
            input(*stack_int1);
            switch(func){
                case MAP:
                    output(*stack_int1);
                    map_procedure(stack_int1);
                    break;
                case WHERE:
                    output(*stack_int1);
                    where_procedure(stack_int1);
                    break;
                case REDUCE:
                    output(*stack_int1);
                    reduce_procedure(stack_int1);
                    break;
                case CONCATENATION:
                    input(*stack_int2);
                    concatenation_procedure(stack_int1, stack_int2);
                    break;
                case RECOVERY:
                    output(*stack_int1);
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
                    output(*stack_int1);
                    separation_procedure(stack_int1);
                    break;
            }
            break;
        case FLOAT:
            input(*stack_float1);
            switch(func){
                case MAP:
                    output(*stack_float1);
                    map_procedure(stack_float1);
                    break;
                case WHERE:
                    output(*stack_float1);
                    where_procedure(stack_float1);
                    break;
                case REDUCE:
                    output(*stack_float1);
                    reduce_procedure(stack_float1);
                    break;
                case CONCATENATION:
                    input(*stack_float2);
                    concatenation_procedure(stack_float1, stack_float2);
                    break;
                case RECOVERY:
                    output(*stack_float1);
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
                    output(*stack_float1);
                    separation_procedure(stack_float1);
                    break;
            }
            break;
        case COMPLEX_INT:
            input(*stack_complex_int1);
            switch(func){
                case MAP:
                    output(*stack_complex_int1);
                    map_procedure(stack_complex_int1);
                    break;
                case WHERE:
                    output(*stack_complex_int1);
                    where_procedure(stack_complex_int1);
                    break;
                case REDUCE:
                    output(*stack_complex_int1);
                    reduce_procedure(stack_complex_int1);
                    break;
                case CONCATENATION:
                    input(*stack_complex_int2);
                    concatenation_procedure(stack_complex_int1, stack_complex_int2);
                    break;
                case RECOVERY:
                    output(*stack_complex_int1);
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
                    output(*stack_complex_int1);
                    separation_procedure(stack_complex_int1);
                    break;
            }
            break;
        case COMPLEX_FLOAT:
            input(*stack_complex_float1);
            switch(func){
                case MAP:
                    output(*stack_complex_float1);
                    map_procedure(stack_complex_float1);
                    break;
                case WHERE:
                    output(*stack_complex_float1);
                    where_procedure(stack_complex_float1);
                    break;
                case REDUCE:
                    output(*stack_complex_float1);
                    reduce_procedure(stack_complex_float1);
                    break;
                case CONCATENATION:
                    input(*stack_complex_float2);
                    concatenation_procedure(stack_complex_float1, stack_complex_float2);
                    break;
                case RECOVERY:
                    output(*stack_complex_float1);
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
                    output(*stack_complex_float1);
                    separation_procedure(stack_complex_float1);
                    break;
            }
            break;
    }

    system("pause");
    system("cls");
}


#endif // INTERFACE_H_INCLUDED
