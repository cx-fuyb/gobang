#include "scan_gobang.h"
#include "ui_scan_gobang.h"
#include "welcome.h"
#include "ui_welcome.h"

scan_gobang::scan_gobang(Gobang_Network *g_network, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scan_gobang)
{
    ui->setupUi(this);
    paint=new QPainter;

    this->g_network = g_network;

    welcome *wc = new welcome();
    wc->show();
    connect(wc->ui->pushButton, &QPushButton::clicked, this, &scan_gobang::on_pushButton_clicked);

    choose_color();
    // 初始化时绑定信号槽连接
    connect(ui->pushButton, &QPushButton::clicked, this, &scan_gobang::on_pushButton_clicked);

    this->clear_chess();
}
/*
* 画棋子
* @param x:棋子横坐标
* @param y:棋子纵坐标
* @param color:棋子颜色
*/
void scan_gobang::draw_chess(char x,char y, char color)
{
    if(color == Chessblack) {
        /* 毛刷：颜色，实图案 */
        paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));
    }
    else if (color == Chesswhite) {
        paint->setBrush(QBrush(Qt::white,Qt::SolidPattern));
    }

    /* 画椭圆：中心点X,Y,宽度，高度 */
    paint->drawEllipse((this->padding+x*WIDTH-WIDTH/4),(this->padding+y*WIDTH-WIDTH/4),WIDTH/2,WIDTH/2);
}
/*
* 棋子刷新
* @param null
*/
void scan_gobang::update_chess()
{
    for(int i=0;i<CHASS_NUM;i++) {
        for(int j=0;j<CHASS_NUM;j++) {
            if(chess[i][j] == Chessblack) {
                draw_chess(static_cast<char>(i),static_cast<char>(j),Chessblack);
            }
            else if(chess[i][j] == Chesswhite) {
                draw_chess(static_cast<char>(i),static_cast<char>(j),Chesswhite);
            }
        }
    }
}
/*
* 判断胜负
* @param null
*/
void scan_gobang::win_or_lose() {
    for(int i = 0; i < CHASS_NUM; i++) {
        for(int j = 0; j < CHASS_NUM; j++) {
            if(chess[i][j] == ChessStatus) {
                // 判断横向
                if(j <= CHASS_NUM - 5) {
                    bool win = true;
                    for(int k = 1; k < 5; k++) {
                        if(chess[i][j + k] != ChessStatus) {
                            win = false;
                            break;
                        }
                    }
                    if(win) {
                        QMessageBox::information(this, "提示", "恭喜你，你赢了！");
                        return;
                    }
                }

                // 判断纵向
                if(i <= CHASS_NUM - 5) {
                    bool win = true;
                    for(int k = 1; k < 5; k++) {
                        if(chess[i + k][j] != ChessStatus) {
                            win = false;
                            break;
                        }
                    }
                    if(win) {
                        QMessageBox::information(this, "提示", "恭喜你，你赢了！");
                        return;
                    }
                }

                // 判断左斜方向
                if(i <= CHASS_NUM - 5 && j <= CHASS_NUM - 5) {
                    bool win = true;
                    for(int k = 1; k < 5; k++) {
                        if(chess[i + k][j + k] != ChessStatus) {
                            win = false;
                            break;
                        }
                    }
                    if(win) {
                        QMessageBox::information(this, "提示", "恭喜你，你赢了！");
                        return;
                    }
                }

                // 判断右斜方向
                if(i <= CHASS_NUM - 5 && j >= 4) {
                    bool win = true;
                    for(int k = 1; k < 5; k++) {
                        if(chess[i + k][j - k] != ChessStatus) {
                            win = false;
                            break;
                        }
                    }
                    if(win) {
                        QMessageBox::information(this, "提示", "恭喜你，你赢了！");
                        return;
                    }
                }
            }
        }
    }
}

