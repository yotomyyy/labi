#include <iostream>
#include <ctime>
using namespace std;
class Array {
	double* arr;
	unsigned size;
	friend void Print() {
	}
public:
	Array() {}
	explicit Array(int s) : size(s)
	{
		arr = new double[size];
	}
	void Init()
	{
		for (int i = 0; i < size; i++)
			*(arr + i) = rand() % 20;
	}
	Array(Array& AC)
	{
		size = AC.size;
		arr = new double[size];
		for (int i = 0; i < size; i++)
			*(arr + i) = AC.arr[i];
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
		if (i >= 0 && i < size) {
			cout << "Введите новое значение: ";
			cin >> *(arr + i);
		}
		else {
			cout << "Выход за пределы массива\n";
			goto link;
		}
	}
	const void Get() {
		int i;
		cout << "\nВведите индекс массива: ";
	link:
		cin >> i;
		if (i >= 0 && i < size) {
			cout << "arr[" << i << "] = " << *(arr + i);
		}
		else {
			cout << "Выход за пределы массива\n";
			goto link;
		}
	}
	friend void Print(Array&);
	Array& operator=(const Array& ACL) { //копирование массива
		if (size == ACL.size)
			for (int i = 0; i < size; i++)
				*(arr + i) = *(ACL.arr + i);
		else {
			delete[] arr;
			size = ACL.size;
			arr = new double[size];
			for (int i = 0; i < size; i++)
				*(arr + i) = *(ACL.arr + i);
		}
		return *this;
	}
	Array& operator+=(const Array& ARp) { //добавление массива
		if (!ARp.size)
			exit(1);
		int buF = size, t = 0;
		double* buffer = new double[buF];
		for (int i = 0; i < buF; i++)
			*(buffer + i) = *(arr + i);
		delete[] arr;
		size += ARp.size;
		arr = new double[size];
		for (int i = 0; i < buF; i++)
			*(arr + i) = *(buffer + i);
		for (int i = buF; i < size; i++)
			*(arr + i) = *(ARp.arr + t++);
		delete[] buffer;
		return *this;
	}
	Array& operator+=(double a) { //добавление нового элемента в массив
		int buF = size;
		double* buffer = new double[buF];
		for (int i = 0; i < buF; i++)
			*(buffer + i) = *(arr + i);
		delete[] arr;
		arr = new double[++size];
		for (int i = 0; i < buF; i++)
			*(arr + i) = *(buffer + i);
		arr[size - 1] = a;
		delete[] buffer;
		return *this;
	}
	double& operator[](int k) { //получение доступа к элементу массива
		if (k >= size || k < 0) {
			cout << "Выход за пределы массива!";
			exit(1);
		}
		return arr[k];
	}
	friend istream& operator>>(istream& is, Array&);//ввод значений
	friend ostream& operator<<(ostream& os, Array&);//вывод массива
	~Array()
	{
		delete[] arr;
	}
};
void Print(Array& AR1)
{
	cout << "\nArray: ";
	for (int i = 0; i < AR1.size; i++)
		cout << AR1.arr[i] << " ";
}

int In()
{
	int size;
	cout << "Введите размер массива: ";
link:
	cin >> size;
	if (size < 1) {
		cout << "\nВведите корректный размер!\n";
		goto link;
	}
	return size;
}

istream& operator>>(istream& is, Array& AR) {
	if (!AR.size)
		exit(1);
	for (int i = 0; i < AR.size; i++) {
		cout << "\narr[" << i << "] = ";
		is >> *(AR.arr + i);
	}
	return is;
}

ostream& operator<<(ostream& os, Array& AR) {
	if (!AR.size)
		exit(1);
	for (int i = 0; i < AR.size; i++) {
		cout << "\narr[" << i << "] = ";
		os << *(AR.arr + i);
	}
	return os;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int s = In();
	int p = In();
	Array ARR(s), ARRCopy(p);
	ARR.Init();
	ARRCopy.Init();
	Print(ARR);
	Print(ARRCopy);
	ARR += ARRCopy;
	Print(ARR);
	ARR += -2;
	Print(ARR);
	cout << endl <<  "Элемент с индексом 2 = " << ARR[2];
	cin >> ARR;
	Print(ARR);
	cout << "\nARRCopy:" << ARRCopy;
	return 0;
}
