#include <QApplication>
#include "finddialog.h"
#include "gotocelldialog.h"


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QDialog * dialog = new GoToCellDialog;
    dialog -> show();

    return app.exec();
}
