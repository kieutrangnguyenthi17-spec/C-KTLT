#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b) {
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;

    int carry = 0;
    string res = "";

    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
    }
    if (carry) res.push_back(carry + '0');

    reverse(res.begin(), res.end());
    return res;
}

string sub(string a, string b) {
    while (b.length() < a.length()) b = "0" + b;

    int carry = 0;
    string res = "";

    for (int i = a.length() - 1; i >= 0; i--) {
        int x = (a[i] - '0') - (b[i] - '0') - carry;
        if (x < 0) { x += 10; carry = 1; }
        else carry = 0;
        res.push_back(x + '0');
    }

    while (res.length() > 1 && res.back() == '0')
        res.pop_back();

    reverse(res.begin(), res.end());
    return res;
}

string multiply(string x, string y) {
    while (x.length() < y.length()) x = "0" + x;
    while (y.length() < x.length()) y = "0" + y;

    int n = x.length();
    if (n == 1)
        return to_string((x[0] - '0') * (y[0] - '0'));

    int mid = n / 2;

    string A = x.substr(0, mid);
    string B = x.substr(mid);
    string C = y.substr(0, mid);
    string D = y.substr(mid);

    string AC = multiply(A, C);
    string BD = multiply(B, D);
    string AD = multiply(A, D);
    string BC = multiply(B, C);

    string middle = add(AD, BC);

    AC.append(2 * (n - mid), '0');
    middle.append(n - mid, '0');

    string result = add(add(AC, middle), BD);

    while (result.length() > 1 && result[0] == '0')
        result.erase(result.begin());

    return result;
}

int main() {
    string X, Y;
    cout << "Nhap so thu nhat: ";
    cin >> X;
    cout << "Nhap so thu hai: ";
    cin >> Y;

    cout << "Ket qua: " << multiply(X, Y);
    return 0;
}
