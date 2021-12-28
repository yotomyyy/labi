#include <iostream>
#include <ctime>
#include "Weapon.h"
using namespace std;




Weapon::Weapon(const char* str, int bp, int pp)
{
		blow_power = bp;
		protect_power = pp;
		strcpy(name, str);
}


Shield::Shield(const char* str, int bp, int pp) : Weapon(str, bp, pp){}
int Shield::Strike()
	{
		int r = rand() % blow_power;
		blow_power -= r % 10;
		return r;
	}
int Shield::Protect(int power)
	{
		int r = rand() % protect_power;
		protect_power -= r % 10;
		if ((power - r) > 0)
			return (power - r);
		else
			return 0;
	}


Club::Club(const char* str, int bp, int pp) : Weapon(str, bp, pp){}
int Club::Strike()
	{
		int r = rand() % blow_power;
		blow_power -= r % 10;
		return r;
	}
int Club::Protect(int power)
	{
		int r = rand() % protect_power;
		protect_power -= r % 10;
		if ((power - r) > 0)
			return (power - r);
		else
			return 0;
	}


Sword::Sword(const char* str, int bp, int pp) : Weapon(str, bp, pp){}
int Sword::Strike()
	{
		int r = rand() % blow_power;
		blow_power -= r % 10;
		return r;
	}
int Sword::Protect(int power)
	{
		int r = rand() % protect_power;
		protect_power -= r % 10;
		if ((power - r) > 0)
			return (power - r);
		else
			return 0;
	}



