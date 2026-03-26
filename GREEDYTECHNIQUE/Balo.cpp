#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using namespace std;

struct Item{
    double weight;
    double value;
    double unit;
};

bool cmp(Item a, Item b){
    return a.unit > b.unit; 
}

double GreedyKnapsack(double W, vector<Item> &items){
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0;

    for(auto &x : items){
        if(W <= 0) break;

        double take = floor(W / x.weight);  
        if(take > 0){
            totalValue += take * x.value;
            W -= take * x.weight;
        }
    }

    return totalValue;
}

int main(){
    int n;
    double W;

    cout << "Nhap so loai vat: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Nhap (trong luong, gia tri) cho tung vat:\n";
    for(int i=0;i<n;i++){
        cin >> items[i].weight >> items[i].value;
        items[i].unit = items[i].value / items[i].weight;
    }

    cout << "Nhap suc chua balo W: ";
    cin >> W;

    double ans = GreedyKnapsack(W, items);

    cout << "Tong gia tri lon nhat = " << ans;

    return 0;
}
