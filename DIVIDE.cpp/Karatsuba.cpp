#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string strip(string s) {
    int i = 0;
    while (i + 1 < (int)s.size() && s[i] == '0') i++;
    return s.substr(i);
}

string add(string a, string b) {
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    int carry = 0;
    string res = "";

    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res.push_back(char(sum % 10 + '0'));
        carry = sum / 10;
    }
    if (carry) res.push_back(char(carry + '0'));

    reverse(res.begin(), res.end());
    return strip(res);
}

string subtr(string a, string b) {
    while (b.size() < a.size()) b = "0" + b;

    int carry = 0;
    string res = "";

    for (int i = a.size() - 1; i >= 0; i--) {
        int x = (a[i] - '0') - (b[i] - '0') - carry;
        if (x < 0) { x += 10; carry = 1; }
        else carry = 0;
        res.push_back(char(x + '0'));
    }

    while (res.size() > 1 && res.back() == '0')
        res.pop_back();

    reverse(res.begin(), res.end());
    return res;
}

string karatsuba(string x, string y) {
    x = strip(x);
    y = strip(y);

    if (x == "0" || y == "0") return "0";

    int n = max(x.size(), y.size());
    while (x.size() < n) x = "0" + x;
    while (y.size() < n) y = "0" + y;

    if (n == 1)
        return to_string((x[0] - '0') * (y[0] - '0'));

    int m = n / 2;

    string A = x.substr(0, n - m);
    string B = x.substr(n - m);
    string C = y.substr(0, n - m);
    string D = y.substr(n - m);

    string P = karatsuba(A, C);
    string Q = karatsuba(B, D);
    string R = karatsuba(subtr(A, B), subtr(C, D));

    string mid = add(add(P, Q), R);

    P.append(2 * m, '0');
    mid.append(m, '0');

    string res = add(add(P, mid), Q);
    return strip(res);
}

int main() {
    string X, Y;
    cin >> X >> Y;

    int sign = 1;
    if (X[0] == '-') { sign *= -1; X = X.substr(1); }
    if (Y[0] == '-') { sign *= -1; Y = Y.substr(1); }

    string ans = karatsuba(X, Y);

    if (sign == -1 && ans != "0") cout << "-";
    cout << ans;
}
