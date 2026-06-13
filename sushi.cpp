#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double dp[305][305][305];

int main() {
    int n;
    cin >> n;

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 1) a++;
        else if (x == 2) b++;
        else c++;
    }

    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            for (int k = n; k >= 0; k--) {

                if (i == 0 && j == 0 && k == 0)
                    continue;

                int s = i + j + k;
                if (s > n) continue;

                dp[i][j][k] = (double)n / s;

                if (i)
                    dp[i][j][k] += (double)i / s * dp[i - 1][j][k];

                if (j)
                    dp[i][j][k] += (double)j / s * dp[i + 1][j - 1][k];

                if (k)
                    dp[i][j][k] += (double)k / s * dp[i][j + 1][k - 1];
            }
        }
    }

    cout << fixed << setprecision(10) << dp[a][b][c];
}
