#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QMessageBox>
#include <QShowEvent>
#include <QPixmap>
#include <QPushButton>
#include <QtNetWork>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *);
    void Blackplay(int x,int y);
    void Whiteplay(int x,int y);
    void win();
    bool exchange;
protected:
void paintEvent(QPaintEvent *);
private slots:
void on_pushButton_clicked();
void on_pushButton_3_clicked();
void judge();
void on_pushButton_2_clicked();

void on_pushButton_4_clicked();

void on_pushButton_5_clicked();

void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *blackLabel;
    QPixmap pixb;
    QPixmap pixw;
    QLabel *whiteLabel;
    QLabel *g[225];
    int x,y;
    int n;
    int nn;
    int xx,yy,i;
    bool connected;
    bool beconnected;
  //  int Ret,Rets;
   // void on_pushButton_6_clicked();
    QAction *openAction; //声明私有的QAction变量

    //TCP客户端
    QTcpSocket tcpClient;//封装了一条TCP连接
    QTcpSocket *tcpServerConnection;//封装了一条TCP连接
    QByteArray outBlock ;

    //TCP服务器端
    QTcpServer tcpServer;//监听并处理外来连接请求
    QByteArray inBlock;
    private slots:
    void disConnect();
    //连接按钮的槽函数
    void dispalyError(QAbstractSocket::SocketError);//检查错误
    void server_error(QAbstractSocket::SocketError socketError);
    void acceptConnection();
    void connecting();//确认有没有成功连接
    //客户端
    void client_readMessage();//客户端接收函数
    void client_sendMessage();//客户发送收函数
    //服务器
    void server_sendMessege();
    void server_readMessege();


};

#endif // MAINWINDOW_H
