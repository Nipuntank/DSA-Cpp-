#include <iostream>
#include "hasmaps.h"
using namespace std;

int main()
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + 1;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        cout << map.getloadFactor() << endl;
    }
    return 0;
}