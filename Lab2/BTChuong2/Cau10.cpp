#include<iostream>
using namespace std;

bool isleapyear(int y){
    return (y%400==0)||(y%4==0 && y%100!=0); 
}
int daysinmonth(int m, int y){
    switch(m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isleapyear(y) ? 29:28;
        default:
         return 0;
        }
 }
 bool isvaliddate(int d, int m, int y){
    if(y<1) return false;
    if (m<1||m>12) return false;
    int dim = daysinmonth(m,y);
    if(dim==0) return false;
    if (d<1||d>dim) return false;
    return true;
 }
void nextdate(int &d, int &m, int &y){
    d++;
    int dim=daysinmonth(m,y);
    if(d>dim){
        d=1;
        m++;
        if(m>12){
            m=1;
            y++;
        }
    }
}

int main(){
    int d,m,y;
    cout<<"Nhap ngay, thang, nam: ";
    cin>>d>>m>>y;

    if(!isvaliddate(d,m,y)){
        cout<<"Ngay thang nam khong hop le.\n";
    } else {
        nextdate(d,m,y);
        cout<<"Ngay tiep theo la: "<<d<<"/"<<m<<"/"<<y<<"\n";
    }
    return 0;
}

