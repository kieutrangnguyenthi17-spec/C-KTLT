#include "mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTimer>
#include <QFontDatabase>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    score(0),
    currentQuestionIndex(0)
{
    setWindowTitle("Quiz Game");
    setFixedSize(1000, 600);  // Tăng kích thước cửa sổ
    // Thiết lập font chữ
    QFont font = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
    font.setPointSize(25);  // Kích thước chữ
    setFont(font);
    // Thiết lập màu nền
    setStyleSheet("background-color: #FFFFFF;");
    // Tạo nhãn hiển thị câu hỏi
    questionLabel = new QLabel("Loading question...", this);
    questionLabel->setAlignment(Qt::AlignCenter);
    questionLabel->font();
    font.setPointSize(24);
    questionLabel->setFont(font);
    // Đặt màu chữ cho câu hỏi
    questionLabel->setStyleSheet("color: #006994;");
    // Tạo các nút cho mỗi lựa chọn
    for (int i = 0; i < 4; ++i) {
        optionButtons[i] = new QPushButton(this);
        optionButtons[i]->setStyleSheet("background-color: #b0e0e6; color: #006994; font-size: 16px; border-radius: 10px; padding: 10px;");
        connect(optionButtons[i], &QPushButton::clicked, this, &MainWindow::onOptionClicked);
    }
    // Thiết lập bố cục
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(questionLabel);
    for (int i = 0; i < 4; ++i) {
        layout->addWidget(optionButtons[i]);
    }
    // Tạo nhãn hiển thị điểm số
    scoreLabel = new QLabel("Score: 0", this);
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setStyleSheet("color: #006994; font-size: 25px;");
    layout->addWidget(scoreLabel);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    // Tải câu hỏi đầu tiên
    loadQuestion();
}

MainWindow::~MainWindow() {}

void MainWindow::loadQuestion()
{
    static const QList<Question> questions = {
                                              { "1. Từ khóa nào dùng để khai báo lớp trong C++?", {"struct", "class", "object", "define"}, "class" },
                                              { "2. Toán tử nào dùng để truy cập thành viên của đối tượng?", {"::", "->", ".", "*"}, "." },
                                              { "3. Hàm nào dùng để xuất dữ liệu ra màn hình?", {"print()", "cout", "scanf()", "cin"}, "cout" },
                                              { "4. Từ khóa nào dùng để cấp phát bộ nhớ động?", {"malloc", "alloc", "new", "create"}, "new" },
                                              { "5. Từ khóa nào dùng để giải phóng bộ nhớ động?", {"free", "delete", "remove", "clear"}, "delete" },
                                              { "6. Hàm main() trong C++ trả về kiểu dữ liệu gì?", {"void", "float", "int", "double"}, "int" },
                                              { "7. Tính chất nào KHÔNG thuộc lập trình hướng đối tượng?", {"Đóng gói", "Kế thừa", "Đa hình", "Biên dịch động"}, "Biên dịch động" },
                                              { "8. Từ khóa nào dùng để khai báo hàm ảo?", {"static", "virtual", "override", "inline"}, "virtual" },
                                              { "9. Câu lệnh nào dùng để nhập dữ liệu từ bàn phím?", {"cin", "cout", "input()", "gets()"}, "cin" },
                                              { "10. Thư viện nào hỗ trợ nhập xuất chuẩn trong C++?", {"<math.h>", "<stdio.h>", "<iostream>", "<string>"}, "<iostream>" },
                                              };

    if (currentQuestionIndex < 0 || currentQuestionIndex >= questions.size()) {
        return;
    }

    const Question &q = questions[currentQuestionIndex];
    currentQuestion = q.questionText;
    correctAnswer = q.correctAnswer;
    options = q.options;

    updateUI();
}


void MainWindow::updateUI() {
    // Cập nhật câu hỏi và các lựa chọn trên giao diện
    questionLabel->setText(currentQuestion);
    for (int i = 0; i < 4; ++i) {
        optionButtons[i]->setText(options[i]);
    }
}

void MainWindow::onOptionClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    checkAnswer(clickedButton->text());
}
void MainWindow::endQuiz()
{
    for (int i = 0; i < 4; ++i)
        optionButtons[i]->setEnabled(false);

    QMessageBox endMsg(this);
    endMsg.setIcon(QMessageBox::Information);
    endMsg.setWindowTitle("🎉 Hoàn thành bài kiểm tra");

    endMsg.setText(
        "<h2 style='color:#2ecc71;'>🎉 Bạn đã hoàn thành bài kiểm tra!</h2>"
        "<p style='font-size:16px; color:#333;'>"
        "⭐ <b>Điểm của bạn:</b> "
        "<span style='color:#e67e22; font-size:20px;'>"
        + QString::number(score) +
        "</span>"
        "</p>"
        "<p style='color:#555;'>Bạn có muốn thoát chương trình không?</p>"
        );
    endMsg.setStandardButtons(QMessageBox::Ok);
    endMsg.setDefaultButton(QMessageBox::Ok);
    endMsg.setStyleSheet(
        "QPushButton {"
        "   color: black;"
        "   font-size: 14px;"
        "   padding: 6px 16px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #e6f2ff;"
        "}"
        );

    int ret = endMsg.exec();
    if (ret == QMessageBox::Ok) {
        close();
    }
}


void MainWindow::checkAnswer(const QString &answer)
{
    if (answer == correctAnswer) {
        score += 10;

        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Đáp án đúng!");
        msgBox.setText("Bạn đã chọn chính xác!");
        msgBox.setStyleSheet("QLabel { font-size: 16px; color: #33CC99; font-weight: bold; }"
                             "QPushButton { font-size: 16px; background-color: #33CC99; color: white; border-radius: 5px; padding: 10px; }");
        msgBox.exec();
    } else {
        QMessageBox msgBox(this);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Đáp án sai");
        msgBox.setText("Chúc bạn may mắn lần sau!");
        msgBox.setStyleSheet("QLabel { font-size: 16px; color: #FF3300; font-weight: bold; }"
                             "QPushButton { font-size: 16px; background-color: #FF3300; color: white; border-radius: 5px; padding: 10px; }");
        msgBox.exec();
    }

    scoreLabel->setText("Score: " + QString::number(score));

    for (int i = 0; i < 4; ++i) optionButtons[i]->setDisabled(true);

    const int TOTAL = 10;

    if (currentQuestionIndex == TOTAL - 1) {
        QTimer::singleShot(0, this, [this]() { endQuiz(); });
        return;
    }

    QTimer::singleShot(2000, this, &MainWindow::nextQuestion);
}


void MainWindow::nextQuestion()
{
    const int TOTAL = 10;

    if (currentQuestionIndex >= TOTAL - 1) {
        endQuiz();
        return;
    }

    currentQuestionIndex++;
    loadQuestion();

    for (int i = 0; i < 4; ++i) optionButtons[i]->setEnabled(true);
}


void MainWindow::resetButtons() {
    // Bật lại các nút sau khi trả lời
    for (int i = 0; i < 4; ++i) {
        optionButtons[i]->setEnabled(true);
    }
}
