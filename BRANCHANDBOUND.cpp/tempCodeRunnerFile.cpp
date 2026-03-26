#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 20;
const double INF = 1e18;

int n;
double c[MAXN][MAXN];
bool visited[MAXN];
double bestCost = INF;
vector<int> bestPath, curPath;

double minEdge = INF;

void Try(int k, double cost){
    if(cost >= bestCost) return;

    if(k == n){
        double total = cost + c[curPath[n-1]][curPath[0]];
        if(total < bestCost){
            bestCost = total;
            bestPath = curPath;
        }
        return;
    }

    for(int v=0; v<n; v++){
        if(!visited[v]){
            visited[v] = true;
            curPath[k] = v;

            double bound = cost + c[curPath[k-1]][v] + (n-k)*minEdge;

            if(bound < bestCost)
                Try(k+1, cost + c[curPath[k-1]][v]);

            visited[v] = false;
        }
    }
}

int main(){
    cout << "Nhap so thanh pho: ";
    cin >> n;

    cout << "Nhap ma tran chi phi:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> c[i][j];
            if(i!=j) minEdge = min(minEdge, c[i][j]);
        }

    curPath.resize(n);
    bestPath.resize(n);
    memset(visited,false,sizeof(visited));

    curPath[0] = 0;
    visited[0] = true;

    Try(1,0);

    cout << "\nDuong di tot nhat:\n";
    for(int x:bestPath) cout << x << " -> ";
    cout << bestPath[0];

    cout << "\nChi phi = " << bestCost;

    return 0;
}
