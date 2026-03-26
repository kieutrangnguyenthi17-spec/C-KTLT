#include <iostream>
#include <cstring>
using namespace std;

// a) Kiểm tra chuỗi đối xứng
bool is_palindrome(const char* s) {
    int l = 0;
    int r = strlen(s) - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

// b) Xóa ký tự space trong chuỗi
void remove_space(char* s) {
    int j = 0; 
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ')
            s[j++] = s[i];
    }
    s[j] = '\0';
}

// c) Đếm số lần xuất hiện (có chồng lấn)
int count_substr(const char* s, const char* sub) {
    int count = 0;
    int n = strlen(s);
    int m = strlen(sub);

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != sub[j]) {
                match = false;
                break;
            }
        }
        if (match)
            count++;
    }
    return count;
}

// Demo
int main() {
    char s1[] = "radar";
    cout << boolalpha << is_palindrome(s1) << endl;  // true

    char s2[] = "a b  c d";
    remove_space(s2);
    cout << s2 << endl;  // "abcd"

    cout << count_substr("aaa", "aa") << endl; // 2

    return 0;
}
