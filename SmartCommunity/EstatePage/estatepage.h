#ifndef ESTATEPAGE_H
#define ESTATEPAGE_H

#include <QWidget>

namespace Ui {
class EstatePage;
}

class EstatePage : public QWidget
{
    Q_OBJECT

public:
    explicit EstatePage(QWidget *parent = nullptr);
    ~EstatePage();

private:
    Ui::EstatePage *ui;
};

#endif // ESTATEPAGE_H
