#include <iostream>
using namespace std;

const int INF = 1e9;
int n;
int dist[20][20];
int dp[1<<20][20];

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> dist[i][j];

    int FULL = (1<<n);

    for(int mask=0;mask<FULL;mask++)
        for(int i=0;i<n;i++)
            dp[mask][i] = INF;

    dp[1][0] = 0;

    for(int mask=1;mask<FULL;mask++){
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))) continue;

            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(!(mask & (1<<j))) continue;

                int prev = mask ^ (1<<i);
                dp[mask][i] = min(dp[mask][i],
                                  dp[prev][j] + dist[j][i]);
            }
        }
    }

    int ans = INF;
    for(int i=1;i<n;i++)
        ans = min(ans, dp[FULL-1][i] + dist[i][0]);

    cout << ans;
}
