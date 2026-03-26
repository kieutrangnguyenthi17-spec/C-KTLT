#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    h.push_back(0);

    stack<int> st;
    ll max_area = 0;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && h[i] < h[st.top()]) {
            ll height = h[st.top()];
            st.pop();

            ll width = st.empty() ? i : (i - st.top() - 1);

            max_area = max(max_area, height * width);
        }
        st.push(i);
    }

    cout << max_area << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
