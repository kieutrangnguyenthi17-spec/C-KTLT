#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QStringList>

// Khai báo cấu trúc Question để lưu trữ câu hỏi, lựa chọn và câu trả lời đúng
struct Question {
    QString questionText;
    QStringList options;
    QString correctAnswer;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onOptionClicked();
    void checkAnswer(const QString &answer);
    void loadQuestion();
    void nextQuestion();
    void resetButtons();  // Khai báo resetButtons()

private:
    QLabel *questionLabel;
    QLabel *scoreLabel;
    QPushButton* nextButton;
    QPushButton *optionButtons[4];  // Lưu trữ 4 nút lựa chọn
    int score;
    QString currentQuestion, correctAnswer;
    QStringList options;
    int currentQuestionIndex;
    void updateUI();
    void endQuiz();
};

#endif // MAINWINDOW_H
