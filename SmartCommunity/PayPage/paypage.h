#ifndef PAYPAGE_H
#define PAYPAGE_H

#include <QWidget>
#include "paypart.h"
#include "pricepart.h"
#include "querypart.h"

namespace Ui {
class PayPage;
}

class PayPage : public QWidget
{
    Q_OBJECT

public:
    explicit PayPage(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~PayPage();

private slots:
    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::PayPage *ui;
    PayPart * pyp;
    PricePart * pcp;
    QueryPart * qp;
};

#endif // PAYPAGE_H
