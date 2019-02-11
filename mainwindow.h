#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_btnGen_clicked();

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

    void on_chkBoxNeg_stateChanged(int arg1);

    void on_chkBoxCD_stateChanged(int arg1);

    void on_chkBoxCI_stateChanged(int arg1);

    void on_chkBoxInc_stateChanged(int arg1);

    void on_chkBoxCD_clicked();

    void on_chkBoxCI_clicked();

    void on_chkBoxInc_clicked();

    void on_BtnExit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
