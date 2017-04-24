#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process.h"
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection);
    maini = 2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()   //就绪状态按钮
{
    ui->tableWidget->clear();
    for (int i=0; i<a.ready.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(a.ready.at(i).PID)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(a.ready.at(i).priority)));
    }
}

void MainWindow::on_pushButton_3_clicked()   //执行状态按钮
{
    ui->tableWidget->clear();
    ui->tableWidget->insertRow(0);
    if(a.executive.PID == -1)
    {
        ui->tableWidget->setItem(0,0,new QTableWidgetItem("NULL"));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem("NULL"));
    }
    else
    {
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::number(a.executive.PID)));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(a.executive.priority)));
    }
    //QObject::connect(listWidget, SIGNAL(currentTextChanged(const QString &)), label, SLOT(setText(const QString &)));
}

void MainWindow::on_pushButton_4_clicked()   //阻塞状态按钮
{
    ui->tableWidget->clear();
    for (int i=0; i<a.blocked.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(a.blocked.at(i).PID)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(a.blocked.at(i).priority)));
    }
}


void MainWindow::on_pushButton_clicked()  //创建进程
{
    QString input2 = ui->textEdit_2->toPlainText();
    if (input2.isEmpty()) ui->label_6->setText("ERROR");
    else
    {
        int i2 = input2.toInt();
        a.createProcess(maini,i2);
        ui->label_6->setText("CREATE");
    }
    maini++;
}

void MainWindow::on_pushButton_8_clicked()  //撤销进程
{
    a.undoProcess();
}

void MainWindow::on_pushButton_5_clicked()//时间片用完
{
    a.timeout();
}

void MainWindow::on_pushButton_6_clicked()  //阻塞进程
{
    a.brokeProcess();
}

void MainWindow::on_pushButton_7_clicked()
{
    int b = ui->tableWidget->currentItem()->row();
    //ui->label_6->setText(QString::number(b));
    a.revokeProcess(b);
}
