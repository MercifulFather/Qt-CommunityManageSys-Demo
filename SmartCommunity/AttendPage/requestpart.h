#ifndef REQUESTPART_H
#define REQUESTPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class RequestPart;
}

class RequestPart : public QWidget
{
    Q_OBJECT

public:
    explicit RequestPart(QWidget *parent = nullptr, QString username = nullptr, int role = 0);
    ~RequestPart();
    void update();
private slots:
    void on_createButton_clicked();

    void on_finishButton_clicked();

private:
    Ui::RequestPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    QString curUsername;
    int curRole;
    void init();

};

#endif // REQUESTPART_H
