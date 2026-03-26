// // Bài tập 1: Truyền tham trị
// // Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.
// #include <stdio.h>
// #include <math.h>
// float get_hypotenuse(float x, float y) {
//   return sqrt(x*x+y*y);
// }
// int main(){
// float x, y;
// scanf("%f%f", &x, &y);
// float z = get_hypotenuse(x, y);
// printf("z = %.2f\n", z);
// return 0;
// }

#include <stdio.h>
#include <math.h>   

float get_hypotenuse(float x, float y) {
    /****************
        Ho va ten : Nguyen Thi Kieu Trang
        MSSV : 24133064
    */

    float z = sqrt(x*x + y*y);
    return z;
    /*****************/
}

int main(){
    printf("Ho Va Ten: Nguyen Thi Kieu Trang\n");
    printf("MSSV: 24133064\n\n");
    float x, y;
    scanf("%f%f", &x, &y);

    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);

    return 0;
}
