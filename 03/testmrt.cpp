#include <iostream>
#include "mxtlib.h"
int main()
{
    int m = 2;
    int n = 2;
    matrix a(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i * j;
        }
    }
    if (a[1][1] == 1) {
        cout << "Ok";
    };
    return 0;
}