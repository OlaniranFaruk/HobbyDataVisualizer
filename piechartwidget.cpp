#include "piechartwidget.h"
#include "mainwindow.h"
#include <QDebug>
#include <QLabel>

pieChartWidget::pieChartWidget(QWidget *parent, QMap<QString, int> dataEntered) : QWidget(parent)
{
    data = dataEntered;


}

void pieChartWidget::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    int radius;

    int mywidth = height() - 100;
    if(width() > mywidth)
    {
        radius = mywidth - 50;
    }else{
        radius = width() - 50;
    }
    QRect rectangle(20,20, radius, radius);

    p.setBrush(Qt::red);
    p.drawEllipse(rectangle);

    QList<QString> hobbyNames = data.keys();
    QList<int> hobbyRatings = data.values();
    QList<QString> correspondingColor;

    //used in the calculation of the angles
    float additionOfAllRatings = 0;


    QColor color;
    QList<int> percentage;

    QColor myPalette[5] = {Qt::red, Qt::blue, Qt::black, Qt::magenta, Qt::cyan};



    if (data.count() != 1)
    {
        for (int i = 0; i< data.count(); i++ ) {
            additionOfAllRatings += hobbyRatings.value(i);
        }
        int startAngle = 0;
        for (int i= 0; i< data.count() ; i++) {
            //calculate the angle with respect to the percentage
            float angleOfpie = (hobbyRatings.value(i)/additionOfAllRatings) * 360 * 16;

            int pb = (hobbyRatings.value(i)/additionOfAllRatings) * 100;

            percentage.append(pb);

            color = myPalette[i];

            p.setBrush(color);

            correspondingColor.append(color.name());

            p.drawPie(rectangle, startAngle, angleOfpie);


            startAngle += angleOfpie;
        }
    }else{
        correspondingColor.append("Red");
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch();

    QLabel *label = new QLabel(this);
    label->setText("List Hobbies: ");

    layout->addWidget(label);

    qDebug() << percentage;
    for (int i = 0; i < data.count() ; i++) {
        QLabel *l = new QLabel(this);
        l->setText(hobbyNames[i] + ": " +correspondingColor[i]+ " ("+((hobbyRatings.value(i)/additionOfAllRatings) * 100)+"%)" );
        l->setStyleSheet("QLabel{color: "+correspondingColor[i]+"; } ");
        layout->addWidget(l);
    }

}








