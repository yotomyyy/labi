#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <ctime>
using namespace std;

class Weapon
{
protected:
	//имя
	char name[20];
	int blow_power;
	int protect_power;
public:
	Weapon(const char* str, int bp, int pp);
	virtual int Strike() = 0;
	virtual int Protect(int power) = 0;
	char* GetName()
	{
		return name;
	}
};


class Shield :public Weapon //щит
{
public:
Shield(const char* str, int bp, int pp);
	int Strike() override;
	int Protect(int power) override;
};


class Club :public Weapon //дубинка
{
public:
Club(const char* str, int bp, int pp);
	int Strike() override;
	int Protect(int power) override;
};


class Sword :public Weapon //меч
{
public:
Sword(const char* str, int bp, int pp);
	int Strike() override;
	int Protect(int power) override;
};
#endif