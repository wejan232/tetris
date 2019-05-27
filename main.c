#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define FrameX 13
#define FrameY 3
#define Frame_height 20
#define Frame_width 18

int i,j,Temp,Temp1,Temp2;
int a[80][80]={0};//0无方块 1有方块 2边框
int b[4];//方块类型 0无方块 1有方块
struct Tetris{
    int x;
    int y;
    int flag;
    int next;
    int speed;
    int number;
    int score;
    int level;
}tetris;

HANDLE hOut;//控制台局表，位置，颜色


int color(int c);                       //颜色控制
void gotoxy(int x,int y);               //光标位置
void ShowGameframe();                   //显示游戏窗体
void Flag(struct Tetris *);             //方块类型
void MakeTeTris(struct Tetris *);       //制作方块
void PrintfTeTris(struct Tetris *);     //打印方块
void CleanTeTris(struct Tetris *);      //清除方块移动痕迹
int ifMove(struct Tetris *);            //判断是否可以移动
void Del_Fullline(struct Tetris *);     //清除满行方块
void Gameplay();                        //开始游戏
void regulation();                      //游戏规则界面
void explation();                       //游戏说明界面
void welcome();                         //欢迎界面（首界面）
void Replace(struct Tetris *);          //重新开始游戏
void title();                           //标题
void flower();                          //字符花
void close();                           //退出游戏

int color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
    return 0;
}



