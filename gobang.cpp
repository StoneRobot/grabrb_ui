#include "gobang.h"
#include "ui_gobang.h"

gobang::gobang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gobang)
{
    ui->setupUi(this);
}

gobang::~gobang()
{
    delete ui;
}
