#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   qpaint1 = new QPaintBox(0,0,ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QPainter paint(qpaint1->getCanvas());

    QPen pen;


    pen.setWidth(3);

     for(int i=0;i<ui->widget->height();i+=10){
         pen.setColor(Qt::red);
         paint.setPen(pen);
         paint.drawLine(0,ui->widget->height()-i,ui->widget->width(),ui->widget->height()-i);
         pen.setColor(Qt::green);
         paint.setPen(pen);
         paint.drawEllipse(10,i,100,10+i);

     }


    qpaint1->update();
}

