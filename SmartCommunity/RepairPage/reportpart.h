#ifndef REPORTPART_H
#define REPORTPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class ReportPart;
}

class ReportPart : public QWidget
{
    Q_OBJECT

public:
    explicit ReportPart(QWidget *parent = nullptr, QString username = nullptr);
    ~ReportPart();
    void refresh();
private slots:
    void on_saveButton_clicked();

private:
    Ui::ReportPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    QString iUsername;
};

#endif // REPORTPART_H
