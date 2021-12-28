#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    set<int> ss;
    for(int i = 0; i < 11; i+=2)
        ss.insert(i);
    set<int> :: iterator itr;
    cout << "Starter Set: ";
    for(itr=ss.begin(); itr != ss.end(); itr++)
        cout << *itr << " ";
    while(ss.size() != 1)
        ss.erase(ss.begin());
    cout << "\nFinal Set: ";
    for(itr=ss.begin(); itr != ss.end(); itr++)
        cout << *itr << " ";
    ss.clear();
    for(itr=ss.begin(); itr != ss.end(); itr++)
        cout << *itr << " ";
    return 0;
}