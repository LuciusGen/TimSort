#include <iostream>
#include "head.h"


using namespace std;

bool key(int arg1, int arg2) {
    return (arg1 > arg2);
}

int main()
{
    int *a = new int[5];
    size_t n = 5;
    a[0] = 1; a[1] = 2; a[2] = 5; a[3] = 3; a[4] = 0;

    timSort(a, n, key);

    for (int i = 0; i < 5; ++i) {
        cout << a[i];
    }
    delete[] a;
}
