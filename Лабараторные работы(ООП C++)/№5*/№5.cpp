#include <iostream>
#include <ctime>
using namespace std;

class Weapon
{
protected:
	//имя
	char name[20];
	//сила удара
	int blow_power;
	//сила защиты
	int protect_power;
public:
	//конструктор
	Weapon(const char* str, int bp, int pp)
	{
		blow_power = bp;
		protect_power = pp;
		strcpy(name, str);
	}
	//ударить
	virtual int Strike() = 0;
	//защититься
	virtual int Protect(int power) = 0;
	//возвратить имя оружия
	char* GetName()
	{
		return name;
	}
};


class Shield :public Weapon //щит
{
public:
	Shield(const char* str, int bp, int pp) : Weapon(str, bp, pp){}
	int Strike() override
	{
		int r = rand() % blow_power;
		blow_power -= r % 10;
		return r;
	}
	int Protect(int power) override
	{
		int r = rand() % protect_power;
		protect_power -= r % 10;
		if ((power - r) > 0)
			return (power - r);
		else
			return 0;
	}
};


class Club :public Weapon //дубинка
{
public:
	Club(const char* str, int bp, int pp) : Weapon(str, bp, pp) {}
	int Strike() override
	{
		int r = rand() % blow_power;
		blow_power -= r % 10;
		return r;
	}
	int Protect(int power) override
	{
		int r = rand() % protect_power;
		protect_power -= r % 10;
		if ((power - r) > 0)
			return (power - r);
		else
			return 0;
	}
};


class Sword :public Weapon //меч
{
public:
	Sword(const char* str, int bp, int pp) : Weapon(str, bp, pp){}
	int Strike() override
	{
		int r = rand() % blow_power;
		blow_power -= r % 10;
		return r;
	}
	int Protect(int power) override
	{
		int r = rand() % protect_power;
		protect_power -= r % 10;
		if ((power - r) > 0)
			return (power - r);
		else
			return 0;
	}
};

int main()
{
	srand(time(NULL));
	Sword sd("Sworddd", 5, 3);
	cout << sd.Protect(2);
	cout << sd.GetName() << endl;
	Club cl("Clubbb", 12, 4);
	cout << cl.Protect(2);
	cout << cl.GetName() << endl;
	Shield sh("Shielddd", 5, 3);
	cout << sh.Protect(2);
	cout << sh.GetName() << endl;
    return 0;
}

