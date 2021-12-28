#include <iostream>
using namespace std;

template <typename T>
struct StackItem
{
	T data;		//данные
	StackItem<T>* next ;	//указатель на следующий элемент
};
template <typename T>
class Stackk
{
	StackItem<T>* top;	//указатель на вершину стека
public:
	Stackk() : top(nullptr){}
	void push(T inf)
	{
		StackItem<T>* t = new StackItem<T>;
		t->data = inf;
		t->next = top;
		top = t;
	}
	void pop()
	{
		StackItem<T>* t = top;
		top = top->next;
		delete t;
	}
	void PrintStack()
	{
		StackItem<T>* t = top;
		cout << "Stack: ";
		while (t != nullptr)
		{
			cout << t->data << " ";
			t = t->next;
		}
	}
	~Stackk()
	{
		StackItem<T>* t = top;
		while (t != nullptr)
		{
			top = top->next;
			delete t;
			t = top;
		}
		cout << "\nStack is empty" << endl;
	}
};

int main()
{
	Stackk<int> s1;
	for (int i = 0; i < 10; i++)
		s1.push(i);
	s1.PrintStack();
	cout << "\nDeleting the last two elements in the stack:\n";
	for (int i = 0; i < 2; i++)
		s1.pop();
	s1.PrintStack();
    return 0;
}