// Liệt kê tất cả tập con của tập n phần tử
#include<iostream>
#include<vector>
using namespace std;
void LietKe(vector<int>& a, vector<int>& Thcon, int index){
    if(index==a.size()){
        cout<<"{ ";
        for( int x:Thcon){
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    LietKe(a,Thcon,index+1);
    Thcon.push_back(a[index]);
    LietKe(a,Thcon,index+1);
    Thcon.pop_back();// quay lui
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> Thcon;
    LietKe(a,Thcon,0);
    return 0;
}