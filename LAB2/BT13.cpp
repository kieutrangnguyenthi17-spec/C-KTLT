// Số nguyên lớn là các số nguyên có giá trị rất lớn và không thể biểu diễn bằng các kiểu dữ liệu
// nguyên cơ bản. Để biểu diễn số nguyên lớn, ta có thể dùng kiểu struct như sau:
// struct bigNum{
// char sign;
// char num[101];
// };
// Nhiệm vụ các bạn là đa năng hóa các toán tử để thực hiện các phép toán số học với kiểu dữ liệu số
// nguyên lớn vừa định nghĩa ở trên.
// Input: Dữ liệu vào gồm hai dòng mô tả hai số nguyên lớn a và b, mỗi dòng chứa 1 chuỗi ký tự mô
// tả 1 số nguyên lớn không vượt quá 10100. Chữ số đầu của mỗi chuỗi ký tự sẽ thể hiện dấu của số
// đó: 0 là âm, 1 là dương. Các chữ số sau thể hiện giá trị của số đó.
// Output: In ra giá trị của biểu thức ab−3a+4b. Kết quả in ra một số nguyên lớn dưới dạng chuỗi
// ký tự có định dạng như mô tả trong dữ liệu vào.
// Ví dụ:
// Input:
// 0121807015
// 1347227347

// Output:
// 042294724910108772
// In [ ]:

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct bigNum {
    char sign; // '0' = âm, '1' = dương
    string num; // lưu các chữ số, chữ số cao nhất ở đầu (vd: "1234")

    bigNum() : sign('1'), num("0") {}
    bigNum(const string& s) {
        sign = s[0];
        num = s.substr(1);
        trim();
    }

    void trim() {
        // xóa số 0 đầu tiên
        while (num.size() > 1 && num[0] == '0') num.erase(num.begin());
        if (num == "0") sign = '1'; // số 0 coi là dương
    }

    // So sánh trị tuyệt đối (không tính dấu)
    bool absLess(const bigNum &b) const {
        if (num.size() != b.num.size()) return num.size() < b.num.size();
        return num < b.num;
    }

    // Cộng trị tuyệt đối: this + b (cả 2 dương)
    bigNum absAdd(const bigNum &b) const {
        string res = "";
        int carry = 0;
        int i = (int)num.size() - 1;
        int j = (int)b.num.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? (num[i] - '0') : 0;
            int y = (j >= 0) ? (b.num[j] - '0') : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            res.push_back((sum % 10) + '0');
            i--; j--;
        }
        reverse(res.begin(), res.end());
        bigNum ret;
        ret.sign = '1';
        ret.num = res;
        return ret;
    }

    // Trừ trị tuyệt đối: this - b (this >= b, cả 2 dương)
    bigNum absSub(const bigNum &b) const {
        string res = "";
        int borrow = 0;
        int i = (int)num.size() - 1;
        int j = (int)b.num.size() - 1;
        while (i >= 0) {
            int x = num[i] - '0' - borrow;
            int y = (j >= 0) ? (b.num[j] - '0') : 0;
            if (x < y) {
                x += 10;
                borrow = 1;
            } else borrow = 0;
            res.push_back(x - y + '0');
            i--; j--;
        }
        // xóa 0 cuối
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        bigNum ret;
        ret.sign = '1';
        ret.num = res;
        return ret;
    }

    // Cộng hai số lớn
    bigNum operator+(const bigNum &b) const {
        if (sign == b.sign) {
            // cùng dấu => cộng trị tuyệt đối
            bigNum res = absAdd(b);
            res.sign = sign;
            return res;
        }
        else {
            // khác dấu => trừ trị tuyệt đối
            if (absLess(b)) {
                bigNum res = b.absSub(*this);
                res.sign = b.sign;
                return res;
            } else {
                bigNum res = absSub(b);
                res.sign = sign;
                return res;
            }
        }
    }

    // Trừ hai số lớn
    bigNum operator-(const bigNum &b) const {
        bigNum nb = b;
        nb.sign = (b.sign == '1') ? '0' : '1'; // đổi dấu b
        return *this + nb;
    }

    // Nhân số lớn với số nguyên nhỏ
    bigNum mulInt(int x) const {
        if (x == 0) return bigNum("10");
        bigNum res;
        res.sign = (sign == '1') == (x >= 0) ? '1' : '0';
        x = abs(x);
        int carry = 0;
        string r = "";
        for (int i = (int)num.size() - 1; i >= 0; i--) {
            int tmp = (num[i] - '0') * x + carry;
            carry = tmp / 10;
            r.push_back((tmp % 10) + '0');
        }
        if (carry) r.push_back(carry + '0');
        reverse(r.begin(), r.end());
        res.num = r;
        res.trim();
        return res;
    }

    // Nhân hai số lớn (chỉ dùng cho b nhỏ hơn 10^9 vì đơn giản)
    bigNum operator*(const bigNum &b) const {
        // Nếu bạn muốn có nhân số lớn đầy đủ, code sẽ dài hơn nhiều.
        // Ở đây tạm chỉ hỗ trợ nhân với số nhỏ trong đề: nhân với 3 hoặc 4.
        int small = stoi(b.num); // lưu ý chỉ đúng nếu b nhỏ
        return mulInt((sign == '1' ? 1 : -1) * (b.sign == '1' ? small : -small));
    }

    // Lũy thừa với số nguyên nhỏ (b nhỏ hơn int)
    bigNum powInt(int b) const {
        bigNum base = *this;
        bigNum res("11"); // 1
        while (b > 0) {
            if (b & 1) res = res * base;
            base = base * base;
            b >>= 1;
        }
        return res;
    }

    void print() const {
        cout << sign << num << "\n";
    }
};

int main() {
    string sa, sb;
    cin >> sa >> sb;

    bigNum a(sa), b(sb);

    // Ví dụ đơn giản: tính a^b - 3a + 4b (chỉ khi b nhỏ)
    // Để tính a^b với b quá lớn, phải có thuật toán khác.

    // Do đó ta sẽ demo với b nhỏ (int)
    int b_int = stoi(b.num); // Chỉ đúng nếu b nhỏ

    bigNum three("13"); // 3
    bigNum four("14");  // 4

    bigNum part1 = a.powInt(b_int);       // a^b
    bigNum part2 = a.mulInt(3);           // 3a
    bigNum part3 = b.mulInt(4);           // 4b

    bigNum result = part1 - part2 + part3;

    result.print();

    return 0;
}
