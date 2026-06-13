#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> d(200005, 0);

    while (n--) {
        int l, r;
        cin >> l >> r;

        d[l]++;
        d[r + 1]--;
    }

    vector<int> a(200005, 0);

    for (int i = 1; i <= 200000; i++) {
        a[i] = a[i - 1] + d[i];

        if (a[i] >= k)
            a[i] = 1;
        else
            a[i] = 0;
    }

    vector<int> p(200005, 0);

    for (int i = 1; i <= 200000; i++)
        p[i] = p[i - 1] + a[i];

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << p[r] - p[l - 1] << "\n";
    }

    return 0;
}
