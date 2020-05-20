#ifndef QUERYPART_H
#define QUERYPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class QueryPart;
}

class QueryPart : public QWidget
{
    Q_OBJECT

public:
    explicit QueryPart(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~QueryPart();
    void refresh();
private slots:
    void on_queryButton_clicked();

private:
    Ui::QueryPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    QString iUsername;
    int iRole = 0;
};

#endif // QUERYPART_H
