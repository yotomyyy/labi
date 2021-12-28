#include <iostream>
using namespace std;

struct Info
{
    int inf;
};

struct Stack
{
    Info data; //информационная часть
    Stack* prev; //указатель на предыдущий элемент
}; 
Stack* top = nullptr; //указатель на вершину стека


void Push(int data)
{
    Stack* node = new Stack;
    node->data.inf = data;
    node->prev = top;
    top = node;
}

void Pop()
{
    Stack* dnode = top;
    top = top->prev;
    delete dnode;
}

void PrintStack()
{
    Stack* node = top;
    while (node != nullptr)
    {
        cout << node->data.inf << " ";
        node = node->prev;
    }
}

int main()
{
    Push(6);    Push(9);    Push(4);    Push(11);    Push(3);
    PrintStack();
    while (top != nullptr)
        Pop();
    cout << "\nStack is empty!";
    return 0;
}