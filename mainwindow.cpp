#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QLabel>
#include<QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("nodes name");
    ui->lineEdit_2->setText("costs");
    ui->lineEdit_3->setText("number of nodes");
    ui->lineEdit_4->setText("start from");
    ui->pushButton_2->setText("Dijkstra’s");
    ui->pushButton_3->setText("Bellman-Ford");
    ui->pushButton->setGeometry(QRect(QPoint(240,20),QSize(120,30)));
    ui->pushButton_2->setGeometry(QRect(QPoint(370,20),QSize(120,30)));
    ui->pushButton_3->setGeometry(QRect(QPoint(500,20),QSize(120,30)));

    QStandardItemModel *model = new QStandardItemModel();


    //model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit(" "));
    /*model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("1"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("2"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("3"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("4"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("5"));
    model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("6"));
    //model->setHeaderData(0,Qt::Vertical,QString::fromLocal8Bit(" "));
    model->setHeaderData(0,Qt::Vertical,QString::fromLocal8Bit("1"));
    model->setHeaderData(1,Qt::Vertical,QString::fromLocal8Bit("2"));
    model->setHeaderData(2,Qt::Vertical,QString::fromLocal8Bit("3"));
    model->setHeaderData(3,Qt::Vertical,QString::fromLocal8Bit("4"));
    model->setHeaderData(4,Qt::Vertical,QString::fromLocal8Bit("5"));
    model->setHeaderData(5,Qt::Vertical,QString::fromLocal8Bit("6"));*/
    ui->tableView->setModel(model);

    //表头信息显示居左
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    //设置列宽不可变
    //ui->tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Fixed);
    //ui->tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Fixed);
    /*ui->tableView->setColumnWidth(0,5);
    ui->tableView->setColumnWidth(1,5);
    ui->tableView->setColumnWidth(2,5);
    ui->tableView->setColumnWidth(3,5);
    ui->tableView->setColumnWidth(4,5);
    ui->tableView->setColumnWidth(5,5);
    ui->tableView->setColumnWidth(6,5);
    ui->tableView->setRowHeight(5,0);
    ui->tableView->setRowHeight(5,1);
    ui->tableView->setRowHeight(5,2);
    ui->tableView->setRowHeight(5,3);
    ui->tableView->setRowHeight(5,4);
    ui->tableView->setRowHeight(5,5);
    ui->tableView->setRowHeight(5,6);*/
    //ui->tableView->setColumnWidth(1,10);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->setGeometry(QRect(QPoint(240,60),QSize(300,300)));
    ui->tableView_2->setGeometry(QRect(QPoint(240,370),QSize(300,300)));
    ui->tableView_3->setGeometry(QRect(QPoint(570,370),QSize(300,300)));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{

    node = ui->lineEdit->text();
    cost = ui->lineEdit_2->text();
    num = ui->lineEdit_3->text();
    nodes=node.split(QRegExp(" "));
    costs=cost.split(QRegExp(" "));
    int a=0;
    /*for(int i=0;i<nodes.size();i++)
        qDebug()<<nodes[i];
    for(int i=0;i<costs.size();i++)
        qDebug()<<costs[i];
    qDebug()<<nodes.size();
    qDebug()<<costs.size();
    qDebug()<<node;
    qDebug()<<cost;*/

    QStandardItemModel *model = new QStandardItemModel();
    ui->tableView->setModel(model);
    model->setColumnCount(num.toInt());
    model->setRowCount(num.toInt());
    for(int i=0;i<num.toInt();i++)
    {
        model->setHeaderData(i,Qt::Horizontal,nodes[i]);
        model->setHeaderData(i,Qt::Vertical,nodes[i]);
    }
    for(int i=0;i<num.toInt();i++)
        for(int j=0;j<num.toInt();j++)
            model->setItem(i, j, new QStandardItem(costs[a++]));
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();

}

