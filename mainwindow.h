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
    QAction *openAction; //����˽�е�QAction����

    //TCP�ͻ���
    QTcpSocket tcpClient;//��װ��һ��TCP����
    QTcpSocket *tcpServerConnection;//��װ��һ��TCP����
    QByteArray outBlock ;

    //TCP��������
    QTcpServer tcpServer;//����������������������
    QByteArray inBlock;
    private slots:
    void disConnect();
    //���Ӱ�ť�Ĳۺ���
    void dispalyError(QAbstractSocket::SocketError);//������
    void server_error(QAbstractSocket::SocketError socketError);
    void acceptConnection();
    void connecting();//ȷ����û�гɹ�����
    //�ͻ���
    void client_readMessage();//�ͻ��˽��պ���
    void client_sendMessage();//�ͻ������պ���
    //������
    void server_sendMessege();
    void server_readMessege();


};

#endif // MAINWINDOW_H
