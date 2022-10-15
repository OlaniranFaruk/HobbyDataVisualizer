#ifndef LISTHOBBYWIDGET_H
#define LISTHOBBYWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QLineEdit>
#include <QHBoxLayout>

class ListHobbyWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QList<QLineEdit*> HobbyInputs READ getHobbyInputs )
    Q_PROPERTY(QList<QSlider*> Sliders READ getSliders )
public:
    explicit ListHobbyWidget(QWidget *parent = nullptr, int amntOfHibbiesInput = 0);
    QHBoxLayout* getHBoxLayout();

    ~ListHobbyWidget();
    QList<QLineEdit*> getHobbyInputs();
    QList<QSlider*> getSliders();


signals:

private:
    QList<QSlider*> *Sliders;
    QList<QLineEdit*>  *HobbyInputs;
    QHBoxLayout *layoutsLayout;

};

#endif // LISTHOBBYWIDGET_H