void MainWindow::on_pushButton_2_clicked()
{
    QString start = ui->lineEdit_4->text();
    int tim=0;
    int t=1;
    //int st=start.toInt();
    int rows=0;
    while(t)
    {
        nodes2=start;
        int startFrom=0;

        //qDebug()<<nodes[0];
        if(rows==0)
            rowsHead<<start;
        if(rows>0)
        {
            rowsHead<<start;
            rowsHeads=rowsHead.join(",");
        }
        for(int i=0;i<num.toInt();i++)
        {
            if(!(QString::compare(start,nodes[i])))
            {
                startFrom=i;
                startF<<nodes[i];
                startFr<<startF.join(",");
                rows++;
            }

        }
        //qDebug()<<nodes[startFrom];
        QStandardItemModel *model1 = new QStandardItemModel();
        model1->setColumnCount(num.toInt());
        model1->setRowCount(rows);
        for(int i=0;i<num.toInt();i++)
        {
            model1->setHeaderData(i,Qt::Horizontal,nodes[i]);

        }
        for(int i=0;i<rows;i++)
        {
            model1->setHeaderData(i,Qt::Vertical,startFr[i]);
            /*if(i>0)
                startF[i]+=startF[i-1];*/
        }
        ui->tableView_2->setModel(model1);
        for(int i=0;i<costs.size();i++)
            costsd<<costs[i];
        for(int j=0;j<rows;j++)
            for(int i=0;i<num.toInt();i++)
                //if(i!=startF[j].toInt()-1)
                    model1->setItem(j, i, new QStandardItem(costsd[num.toInt()*i+startF[j].toInt()-1]));

        ui->tableView_2->resizeColumnsToContents();
        ui->tableView_2->resizeRowsToContents();
        QString mini=num;
        QString minim=num;

        for(int i=0;i<num.toInt();i++)
            costsl<<costsd[num.toInt()*i+start.toInt()-1];
        qDebug()<<costsl;
        for(int i=0;i<startF.size();i++)
            costsl[startF[i].toInt()-1]='0';
        for(int i=num.toInt()-1;i>=0;i--)
        {
            //qDebug()<<costsl[i];
            if(costsl[i].toInt()!=0)
            {
                //qDebug()<<i;
                mini=costsl[i];
                minim=nodes[i];
                qDebug()<<mini;
            }
        }
        //qDebug()<<costsl[0]<<costsl[1]<<costsl[2]<<costsl[3]<<costsl[4]<<costsl[5];
        for(int i=0;i<num.toInt();i++)
        {
            if(costsl[i].toInt()!=0 )
            {
                qDebug()<<costsl[i]<<start<<costsd[num.toInt()*i+start.toInt()-1];
                if((costsd[num.toInt()*i+start.toInt()-1].toInt())!=0)
                {
                    //qDebug()<<i;
                    if(mini.toInt()>costsd[num.toInt()*i+start.toInt()-1].toInt())
                    {
                        mini=costsd[num.toInt()*i+start.toInt()-1];
                        qDebug()<<mini;
                        minim=nodes[i];
                    }
                }
            }
        }
        for(int i=0;i<num.toInt();i++)
        {
            if(costsl[i].toInt()!=0 && costsd[num.toInt()*(minim.toInt()-1)+start.toInt()-1].toInt()+costsd[num.toInt()*i+minim.toInt()-1].toInt()!=0)
            {
                if(costsd[num.toInt()*i+start.toInt()-1].toInt()>(costsd[num.toInt()*(minim.toInt()-1)+start.toInt()-1].toInt()+costsd[num.toInt()*i+minim.toInt()-1].toInt()))
                {
                    qDebug()<<costsd[num.toInt()*i+start.toInt()-1]<<costsd[num.toInt()*(minim.toInt()-1)+start.toInt()-1]<<costsd[num.toInt()*i+minim.toInt()-1];
                    costsd[num.toInt()*i+minim.toInt()-1]=QString::number(costsd[num.toInt()*(minim.toInt()-1)+start.toInt()-1].toInt()+costsd[num.toInt()*i+minim.toInt()-1].toInt());
                }
                else if(costsd[num.toInt()*i+start.toInt()-1].toInt()==0 && costsd[num.toInt()*(minim.toInt()-1)+start.toInt()-1].toInt()+costsd[num.toInt()*i+minim.toInt()-1].toInt()!=0)
                {
                    costsd[num.toInt()*i+minim.toInt()-1]=QString::number(costsd[num.toInt()*(minim.toInt()-1)+start.toInt()-1].toInt()+costsd[num.toInt()*i+minim.toInt()-1].toInt());
                }
                else
                {
                    costsd[num.toInt()*i+minim.toInt()-1]=costsl[i];
                }
            }
            else if(costsd[num.toInt()*i+start.toInt()-1].toInt()==0 && costsd[num.toInt()*i+minim.toInt()-1].toInt()!=0)
                costsd[num.toInt()*i+minim.toInt()-1]=QString::number(costsd[num.toInt()*(minim.toInt()-1)+start.toInt()-1].toInt()+costsd[num.toInt()*i+minim.toInt()-1].toInt());
            else
                costsd[num.toInt()*i+minim.toInt()-1]=costsd[num.toInt()*i+start.toInt()-1];
        }
        start=minim;
        //qDebug()<<minim;
        for(int i=0;i<startF.size();i++)
        {
            if(!(QString::compare(start,startF[i])) || tim==num.toInt())
                t=0;
        }
        tim++;
        costsl.clear();
    }
    rowsHead.clear();
    rowsHeads.clear();
    startF.clear();
    startFr.clear();
    costsd.clear();
    costsl.clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString start = ui->lineEdit_4->text();
    int ti=1;
    int rows2=1;
    int chang=0;
    while(ti)
    {
        QStandardItemModel *model2 = new QStandardItemModel();
        model2->setColumnCount(num.toInt());
        model2->setRowCount(rows2);
        for(int i=0;i<num.toInt();i++)
        {
            model2->setHeaderData(i,Qt::Horizontal,nodes[i]);

        }
        for(int i=0;i<rows2;i++)
        {
            model2->setHeaderData(i,Qt::Vertical,QString::number(i));
            /*if(i>0)
                startF[i]+=startF[i-1];*/
        }

        if(rows2==1)
        {
            for(int i=0;i<num.toInt();i++)
            {
                costs2d<<costs[i*num.toInt()+start.toInt()-1];
                costs2l<<costs[i*num.toInt()+start.toInt()-1];
                costs2li<<costs[i*num.toInt()+start.toInt()-1];
                costs2lin<<costs[i*num.toInt()+start.toInt()-1];
            }
        }
        else
        {
            for(int i=0;i<num.toInt();i++)
            {
                for(int j=0;j<num.toInt();j++)
                {
                    if(costs[i*num.toInt()+j].toInt()!=0)
                    {
                        qDebug()<<costs[i*num.toInt()+j]<<costs2li[j];
                        chang=1;
                        if(costs[i*num.toInt()+j].toInt()+costs2li[j].toInt()<costs2li[i].toInt() && costs2li[j].toInt()!=0)
                        {
                            costs2lin[i]=QString::number(costs[i*num.toInt()+j].toInt()+costs2li[j].toInt());
                            qDebug()<<costs2li;
                        }
                        if(costs2li[i].toInt()==0 && costs[i*num.toInt()+j].toInt()+costs2li[j].toInt()!=0 && costs2li[j].toInt()!=0)
                            costs2lin[i]=QString::number(costs[i*num.toInt()+j].toInt()+costs2li[j].toInt());

                    }
                }
                if(chang==0 && costs2l[i].toInt()!=0)
                    costs2l[i]='a';
                else
                    costs2l[i]=costs2lin[i];
            }
            ti=0;
            for(int i=0;i<num.toInt();i++)
            {
                costs2d<<costs2lin[i];
                if(costs2l[i]!=costs2li[i])
                    ti=1;
                costs2li[i]=costs2lin[i];
            }
        }
        rows2++;
    }
    QStandardItemModel *model2 = new QStandardItemModel();
    ui->tableView_3->setModel(model2);
    if(rows2==1)
    {
        for(int i=0;i<num.toInt();i++)
            costs2d<<QString::number(0);
    }
    //qDebug()<<costs2d;
    for(int j=0;j<costs2d.size();j++)
           model2->setItem(j/num.toInt(), j%num.toInt(), new QStandardItem(costs2d[j]));
    ui->tableView_3->resizeColumnsToContents();
    ui->tableView_3->resizeRowsToContents();
    costs2d.clear();
    costs2l.clear();
    costs2li.clear();
}
