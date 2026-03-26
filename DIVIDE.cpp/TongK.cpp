#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &v){
    if(v.empty()) return "";
    string pre = v[0];

    for(int i = 1; i < v.size(); i++){
        while(v[i].find(pre) != 0){
            pre = pre.substr(0, pre.size()-1);
            if(pre == "") return "";
        }
    }
    return pre;
}

int main(){
    vector<string> v = {"apple","ape","april"};

    cout << longestCommonPrefix(v);
    return 0;
}
