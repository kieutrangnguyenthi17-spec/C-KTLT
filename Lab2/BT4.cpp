// // Viết các hàm tính lập phương của số nguyên và số thực.
// //In [ ]:
// #include <stdio.h>
// int cube(int x) {
//     return x*x*x;
// }
// double cube(double x){
//     return x*x*x;
// }
// int main() {
// int n;
// double f;
// scanf("%d %lf", &n, &f);
// printf("Int: %d\n", cube(n));
// printf("Double: %.2lf\n", cube(f));
// return 0;
// }
#include <stdio.h>
int cube(int x) {
    //# trả về lập phương của x
    /****************
            Ho va ten : Nguyen Thi Kieu Trang
            MSSV : 24133064
    */
    return x*x*x;
    /*****************/
}

//# viết hàm tính lập phương của một số kiểu double
/*****************/
double cube(double x){
    return x*x*x;
}
/*****************/

int main() {
    printf("Ho Va Ten: Nguyen Thi Kieu Trang\n");

    printf("MSSV: 24133064\n\n");

    int n;
    double f;
    scanf("%d %lf", &n, &f);

    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));

    return 0;
}
