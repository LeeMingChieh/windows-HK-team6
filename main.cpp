#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLabel *memberLabel0 = new QLabel("隊長(李銘杰ID:41243118)\n組員1(潘怡潔ID:41243107)\n組員2(雷務馨ID:40643149)\n組員3(吳宗恆ID:50915130)");
    QTabWidget *tabWidget = new QTabWidget;
    QWidget *memberTab0 = new QWidget;
    memberLabel0->setStyleSheet("color: yellow;");
    QVBoxLayout *memberLayout0 = new QVBoxLayout;
    memberLayout0->addWidget(memberLabel0);
    memberTab0->setLayout(memberLayout0);

    QWidget *memberTab3 = new QWidget;
    QLabel *memberLabel3 = new QLabel("組員3=>吳宗恆ID:50915130");
    QPushButton *fileButton = new QPushButton("File select");
    QVBoxLayout *memberLayout3 = new QVBoxLayout;
    memberLayout3->addWidget(memberLabel3);
    memberLayout3->addWidget(fileButton);
    memberTab3->setLayout(memberLayout3);


    QObject::connect(fileButton, &QPushButton::clicked, [=]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, "選擇檔案", "", "所有檔案 (*.*)");
        if (!filePath.isEmpty()) {
            memberLabel0->setText(filePath);
        }
    });


    tabWidget->addTab(memberTab0, "隊長");
    tabWidget->addTab(memberTab1, "組員1");
    tabWidget->addTab(memberTab2, "組員2");
    tabWidget->addTab(memberTab3, "組員3");

    tabWidget->setWindowTitle("WorkGroup");
    tabWidget->resize(400, 300);
    tabWidget->show();

    return app.exec();
}
