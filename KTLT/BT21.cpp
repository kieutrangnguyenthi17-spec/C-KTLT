// Một dãy dấu ngoặc hợp lệ là một dãy ký tự “(“ và “)” được định nghĩa như
// sau:
// - Dãy rỗng là 1 dãy dấu ngoặc hợp lệ độ sâu là 0.
// - Nếu A là dãy dấu ngoặc độ sâu k thì (A) là dãy dấu ngoặc hợp lệ độ sâu k
// + 1
// - Nếu A và B là hai dãy dấu ngoặc hợp lệ với độ sâu lần lượt là p và q thì
// AB là dãy dấu ngoặc hợp lệ độ sâu là max (p,q)
// - Độ dài của 1 dãy ngoặc là tổng số ký tự “(“ và “)”.
// Hãy liệt kê 1 dãy dấu ngoặc hợp lệ có độ dài m và độ sâu n.
/**/
#include <iostream>
#include <string>
using namespace std;

int m, n;

void generate(string s, int left, int right, int currentDepth, int maxDepth) {
    if (left == 0 && right == 0) {
        if (maxDepth == n) {
            cout << s << "\n";
        }
        return;
    }

    // Thêm '(' nếu còn
    if (left > 0) {
        generate(s + "(", left - 1, right, currentDepth + 1, max(maxDepth, currentDepth + 1));
    }

    // Thêm ')' nếu còn và còn ngoặc chưa đóng
    if (right > 0 && currentDepth > 0) {
        generate(s + ")", left, right - 1, currentDepth - 1, maxDepth);
    }
}

int main() {
    cin >> m >> n;
    if (m % 2 != 0) {
        cout << "Khong co day ngoac hop le do do dai le\n";
        return 0;
    }
    generate("", m / 2, m / 2, 0, 0);
    return 0;
}
