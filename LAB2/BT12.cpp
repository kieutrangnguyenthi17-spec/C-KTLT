// Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. Cô cho một danh sách với mỗi phần tử có dạng
// <key, value> và yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value. Nếu 2 phần tử có
// value giống nhau thì sắp xếp giảm dần theo key.
// Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.
// Input: Danh sách đầu vào. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách (|
// key| ≤109, |value| ≤109).
// Output: In danh sách đã được sắp xếp theo yêu cầu. Mỗi dòng ghi một cặp giá trị key, value cách
// nhau bởi dấu cách.
// Ví dụ:
// Input:
// 2 3
// 4 8
// 9 1
// 1 8
// Output:
// 4 8
// 1 8
// 2 3
// 9 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<long long, long long>> arr;
    long long key, value;

    // Đọc dữ liệu đầu vào (đọc tới khi hết dòng)
    while (cin >> key >> value) {
        arr.emplace_back(key, value);
    }

    // Sắp xếp với lambda: giảm dần theo value, nếu bằng nhau giảm dần theo key
    sort(arr.begin(), arr.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b) {
        if (a.second != b.second)
        return a.second > b.second;  // value giảm dần
        return a.first > b.first;  // key giảm dần khi value bằng nhau
    });

    // In kết quả
    for (const auto& p : arr) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
