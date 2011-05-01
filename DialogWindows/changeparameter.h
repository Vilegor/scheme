#ifndef CHANGEPARAMETER_H
#define CHANGEPARAMETER_H

#include <QDialog>
class QWidget;
class QPushButton;
class QSlider;
class QLineEdit;
class QHBoxLayout;

class ChangeParameter : public QDialog{
    Q_OBJECT;

public:
    ChangeParameter(QWidget * parent = 0);
    ~ChangeParameter(void);

public slots:
    void setValue(float value);

signals:
    void changeValue(float newValue); //new value

protected:


private:

    QPushButton *_okButton;
    QPushButton *_cancelButton;
    QLineEdit *_lineEdit;

};

#endif // CHANGEPARAMETER_H
