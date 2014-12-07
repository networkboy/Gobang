#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qDebug.h"
#include <QtGui>
#include <math.h>
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
pixb.load(":/black.png");
pixw.load(":/white.png");
connected = false;//��û������
beconnected = false;
exchange = true;
//link = 1;
//numw = 0;
//connect(mConnectBtn, SIGNAL(clicked()), this, SLOT(on_pushButton_6_clicked()));

//TCP�ͻ��˲ۺ���
connect(&tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),
        this, SLOT(dispalyError(QAbstractSocket::SocketError)));//������
connect(&tcpClient, SIGNAL(readyRead()), this, SLOT(client_readMessage()));

//TCP�������ۺ���
connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));


//����
if(!tcpServer.isListening() &&
        !tcpServer.listen(QHostAddress::Any, 6665))
{
    qDebug() << tcpServer.errorString();
    close();
}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e){





     QPainter paint(this);
     QPixmap pixbg(":/cv.png");
     paint.drawPixmap(0,0,pixbg);
     paint.drawRect(40,40,560,560);
     for(int i=0;i<13;i++)
       paint.drawLine(40,i*40+80,600,i*40+80);
     for(int i=0;i<13;i++)
       paint.drawLine(i*40+80,40,i*40+80,600);




}


void MainWindow::on_pushButton_clicked()
{
   n=QMessageBox::warning(this, "Hei,Guys","My Game Will Start Soon.",QMessageBox::Yes);
}
int j=0;
int a[600][600]={2};
int l=0;
int i,k=0;
int q=0;
void  MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(q==0)
    { for(i=0;i<600;i++)
      for(k=0;k<600;k++)
          a[i][k]=2;
          q=1;
    }
    int xx=0;
    int yy=0;
    qDebug() <<e->pos();
    if(n==QMessageBox::Yes)
    {

    if(e->button()==Qt::LeftButton)
    {

      x = e->x();
      y = e->y();
}

if(x>=40&&y>=40&&x<=600&&y<=600)
{
    for(i=0;i<=15;i++,xx=i*40)
    if(x-xx<=40)
    {
        if(x-xx<=20)
         x=x-(x-xx);
        if(x-xx>20)
        x=x-(x-xx)+40;
         break;
     }
    for(k=0;k<=15;k++,yy=k*40)
        if(y-yy<=40)
         {   if(y-yy<=20)
             y=y-(y-yy);
             if(y-yy>20)
             y=y-(y-yy)+40;
             break;
         }
    if(j==0&&a[x][y]!=1&&a[x][y]!=-1)
   {

   /*whiteLabel=new QLabel(this);
    whiteLabel->setPixmap(pixw);
    whiteLabel->setGeometry(x-15,y-15,32,32);
    whiteLabel->show();
    whiteLabel;
    j=1;
    a[x][y]=1;
    g[l]=whiteLabel;
    l++;*/
    Whiteplay(x,y);
   }
   else
   {
       if(a[x][y]!=-1&&a[x][y]!=1)
      {
       /*blackLabel=new QLabel(this);
       blackLabel->setPixmap(pixb);
       blackLabel->setGeometry(x-15,y-15,32,32);
       blackLabel->show();
       blackLabel;
      j=0;
      a[x][y]=-1;
      g[l]=blackLabel;
      l++;*/
          Blackplay(x,y);

      }
   }

/*
    for(i=0;i<=440;i=i+40)
    for(k=0;k<=600;k=k+40)
   {

      if(a[i][k]==1&&a[i+40][k]==1&&a[i+80][k]==1&&a[i+120][k]==1&&a[i+160][k]==1)
        QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
      if(a[i][k]==-1&&a[i+40][k]==-1&&a[i+80][k]==-1&&a[i+120][k]==-1&&a[i+160][k]==-1)
        QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);

}
    for(i=0;i<=600;i=i+40)
    for(k=0;k<=440;k=k+40)
   {

      if(a[i][k]==1&&a[i][k+40]==1&&a[i][k+80]==1&&a[i][k+120]==1&&a[i][k+160]==1)
        QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
      if(a[i][k]==-1&&a[i][k+40]==-1&&a[i][k+80]==-1&&a[i][k+120]==-1&&a[i][k+160]==-1)
        QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);

}
    for(i=0;i<=440;i=i+40)
    for(k=0;k<=440;k=k+40)
    {
        if(a[i][k]==1&&a[i+40][k+40]==1&&a[i+80][k+80]==1&&a[i+120][k+120]==1&&a[i+160][k+160]==1)
          QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
        if(a[i][k]==-1&&a[i+40][k+40]==-1&&a[i+80][k+80]==-1&&a[i+120][k+120]==-1&&a[i+160][k+160]==-1)
          QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);

    }
    for(i=600;i>=0;i=i-40)
    for(k=0;k<=440;k=k+40)
    {
        if(a[i][k]==1&&a[i-40][k+40]==1&&a[i-80][k+80]==1&&a[i-120][k+120]==1&&a[i-160][k+160]==1)
          QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
        if(a[i][k]==-1&&a[i-40][k+40]==-1&&a[i-80][k+80]==-1&&a[i-120][k+120]==-1&&a[i-160][k+160]==-1)
          QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);
    }
*/
    win();
}


}

}
void  MainWindow::win()
{
    for(i=0;i<=440;i=i+40)
    for(k=0;k<=600;k=k+40)
   {

      if(a[i][k]==1&&a[i+40][k]==1&&a[i+80][k]==1&&a[i+120][k]==1&&a[i+160][k]==1)
        QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
      if(a[i][k]==-1&&a[i+40][k]==-1&&a[i+80][k]==-1&&a[i+120][k]==-1&&a[i+160][k]==-1)
        QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);

}
    for(i=0;i<=600;i=i+40)
    for(k=0;k<=440;k=k+40)
   {

      if(a[i][k]==1&&a[i][k+40]==1&&a[i][k+80]==1&&a[i][k+120]==1&&a[i][k+160]==1)
        QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
      if(a[i][k]==-1&&a[i][k+40]==-1&&a[i][k+80]==-1&&a[i][k+120]==-1&&a[i][k+160]==-1)
        QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);

}
    for(i=0;i<=440;i=i+40)
    for(k=0;k<=440;k=k+40)
    {
        if(a[i][k]==1&&a[i+40][k+40]==1&&a[i+80][k+80]==1&&a[i+120][k+120]==1&&a[i+160][k+160]==1)
          QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
        if(a[i][k]==-1&&a[i+40][k+40]==-1&&a[i+80][k+80]==-1&&a[i+120][k+120]==-1&&a[i+160][k+160]==-1)
          QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);

    }
    for(i=600;i>=0;i=i-40)
    for(k=0;k<=440;k=k+40)
    {
        if(a[i][k]==1&&a[i-40][k+40]==1&&a[i-80][k+80]==1&&a[i-120][k+120]==1&&a[i-160][k+160]==1)
          QMessageBox::warning(this, "Hei,Guys","white win.",QMessageBox::Yes);
        if(a[i][k]==-1&&a[i-40][k+40]==-1&&a[i-80][k+80]==-1&&a[i-120][k+120]==-1&&a[i-160][k+160]==-1)
          QMessageBox::warning(this, "Hei,Guys","black win.",QMessageBox::Yes);
    }
}
void  MainWindow::Blackplay(int x,int y)
{
           blackLabel=new QLabel(this);
           blackLabel->setPixmap(pixb);
           blackLabel->setGeometry(x-15,y-15,32,32);
           blackLabel->show();
           blackLabel;
           j=0;
           a[x][y]=-1;
           g[l]=blackLabel;
           l++;
           if(connected&&nn==QMessageBox::Yes){
               win();
               client_sendMessage();
               exchange = false;

           }
           else{
               exchange = true;
           }
}
void  MainWindow::Whiteplay(int x,int y)
{
        whiteLabel=new QLabel(this);
        whiteLabel->setPixmap(pixw);
        whiteLabel->setGeometry(x-15,y-15,32,32);
        whiteLabel->show();
        whiteLabel;
        j=1;
        a[x][y]=1;
        g[l]=whiteLabel;
        l++;

        if(beconnected&&nn==QMessageBox::Yes){
           win();
            server_sendMessege();
            exchange = false;
        }
        else{
            exchange =true;
        }

}
void MainWindow::on_pushButton_3_clicked()
{
    close();

}

