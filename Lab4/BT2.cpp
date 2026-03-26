// Một điểm trong không gian 2 chiều được biểu diễn bằng pair. Hãy viết hàm double area(Point  a, Point b, Point c) tính diện tích tam giác theo tọa độ 3 đỉnh. Trong đó, Point là kiểu được  định nghĩa sẵn trong trình chấm như sau: using Point = pair<double, double>; 
// In [ ]: 
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    return 0.5 * abs(
        a.first * (b.second - c.second) +
        b.first * (c.second - a.second) +
        c.first * (a.second - b.second)
    );
}

int main() {
    Point a, b, c;

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    cout << area(a, b, c);

    return 0;
}
