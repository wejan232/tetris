#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define FrameX 13
#define FrameY 3
#define Frame_height 20
#define Frame_width 18

int i,j,Temp,Temp1,Temp2;
int a[80][80]={0};//0�޷��� 1�з��� 2�߿�
int b[4];//�������� 0�޷��� 1�з���
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

HANDLE hOut;//����̨�ֱ���λ�ã���ɫ


int color(int c);                       //��ɫ����
void gotoxy(int x,int y);               //���λ��
void ShowGameframe();                   //��ʾ��Ϸ����
void Flag(struct Tetris *);             //��������
void MakeTeTris(struct Tetris *);       //��������
void PrintfTeTris(struct Tetris *);     //��ӡ����
void CleanTeTris(struct Tetris *);      //��������ƶ��ۼ�
int ifMove(struct Tetris *);            //�ж��Ƿ�����ƶ�
void Del_Fullline(struct Tetris *);     //������з���
void Gameplay();                        //��ʼ��Ϸ
void regulation();                      //��Ϸ�������
void explation();                       //��Ϸ˵������
void welcome();                         //��ӭ���棨�׽��棩
void Replace(struct Tetris *);          //���¿�ʼ��Ϸ
void title();                           //����
void flower();                          //�ַ���
void close();                           //�˳���Ϸ

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
    printf("Ȥ ζ �� �� ˹ �� ��");        //����

    color(11);
    gotoxy(18,5);
    printf("��");
    gotoxy(18,6);
    printf("����");           //��
    gotoxy(18,7);           //�� ��
    printf("��");            //��

    color(6);
    gotoxy(26,6);
    printf("����");
    gotoxy(28,7);           //�� ��
    printf("����");           //  �� ��

    color(10);
    gotoxy(36,6);
    printf("����");
    gotoxy(36,7);           //�� ��
    printf("����");           //�� ��

    color(13);
    gotoxy(46,5);
    printf("��");
    gotoxy(46,6);           //��
    printf("��");            //��
    gotoxy(46,7);           //��
    printf("��");            //��

    color(4);
    gotoxy(60,6);
    printf("��");
    gotoxy(56,7);           //    ��
    printf("������");          //�� �� ��
}




void ShowGameframe(){
    color(9);
    gotoxy(FrameX+Frame_width-7,FrameY-2);
    printf("����˹����");

    color(4);
    gotoxy(FrameX,FrameY);
    printf("�X ");
    gotoxy(FrameX+2*Frame_width-2,FrameY);
    printf("�[ ");
    gotoxy(FrameX,FrameY+Frame_height);
    printf("�^ ");
    gotoxy(FrameX+2*Frame_width-2,FrameY+Frame_height);
    printf("�a ");

    for(i=2;i<2*Frame_width-2;i+=2){    //�ϱ߿�
        gotoxy(FrameX+i,FrameY);
        printf("�� ");
    }

    for(i=2;i<2*Frame_width-2;i+=2){    //�±߿�
        gotoxy(FrameX+i,FrameY+Frame_height);
        printf("�� ");
    }

    for(i=1;i<Frame_height;i++){    //��߿�
        gotoxy(FrameX,FrameY+i);
        printf("��");
    }

    for(i=1;i<Frame_height;i++){    //�ұ߿�
        gotoxy(FrameX+2*Frame_width-2,FrameY+i);
        printf("��");
    }


    color(10);
    gotoxy(FrameX+2*Frame_width+6,FrameY+8);
    printf("��һ������");
    gotoxy(FrameX+2*Frame_width+3,FrameY+9);
    printf("******************");
    gotoxy(FrameX+2*Frame_width+3,FrameY+14);
    printf("******************");


    color(6);
    gotoxy(FrameX+2*Frame_width+6,FrameY+Frame_height-4);
    printf("��Ϸ��ʾ��");
    gotoxy(FrameX+2*Frame_width+3,FrameY+Frame_height-3);
    printf("1��ESC�˳���Ϸ");
    gotoxy(FrameX+2*Frame_width+3,FrameY+Frame_height-2);
    printf("2������ת�������ƶ�");
    gotoxy(FrameX+2*Frame_width+3,FrameY+Frame_height-1);
    printf("3���ո���ͣ");




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
                printf("||");               //���Ʊ߿�

        }
    }

    color(4);
    gotoxy(25,12);
    printf("1.��ʼ��Ϸ");
    gotoxy(40,12);
    printf("2.����˵��");
    gotoxy(25,17);
    printf("3.��Ϸ����");
    gotoxy(40,17);
    printf("4.�˳�");

    gotoxy(27,22);
    color(2);
    printf("��ѡ��[1 2 3 4]:[ ]\b\b");
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
    printf("@");            //���ƺ�ɫ�ַ���

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
    printf("|");                    //����֮�������

    color(2);
    gotoxy(67,18);
    printf("\\\\\\\\");
    gotoxy(72,18);
    printf(" //");
    color(2);
    gotoxy(67,19);
    printf("^^^^^^^^");             //�ݵ�


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
    printf("@");                //������ɫ�ַ���

}


