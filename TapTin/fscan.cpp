#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // mở hoặc tạo mới tập tin "text. txt" ở chế độ ghi
    FILE *f=fopen("text.txt", "r");
    if(f==NULL){
        printf("Mo tap tin khong thanh cong!\n");
        return 1;
    }
    else {
        char* s= (char *)malloc(28*sizeof(char)); 
        int a; 
        float b;
        // fscanf(f, "%s%d%f", s, &a, &b); // ghi vào tập tin
        fgets(s, 28, f);
        s[strcspn(s, "\n")] = '\0';
        fscanf(f, "%d%f", &a, &b);

        printf("Doc cac bien tu file thanh cong, gia tri cac bien:\n");
        printf("s=[%s]\n", s);
        printf("a=[%d]\n", a);
        printf("b=[%.3f]\n", b);
        printf("Dong file!");
        fclose(f); // đóng tập tin sau khi mở thành công
    }
    return 0;
}