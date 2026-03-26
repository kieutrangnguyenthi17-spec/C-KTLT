#include<stdio.h>
int main(){
    // mở hoặc tạo mới tập tin "text. txt" ở chế độ ghi
    FILE *f=fopen("text.txt", "w");
    if(f==NULL){
        printf("Mo tap tin khong thanh cong!\n");
        return 1;
    }
    else {
        char s[]="Nguyễn Thị Kiều Trang";
        fputs(s,f); // ghi vào tập tin
        printf("Ghi chuoi kich thuoc = [%d] bytes vao file thanh cong, dong file!\n", sizeof(s));
        fclose(f); // đóng tập tin sau khi mở thành công
    }
    return 0;
}