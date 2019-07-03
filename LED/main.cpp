#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FILE *sysfs_handle = NULL;

    if((sysfs_handle = fopen("sys/class/gpio/export","w")) != NULL)
    {
        fwrite("3",sizeof(char),2,sysfs_handle);
        fclose(sysfs_handle);
    }

    if((sysfs_handle = fopen("sys/class/gpio/gpio3/direction","w")) != NULL)
    {
        fwrite("out",sizeof(char),4,sysfs_handle);
        fclose(sysfs_handle);
    }

    MainWindow w;
    w.show();

    return a.exec();
}