/*
* 清空棋盘
* @param null
*/
void scan_gobang::clear_chess() {
    for( int i = 0; i < CHASS_NUM; i++) {
        for(int j = 0; j < CHASS_NUM; j++) {
            chess[i][j] = ChessNull;
        }
    }
}
void scan_gobang::paintEvent(QPaintEvent *)
{
    /* 窗口拖动 */
    window_changed();

    /* 主窗口 */
    paint->begin(this);

    /* 画棋盘 */
    draw_chessboard();

    /* 更新棋子 */
    update_chess();
    paint->end();
    qDebug("paintEvent width:%d", width());

    update();
}
/*
* 窗口大小改变响应函数
*/
void scan_gobang::window_changed()
{
    int new_width = std::max(width(), width() / 2);

    if (new_width < MIN_WIDTH) {
        new_width = MIN_WIDTH;
    }
    int new_height = new_width * 2 / 3;

    resize(new_width, new_height);

    if (width() > height()) {
        WIDTH =(height()-padding*2) / SIZE;
    } else {
        WIDTH =(width()-padding*2) / SIZE;
    }

    /* 按键更新 */
    ui->pushButton->setGeometry(QRect(new_width - 300, new_height - 100, 200, 50));
}

/*
* 画棋盘
*/
void scan_gobang::draw_chessboard()
{
    /* 钢笔工具：颜色，线号，实线 */
    paint->setPen(QPen(Qt::darkGreen,2,Qt::SolidLine));

    for(int i=0;i<SIZE+1;i++) {

        /* 画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线 */
        paint->drawLine(padding,padding+WIDTH*i,padding+WIDTH*(SIZE),padding+WIDTH*i);
    }
    /* 画SIZE+1条竖线 */
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(padding+WIDTH*i,padding,padding+WIDTH*i,padding+WIDTH*(SIZE));
    }
}

void scan_gobang::mousePressEvent(QMouseEvent* event)
{
    /* 获取鼠标点击位置 */ 
    int mouse_x = event->pos().x();
    int mouse_y = event->pos().y();

    /* 计算棋盘的宽度 */ 
    int width = WIDTH * SIZE;

    qDebug("mouse_x: %d, mouse_y: %d", mouse_x, mouse_y);

    /* 检查点击是否在棋盘范围内 */ 
    if (mouse_x < padding || mouse_x >= width + padding * 2 || mouse_y < padding || mouse_y >= width + padding * 2 )
        return;

    /* 计算相对棋盘的坐标 */ 
    mouse_x -= padding;
    mouse_y -= padding;

    /* 计算棋盘上的坐标 */
    int chess_x = mouse_x / WIDTH;
    int chess_y = mouse_y / WIDTH;

    /* 根据鼠标点击的位置调整棋盘坐标，确保棋子放置在最近的格子中心 */
    int center_x = (mouse_x % WIDTH) * 2;
    int center_y = (mouse_y % WIDTH) * 2;

    if (center_x > WIDTH) {
        chess_x += 1;
    }
    if (center_y > WIDTH) {
        chess_y += 1;
    }

    /* 限幅，确保坐标在棋盘范围内 */ 
    chess_x = qBound(0, chess_x, SIZE);
    chess_y = qBound(0, chess_y, SIZE);

    qDebug("chess_x: %d, chess_y: %d", chess_x, chess_y);

    /* 标记棋盘上的位置 */ 
    chess[chess_x][chess_y] = ChessStatus;
    g_network->tellOpponent_chassxy(chess_x,chess_y,ChessStatus);
    update();
    win_or_lose();
}
void scan_gobang::mouseReleaseEvent(QMouseEvent* event)
{
    event->button();
    qDebug("鼠标移动响应函数");
}

void scan_gobang::on_pushButton_clicked()
{
    qDebug("清空棋盘");
    /*
    * 清除棋盘
    */
    clear_chess();
    update();
}

/*
* 选择棋子颜色
* 弹出选择对话框
*/
void scan_gobang::choose_color()
{
    QMessageBox msgBox;
    msgBox.setText("选择棋子颜色: Yes黑棋 & No白棋");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        setChessStatus(Chessblack);
        qDebug("选择黑棋");
    } else if (ret == QMessageBox::No) {
        setChessStatus(Chesswhite);
        qDebug("选择白棋");
    }
    update();
}

void scan_gobang::mouseMoveEvent(QMouseEvent* event)
{
    event->button();
    qDebug("鼠标移动响应函数");
}

/*
* 设置棋子状态
* @param color:棋子颜色
*/
void scan_gobang::setChessStatus(char color)
{
    this->ChessStatus = color;
}
scan_gobang::~scan_gobang()
{
    delete ui;
}
