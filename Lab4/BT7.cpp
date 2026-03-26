#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> result;
    std::set_union(
        a.begin(), a.end(),
        b.begin(), b.end(),
        inserter(result, result.begin())
    );
    return result;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> result;
    std::set_intersection(
        a.begin(), a.end(),
        b.begin(), b.end(),
        inserter(result, result.begin())
    );
    return result;
}

template<class T>
set<T> set_difference(const set<T> &a, const set<T> &b) {
    set<T> result;
    std::set_difference(
        a.begin(), a.end(),
        b.begin(), b.end(),
        inserter(result, result.begin())
    );
    return result;
}

template<class T>
void print_set(const set<T>& s) {
    cout << "{ ";
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

int main() {
    set<int> A = {1, 2, 3, 4, 5};
    set<int> B = {4, 5, 6, 7};

    cout << "Tap A: "; print_set(A);
    cout << "Tap B: "; print_set(B);

    set<int> U = set_union(A, B);
    cout << "Hop A và B: "; print_set(U);

    set<int> I = set_intersection(A, B);
    cout << "Giao A và B: "; print_set(I);

    set<int> D = set_difference(A, B);
    cout << "Hieu A - B: "; print_set(D);

    return 0;
}
