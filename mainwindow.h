#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString node;
    QString num;
    QString cost;
    QStringList nodes;
    QString nodes2;
    QStringList costs;
    QStringList costsd;
    QStringList costs2d;
    QStringList costs2da;
    QStringList costsl;
    QStringList costs2l;
    QStringList costs2li;
    QStringList costs2lin;
    QStringList temp;

    QString rowsHeads;
    QStringList rowsHead;
    QStringList startF;
    QStringList startFr;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
