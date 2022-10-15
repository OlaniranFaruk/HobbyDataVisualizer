#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listhobbywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool getUserEntries();
    void displayPieChart();


private slots:
    void on_addItemBtn_clicked();

    void on_saveSettingsBtn_clicked();

    void loadSettingsFromFile();

    void on_showChartBtn_clicked();

private:
    Ui::MainWindow *ui;
    ListHobbyWidget *lhw;
    QMap <QString, int> dataEntered;
    QList<QString> listOfColor;
};
#endif // MAINWINDOW_H
