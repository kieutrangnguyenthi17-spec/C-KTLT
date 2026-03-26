#include<iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    // priority_queue lưu (khoảng cách, đỉnh)
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({2, 3});
    adj[2].push_back({0, 3});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});

    adj[2].push_back({3, 8});
    adj[3].push_back({2, 8});

    adj[2].push_back({4, 2});
    adj[4].push_back({2, 2});

    adj[3].push_back({4, 7});
    adj[4].push_back({3, 7});

    vector<int> dist = dijkstra(adj);

    cout << "Khoang cach ngan nhat tu dinh 0 toi cac dinh:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Dinh " << i << ": Khong the toi duoc\n";
        else
            cout << "Dinh " << i << ": " << dist[i] << "\n";
    }

    return 0;
}

