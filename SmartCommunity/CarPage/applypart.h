#ifndef APPLYPART_H
#define APPLYPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class ApplyPart;
}

class ApplyPart : public QWidget
{
    Q_OBJECT

public:
    explicit ApplyPart(QWidget *parent = nullptr, QString username = nullptr);
    ~ApplyPart();
    void query();
private slots:
    void on_saveButton_clicked();

private:
    Ui::ApplyPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    QString iUsername;
};

#endif // APPLYPART_H
