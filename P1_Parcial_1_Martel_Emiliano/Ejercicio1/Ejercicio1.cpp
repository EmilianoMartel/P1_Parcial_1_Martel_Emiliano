#include <iostream>
#include "WarriorCreator.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    WarriorCreator creator = WarriorCreator();

    creator.start();

    cin.get();
}