// Superior là một hòn đảo tuyệt đẹp với n địa điểm chụp ảnh và các đường một chiều nối các điểm
// chụp ảnh với nhau. Đoàn khách tham quan có r người với sở thích chụp ảnh khác nhau. Theo đó,
// mỗi người sẽ đưa ra danh sách các địa điểm mà họ muốn chụp. Bạn cần giúp mỗi người trong đoàn
// lập lịch di chuyển sao cho đi qua các điểm họ yêu cầu đúng một lần, không đi qua điểm nào khác,
// bắt đầu tại điểm đầu tiên và kết thúc tại điểm cuối cùng trong danh sách mà họ đưa ra, và có tổng
// khoảng cách đi lại là nhỏ nhất.
// Dữ liệu vào:
// Dòng đầu chứa n và r
// Tiếp theo là ma trận n×n mô tả chi phí đi lại giữa các địa điểm. Chi phí bằng 0 có nghĩa là không
// thể đi lại giữa hai địa điểm đó.
// r dòng tiếp theo chứa danh sách các địa điểm mà người r đưa ra. Lưu ý là hành mỗi hành trình cần
// phải bắt đầu và kết thúc bởi hai đỉnh đầu và cuối của danh sách, còn các địa điểm còn lại có thể
// thăm theo bất kỳ thứ tự nào
// Kết quả:

// Gồm r dòng ghi chi phí đi lại ít nhất của r người theo thứ tự đầu vào
// Ví dụ:
// Dữ liệu mẫu:
// 6 3
// 0 1 2 0 1 1
// 1 0 1 1 1 0
// 0 2 0 1 3 0
// 4 3 1 0 0 0
// 0 0 1 1 0 0
// 1 0 0 0 0 0
// 1 3 5
// 6 3 2 5
// 6 1 2 3 4 5
// Kết quả mẫu:
// 5
// 0
// 7
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;

    vector<vector<long long>> dist(n+1, vector<long long>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dist[i][j];
            if(i != j && dist[i][j] == 0)
                dist[i][j] = INF;
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    while(r--){
        vector<int> p;
        int x;
        while(cin >> x){
            p.push_back(x);
            if(cin.peek() == '\n') break;
        }

        int k = p.size();
        if(k == 1){
            cout << 0 << '\n';
            continue;
        }

        int mid = k - 2; 
        if(mid < 0){
            long long ans = dist[p[0]][p[1]];
            cout << (ans >= INF ? 0 : ans) << '\n';
            continue;
        }

        int FULL = 1 << mid;
        vector<vector<long long>> dp(FULL, vector<long long>(mid, INF));
        for(int i = 0; i < mid; i++){
            long long d = dist[p[0]][p[i+1]];
            if(d < INF)
                dp[1 << i][i] = d;
        }
        for(int mask = 0; mask < FULL; mask++){
            for(int u = 0; u < mid; u++){
                if(!(mask & (1 << u))) continue;
                long long cur = dp[mask][u];
                if(cur >= INF) continue;
                for(int v = 0; v < mid; v++){
                    if(mask & (1 << v)) continue;
                    long long d = dist[p[u+1]][p[v+1]];
                    if(d < INF)
                        dp[mask | (1 << v)][v] =
                            min(dp[mask | (1 << v)][v], cur + d);
                }
            }
        }

        long long ans = INF;
        for(int i = 0; i < mid; i++){
            long long d = dist[p[i+1]][p[k-1]];
            if(d < INF)
                ans = min(ans, dp[FULL-1][i] + d);
        }

        cout << (ans >= INF ? 0 : ans) << '\n';
    }

    return 0;
}
