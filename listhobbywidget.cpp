#include "listhobbywidget.h"
#include <QDebug>
#include <QLabel>


ListHobbyWidget::ListHobbyWidget(QWidget *parent, int amntInput) : QWidget(parent)
{
    QVBoxLayout *sliderLayout = new QVBoxLayout();
    QVBoxLayout *lineEditLayout = new QVBoxLayout();
    layoutsLayout = new QHBoxLayout();

    Sliders = new QList<QSlider*>;
    HobbyInputs = new QList<QLineEdit*>;

    QLabel *lineEditLabel = new QLabel("Name of your hobbies:");
    QLabel *slidersLabel = new QLabel("Give a rating(out of 100):");

    lineEditLabel->setAlignment(Qt::AlignCenter);
    slidersLabel->setAlignment(Qt::AlignCenter);

    lineEditLayout->addWidget(lineEditLabel);
    sliderLayout->addWidget(slidersLabel);

    for (int i=0; i<amntInput ; i++ ) {

        QLineEdit *tmpLineEdit = new QLineEdit();
        HobbyInputs->append(tmpLineEdit);
        lineEditLayout->addWidget(tmpLineEdit);


        QSlider *tmpSlider = new QSlider(Qt::Horizontal, this);
        tmpSlider->setMinimum(0);
        tmpSlider->setMaximum(100);
        Sliders->append(tmpSlider);
        sliderLayout->addWidget(tmpSlider);

    }

    layoutsLayout->addItem(sliderLayout);
    layoutsLayout->addItem(lineEditLayout);


}

ListHobbyWidget::~ListHobbyWidget()
{

}

QList<QLineEdit *> ListHobbyWidget::getHobbyInputs()
{
    return *HobbyInputs;
}

QList<QSlider *> ListHobbyWidget::getSliders()
{
    return *Sliders;
}



QHBoxLayout* ListHobbyWidget::getHBoxLayout()
{
    return layoutsLayout;
}
