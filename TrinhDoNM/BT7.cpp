// Tính tổng giá trị các số nguyên có trong một chuỗi ký tự.
//Ví dụ: Chuỗi 2AS34ASDF342B có tổng là 2+34+342=378
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int Sum=0;
    string temp="";    
    for(char ch: s){
        if(isdigit(ch)){
            temp+=ch;
        }else {
            if(!temp.empty()){
                Sum+=stoi(temp);
                temp=" ";
            }
        }
    }
    if(!temp.empty()){
        Sum+=stoi(temp);
    }
    cout<<"Tong so nguyen: "<<Sum;
    return 0;
}