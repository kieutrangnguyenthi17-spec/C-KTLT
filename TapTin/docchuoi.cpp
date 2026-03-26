#include<stdio.h>
int main(){
    // mở hoặc tạo mới tập tin "text. txt" ở chế độ ghi
    FILE *f=fopen("text.txt", "r");
    if(f==NULL){
        printf("Mo tap tin khong thanh cong!\n");
    }
    else {
        int n=28;
        char s[n]; // đọc 1 chuỗi từ tập tin
        fgets(s,n,f);
        if (s==NULL)
        printf("Doc chuoi khong thanh cong, dong file!\n");
        else 
        printf("Doc chuoi(%s) thanh cong, dong file!", s);
        fclose(f); // đóng tập tin sau khi mở thành công
    }
    return 0;
}