void gotoxy(int x,int y){
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


void title()
{
    color(15);
    gotoxy(30,3);
    printf("趣 味 俄 罗 斯 方 块");        //标题

    color(11);
    gotoxy(18,5);
    printf("■");
    gotoxy(18,6);
    printf("■■");           //■
    gotoxy(18,7);           //■ ■
    printf("■");            //■

    color(6);
    gotoxy(26,6);
    printf("■■");
    gotoxy(28,7);           //■ ■
    printf("■■");           //  ■ ■

    color(10);
    gotoxy(36,6);
    printf("■■");
    gotoxy(36,7);           //■ ■
    printf("■■");           //■ ■

    color(13);
    gotoxy(46,5);
    printf("■");
    gotoxy(46,6);           //■
    printf("■");            //■
    gotoxy(46,7);           //■
    printf("■");            //■

    color(4);
    gotoxy(60,6);
    printf("■");
    gotoxy(56,7);           //    ■
    printf("■■■");          //■ ■ ■
}




void ShowGameframe(){
    color(9);
    gotoxy(FrameX+Frame_width-7,FrameY-2);
    printf("俄罗斯方块");

    color(4);
    gotoxy(FrameX,FrameY);
    printf("╔ ");
    gotoxy(FrameX+2*Frame_width-2,FrameY);
    printf("╗ ");
    gotoxy(FrameX,FrameY+Frame_height);
    printf("╚ ");
    gotoxy(FrameX+2*Frame_width-2,FrameY+Frame_height);
    printf("╝ ");

    for(i=2;i<2*Frame_width-2;i+=2){    //上边框
        gotoxy(FrameX+i,FrameY);
        printf("━ ");
    }

    for(i=2;i<2*Frame_width-2;i+=2){    //下边框
        gotoxy(FrameX+i,FrameY+Frame_height);
        printf("━ ");
    }

    for(i=1;i<Frame_height;i++){    //左边框
        gotoxy(FrameX,FrameY+i);
        printf("┃");
    }

    for(i=1;i<Frame_height;i++){    //右边框
        gotoxy(FrameX+2*Frame_width-2,FrameY+i);
        printf("┃");
    }


    color(10);
    gotoxy(FrameX+2*Frame_width+6,FrameY+8);
    printf("下一个方块");
    gotoxy(FrameX+2*Frame_width+3,FrameY+9);
    printf("******************");
    gotoxy(FrameX+2*Frame_width+3,FrameY+14);
    printf("******************");


    color(6);
    gotoxy(FrameX+2*Frame_width+6,FrameY+Frame_height-4);
    printf("游戏提示：");
    gotoxy(FrameX+2*Frame_width+3,FrameY+Frame_height-3);
    printf("1：ESC退出游戏");
    gotoxy(FrameX+2*Frame_width+3,FrameY+Frame_height-2);
    printf("2：↑旋转，←→移动");
    gotoxy(FrameX+2*Frame_width+3,FrameY+Frame_height-1);
    printf("3：空格暂停");




}

void welcome()
{
    title();
    flower();
    int i,j;
    for(i=9;i<=20;i++)
    {
        for(j=15;j<=60;j++)
        {
            color(6);
            gotoxy(j,i);
            if(i==9 || i==20)
                printf("=");
            else if(j==15 || j==59)
                printf("||");               //绘制边框

        }
    }

    color(4);
    gotoxy(25,12);
    printf("1.开始游戏");
    gotoxy(40,12);
    printf("2.按键说明");
    gotoxy(25,17);
    printf("3.游戏规则");
    gotoxy(40,17);
    printf("4.退出");

    gotoxy(27,22);
    color(2);
    printf("请选择[1 2 3 4]:[ ]\b\b");
    int a;
    scanf("%d",&a);

    switch(a)
    {
        //case 1: system("cls");Gameplay();break;
        case 2: system("cls");explation();break;
        case 3: system("cls");regulation();break;
        case 4: system("cls");close();break;

    }
}


void flower()
{
    color(4);
    gotoxy(66,11);
    printf("(_)");
    gotoxy(64,12);
    printf("(_)");
    gotoxy(68,12);
    printf("(_)");
    gotoxy(66,13);
    printf("(_)");
    color(6);
    gotoxy(67,12);
    printf("@");            //绘制红色字符花

    color(6);
    gotoxy(72,12);
    printf("/");
    gotoxy(71,13);
    printf("|");
    gotoxy(70,14);
    printf("\\|");
    gotoxy(71,15);
    printf("|/");
    gotoxy(70,16);
    printf("\\|");
    gotoxy(71,17);
    printf("|/");
    gotoxy(71,18);
    printf("|");                    //两花之间的连接

    color(2);
    gotoxy(67,18);
    printf("\\\\\\\\");
    gotoxy(72,18);
    printf(" //");
    color(2);
    gotoxy(67,19);
    printf("^^^^^^^^");             //草地


    color(13);
    gotoxy(73,8);
    printf("(_)");
    gotoxy(71,9);
    printf("(_)");
    gotoxy(75,9);
    printf("(_)");
    gotoxy(73,10);
    printf("(_)");
    color(6);
    gotoxy(74,9);
    printf("@");                //绘制紫色字符花

}


void regulation()
{
    color(4);
    gotoxy(28,3);
    printf("游戏规则");

    int i,j;
    for(i=5;i<=18;i++)
    {
        for(j=5;j<=60;j++)
        {
            color(2);
            gotoxy(j,i);
            if(i==5 || i==18)
                printf("=");
            else if(j==5 || j==59)
                printf("||");                   //绘制边框

        }

    }
    color(4);
    gotoxy(7,6);
    printf("tip1:不同形状的小方块从屏幕上方落下，玩家通过");
    gotoxy(12,8);
    printf("调整方块的位置和方向，使他们在屏幕底部拼");
    gotoxy(12,10);
    printf("出完整的一条或几条");

    color(6);
    gotoxy(7,12);
    printf("tip2:每消除一行，积分涨100");

    color(2);
    gotoxy(7,14);
    printf("tip3:每累计1000分，会提升一个等级");

    gotoxy(7,16);
    printf("tip4:提升等级会使方块下落速度加快游戏难度加大");
    getchar();

    gotoxy(21,19);
    color(2);
    printf("按'0'返回上一级菜单[ ]\b\b");
    int a;
    scanf("%d",&a);

    switch(a)
    {
        case 0: system("cls");welcome();break;

    }
}


void explation()
{
    color(5);
    gotoxy(30,3);
    printf("游戏规则");

    int i,j;
    for(i=5;i<=16;i++)
    {
        for(j=13;j<=56;j++)
        {
            color(10);
            gotoxy(j,i);
            if(i==5 || i==16)
                printf("=");
            else if(j==13 || j==55)
                printf("||");              //绘制边框
        }
    }

    color(2);
    gotoxy(15,6);
    printf("tip1:玩家可以通过← →方向键来移动方块");

    color(10);
    gotoxy(15,8);
    printf("tip2:通过↑使方块旋转");

    color(6);
    gotoxy(15,10);
    printf("tip3:通过↓加速方块下落");

    color(9);
    gotoxy(15,12);
    printf("tip4:按空格键暂停游戏，再按空格键继续");

    color(4);
    gotoxy(15,14);
    printf("tip5:按ESC退出游戏");


    gotoxy(22,17);
    color(2);
    printf("按'0'返回上一级菜单[ ]\b\b");
    int a;
    scanf("%d",&a);

    switch(a)
    {
        case 0: system("cls");welcome();break;

    }
}



void MakeTeTris(struct Tetris *tetris){
    a[tetris->x][tetris->y] = b[0];
    switch(tetris->flag){
    case 1 :                                  //▇▇
        a[tetris->x+2][tetris->y] = b[1];     //▇▇
        a[tetris->x][tetris->y+1] = b[2];
        a[tetris->x+2][tetris->y+1] = b[3];
        break;
    case 2 :
        a[tetris->x-2][tetris->y] = b[1];     //▇▇▇▇
        a[tetris->x+2][tetris->y] = b[2];
        a[tetris->x+4][tetris->y] = b[3];
        break;
    case 3 :
        a[tetris->x][tetris->y-1] = b[1];     //▇
        a[tetris->x][tetris->y+1] = b[2];     //▇
        a[tetris->x][tetris->y+2] = b[3];     //▇
        break;                                //▇
    case 4 :
        a[tetris->x+2][tetris->y] = b[1];     //▇▇
        a[tetris->x][tetris->y+1] = b[2];     //▇
        a[tetris->x][tetris->y+2] = b[3];     //▇
        break;
    case 5 :
        a[tetris->x][tetris->y-1] = b[1];
        a[tetris->x+2][tetris->y] = b[2];     //▇
        a[tetris->x+4][tetris->y] = b[3];     //▇▇▇
        break;
    case 6 :
        a[tetris->x-2][tetris->y] = b[1];     //  ▇
        a[tetris->x][tetris->y-1] = b[2];     //  ▇
        a[tetris->x][tetris->y-2] = b[3];     //▇▇
        break;
    case 7 :
        a[tetris->x][tetris->y+1] = b[1];     //▇▇▇
        a[tetris->x-2][tetris->y] = b[2];     //    ▇
        a[tetris->x-4][tetris->y] = b[3];
        break;
    case 8 :
        a[tetris->x][tetris->y+1] = b[1];     //▇▇▇
        a[tetris->x+2][tetris->y] = b[2];     //▇
        a[tetris->x+4][tetris->y] = b[3];
        break;
    case 9 :
        a[tetris->x-2][tetris->y] = b[1];     //▇▇
        a[tetris->x][tetris->y+1] = b[2];     //  ▇
        a[tetris->x][tetris->y+2] = b[3];     //  ▇
        break;
    case 10 :
        a[tetris->x][tetris->y-1] = b[1];     //    ▇
        a[tetris->x-2][tetris->y] = b[2];     //▇▇▇
        a[tetris->x-4][tetris->y] = b[3];
        break;
    case 11 :
        a[tetris->x+2][tetris->y] = b[1];     //▇
        a[tetris->x][tetris->y-1] = b[2];     //▇
        a[tetris->x][tetris->y-2] = b[3];     //▇▇
        break;
    case 12 :
        a[tetris->x][tetris->y-1] = b[1];
        a[tetris->x-2][tetris->y] = b[2];     //  ▇
        a[tetris->x+2][tetris->y] = b[3];     //▇▇▇
        break;
    case 13 :
        a[tetris->x-2][tetris->y] = b[1];     //  ▇
        a[tetris->x][tetris->y-1] = b[2];     //▇▇
        a[tetris->x][tetris->y+1] = b[3];     //  ▇
        break;
    case 14 :
        a[tetris->x][tetris->y+1] = b[1];     //▇▇▇
        a[tetris->x-2][tetris->y] = b[2];     //  ▇
        a[tetris->x+2][tetris->y] = b[3];
        break;
    case 15 :
        a[tetris->x+2][tetris->y] = b[1];     //▇
        a[tetris->x][tetris->y-1] = b[2];     //▇▇
        a[tetris->x][tetris->y+1] = b[3];     //▇
        break;
    case 16 :
        a[tetris->x+2][tetris->y] = b[1];     //▇
        a[tetris->x][tetris->y-1] = b[2];     //▇▇
        a[tetris->x][tetris->y+1] = b[3];     //  ▇
        break;
    case 17 :
        a[tetris->x+2][tetris->y] = b[1];     //  ▇▇
        a[tetris->x][tetris->y-1] = b[2];     //▇▇
        a[tetris->x][tetris->y+1] = b[3];
        break;
    case 18 :
        a[tetris->x+2][tetris->y] = b[1];     //  ▇
        a[tetris->x][tetris->y-1] = b[2];     //▇▇
        a[tetris->x][tetris->y+1] = b[3];     //▇
        break;
    case 19 :
        a[tetris->x+2][tetris->y] = b[1];     //▇▇
        a[tetris->x][tetris->y-1] = b[2];     //  ▇▇
        a[tetris->x][tetris->y+1] = b[3];
        break;
    }
}


void PrintTetris(struct Tetris *tetris)
{
    for(int i=0;i<4;i++)
    {
        b[i]=1;
    }
    MakeTeTris(tetris);
    for(i=tetris->x-2;i<=tetris->x+4;i+=2)
    {
        for(j=tetris->y-2;j<=tetris->y+1;j++)
        {
            if(a[i][j]==1&& j>FrameY)
            {
                gotoxy(i,j);
                printf("■ ");
            }
        }
    }
    //打印菜单信息
    gotoxy(FrameX+2*Frame_width+3,FrameY+1);
    color(4);
    printf("level: ");
    color(12);
    printf("%d",tetris->level);

    gotoxy(FrameX+2*Frame_width+3,FrameY+3);
    color(4);
    printf("score: ");
    color(12);
    printf("%d",tetris->score);

    gotoxy(FrameX+2*Frame_width+3,FrameY+5);
    color(4);
    printf("speed: ");
    color(12);
    printf("%dms",tetris->speed);
}

/*
擦除方块移动的痕迹
*/

void CleanTetris(struct Tetris *tetris)
{
    for(i=0;i<4;i++)
    {
        b[i]=0;
    }
    MakeTeTris(tetris);
    for(i=tetris->x-2;i<=tetris->x+4;i+=2)
    {
        for(j=tetris->y-2;j<=tetris->y+1;j++)
        {
            if(a[i][j]==0&& j>FrameY)
            {
                gotoxy(i,j);
                printf(" ");
            }
        }
    }
}

/*
删除满行的方块
*/
void Del_fullline(struct Tetris *tetris)
{
    int k,del_rows=0;
    for(j=FrameY+Frame_height-1;j>=FrameY+1;j--)
    {
        k=0;
        for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
        {
            if(a[i][j]==1)
            {
                k++;
                if(k==Frame_width-2)
                {
                    for(k=FrameX+2;k<FrameX+2*Frame_width-2;k+=2)
                    {
                        a[k][j]=0;
                        gotoxy(k,j);
                        printf(" ");
                    }
                    for(k=j-1;k>FrameY;k--)
                    {
                        for(i=FrameX+2;i<FrameX+2*Frame_width-2;i+=2)
                        {
                            if(a[i][k]==1)
                            {
                                a[i][k]==0;
                                gotoxy(i,k);
                                printf(" ");
                                a[i][k+1]==1;
                                gotoxy(i,k+1);
                                printf("■");
                            }
                        }
                    }
                    j++;
                    del_rows++;
                }
            }
        }
    }
    tetris->score+=100*del_rows;
    if(del_rows>0&&(tetris->score%1000==0||tetris->score/1000>tetris->level-1))
    {
        tetris->speed-=20;
        tetris->level++;
    }
}
/*
随机产生俄罗斯方块类型的序号
*/

void Flag(struct Tetris *tetris)
{
    tetris->number++;
    srand(time(NULL));
    if(tetris->number==1)
    {
        tetris->flag=rand()%19+1;

    }
    tetris->next=rand()%19+1;
}

void Gameplay(){
    int n;
    struct Tetris t, *tetris = &t;
    tetris->number = 0;
    tetris->speed = 300;
    tetris->score = 0;
    tetris->level = 1;
    while(1){
        Flag(tetris);
        Temp = tetris->flag;
        tetris->x = FrameX+2*Frame_width+6;
        tetris->y = FrameY+10;
        tetris->flag = tetris->next;
        PrintfTeTris(tetris);
        tetris->x = FrameX+Frame_width;
        tetris->y = FrameY-1;
        tetris->flag = Temp;

        while(1){                           //控制方向，直至方块不在下移
            label:PrintfTeTris(tetris);     //打印俄罗斯方块
            Sleep(tetris->speed);           //延缓时间
            CleanTeTris(tetris);            //清除痕迹
            Temp1 = tetris->x;              //记住中心方块横坐标的值
            Temp2 = tetris->flag;           //判断是否有键盘输入，有则用ch接收
            if(kbhit()){
                ch = getch();
                if(ch==75){                 //左边
                    tetris->x-=2;
                }
                if(ch==77){                 //右边
                    tetris->x+=2;
                }
                if(ch==80){                 //向下 加速下滑
                    if(ifMove(tetris)!=0){
                        tetris->y+=2;
                    }
                    if(ifMove(tetris)==0){
                        tetris->y = FrameY+Frame_height-2;
                    }
                }
                if(ch==72){
                    if(tetris->flag>=2 && tetris->flag<=7){     //直线方块
                        tetris->flag++;
                        tetris->flag%=2;
                        tetris->flag+=2;
                    }
                    if(tetris->flag>=4 && tetris->flag<=7){     //T 方块
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=4;
                    }
                    if(tetris->flag>=8 && tetris->flag<=11){     //Z 方块
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=8;
                    }
                    if(tetris->flag>=12 && tetris->flag<=15){     // 7 方块
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=12;
                    }
                    if(tetris->flag>=16 && tetris->flag<=19){     // 反7 方块
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=16;
                    }
                }
                if(ch==32){       //空格
                    PrintfTeTris(tetris);
                    while(1){
                        if(kbhit()){            //再按空格继续游戏
                            ch=getch();
                            if(ch==32){
                                goto label;
                            }
                        }
                    }
                }
                if(ch==27){     //退出游戏
                    system("cls");
                    memset(a,0,6400*sizeof(int));       //初始化BOX数据
                    welcome();
                }
                if(ifMove(tetris)==0){     //如果不可动，上面操作无效
                    tetris->x = Temp1;
                    tetris->flag = Temp2;
                }
                else{                       //如果可动，执行操作
                    goto label;
                }
            }
            tetris->y++;            //如果没有操作指令，方块向下移动
            if(ifMove(tetris)==0){  //如果向下移动且不可动，方块放在此处
                tetris->y--;
                PrintfTeTris(tetris);
                Del_Fullline(tetris);
                break;
            }
        }
        for(i=tetris->y-2 ; i<tetris->y+2 ; i++){
            if(i==FrameY){
                system("cls");
                gotoxy(29,7);
                printf(" \n");
                color(12);
                printf("\t\t\t▇▇▇▇   ▇      ▇   ▇▇▇       /n");
                printf("\t\t\t▇         ▇▇    ▇   ▇    ▇     /n");
                printf("\t\t\t▇▇▇▇   ▇  ▇  ▇   ▇     ▇    /n");
                printf("\t\t\t▇         ▇    ▇▇   ▇    ▇     /n");
                printf("\t\t\t▇▇▇▇   ▇      ▇   ▇▇▇       /n");
                gotoxy(17,18);
                color(14);
                printf("我要重新玩一局-----------1");
                gotoxy(44，18);
                printf("不玩了，退出吧-----------2");
                int n;
                gotoxy(32,20);
                printf("选择【1/2】");
                color(11);
                scanf("%d",&n);
                switch(n){
                case 1:
                    system("cls");
                    Replay(tetris);     //重开游戏
                    break;
                case 2:
                    exit(0);
                    break;
                }
            }
        }
        tetris->flag = tetris->next;       //清除下一个俄罗斯方块的图形（右边窗口）
        tetris->x = FrameX+2*Frame_width+6;
        tetris->y = FrameY+10;
        CleanTeTris(tetris);
    }
}





int main(){
    welcome();



}







