#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

template <typename A, typename B> decltype(auto) sum(A a, B b){ return a+b; }
template <typename A> decltype(auto) sqrt_f(A a){ return sqrt(a); }
template <typename A> decltype(auto) squad_f(A a){ return pow(a, 2); }
template <typename A> decltype(auto) add_f(A a){ return a+a; }

template <typename Type> struct Complex
{
	Type Real;
	Type Imagine;
};

template <class Type> class Stack
{
protected:
    int size;
private:
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

	virtual bool push(Type data){
        Element *elem = new Element;
        (head == NULL) ? (elem->next = NULL) : (elem->next = head);
        elem->data = data;
        head = elem;
        size++;
        return true;
    }

	virtual bool pop(){
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

    virtual void output(){
        if (head != NULL) {
            Element *current = head;
            cout<<current->data<<"\n";
            while (current->next != NULL) {
                current = current->next;
                cout<<current->data<<"\n";
            }
        }else {
            cout<<"Stack is empty...\n";
        }
        cout<<"\n";
    }

	virtual void del(){
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
            return 0;
        }
    }

};

template <class Type> class Stack_Complex : public Stack<Type>
{
private:
    typedef struct Element_Complex
    {
        Type Re_data;
        Type Im_data;
        Element_Complex *next;
    };
    Element_Complex *head;
public:
    Stack_Complex <Type>() : Stack <Type>() {}

    bool push(struct Complex <Type> data){
        Element_Complex *elem = new Element_Complex;
        (head == NULL) ? (elem->next = NULL) : (elem->next = head);
        elem->Re_data = data.Real;
        elem->Im_data = data.Imagine;
        head = elem;
        this->size++;
        return true;
    }

    bool pop() override {
        if (this->size == 0){
            return false;
        }else{
            Element_Complex *elem = head;
            head = head->next;
            delete elem;
            this->size--;
            return true;
        }
    }

    void del() override {
        Element_Complex *current = head;
        Element_Complex *elem = head;
        while (elem != NULL)
        {
            current = current->next;
            delete elem;
            elem = current;
        }
        head = NULL;
        this->size = 0;
    }

    void output() override {
        if (head != NULL) {
            Element_Complex *current = head;
            cout<<current->Re_data<<"+i("<<current->Im_data<<")\n";
            while (current->next != NULL) {
                current = current->next;
                cout<<current->Re_data<<"+i("<<current->Im_data<<")\n";
            }
        }else {
            cout<<"Stack is empty...\n";
        }
        cout<<"\n";
    }

    struct Complex <Type> get(){
        struct Complex <Type> comp;
        if (head != NULL) {
            Element_Complex *elem = head;
            comp.Real = elem->Re_data;
            comp.Imagine = elem->Im_data;
        }else {
            cout<<"Stack is empty...\n";
            comp.Real = 0;
            comp.Imagine = 0;
        }
        return comp;
    }
};

template <class Type> Stack<Type> sort(Stack<Type> s)
{
    Stack<Type> result, tower;
    int s_size = s.getSize();
    int count = s_size;
    while(count!=0){
        if(count==s_size){
            result.push(s.get());
            s.pop();
        }else{
            if(s.get()<=result.get()){
                result.push(s.get());
                s.pop();
            }else{
                for(int i=0;i<result.getSize();i++){
                    tower.push(result.get());
                    result.pop();
                }

                result.push(s.get());
                s.pop();

                for(int i=0;i<tower.getSize();i++){
                    result.push(tower.get());
                    tower.pop();
                }
            }
        }
        count--;
    }
    return result;
}

template <class Type, typename Func> Stack<Type> *map(Stack<Type> *stack, Func func)
{
    Stack<Type> *result = new Stack<Type>;
    Stack<Type> *S = new Stack<Type>;

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

template <class Type> Stack<Type> extractionOfSubsequence(Stack<Type> s, string index_str)
{
    Stack<Type> result;
    for(int i=0;i<index_str.length();i++){
        string number;
        number+=index_str[i];
        //if(index_str[i] == " "){

        //}
    }
    return result;
}

template <class Type> Stack<Type> concatenation(Stack <Type> s1, Stack <Type> s2)
{
    Stack <Type> result;
    int size_s1 = s1.getSize();
    int size_s2 = s2.getSize();
    Type *a = new Type[size_s1 + size_s2];

    for(int i=0;i<size_s1;i++){
        a[i] = s1.get();
        s1.pop();
    }

    for(int i=0;i<size_s2;i++){
        a[i + size_s1] = s2.get();
        s2.pop();
    }

    for(int i=size_s1 + size_s2-1;i>=0;i--){
        result.push(a[i]);
    }
    delete [] a;
    return result;
}

#endif

