#include<stdio.h>
int main(){
    // mở hoặc tạo mới tập tin "text. txt" ở chế độ ghi
    FILE *f=fopen("text.txt", "w");
    if(f==NULL){
        printf("Mo tap tin khong thanh cong!\n");
    }
    else {
        char s[]="Nguyen Thi Kieu Trang";
        int a=10;
        float b=9.5;
        fprintf(f, "%s\n%d\n%.3f", s, a, b); // ghi vào tập tin
        printf("Ghi cac bien vao file thanh cong, dong file!\n", sizeof(s));
        fclose(f); // đóng tập tin sau khi mở thành công
    }
    return 0;
}