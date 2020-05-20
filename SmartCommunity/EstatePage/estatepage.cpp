#pragma execution_character_set("utf-8")
#include "estatepage.h"
#include "ui_estatepage.h"

EstatePage::EstatePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EstatePage)
{
    ui->setupUi(this);
}

EstatePage::~EstatePage()
{
    delete ui;
}
