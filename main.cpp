#include <iostream>
#include <fstream>
#include "Lista.h"
using namespace std;
int main()
{
    ifstream input;
    input.open("input.txt");

    Lista l1(4);
    input>>l1;
    cout<<l1;

    input.close();


    return 0;
}