void MainWindow::on_pushButton_2_clicked()
{

}
void MainWindow::judge()
{

}

void MainWindow::on_pushButton_4_clicked()
{

     if(n==QMessageBox::Yes)
     {

     if(j==0)
     {
         j=1;
      blackLabel->clear();

     }
    else
    {
        j=0;
    whiteLabel->clear();


     }
     a[x][y]=2;
}
}
int u;
void MainWindow::on_pushButton_5_clicked()
{
    if(n==QMessageBox::Yes)
    {
        for(u=0;u<l;u++)
        g[u]->clear();
    }
   for(i=0;i<600;i++)
          for(k=0;k<600;k++)
            a[i][k]=2;
}

void MainWindow::on_pushButton_6_clicked()
{

    nn=QMessageBox::warning(this, "Funny Game","Connect to my friend, His  ip is : " , QMessageBox::Yes);
    QString ipAddr="192.168.0.1";
    QMessageBox::warning(this, tr("Funny Game"),
                         tr("���������, ���ĵ�ַ : ") + ipAddr, QMessageBox::Yes);
    tcpClient.abort();//ȡ����������
   tcpClient.connectToHost(QHostAddress::LocalHost, 6665);
    //tcpClient.connectToHost(ipAddr,
             //               6666);

    //Tcp�ͻ��˲ۺ���
    connect(&tcpClient, SIGNAL(connected()), this, SLOT(connecting()));//���ӳɹ����ص�connected�ź�

    //mConnectBtn->setText(tr("������.."));

}
void MainWindow::dispalyError(QAbstractSocket::SocketError socketError)
{
    QMessageBox::information(this, tr("����"), tr("�ͻ��˴��� ") + socketError, QMessageBox::Yes);

    if(socketError == QTcpSocket::RemoteHostClosedError)
        return;

    tcpClient.close();
    //mConnectBtn->setText(tr("����"));
}

