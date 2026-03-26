#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool twoSumUnsorted(vector<int> a, int k, pair<int,int> &res){
    unordered_set<int> s;
    for(int x : a){
        if(s.count(k - x)){
            res = {x, k - x};
            return true;
        }
        s.insert(x);
    }
    return false;
}

int main(){
    vector<int> a = {7,2,9,4,1,5};
    int k = 6;
    pair<int,int> ans;

    if(twoSumUnsorted(a,k,ans))
        cout << ans.first << " " << ans.second;
    else
        cout << "Khong ton tai";

    return 0;
}
