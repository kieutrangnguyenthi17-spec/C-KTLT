// Một vector trong không gian 3 chiều được biểu diễn bằng tuple<double, double, double>. Hãy viết  hàm Vector cross_product(Vector a, Vector b) tính tích có hướng của 2 vector. Trong đó  Vector là kiểu dữ liệu được định nghĩa sẵn trong trình chấm như sau: using Vector = tuple<double,  double, double>; 
// In [ ]: 
#include <iostream>
#include <tuple>
using namespace std;

using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    double ax = get<0>(a), ay = get<1>(a), az = get<2>(a);
    double bx = get<0>(b), by = get<1>(b), bz = get<2>(b);

    return Vector{
        ay * bz - az * by,
        az * bx - ax * bz,
        ax * by - ay * bx
    };
}

void print_vector(const Vector& v) {
    cout << "(" << get<0>(v) << ", " << get<1>(v) << ", " << get<2>(v) << ")\n";
}

int main() {
    Vector a = {1.0, 2.0, 3.0};
    Vector b = {4.0, 5.0, 6.0};

    Vector c = cross_product(a, b);

    cout << "Vector a: ";
    print_vector(a);

    cout << "Vector b: ";
    print_vector(b);

    cout << "Cross product a x b: ";
    print_vector(c);

    return 0;
}
