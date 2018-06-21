#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/*
template <typename A> decltype(auto) sqrt_f(A a){ return sqrt(a); }
template <typename A> decltype(auto) squad_f(A a){ return pow(a, 2); }
template <typename A> decltype(auto) add_f(A a){ return a+a; }
*/

template <class Type> double module(Type data){ return (sqrt((data.Real*data.Real) + (data.Imagine*data.Imagine))); }


template <typename Type> struct Complex
{
	Type Real;
	Type Imagine;
};

template <class Type> class Stack
{
private:
    int size;
    typedef struct Element
	{
		Type data;
		Element *next;
	};
	Element *head;
public:
	Stack() : head(NULL), size(0) {}
	~Stack() { del(); }

    int getSize() { return size; }

	bool push(Type data){
        Element *elem = new Element;
        (head == NULL) ? (elem->next = NULL) : (elem->next = head);
        elem->data = data;
        head = elem;
        size++;
        return true;
    }

	bool pop(){
        if (size == 0){
            return false;
        }else{
            Element *elem = head;
            head = head->next;
            delete elem;
            size--;
            return true;
        }
    }

	void del(){
        Element *current = head;
        Element *elem = head;
        while (elem != NULL)
        {
            current = current->next;
            delete elem;
            elem = current;
        }
        head = NULL;
        size = 0;
    }

	Type get(){
        if (head != NULL) {
            Element *elem = head;
            return elem->data;
        }else {
            cout<<"Stack is empty...\n";
        }
    }

};

template <typename Type> void output(struct Stack<Type> *s){
    Stack <Type> a = *s;
    int size = a.getSize();
    for(int i=0;i<size;i++){
        cout<<a.get()<<"\n";
        a.pop();
    }
    cout<<"\n";
}

template <typename Type> void output(struct Stack<Complex<Type>> *s){
    Stack <Complex<Type>> a = *s;
    int size = a.getSize();
    for(int i=0;i<size;i++){
        cout<<a.get().Real<<"+i("<<a.get().Imagine<<")\n";
        a.pop();
    }
    cout<<"\n";
}


template <typename Type> Stack<Type> *sort(Stack<Type> *stack_old)
{
    Stack<Type> *result = new Stack<Type>;
    Stack<Type> *tower = new Stack<Type>;
    Stack<Type> s = *stack_old;
    int s_size = s.getSize(), count = s_size;
    while(count!=0){
        if(count==s_size){
            result->push(s.get());
            cout<<result->get()<<"   res \n";
            s.pop();
        }else{
            cout<<s.get()<<"   get\n";
            if(s.get()<=result->get()){
                result->push(s.get());
                s.pop();
            }else{
                int res_size = result->getSize();
                for(int i=0;i<res_size;i++){
                    tower->push(result->get());
                    result->pop();
                }

                result->push(s.get());
                s.pop();

                int tow_size = tower->getSize();
                for(int i=0;i<tow_size;i++){
                    result->push(tower->get());
                    tower->pop();
                }
            }

            //output(result);

        }
        count--;
    }
    return result;
}

/*
template <typename Type> Stack<Complex<Type>> sort(Stack<Complex<Type>> *s)
{
    Stack<Complex<Type>> *result, *tower;
    int s_size = s->getSize();
    int count = s_size;
    while(count!=0){
        if(count==s_size){
            result->push(s->get());
            s->pop();
        }else{
            Complex <Type> comp = s->get();
            cout<<"re  "<<comp.Real<<"   im  "<<comp.Imagine<<"\n";
            cout<<"module: "<<module(s->get())<<"   "<<module(result->get())<<"\n";
            if(module(s->get())<=module(result->get())){
                result->push(s->get());
                s->pop();
            }else{
                int res_size = result->getSize();
                for(int i=0;i<res_size;i++){
                    tower->push(result->get());
                    result->pop();
                }

                result->push(s->get());
                s->pop();

                int tow_size = tower->getSize();
                for(int i=0;i<tow_size;i++){
                    result->push(tower->get());
                    tower->pop();
                }
            }
        }
        count--;
    }
    return result;
}
*/

template <class Type, typename Func> Stack<Type> *map(Stack<Type> *stack, Func func)
{
    Stack<Type> result = *stack;
    Stack<Type> *S = new Stack<Type>;

    int stack_size = stack->getSize();
    for(auto i=0;i<stack_size;i++){
            cout<<stack->get()<<"    stack get\n";
            cout<<func(stack->get())<<"    func\n";
        S->push(func(stack->get()));
        stack->pop();
    }

    for(auto i=0;i<stack_size;i++){
        result.push(S->get());
        S->pop();
    }

    delete S;
    return &result;
}


template <class Type, typename Func> Stack<Complex<Type>> *map(Stack<Complex<Type>> *stack, Func func)
{
    Stack<Complex<Type>> *result = new Stack<Complex<Type>>;
    Stack<Complex<Type>> *S = new Stack<Complex<Type>>;

    int stack_size = stack->getSize();
    for(auto i=0;i<stack_size;i++){
        S->push(func(stack->get()));
        stack->pop();
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
    Stack<Type> *S = new Stack<Type>;

    int stack_size = stack->getSize();
    for(auto i=0;i<stack_size;i++){
        if(func(stack->get())) S->push(func(stack->get()));
        stack->pop();
    }

    int s_size = S->getSize();
    for(auto i=0;i<s_size;i++){
        result->push(S->get());
        S->pop();
    }

    delete S;
    return result;
}

template <class Type> Stack<Type> *reduce(Stack<Type> *stack)
{
    Stack<Type> *result = new Stack<Type>;
    return result;
}

template <class Type> Stack<Type> merger(Stack<Type> s)
{

}

template <class Type> Stack<Type> extractionOfSubsequence(Stack<Type> s, int A[])
{
    Stack<Type> result;
    return result;
}


template <typename Type> void input(Stack<Type> *s){
    int N = 0;
    Type element;
    cout<<"Input number N of elements: ";
    cin>>N;

    for(int i=0;i<N;i++){
        cout<<"Input element: ";
        cin>>element;
        s->push(element);
    }
}

template <typename Type> void input(Stack<Complex<Type>> *s){
    int N = 0;
    Complex<Type> element_complex;
    cout<<"Input number N of elements: ";
    cin>>N;

    for(int i=0;i<N;i++){
        cout<<"Input REAL and IMAGINE parts of element: ";
        cin>>element_complex.Real>>element_complex.Imagine;
        s->push(element_complex);
    }
}



#endif

