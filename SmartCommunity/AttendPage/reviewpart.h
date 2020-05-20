#ifndef REVIEWPART_H
#define REVIEWPART_H

#include <QWidget>
#include "common.h"

namespace Ui {
class ReviewPart;
}

class ReviewPart : public QWidget
{
    Q_OBJECT

public:
    explicit ReviewPart(QWidget *parent = nullptr);
    ~ReviewPart();
    void update();
private slots:
    void on_rejectButton_clicked();

    void on_acceptButton_clicked();

private:
    Ui::ReviewPart *ui;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(this, db);
    void init();

};

#endif // REVIEWPART_H
