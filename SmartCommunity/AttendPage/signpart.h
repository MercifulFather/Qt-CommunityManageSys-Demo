#ifndef SIGNPART_H
#define SIGNPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class SignPart;
}

class SignPart : public QWidget
{
    Q_OBJECT

public:
    explicit SignPart(QWidget *parent = nullptr, QString username = nullptr);
    ~SignPart();

private slots:
    void on_inButton_clicked();

    void on_outButton_clicked();

private:
    Ui::SignPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    QString curUsername;
    QDate date;
};

#endif // SIGNPART_H
