
#include "Stack.h"


template <typename Type> void input(Stack<Type> &s){
    int N = 0;
    Type element;
    cout<<"Input number N of elements: ";
    cin>>N;

    for(int i=0;i<N;i++){
        cout<<"Input element: ";
        cin>>element;
        s.push(element);
    }
}

template <typename Type> void input(Stack<Complex<Type>> &s){
    int N = 0;
    Complex<Type> element_complex;
    cout<<"Input number N of elements: ";
    cin>>N;

    for(int i=0;i<N;i++){
        cout<<"Input REAL and IMAGINE parts of element: ";
        cin>>element_complex.Real>>element_complex.Imagine;
        s.push(element_complex);
    }
}

template <typename Type> void output(struct Stack<Type> a){
    int size = a.getSize();
    for(int i=0;i<size;i++){
        cout<<a.get()<<"\n";
        a.pop();
    }
    cout<<"\n";
}


template <typename Type> void output(struct Stack<Complex<Type>> a){
    int size = a.getSize();
    for(int i=0;i<size;i++){
        cout<<a.get().Real<<"+i("<<a.get().Imagine<<")\n";
        a.pop();
    }
    cout<<"\n";
}

template <class Type, typename Func> Stack<Type> *map(Stack<Type> *stack, Func func)
{
    Stack<Type> *result = new Stack<Type>;
    Stack<Type> A = *stack;
    Stack<Type> *S = new Stack<Type>;

    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        S->push(func(A.get()));
        A.pop();
    }

    for(auto i=0;i<stack_size;i++){
        result->push(S->get());
        S->pop();
    }

    delete S;
    return result;
}


template <class Type, typename Func> Stack<Complex<Type>> *map(Stack<Complex<Type>> *stack, Func func)
{
    Stack<Complex<Type>> *result = new Stack<Complex<Type>>;
    Stack<Complex<Type>> A = *stack;
    Stack<Complex<Type>> *S = new Stack<Complex<Type>>;

    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        S->push(func(A.get()));
        A.pop();
    }

    for(auto i=0;i<stack_size;i++){
        result->push(S->get());
        S->pop();
    }

    delete S;
    return result;
}


template <class Type, typename Func> Stack<Type> *where(Stack<Type> *stack, Func func)
{
    Stack<Type> *result = new Stack<Type>;
    Stack<Type> A = *stack;
    Stack<Type> *S = new Stack<Type>;

    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        if(func(A.get())==true){
            S->push(A.get());
        }
        A.pop();
    }

    stack_size = S->getSize();
    for(auto i=0;i<stack_size;i++){
        result->push(S->get());
        S->pop();
    }

    delete S;
    return result;
}


template <class Type, typename Func> Stack<Complex<Type>> *where(Stack<Complex<Type>> *stack, Func func)
{
    Stack<Complex<Type>> *result = new Stack<Complex<Type>>;
    Stack<Complex<Type>> A = *stack;
    Stack<Complex<Type>> *S = new Stack<Complex<Type>>;

    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        if(func(A.get())==true){
            S->push(A.get());
        }
        A.pop();
    }

    stack_size = S->getSize();
    for(auto i=0;i<stack_size;i++){
        result->push(S->get());
        S->pop();
    }

    delete S;
    return result;
}

template <class Type, typename Func> Type *reduce(Stack<Type> *stack, Func func, int constant)
{
    Type B = 0, C = 0;
    Stack<Type> A = *stack;
    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        if(i==0){
            B = func(A.get(), constant);
        }else{
            C = func(A.get(), B);
            B = C;
        }
        A.pop();
    }

    Type *result = &B;
    return result;
}

template <class Type, typename Func> Type *reduce(Stack<Complex<Type>> *stack, Func func, int constant)
{
    Type B = 0, C = 0;
    Stack<Complex<Type>> A = *stack;
    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        if(i==0){
            B = func(A.get(), constant);
        }else{
            C = func(A.get(), B);
            B = C;
        }
        A.pop();
    }

    Type *result = &B;
    return result;
}


template <class Type> Stack<Type> *concatenation(Stack<Type> *stack1, Stack<Type> *stack2)
{
    Stack<Type> *result = new Stack<Type>;
    Stack<Type> *S1 = new Stack<Type>;
    Stack<Type> *S2 = new Stack<Type>;
    Stack<Type> A = *stack1;
    Stack<Type> B = *stack2;

    int stack1_size = A.getSize();
    int stack2_size = B.getSize();

    for(auto i=0;i<stack1_size;i++){
        S1->push(A.get());
        A.pop();
    }

    for(auto i=0;i<stack2_size;i++){
        S2->push(B.get());
        B.pop();
    }

    for(auto i=0;i<stack1_size;i++){
        result->push(S1->get());
        S1->pop();
    }

    for(auto i=0;i<stack2_size;i++){
        result->push(S2->get());
        S2->pop();
    }
    return result;
}

