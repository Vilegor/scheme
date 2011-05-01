#include <QtGui>
#include "changeparameter.h"


ChangeParameter::ChangeParameter(QWidget *parent)
    : QDialog(parent)
{
    _okButton = new QPushButton("Ok");
    _cancelButton = new QPushButton("Cancel");
    _lineEdit = new QLineEdit;
    QRegExp regExp("[0-9]{0,5}[.][0-9]{0,10}");
    _lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(_cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(_okButton, SIGNAL(clicked()), this, SIGNAL(changeValue(float)));
    connect(_okButton, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *_leftLayout = new QVBoxLayout;
    QVBoxLayout *_rightLayout = new QVBoxLayout;
    QHBoxLayout *_layout = new QHBoxLayout;
    _leftLayout->addWidget(_lineEdit);
    _rightLayout->addWidget(_okButton);
    _rightLayout->addWidget(_cancelButton);
    _layout->addLayout(_leftLayout);
    _layout->addLayout(_rightLayout);
    setLayout(_layout);
    setWindowTitle("Change parameter");
    setFixedSize(sizeHint());

}

ChangeParameter::~ChangeParameter(void){

}

void ChangeParameter::setValue(float value)
{
    QString num;
    num.setNum(value);
    if( _lineEdit->text() != num){
        _lineEdit->setText(num);
    }
}
