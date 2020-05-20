#ifndef PAYPART_H
#define PAYPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class PayPart;
}

class PayPart : public QWidget
{
    Q_OBJECT

public:
    explicit PayPart(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~PayPart();
    void refresh();
private slots:
    void on_payButton_clicked();

private:
    Ui::PayPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
};

#endif // PAYPART_H
