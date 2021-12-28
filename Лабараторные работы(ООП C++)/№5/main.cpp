#include <iostream>
#include <ctime>
#include "Weapon.h"
using namespace std;



int main()
{
	srand(time(NULL));
	Shield shield("Shield", 5, 3);
	cout << shield.Protect(2);
	cout << shield.GetName() << endl;
    return 0;
}

