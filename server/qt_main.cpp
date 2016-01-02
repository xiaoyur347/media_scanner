#include <QApplication>
#include <QTextCodec>
#include "main_widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWidget widget;
    widget.show();
    app.exec();
    return 0;
}