template <class Type> Stack<Complex<Type>> *concatenation(Stack<Complex<Type>> *stack1, Stack<Complex<Type>> *stack2)
{
    Stack<Complex<Type>> *result = new Stack<Complex<Type>>;
    Stack<Complex<Type>> *S1 = new Stack<Complex<Type>>;
    Stack<Complex<Type>> *S2 = new Stack<Complex<Type>>;
    Stack<Complex<Type>> A = *stack1;
    Stack<Complex<Type>> B = *stack2;

    int stack1_size = A.getSize();
    int stack2_size = B.getSize();

    for(auto i=0;i<stack1_size;i++){
        S1->push(A.get());
        A.pop();
    }

    for(auto i=0;i<stack2_size;i++){
        S2->push(B.get());
        B.pop();
    }

    for(auto i=0;i<stack1_size;i++){
        result->push(S1->get());
        S1->pop();
    }

    for(auto i=0;i<stack2_size;i++){
        result->push(S2->get());
        S2->pop();
    }
    return result;
}


template <class Type> Stack<Type> *recovery(Stack<Type> *stack, int index_arr[] , int N)
{
    Stack<Type> *result = new Stack<Type>;
    Stack<Type> A = *stack;
    Stack<Type> *S = new Stack<Type>;

    int count = 0;
    int stack_size = A.getSize();
    for(auto i=1;i<=stack_size;i++){
        for(auto j=0;j<N;j++){
            if(i==index_arr[j]){
                S->push(A.get());
                count++;
            }
        }
        A.pop();
    }

    for(auto i=0;i<count;i++){
        result->push(S->get());
        S->pop();
    }

    delete S;
    return result;
}


template <class Type> Stack<Complex<Type>> *recovery(Stack<Complex<Type>> *stack, int index_arr[] , int N)
{
    Stack<Complex<Type>> *result = new Stack<Complex<Type>>;
    Stack<Complex<Type>> A = *stack;
    Stack<Complex<Type>> *S = new Stack<Complex<Type>>;

    int count = 0;
    int stack_size = A.getSize();
    for(auto i=1;i<=stack_size;i++){
        for(auto j=0;j<N;j++){
            if(i==index_arr[j]){
                S->push(A.get());
                count++;
            }
        }
        A.pop();
    }

    for(auto i=0;i<count;i++){
        result->push(S->get());
        S->pop();
    }

    delete S;
    return result;
}


template <class Type> bool search_subsequence(Stack<Type> *stack1, Stack<Type> *stack2)
{
    bool result = false;
    Stack<Type> A = *stack1;
    Stack<Type> B = *stack2;

    int stack1_size = A.getSize();
    int stack2_size = B.getSize();

    Type S1[stack1_size], S2[stack2_size];

    for(auto i=0;i<stack1_size;i++){
        S1[i] = A.get();
        A.pop();
    }

    for(auto i=0;i<stack2_size;i++){
        S2[i] = B.get();
        B.pop();
    }

    bool flag;
    for(auto i=0;i<stack1_size;i++){
        flag = true;
        for(auto j=0;j<stack2_size;j++){
            if((S1[i+j]==S2[j])&&(flag == true)){
                flag = true;
                if(j==stack2_size-1){
                    result = true;
                    break;
                }
            }else{
                flag = false;
            }
        }
    }

    return result;
}

template <class Type> bool search_subsequence(Stack<Complex<Type>> *stack1, Stack<Complex<Type>> *stack2)
{
    bool result = false;
    Stack<Complex<Type>> A = *stack1;
    Stack<Complex<Type>> B = *stack2;

    int stack1_size = A.getSize();
    int stack2_size = B.getSize();

    Complex<Type> S1[stack1_size], S2[stack2_size];

    for(auto i=0;i<stack1_size;i++){
        S1[i] = A.get();
        A.pop();
    }

    for(auto i=0;i<stack2_size;i++){
        S2[i] = B.get();
        B.pop();
    }

    bool flag;
    for(auto i=0;i<stack1_size;i++){
        flag = true;
        for(auto j=0;j<stack2_size;j++){
            if((S1[i+j].Real==S2[j].Real)&&(S1[i+j].Imagine==S2[j].Imagine)&&(flag == true)){
                flag = true;
                if(j==stack2_size-1){
                    result = true;
                    break;
                }
            }else{
                flag = false;
            }
        }
    }

    return result;
}


