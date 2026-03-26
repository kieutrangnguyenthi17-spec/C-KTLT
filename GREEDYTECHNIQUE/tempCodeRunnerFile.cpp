#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using namespace std;

struct Edge {
    int u, v;
    double w;
};

struct DSU {
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n+1);
        rankv.assign(n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;
        return true;
    }
};

vector<pair<double,double>> nhapToaDo(int n){
    vector<pair<double,double>> p(n+1);
    for(int i=1;i<=n;i++)
        cin >> p[i].first >> p[i].second;
    return p;
}

vector<Edge> taoDanhSachCanh(vector<pair<double,double>> &p, int n){
    vector<Edge> E;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            double d = hypot(p[i].first - p[j].first,
                             p[i].second - p[j].second);
            E.push_back({i,j,d});
        }
    sort(E.begin(),E.end(),
        [](Edge a, Edge b){ return a.w < b.w; });
    return E;
}

double TSP_ThamLam(int n){
    auto p = nhapToaDo(n);
    auto E = taoDanhSachCanh(p,n);

    vector<int> degree(n+1,0);
    DSU dsu(n);
    vector<Edge> cycle;
    double totalCost=0;

    for(auto e:E){
        if((int)cycle.size()==n) break;

        bool ok = true;

        if(degree[e.u]==2 || degree[e.v]==2)
            ok=false;

        if(ok){
            int fu = dsu.find(e.u);
            int fv = dsu.find(e.v);

            if(fu==fv && (int)cycle.size()!=n-1)
                ok=false;
        }

        if(ok){
            cycle.push_back(e);
            totalCost += e.w;
            degree[e.u]++;
            degree[e.v]++;
            dsu.unite(e.u,e.v);
        }
    }

    cout << "\nCAC CANH CUA CHU TRINH:\n";
    for(auto e:cycle)
        cout << e.u << " <-> " << e.v 
             << "   w = " << e.w << endl;

    return totalCost;
}

int main(){
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;

    double cost = TSP_ThamLam(n);

    cout << "\nTong do dai: " << cost << endl;
    return 0;
}
