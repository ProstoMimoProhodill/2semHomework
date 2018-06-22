#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "Stack.h"
#include "Interface.h"
#include <string>

bool map_test()
{
    int count_int = 0;
    Stack<int> stack_int;
    int answer_int[] = {2, 2 ,1 , 1, 1};

    for(int i=0;i<5;i++) stack_int.push(i+1);

    Stack<int> answer = *map(&stack_int, [](int x){ return sqrt(x); } );

    for(int i=0;i<5;i++){
        if(answer_int[i]==answer.get()) count_int++;
        stack_int.pop();
        answer.pop();
    }

    if(count_int==5){
        return true;
    }else{
        return false;
    }
}

bool where_test()
{
    int count_int = 0;
    Stack<int> stack_int;
    int data_int[] = {-1, 2 -3, -4,5};
    int answer_int[] = {-4, -1, -1};

    for(int i=0;i<5;i++) stack_int.push(data_int[i]);

    Stack<int> answer = *where(&stack_int, [](int x){
                                            bool b;
                                            (x<0)?(b=true):(b=false);
                                            return b; } );

    for(int i=0;i<3;i++){
        if(answer.get()==answer_int[i]) count_int++;
        stack_int.pop();
        answer.pop();
    }

    if(count_int==3){
        return true;
    }else{
        return false;
    }
}

bool reduce_test()
{
    int count_int = 0;
    Stack<int> stack_int;
    int answer_int = 387;

    for(int i=0;i<5;i++) stack_int.push(i+1);
    int answer = *reduce(&stack_int, [](int x1, int x2){ return 3*x1 + 2*x2; }, 0);

    if(answer==answer_int){
        return true;
    }else{
        return false;
    }
}


bool concatenation_test()
{
    int count_int = 0;
    Stack<int> stack_int1;
    Stack<int> stack_int2;
    int answer_int[] = {5, 4, 3, 2, 1};

    for(int i=0;i<3;i++) stack_int1.push(i+1);
    for(int i=0;i<2;i++) stack_int2.push(i+4);
    Stack<int> answer = *concatenation(&stack_int1, &stack_int2);

    for(int i=0;i<5;i++){
        if(answer.get()==answer_int[i]) count_int++;
        answer.pop();
    }

    if(count_int==5){
        return true;
    }else{
        return false;
    }
}

bool recovery_test()
{
    int count_int = 0;
    Stack<int> stack_int;
    int answer_int[] = {4 ,3};

    for(int i=0;i<5;i++) stack_int.push(i+1);
    int N = 2;
    int index[] = {2, 3};
    Stack<int> answer = *recovery(&stack_int, index, N);

    for(int i=0;i<2;i++){
        if(answer.get()==answer_int[i]) count_int++;
        answer.pop();
    }

    if(count_int==2){
        return true;
    }else{
        return false;
    }
}


bool search_subsequence_test()
{
    bool result;
    int count_int = 0;
    Stack<int> stack_int1, stack_int2;
    for(int i=0;i<5;i++) stack_int1.push(i+1);
    for(int i=0;i<2;i++) stack_int2.push(i+2);
    result = search_subsequence(&stack_int1, &stack_int2);
    return result;
}


bool merger_test()
{
    int count_int = 0;

    Stack<int> stack_int1, stack_int2;
    for(int i=0;i<5;i++) stack_int1.push(i+1);
    for(int i=0;i<3;i++) stack_int2.push(i+10);
    Stack<int> answer = *merger(&stack_int1, &stack_int2, [](int x1, int x2){ return 3*x1 + 2*x2; } );
    int quest_arr[] = {33, 28, 23};

    for(int i=0;i<3;i++){
        if(answer.get()==quest_arr[i]) count_int++;
        answer.pop();
    }

    if(count_int==3){
        return true;
    }else{
        return false;
    }
}


bool separation_test()
{
    int count_int = 0;
    Stack<int> stack_int;
    int data[] = {-1, 2, -3, -4, 5};
    for(int i=0;i<5;i++) stack_int.push(data[i]);

    Stack<int> answer_true = (*separation(&stack_int, [](int x){
                                                bool b;
                                                (x<0)?(b=true):(b=false);
                                                return b; } )).true_stack;

    Stack<int> answer_false = (*separation(&stack_int, [](int x){
                                                bool b;
                                                (x<0)?(b=true):(b=false);
                                                return b; } )).false_stack;

    int quest_true[] = {-4, -3, -1};
    int quest_false[] = {5, 2};

    for(int i=0;i<3;i++){
        if(answer_true.get()==quest_true[i]) count_int++;
        answer_true.pop();
    }

    for(int i=0;i<2;i++){
        if(answer_false.get()==quest_false[i]) count_int++;
        answer_false.pop();
    }

    if(count_int==5){
        return true;
    }else{
        return false;
    }
}

string bool_string(bool b){
        if(b==true){
            return "true";
        }else{
            return "false";
        }
}

void autotest()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);

    cout<<"Autotest:  \n";
    cout<<"map - "<<bool_string(map_test())<<"\n";
    cout<<"where - "<<bool_string(where_test())<<"\n";
    cout<<"reduce - "<<bool_string(reduce_test())<<"\n";
    cout<<"concatenation - "<<bool_string(concatenation_test())<<"\n";
    cout<<"recovery - "<<bool_string(recovery_test())<<"\n";
    cout<<"search_subsequence - "<<bool_string(search_subsequence_test())<<"\n";
    cout<<"merger - "<<bool_string(merger_test())<<"\n";
    cout<<"separation - "<<bool_string(separation_test())<<"\n";
    system("pause");
    system("cls");
}


#endif // TEST_H_INCLUDED