template <class Type, typename Func> Stack<Type> *merger(Stack<Type> *stack1, Stack<Type> *stack2, Func func)
{
    Stack<Type> *result = new Stack<Type>;
    Stack<Type> *S1 = new Stack<Type>;
    Stack<Type> *S2 = new Stack<Type>;
    Stack<Type> A = *stack1;
    Stack<Type> B = *stack2;

    int stack1_size = A.getSize();
    int stack2_size = B.getSize();

    for(auto i=0;i<stack1_size;i++){
        S1->push(A.get());
        A.pop();
    }

    for(auto i=0;i<stack2_size;i++){
        S2->push(B.get());
        B.pop();
    }

    if(min(stack1_size, stack2_size)==stack1_size){
        for(int i=0;i<stack1_size;i++){
            result->push(func(S1->get(), S2->get()));
            S1->pop();
            S2->pop();
        }
    }else if(min(stack1_size, stack2_size)==stack2_size){
        for(int i=0;i<stack2_size;i++){
            result->push(func(S1->get(), S2->get()));
            S1->pop();
            S2->pop();
        }
    }

    return result;
}

template <class Type, typename Func> Stack<Complex<Type>> *merger(Stack<Complex<Type>> *stack1, Stack<Complex<Type>> *stack2, Func func)
{
    Stack<Complex<Type>> *result = new Stack<Complex<Type>>;
    Stack<Complex<Type>> *S1 = new Stack<Complex<Type>>;
    Stack<Complex<Type>> *S2 = new Stack<Complex<Type>>;
    Stack<Complex<Type>> A = *stack1;
    Stack<Complex<Type>> B = *stack2;

    int stack1_size = A.getSize();
    int stack2_size = B.getSize();

    for(auto i=0;i<stack1_size;i++){
        S1->push(A.get());
        A.pop();
    }

    for(auto i=0;i<stack2_size;i++){
        S2->push(B.get());
        B.pop();
    }

    if(min(stack1_size, stack2_size)==stack1_size){
        for(int i=0;i<stack1_size;i++){
            result->push(func(S1->get(), S2->get()));
            S1->pop();
            S2->pop();
        }
    }else if(min(stack1_size, stack2_size)==stack2_size){
        for(int i=0;i<stack2_size;i++){
            result->push(func(S1->get(), S2->get()));
            S1->pop();
            S2->pop();
        }
    }

    return result;
}

template <class Type, typename Func> separation_result<Type> *separation(Stack<Type> *stack, Func func)
{
    separation_result<Type> *result = new separation_result<Type>;
    Stack<Type> *true_stack = new Stack<Type>;
    Stack<Type> *false_stack = new Stack<Type>;
    Stack<Type> A = *stack;

    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        if(func(A.get())==true){
            true_stack->push(A.get());
        }else{
            false_stack->push(A.get());
        }
        A.pop();
    }

    Stack<Type> S_true = result->true_stack;
    Stack<Type> S_false = result->false_stack;

    int true_stack_size = true_stack->getSize(), false_stack_size = false_stack->getSize();
    for(auto i=0;i<true_stack_size;i++){
        S_true.push(true_stack->get());
        true_stack->pop();
    }

    for(auto i=0;i<true_stack_size;i++){
        S_false.push(false_stack->get());
        false_stack->pop();
    }

    delete true_stack;
    delete false_stack;
    return result;
}


template <class Type, typename Func> separation_result<Complex<Type>> *separation(Stack<Complex<Type>> *stack, Func func)
{
    separation_result<Complex<Type>> *result = new separation_result<Complex<Type>>;
    Stack<Complex<Type>> *true_stack = new Stack<Complex<Type>>;
    Stack<Complex<Type>> *false_stack = new Stack<Complex<Type>>;
    Stack<Complex<Type>> A = *stack;

    int stack_size = A.getSize();
    for(auto i=0;i<stack_size;i++){
        if(func(A.get())==true){
            true_stack->push(A.get());
        }else{
            false_stack->push(A.get());
        }
        A.pop();
    }

    Stack<Complex<Type>> S_true = result->true_stack;
    Stack<Complex<Type>> S_false = result->false_stack;

    int true_stack_size = true_stack->getSize(), false_stack_size = false_stack->getSize();
    for(auto i=0;i<true_stack_size;i++){
        S_true.push(true_stack->get());
        true_stack->pop();
    }

    for(auto i=0;i<true_stack_size;i++){
        S_false.push(false_stack->get());
        false_stack->pop();
    }

    delete true_stack;
    delete false_stack;
    return result;
}
