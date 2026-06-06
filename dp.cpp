#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    int a[r][c];
    long long d[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < c; j++) {
        d[0][j] = a[0][j];
    }

    for (int i = 1; i < r; i++) {

        long long x = -1, y = -1;
        int p = -1;

        for (int j = 0; j < c; j++) {
            if (d[i - 1][j] > x) {
                y = x;
                x = d[i - 1][j];
                p = j;
            } else if (d[i - 1][j] > y) {
                y = d[i - 1][j];
            }
        }

        for (int j = 0; j < c; j++) {
            if (j == p)
                d[i][j] = a[i][j] + y;
            else
                d[i][j] = a[i][j] + x;
        }
    }

    long long z = d[r - 1][0];

    for (int j = 1; j < c; j++) {
        if (d[r - 1][j] > z)
            z = d[r - 1][j];
    }

    cout << z;

    return 0;
}