//�������˵Ĵ�����
void MainWindow::server_error(QAbstractSocket::SocketError socketError)
{
    QMessageBox::information(this, tr("����"), tr("��������sever"), QMessageBox::Yes);

    if(socketError == QTcpSocket::RemoteHostClosedError)
        return;

    tcpClient.close();
}

//�Ͽ�����
void MainWindow::disConnect()
{
    tcpClient.close();
   // mConnectBtn->setText(tr("����"));
   // mConnectBtn->setEnabled(true);
}
void MainWindow::acceptConnection()
{
    QMessageBox::information(this, tr("����"), tr("��������"), QMessageBox::Yes);
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection, SIGNAL(readyRead()), this, SLOT(server_readMessege()));//����������Ϣ�Ĳۺ���
    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(server_error(QAbstractSocket::SocketError)));
    connected = false;
    beconnected = true;
    tcpServer.close();

}
//ȷ����û�гɹ�����
void MainWindow::connecting()
{
    QMessageBox::information(this, tr("����"), tr("���ӳɹ�"), QMessageBox::Yes);
   // mConnectBtn->setText(tr("������"));
 // mConnectBtn->setEnabled(false);
    connected = true;
    beconnected = false;

}
void MainWindow::client_sendMessage()
{
    //QMessageBox::information(this, tr("�ͻ���"), tr("client_sendMessage"), QMessageBox::Yes);
    QDataStream out(&outBlock, QIODevice::WriteOnly);

    out << x;
    out << y;
   // out << numx;
   // out << numy;
    //out << numw;

    tcpClient.write(outBlock);
    outBlock.resize(0);
   // QMessageBox::information(this, tr("����"), tr("�ɹ�"), QMessageBox::Yes);

}
//�ͻ��˵Ľ�������
void MainWindow::client_readMessage()
{
    quint32 x;
    quint32 y;
  //  quint32 numx;
    //quint32 numy;
    //quint32 numw;
  //  QMessageBox::information(this, tr("������"), tr("client_readMessege"), QMessageBox::Yes);
    QDataStream in(&tcpClient);

    in >> x;
    in >> y;
    //in >> numx;
    //in >> numy;
    //in >> numw;

    Whiteplay(x, y);
}

//�������ķ�������
void  MainWindow::server_sendMessege()
{
    //QMessageBox::information(this, tr("������"), tr("server_sendMessage"), QMessageBox::Yes);
    QDataStream out(&inBlock, QIODevice::WriteOnly);

    out << x;
    out << y;
   // out << numx;
   // out << numy;
   // out << numw;

    tcpServerConnection->write(inBlock);
    // tcpClient.write(inBlock);
    inBlock.resize(0);
// QMessageBox::information(this, tr("����"), tr("�ɹ�"), QMessageBox::Yes);
}

//�������˵Ľ�������
void MainWindow::server_readMessege()
{
    //QMessageBox::information(this, tr("������"), tr("server_readMessege"), QMessageBox::Yes);
    quint32 x;
    quint32 y;
   // quint32 numx;
    //quint32 numy;
    //quint32 numw;

    QDataStream in(tcpServerConnection);//������<<��ȡTCP�����е�����

    in >> x;
    in >> y;
    //in >> numx;
    //in >> numy;
    //in >> numw;
    Blackplay(x, y);
    // QMessageBox::information(this, tr("����"), tr("�ɹ�"), QMessageBox::Yes);


}
