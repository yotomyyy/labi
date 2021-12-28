#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

//математические исключения
class MathException
{
public:
	char op_name[30]; //имя операции
	long val1; //значение левого операнда операции
	long val2; //значение правого операнда операции
	MathException(const char* name_op, long v1, long v2) : val1(v1), val2(v2) 
	{
		strcpy(op_name, name_op);
	}
	virtual const char* Message() = 0;
};


class OverflowException : public MathException 
{
public:
	OverflowException(const char* name_op, long v1, long v2) : MathException(name_op, v1, v2) {}
	const char* Message()
	{
		if (fabs(val1) > 20000)
			return "OverflowException";
		return "Good is all";
	}
};

class UnderflowException : public MathException 
{
public:
	UnderflowException(const char* name_op, long v1, long v2) : MathException(name_op, v1, v2) {}
	const char* Message()
	{
		if (fabs(val2) > 20000)
			return "UnderflowException";
		return "Good is all";
	}
};

class ZdivideException : public MathException 
{
public:
	ZdivideException(const char* name_op, long v1, long v2) : MathException(name_op, v1, v2) {}
	const char* Message()
	{
		if (!val2)
			return "DivideByZeroException";
		return "Good is all";
	}
};

class Math
{
public:
	long Add(long a, long b); //сложение (a + b)
	long Sub(long a, long b); //вычитание (a - b)
	long Mul(long a, long b); //умножение (a * b)
	long Div(long a, long b); //деление (a / b)
	long Mod(long a, long b); //остаток от деления (a % b)
};

long Math::Add(long a, long b)
{
	if (fabs(a) > 20000)
		throw "OverflowException";
	if (fabs(b) > 20000)
		throw "UnderflowException";
	return a + b;
}

long Math::Sub(long a, long b)
{
	if (fabs(a) > 20000)
		throw "OverflowException";
	if (fabs(b) > 20000)
		throw "UnderflowException";
	return a - b;
}

long Math::Mul(long a, long b)
{
	if (fabs(a) > 20000)
		throw "OverflowException";
	if (fabs(b) > 20000)
		throw "UnderflowException";
	return a * b;
}

long Math::Div(long a, long b)
{
	if (fabs(a) > 20000)
		throw "OverflowException";
	if (fabs(b) > 20000)
		throw "UnderflowException";
	if (!b)
		throw "DivideByZeroException";
	return a / b;
}

long Math::Mod(long a, long b)
{
	if (fabs(a) > 20000)
		throw "OverflowException";
	if (fabs(b) > 20000)
		throw "UnderflowException";
	if (!b)
		throw "DivideByZeroException";
	return a % b;
}

int main()
{
	int a, b;
	cout << "Enter the first operand: ";
	cin >> a;
	cout << "Enter the Second operand: ";
	cin >> b;
	try
	{
		Math A;
		cout << "Add: " << A.Add(a, b) << endl;
		cout << "Sub: " << A.Sub(a, b) << endl;
        cout << "Mul: " << A.Mul(a, b) << endl;
		cout << "Div: " <<  A.Div(a, b) << endl;
	}
	catch (const char* s)
	{
		if (!strcmp(s, "OverflowException"))
		{
			OverflowException Exc(s, a, b);
			cout << Exc.Message();
			return 1;
		}
		if (!strcmp(s, "UnderflowException"))
		{
			UnderflowException Exc(s, a, b);
			cout << Exc.Message();
			return 1;
		}
		if (!strcmp(s, "DivideByZeroException"))
		{
			ZdivideException Exc(s, a, b);
			cout << Exc.Message();
			return 1;
		}
	}
    return 0;
}