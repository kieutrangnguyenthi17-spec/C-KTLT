#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9;

void dijkstra(int n, vector<vector<pair<int,int>>> &adj, int s, vector<int> &D) {
    vector<bool> S(n, false);
    D.assign(n, INF);
    D[s] = 0;

    for (int k = 0; k < n; k++) {
        int u = -1, minD = INF;
        for (int i = 0; i < n; i++) {
            if (!S[i] && D[i] < minD) {
                minD = D[i];
                u = i;
            }
        }

        if (u == -1) return;

        S[u] = true;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (D[u] + w < D[v]) D[v] = D[u] + w;
            }
        }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> D;
    dijkstra(n, adj, s, D);

    for (int i = 0; i < n; i++) {
        if (D[i] == INF) cout << s << " -> " << i << " : INF\n";
        else cout << s << " -> " << i << " : " << D[i] << "\n";
    }

    return 0;
}
