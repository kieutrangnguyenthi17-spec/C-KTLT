#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    unordered_map<long long, long long> cnt;
    cnt.reserve(s.size() * 2);
    cnt.max_load_factor(0.7);

    long long prefix = 0;
    long long ans = 0;

    cnt[0] = 1;

    for (char c : s) {
        if (c == '1')
            prefix++;
        else
            prefix--;

        ans += cnt[prefix];
        cnt[prefix]++;
    }

    cout << ans << "\n";
    return 0;
}
