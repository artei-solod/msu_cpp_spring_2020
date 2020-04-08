#include <iostream>
#include "mxtlib.h"
using namespace std;
int main()
{
    size_t m = 2;
    size_t n = 2;
    Matrix a(m, n);
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            a[i][j] = i * j;
        }
    }
    if (a[1][1] == 1) {
        cout << "Yes"<< '\n';
    };
    return 0;
}