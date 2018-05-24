#include <iostream>
#include <fstream>
#include "overload.h"

using namespace std;

int main()
{
    ofstream file("C:/Users/User/Desktop/lorem.txt");

    int f;

    cin >> f;

    cout << "While _ less than " << endl;

    for(int i = 0; i < f; i++)
    {
        file << "lorem ipson dolor capez lorem ipson dolor capez lorem ipson\n";
    }

    file.close();

    return 0;
}

