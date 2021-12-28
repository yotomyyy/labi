#include <iostream>
#include <ctime>
using namespace std;

class Array{
        double* arr;
        unsigned size;
        friend void Print(){
            
        }
    public:
        Array() {}
        explicit Array(int s) : size(s)
        {
            arr = new double[size];
        }
        void Init()
        {
            for(int i = 0; i < size; i++)
                *(arr+i) = rand() % 20;
        }

        Array(Array& AC)
        {
            size = AC.size;
            arr = new double[size];
            for(int i = 0; i < size; i++)
                *(arr+i) = AC.arr[i];
        }

        void DelArray()
        {
            delete[] arr;
        }

        void Set()
        {
            int i;
            cout << "\nВведите индекс массива: ";
            link:
            cin >> i;
            if(i >= 0 && i < size){
                cout << "Введите новое значение: ";
                cin >> *(arr+i);
            }
            else{
                cout << "Выход за пределы массива\n";
                goto link;
            }
        }

         const void Get(){
            int i;
            cout << "\nВведите индекс массива: ";
            link:
            cin >> i;
            if(i >= 0 && i < size){
                cout << "arr[" << i <<"] = " << *(arr+i);
            }
            else{
                cout << "Выход за пределы массива\n";
                goto link;
            }
        }

        friend void Print(Array&);

        ~Array()
        {
        delete[] arr;
        }
};

void Print(Array& AR1)
{
    cout << "\nArray: ";
    for(int i = 0; i < AR1.size; i++)
        cout << AR1.arr[i] << " ";
}

int In()
{
    int size;
    cout << "Введите размер массива: ";
    link:
    cin >> size;
    if(size < 1){
    cout << "\nВведите корректный размер!\n";
    goto link;
    }
    return size;
}


int main()
{
    srand(time(NULL));
    int s = In();
    Array AR(s);
    AR.Init();
    Print(AR);
    AR.Get();
    AR.Set();
    Print(AR);
    return 0;
}