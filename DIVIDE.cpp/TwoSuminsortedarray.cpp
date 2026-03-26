#include <iostream>
#include <vector>
using namespace std;

bool twoSumSorted(vector<int> a, int k, pair<int,int> &res){
    int l = 0, r = a.size() - 1;
    while(l < r){
        int sum = a[l] + a[r];
        if(sum == k){
            res = {a[l], a[r]};
            return true;
        }
        else if(sum < k) l++;
        else r--;
    }
    return false;
}

int main(){
    vector<int> a = {1,2,3,4,6,8,11};
    int k = 10;
    pair<int,int> ans;

    if(twoSumSorted(a,k,ans))
        cout << ans.first << " " << ans.second;
    else
        cout << "Khong ton tai";

    return 0;
}
