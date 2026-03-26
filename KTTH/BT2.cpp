#include <iostream>
#include <cstring>
using namespace std;

// a) Cấu trúc Book
struct Book {
    char title[101];
    char author[51];
    int year;
    int available; // 1 = còn, 0 = đang mượn
};

// b) Cấu trúc Library
struct Library {
    Book* books;   // mảng động Book
    int size;      // số lượng sách hiện có
};

// c) Lọc sách theo tác giả
Library filterByAuthor(const Library& lib, const char* author) {
    // Đếm số sách phù hợp
    int count = 0;
    for (int i = 0; i < lib.size; i++) {
        if (strcmp(lib.books[i].author, author) == 0)
            count++;
    }

    Library result;
    result.size = count;
    result.books = new Book[count];

    int idx = 0;
    for (int i = 0; i < lib.size; i++) {
        if (strcmp(lib.books[i].author, author) == 0) {
            result.books[idx++] = lib.books[i];
        }
    }

    return result;
}

// d) Đếm sách xuất bản sau năm y
int countAfterYear(const Library& lib, int y) {
    int count = 0;
    for (int i = 0; i < lib.size; i++) {
        if (lib.books[i].year > y)
            count++;
    }
    return count;
}

// e) Đếm sách đang mượn và xuất bản trước năm y
int countBorrowedBeforeYear(const Library& lib, int y) {
    int count = 0;
    for (int i = 0; i < lib.size; i++) {
        if (lib.books[i].available == 0 && lib.books[i].year < y)
            count++;
    }
    return count;
}
int main() {
    Library lib;
    lib.size = 3;
    lib.books = new Book[3];

    strcpy(lib.books[0].title, "Book A");
    strcpy(lib.books[0].author, "Author1");
    lib.books[0].year = 2000;
    lib.books[0].available = 1;

    strcpy(lib.books[1].title, "Book B");
    strcpy(lib.books[1].author, "Author2");
    lib.books[1].year = 1999;
    lib.books[1].available = 0;

    strcpy(lib.books[2].title, "Book C");
    strcpy(lib.books[2].author, "Author1");
    lib.books[2].year = 2010;
    lib.books[2].available = 0;

    Library filtered = filterByAuthor(lib, "Author1");
    cout << "So sach cua Author1: " << filtered.size << endl;

    cout << "Sach sau 2005: " << countAfterYear(lib, 2005) << endl;

    cout << "Sach muon truoc 2005: " 
         << countBorrowedBeforeYear(lib, 2005) << endl;

    delete[] lib.books;
    delete[] filtered.books;

    return 0;
}
