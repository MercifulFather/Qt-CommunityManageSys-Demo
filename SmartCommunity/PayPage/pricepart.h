#ifndef PRICEPART_H
#define PRICEPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class PricePart;
}

class PricePart : public QWidget
{
    Q_OBJECT

public:
    explicit PricePart(QWidget *parent = nullptr);
    ~PricePart();
    void refresh();
private slots:
    void on_saveButton_clicked();

private:
    Ui::PricePart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
};

#endif // PRICEPART_H
