// Viết các hàm thực hiện các phép giao và hợp của hai tập hợp mờ được biểu diễn bằng map. Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1] biểu thị độ thuộc của phần tử  trong tập hợp, với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp và ngược lại độ  thuộc bằng 0 nghĩa là phần tử chắc chắn không thuộc trong tập hợp. 
// Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp, với  độ thuộc mới được tính bằng phép toán min và max của hai độ thuộc.
// In [ ]: 
#include <iostream>
#include <map>
#include <algorithm>   

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> result = a;

    for (const auto &item : b) {
        if (result.count(item.first)) {
            result[item.first] = max(result[item.first], item.second);
        } else {
            result[item.first] = item.second;
        }
    }
    return result;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> result;

    for (const auto &item : a) {
        auto it = b.find(item.first);
        if (it != b.end()) {
            result[item.first] = min(item.second, it->second);
        }
    }
    return result;
}

template<class T>
void print_fuzzy_set(const map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}" << endl;
}

int main() {
    map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};

    cout << "A = ";
    print_fuzzy_set(a);

    cout << "B = ";
    print_fuzzy_set(b);

    map<int, double> c = fuzzy_set_union(a, b);
    map<int, double> d = fuzzy_set_intersection(a, b);

    cout << "Union: ";
    print_fuzzy_set(c);

    cout << "Intersection: ";
    print_fuzzy_set(d);

    return 0;
}
