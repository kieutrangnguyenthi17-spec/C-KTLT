// Bài tập 1: Đảo ngược một danh sách liên kết đơn Hãy hoàn thiện các hàm thao tác trên một danh sách liên kết: 
// Thêm một phần tử vào đầu danh sách liên kết 
// In danh sách 
// Đảo ngược danh sách liên kết (yêu cầu độ phức tạp thời gian O(N) và chi phí bộ nhớ dùng  thêm O(1)) 
// In [ ]: 
#include <iostream>  
using namespace std; 

struct Node {  
    int data;  
    Node* next; 
    Node(int data) { 
        this->data = data; 
        next = NULL; 
    } 
}; 
Node* prepend(Node* head, int data) { 
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
} 
void print(Node* head) { 
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
} 
Node* reverse(Node* head) { 
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;         
        curr = next;             }
    return prev; // prev là head mới
} 
  
int main() { 
    int n, u; 
    cin >> n; 
    Node* head = NULL; 

    for (int i = 0; i < n; ++i){ 
        cin >> u; 
        head = prepend(head, u); 
    }  

    cout << "Original list: "; 
    print(head); 

    head = reverse(head); 

    cout << "Reversed list: "; 
    print(head); 

    return 0;  
} 
