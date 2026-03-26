#include<iostream>
#include<cmath>
using namespace std;
struct Date { 
    int day; 
    int month; 
    int year; 
}; 
struct Student { 
    char name[50]; 
    Date birth; 
}; 
Student findOldestStudent(Student arr[], int n){
    Student oldest=arr[0];
    for(int i=0;i<n;i++){
        Date a=arr[i].birth;
        Date b=oldest.birth;
        if(a.year<b.year||a.year==b.year&&a.month<b.month||a.year==b.year&&a.month==b.month&&a.day<b.day){
            oldest=arr[i];
        }
    }
    return oldest;
}
void NhapSV(Student &s){
     cout << "Nhap ten: ";
    cin.ignore();
    cin.getline(s.name, 50);
    cout << "Nhap ngay thang nam sinh (d m y): ";
    cin >> s.birth.day >> s.birth.month >> s.birth.year;
}
void StudentList(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n-- Nhap sinh vien thu " << i + 1 << " --\n";
        NhapSV(arr[i]);
    }
}
int main() {
    cout<<"Nguyen Thi Kieu Trang"<<endl;
    cout<<"MSSV: 24133064"<<endl;
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;

    Student arr[100];
    StudentList(arr, n);

    Student old = findOldestStudent(arr, n);

    cout << "\nSinh vien lon tuoi nhat:\n";
    cout << "Ten: " << old.name << endl;
    cout << "Ngay sinh: " << old.birth.day << "/" 
         << old.birth.month << "/" << old.birth.year << endl;

    return 0;
}