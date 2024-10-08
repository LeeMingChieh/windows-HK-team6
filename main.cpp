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

    QWidget *memberTab1 = new QWidget;
    QLabel *memberLabel1 = new QLabel("組員1=>潘怡潔ID:41243107");
    QVBoxLayout *memberLayout1 = new QVBoxLayout;
    QPushButton *colorButton = new QPushButton("color select");
    memberLayout1->addWidget(memberLabel1);
    memberLayout1->addWidget(colorButton);
    memberTab1->setLayout(memberLayout1);


    QObject::connect(colorButton, &QPushButton::clicked, [=]() {
        QColor color = QColorDialog::getColor(Qt::white, nullptr, "選擇文字顏色");
        if (color.isValid()) {
            QString colorName = color.name();
            memberLabel0->setStyleSheet(QString("color: %1;").arg(colorName));
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
