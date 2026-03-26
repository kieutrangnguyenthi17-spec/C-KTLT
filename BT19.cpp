// Có N thành phố, được đánh số từ 0 đến N-1. Một người du lịch xuất phát từ
// một thành phố muốn đi thăm các thành phố khác, mỗi thành phố đúng một lần rồi
// quay về nơi xuất phát. Chi phí đi từ thành phố i đến thành phố j là A[i][j], (0 ≤ i,j <
// N). Hãy tìm một hành trình cho người du lịch để tổng chi phí theo hành trình này là
// ít nhất.
//*//
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<vector<int>> cost;       // ma trận chi phí
vector<bool> visited;           // đánh dấu thành phố đã thăm
int minCost = INT_MAX;
vector<int> bestPath;           // lưu đường đi tốt nhất

void TSP(int currentCity, int count, int currentCost, vector<int>& path) {
    // Nếu đã thăm hết các thành phố
    if (count == N) {
        // Cộng chi phí quay về thành phố 0
        if (cost[currentCity][0] > 0) {
            int totalCost = currentCost + cost[currentCity][0];
            if (totalCost < minCost) {
                minCost = totalCost;
                bestPath = path;
                bestPath.push_back(0);  // quay về thành phố đầu
            }
        }
        return;
    }

    // Thử đi đến các thành phố chưa thăm
    for (int nextCity = 0; nextCity < N; nextCity++) {
        if (!visited[nextCity] && cost[currentCity][nextCity] > 0) {
            visited[nextCity] = true;
            path.push_back(nextCity);
            TSP(nextCity, count + 1, currentCost + cost[currentCity][nextCity], path);
            path.pop_back();
            visited[nextCity] = false;
        }
    }
}

int main() {
    cin >> N;
    cost.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    visited.assign(N, false);
    visited[0] = true;
    vector<int> path = {0};   // bắt đầu từ thành phố 0
    TSP(0, 1, 0, path);

    cout << "Chi phi nho nhat: " << minCost << "\nHanh trinh: ";
    for (int city : bestPath) cout << city << " ";
    cout << endl;

    return 0;
}
