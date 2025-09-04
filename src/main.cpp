#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QWidget>
#include "calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Калькулятор");

    QVBoxLayout *layout = new QVBoxLayout;

    QLineEdit *input = new QLineEdit;
    QPushButton *calculateButton = new QPushButton("Вычислить");
    QLineEdit *result = new QLineEdit;
    result->setReadOnly(true);

    layout->addWidget(input);
    layout->addWidget(calculateButton);
    layout->addWidget(result);

    QObject::connect(calculateButton, &QPushButton::clicked, [&]() {
        QString expression = input->text();
        // Используем твою логику калькулятора
        double value = evaluate(expression.toStdString());  // реализуй в calculator.cpp
        result->setText(QString::number(value));
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}