void regulation()
{
    color(4);
    gotoxy(28,3);
    printf("��Ϸ����");

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
                printf("||");                   //���Ʊ߿�

        }

    }
    color(4);
    gotoxy(7,6);
    printf("tip1:��ͬ��״��С�������Ļ�Ϸ����£����ͨ��");
    gotoxy(12,8);
    printf("���������λ�úͷ���ʹ��������Ļ�ײ�ƴ");
    gotoxy(12,10);
    printf("��������һ������");

    color(6);
    gotoxy(7,12);
    printf("tip2:ÿ����һ�У�������100");

    color(2);
    gotoxy(7,14);
    printf("tip3:ÿ�ۼ�1000�֣�������һ���ȼ�");

    gotoxy(7,16);
    printf("tip4:�����ȼ���ʹ���������ٶȼӿ���Ϸ�ѶȼӴ�");
    getchar();

    gotoxy(21,19);
    color(2);
    printf("��'0'������һ���˵�[ ]\b\b");
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
    printf("��Ϸ����");

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
                printf("||");              //���Ʊ߿�
        }
    }

    color(2);
    gotoxy(15,6);
    printf("tip1:��ҿ���ͨ���� ����������ƶ�����");

    color(10);
    gotoxy(15,8);
    printf("tip2:ͨ����ʹ������ת");

    color(6);
    gotoxy(15,10);
    printf("tip3:ͨ�������ٷ�������");

    color(9);
    gotoxy(15,12);
    printf("tip4:���ո����ͣ��Ϸ���ٰ��ո������");

    color(4);
    gotoxy(15,14);
    printf("tip5:��ESC�˳���Ϸ");


    gotoxy(22,17);
    color(2);
    printf("��'0'������һ���˵�[ ]\b\b");
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
    case 1 :                                  //�~�~
        a[tetris->x+2][tetris->y] = b[1];     //�~�~
        a[tetris->x][tetris->y+1] = b[2];
        a[tetris->x+2][tetris->y+1] = b[3];
        break;
    case 2 :
        a[tetris->x-2][tetris->y] = b[1];     //�~�~�~�~
        a[tetris->x+2][tetris->y] = b[2];
        a[tetris->x+4][tetris->y] = b[3];
        break;
    case 3 :
        a[tetris->x][tetris->y-1] = b[1];     //�~
        a[tetris->x][tetris->y+1] = b[2];     //�~
        a[tetris->x][tetris->y+2] = b[3];     //�~
        break;                                //�~
    case 4 :
        a[tetris->x+2][tetris->y] = b[1];     //�~�~
        a[tetris->x][tetris->y+1] = b[2];     //�~
        a[tetris->x][tetris->y+2] = b[3];     //�~
        break;
    case 5 :
        a[tetris->x][tetris->y-1] = b[1];
        a[tetris->x+2][tetris->y] = b[2];     //�~
        a[tetris->x+4][tetris->y] = b[3];     //�~�~�~
        break;
    case 6 :
        a[tetris->x-2][tetris->y] = b[1];     //  �~
        a[tetris->x][tetris->y-1] = b[2];     //  �~
        a[tetris->x][tetris->y-2] = b[3];     //�~�~
        break;
    case 7 :
        a[tetris->x][tetris->y+1] = b[1];     //�~�~�~
        a[tetris->x-2][tetris->y] = b[2];     //    �~
        a[tetris->x-4][tetris->y] = b[3];
        break;
    case 8 :
        a[tetris->x][tetris->y+1] = b[1];     //�~�~�~
        a[tetris->x+2][tetris->y] = b[2];     //�~
        a[tetris->x+4][tetris->y] = b[3];
        break;
    case 9 :
        a[tetris->x-2][tetris->y] = b[1];     //�~�~
        a[tetris->x][tetris->y+1] = b[2];     //  �~
        a[tetris->x][tetris->y+2] = b[3];     //  �~
        break;
    case 10 :
        a[tetris->x][tetris->y-1] = b[1];     //    �~
        a[tetris->x-2][tetris->y] = b[2];     //�~�~�~
        a[tetris->x-4][tetris->y] = b[3];
        break;
    case 11 :
        a[tetris->x+2][tetris->y] = b[1];     //�~
        a[tetris->x][tetris->y-1] = b[2];     //�~
        a[tetris->x][tetris->y-2] = b[3];     //�~�~
        break;
    case 12 :
        a[tetris->x][tetris->y-1] = b[1];
        a[tetris->x-2][tetris->y] = b[2];     //  �~
        a[tetris->x+2][tetris->y] = b[3];     //�~�~�~
        break;
    case 13 :
        a[tetris->x-2][tetris->y] = b[1];     //  �~
        a[tetris->x][tetris->y-1] = b[2];     //�~�~
        a[tetris->x][tetris->y+1] = b[3];     //  �~
        break;
    case 14 :
        a[tetris->x][tetris->y+1] = b[1];     //�~�~�~
        a[tetris->x-2][tetris->y] = b[2];     //  �~
        a[tetris->x+2][tetris->y] = b[3];
        break;
    case 15 :
        a[tetris->x+2][tetris->y] = b[1];     //�~
        a[tetris->x][tetris->y-1] = b[2];     //�~�~
        a[tetris->x][tetris->y+1] = b[3];     //�~
        break;
    case 16 :
        a[tetris->x+2][tetris->y] = b[1];     //�~
        a[tetris->x][tetris->y-1] = b[2];     //�~�~
        a[tetris->x][tetris->y+1] = b[3];     //  �~
        break;
    case 17 :
        a[tetris->x+2][tetris->y] = b[1];     //  �~�~
        a[tetris->x][tetris->y-1] = b[2];     //�~�~
        a[tetris->x][tetris->y+1] = b[3];
        break;
    case 18 :
        a[tetris->x+2][tetris->y] = b[1];     //  �~
        a[tetris->x][tetris->y-1] = b[2];     //�~�~
        a[tetris->x][tetris->y+1] = b[3];     //�~
        break;
    case 19 :
        a[tetris->x+2][tetris->y] = b[1];     //�~�~
        a[tetris->x][tetris->y-1] = b[2];     //  �~�~
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
                printf("�� ");
            }
        }
    }
    //��ӡ�˵���Ϣ
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
���������ƶ��ĺۼ�
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
ɾ�����еķ���
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
                                printf("��");
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
�����������˹�������͵����
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




int main(){
    welcome();



}






