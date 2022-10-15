#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMap>

class pieChartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit pieChartWidget(QWidget *parent = nullptr, QMap<QString, int> dataEntered = QMap<QString, int>());
    void paintEvent(QPaintEvent *ev);



signals:

private:
    int lenOfData;
    QMap<QString, int> data;
//    QList<QString> listOfHobbiesAndPercent;
//    const QMap<QColor, QString> colorPair;


};

#endif // PIECHARTWIDGET_H
