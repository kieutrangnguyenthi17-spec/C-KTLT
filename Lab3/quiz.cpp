#include <iostream>
#include <vector>
using namespace std;

struct Question {
    string text;            // Nội dung câu hỏi
    string optA, optB, optC, optD;  // Các phương án
    char correct;           // Đáp án đúng (A/B/C/D)
};

// Hàm nhập câu hỏi
void insertQuestion(vector<Question>& quiz) {
    Question q;
    cout << "\nEnter question: ";
    cin.ignore();
    getline(cin, q.text);

    cout << "Option A: "; getline(cin, q.optA);
    cout << "Option B: "; getline(cin, q.optB);
    cout << "Option C: "; getline(cin, q.optC);
    cout << "Option D: "; getline(cin, q.optD);

    cout << "Correct answer (A/B/C/D): ";
    cin >> q.correct;
    q.correct = toupper(q.correct);

    quiz.push_back(q);

    cout << "Question added successfully!\n";
}

// Hàm chơi quiz và trả về điểm
int playQuiz(const vector<Question>& quiz) {
    int score = 0;
    char ans;

    for (int i = 0; i < quiz.size(); i++) {
        cout << "\nQuestion " << i + 1 << ": " << quiz[i].text << "\n";
        cout << "A. " << quiz[i].optA << "\n";
        cout << "B. " << quiz[i].optB << "\n";
        cout << "C. " << quiz[i].optC << "\n";
        cout << "D. " << quiz[i].optD << "\n";

        cout << "Your answer: ";
        cin >> ans;
        ans = toupper(ans);

        // kiểm tra đáp án
        if (ans == quiz[i].correct) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer was: " << quiz[i].correct << "\n";
        }
    }

    return score;
}

int main() {
    vector<Question> quiz;
    int choice;

    while (true) {
        cout << "\n====== QUIZ MENU ======\n";
        cout << "1. Insert Question\n";
        cout << "2. Start Quiz\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            insertQuestion(quiz);
        }
        else if (choice == 2) {
            if (quiz.empty()) {
                cout << "No questions available. Please add questions first.\n";
            } else {
                int score = playQuiz(quiz);
                cout << "\nYour Score: " << score << " / " << quiz.size() << "\n";
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
