#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long s;
    cin >> n >> s;

    long long total_attack = 0;

    // priority_queue lưu (ki, số lính còn có thể đặt)
    priority_queue<pair<long long, long long>> pq;

    for (int i = 0; i < n; ++i) {
        long long a, k;
        cin >> a >> k;
        total_attack += a;

        long long need = (a + k - 1) / k; // ceil(a / k)
        pq.push({k, need});
    }

    long long reduced = 0;

    while (s > 0 && !pq.empty()) {
        auto [k, remain] = pq.top();
        pq.pop();

        long long use = min(s, remain);
        reduced += use * k;
        s -= use;

        if (s == 0) break;
    }

    long long result = max(0LL, total_attack - reduced);
    cout << result << "\n";

    return 0;
}

