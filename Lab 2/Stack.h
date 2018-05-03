#ifndef STACK_H_
#define STACK_H_

#include <iostream>
using namespace std;

template <typename Re_type, typename Im_type> struct Complex
{
	Re_type Real;
	Im_type Imagine;
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
	bool push(Type data);
	bool pop();
    void output();
	void del();
	Type get();
};

template <class Type> bool Stack<Type>::push(Type data)
{
	Element *elem = new Element;
	(head == NULL) ? (elem->next = NULL) : (elem->next = head);
	elem->data = data;
	head = elem;
	size++;
	return true;
}

template <class Type> bool Stack<Type>::pop()
{
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

template <class Type> Type Stack<Type>::get()
{
	if (head != NULL) {
		Element *elem = head;
		return elem->data;
	}else {
		cout<<"Stack is empty...\n";
		return 0;
	}
}

template <class Type> void Stack<Type>::output()
{
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

template <class Type> void Stack<Type>::del()
{
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


template <class Type> Stack<Type> sort(Stack<Type> s)
{
    Stack<Type> result;
    int size = s.getSize();
    Type *a = new Type[size];
    for(int i=0;i<size;i++){
        a[i] = s.get();
        s.pop();
    }

    for(int i=size-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                Type tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
     }

     for(int i=size-1;i>=0;i--){
        result.push(a[i]);
     }

     delete [] a;
     return result;
}

template <class Type> Stack<Type> map(Stack<Type> s)
{

}

template <class Type> Stack<Type> where(Stack<Type> s)
{

}

template <class Type> Stack<Type> reduce(Stack<Type> s)
{

}

template <class Type> Stack<Type> merger(Stack<Type> s)
{

}

template <class Type> Stack<Type> extractionOfSubsequence(Stack<Type> s)
{

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
    return result;
}


#endif

