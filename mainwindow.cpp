#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QSizePolicy>
#include "piechartwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->warningLabel->setVisible(false);
    ui->groupBox->setVisible(false);
    ui->showChartBtn->setVisible(false);
    ui->saveSettingsBtn->setVisible(false);

    connect(ui->actionLoadFrom, SIGNAL(triggered()), this, SLOT(loadSettingsFromFile()) );



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addItemBtn_clicked()
{
    if(ui->AmntEntered->value() == 0)
    {
        ui->warningLabel->setVisible(true);
    }
    else
    {
        ui->warningLabel->setVisible(false);
        ui->AmntEntered->setVisible(false);
        ui->addItemBtn->setVisible(false);
        ui->label_2->setVisible(false);
        ui->groupBox->setVisible(true);
        ui->showChartBtn->setVisible(true);
        ui->saveSettingsBtn->setVisible(true);


        lhw = new ListHobbyWidget(this, ui->AmntEntered->value());

        ui->groupBox->setLayout(lhw->getHBoxLayout());
    }



}




bool MainWindow::getUserEntries()
{
    dataEntered.clear();
    //get all the inputs from the user and store them in a temporary variable
    QList<QLineEdit*> tmpLineEdits= lhw->getHobbyInputs();
    QList<QSlider*> tmpSliders = lhw->getSliders();
    //gor through a loop for every ListHobbyWidget created to
    //make sure no lineedit were left blank
   for (int i = 0; i< ui->AmntEntered->value() ; i++) {
       if (tmpLineEdits[i]->text() =="")
       {
           return false;
       }
       if (dataEntered.contains(tmpLineEdits[i]->text()))
       {
           return false;
       }
       dataEntered.insert(tmpLineEdits[i]->text(), tmpSliders[i]->value());
   }


   //if all the entries are valid , store them in an array for the next page
   //for loop to get all values from the sliders and lineEdits

   return true;
}





void MainWindow::on_saveSettingsBtn_clicked()
{
    if(getUserEntries())
    {

        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                         "/home",
                                                         tr("Text files(*.txt)"));
        QFile fileToSaveTo(fileName);
        if(!fileToSaveTo.open(QIODevice::WriteOnly))
            qFatal("Could not open the selected file");
        //copy content of QMap to file

        QDataStream data(&fileToSaveTo);
        data << dataEntered;

        fileToSaveTo.close();
        ui->warningLabel->setText("File saved successfully!");

        ui->warningLabel->setVisible(true);
    }
    else{
        ui->warningLabel->setText("Make sure to fill in every input box!");

        ui->warningLabel->setVisible(true);
        return;
    }
}

void MainWindow::loadSettingsFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "/home",
                                                     tr("Text files(*.txt)"));
    QFile fileToLoadFrom(fileName);
    if(!fileToLoadFrom.open(QIODevice::ReadOnly))
        qFatal("Could not open the selected file");
    QDataStream data(&fileToLoadFrom);
    data >> dataEntered;

    displayPieChart();

}


void MainWindow::on_showChartBtn_clicked()
{

    if(getUserEntries())
    {
        displayPieChart();
    }
    else{
        ui->warningLabel->setText("Make sure to fill in every input box!");

        ui->warningLabel->setVisible(true);
    }
}

void MainWindow::displayPieChart()
{

    ui->stackedWidget->setCurrentIndex(1);

    QList<QString> listOfHobbies = dataEntered.keys();


    QVBoxLayout *layout3 = new QVBoxLayout(ui->groupBox_3);

     pieChartWidget *pcw = new pieChartWidget(ui->groupBox_3, dataEntered);


     layout3->addWidget(pcw);

     ui->groupBox_3->setLayout(layout3);
}

