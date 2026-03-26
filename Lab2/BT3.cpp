// Viết chương trình yêu cầu nhập giá trị cho số nguyên x nhỏ hơn 100. In ra giá trị ax2+bx+c với
// a, b, c định sẵn.
#include <stdio.h>
int get_value(int a, int b, int c, int x){
    return a*x*x+b*x+c;
}
int main(){
    
printf("Ho Va Ten: Nguyen Thi Kieu Trang\n");
printf("MSSV: 24133064\n\n");

int x;
printf("Nhap x:");
scanf("%d", &x);
int a = 2; //# giá trị mặc định của a
int b = 1; //# giá trị mặc định của b
int c = 0; //# giá trị mặc định của c
printf("Nhap a, b, c:");
scanf("%d%d%d",&a,&b,&c);
printf("a=2, b=1, c=0: %d\n", get_value(2,1,0,x));
printf("a=%d, b=1, c=0: %d\n", a, get_value(a,1,0,x));
printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(a, b, c,x));
printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(a, b, c, x));
return 0;
}