#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>

class TextTransformApp : public QWidget
{
    Q_OBJECT

public:
    TextTransformApp(QWidget *parent = 0) : QWidget(parent)
    {
        inputLineEdit = new QLineEdit(this);
        inputLineEdit->setPlaceholderText("Enter text here");

        transformButton = new QPushButton("Transform", this);

        outputLabel = new QLabel(this);
        outputLabel->setAlignment(Qt::AlignCenter);

        connect(transformButton, &QPushButton::clicked, this, &TextTransformApp::transformText);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(inputLineEdit);
        layout->addWidget(transformButton);
        layout->addWidget(outputLabel);

        setLayout(layout);
    }

private slots:
    void transformText()
    {
        QString inputText = inputLineEdit->text();
        QString outputText;
        outputText = "input: " + inputText + "\n";
        if(flag){
            outputText += "input Upper: " + inputText.toUpper();

        } else {
            outputText += "input lower: " + inputText.toLower();
        }
        flag = !flag;
        outputLabel->setText(outputText);
    }

private:
    QLineEdit *inputLineEdit;
    QPushButton *transformButton;
    QLabel *outputLabel;
    bool flag = false;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TextTransformApp textApp;
    textApp.resize(400, 200);
    textApp.setWindowTitle("Text Transform Application");
    textApp.show();

    return app.exec();
}

#include "main.moc"
