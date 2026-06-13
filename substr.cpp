#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0, ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')
            sum--;
        else
            sum++;

        if (mp.count(sum))
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }

    cout << ans;

    return 0;
}
