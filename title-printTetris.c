void title()                                //����
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

void flower()                               //�ַ���
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

void welcome()                              //��ӭ����
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
        case 1: system("cls");ShowGameframe();Gameplay();break;
        case 2: system("cls");explation();break;
        case 3: system("cls");regulation();break;
        case 4: system("cls");close();break;

    }
}

void ShowGameframe(){                       //��ʾ��Ϸ����
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
        a[FrameX+i][FrameY+Frame_height] = 2;
    }

    for(i=1;i<Frame_height;i++){    //��߿�
        gotoxy(FrameX,FrameY+i);
        printf("��");
        a[FrameX][FrameY+i] = 2;
    }

    for(i=1;i<Frame_height;i++){    //�ұ߿�
        gotoxy(FrameX+2*Frame_width-2,FrameY+i);
        printf("��");
        a[FrameX+2*Frame_width-2][FrameY+i] = 2;
    }


    color(10);
    gotoxy(FrameX+2*Frame_width+6,FrameY+7);
    printf("��һ������");
    gotoxy(FrameX+2*Frame_width+3,FrameY+8);
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


void MakeTeTris(struct Tetris *tetris){     //��������˹����
    a[tetris->x][tetris->y] = b[0];
    switch(tetris->flag){
    case 1 :
        a[tetris->x][tetris->y-1] = b[1];     //�~�~
        a[tetris->x+2][tetris->y-1] = b[2];   //�~�~
        a[tetris->x+2][tetris->y] = b[3];
        break;
    case 2 :
        a[tetris->x-2][tetris->y] = b[1];     //�~�~�~�~
        a[tetris->x+2][tetris->y] = b[2];
        a[tetris->x+4][tetris->y] = b[3];
        break;
    case 3 :
        a[tetris->x][tetris->y-1] = b[1];     //�~
        a[tetris->x][tetris->y-2] = b[2];     //�~
        a[tetris->x][tetris->y+1] = b[3];     //�~
        break;                                //�~
    case 4 :
        a[tetris->x-2][tetris->y] = b[1];     //�~�~�~
        a[tetris->x+2][tetris->y] = b[2];     //  �~
        a[tetris->x][tetris->y+1] = b[3];
        break;
    case 5 :
        a[tetris->x][tetris->y-1] = b[1];     //  �~
        a[tetris->x][tetris->y+1] = b[2];     //�~�~
        a[tetris->x-2][tetris->y] = b[3];     //  �~
        break;

    case 6 :
        a[tetris->x][tetris->y-1] = b[1];     //  �~
        a[tetris->x-2][tetris->y] = b[2];     //�~�~�~
        a[tetris->x+2][tetris->y] = b[3];
        break;


    case 7 :
        a[tetris->x][tetris->y-1] = b[1];     //�~
        a[tetris->x][tetris->y+1] = b[2];     //�~�~
        a[tetris->x+2][tetris->y] = b[3];     //�~
        break;
    case 8 :
        a[tetris->x][tetris->y+1] = b[1];   //  �~�~
        a[tetris->x-2][tetris->y] = b[2];   //�~�~
        a[tetris->x+2][tetris->y+1] = b[3];
        break;
    case 9 :
        a[tetris->x][tetris->y-1] = b[1];     //  �~
        a[tetris->x-2][tetris->y] = b[2];     //�~�~
        a[tetris->x-2][tetris->y+1] = b[3];   //�~
        break;
    case 10 :
        a[tetris->x][tetris->y-1] = b[1];     //�~�~
        a[tetris->x-2][tetris->y-1] = b[2];   //  �~�~
        a[tetris->x+2][tetris->y] = b[3];
        break;
    case 11 :
        a[tetris->x][tetris->y+1] = b[1];     //�~
        a[tetris->x-2][tetris->y-1] = b[2];   //�~�~
        a[tetris->x-2][tetris->y] = b[3];     //  �~
        break;
    case 12 :
        a[tetris->x][tetris->y-1] = b[1];     //�~�~
        a[tetris->x][tetris->y+1] = b[2];     //  �~
        a[tetris->x-2][tetris->y-1] = b[3];   //  �~
        break;



    case 13 :
        a[tetris->x-2][tetris->y] = b[1];     //    �~
        a[tetris->x+2][tetris->y-1] = b[2];   //�~�~�~
        a[tetris->x+2][tetris->y] = b[3];
        break;
    case 14 :
        a[tetris->x][tetris->y-1] = b[1];     //�~
        a[tetris->x][tetris->y+1] = b[2];     //�~
        a[tetris->x+2][tetris->y+1] = b[3];   //�~�~
        break;
    case 15 :
        a[tetris->x-2][tetris->y] = b[1];     //�~�~�~
        a[tetris->x-2][tetris->y+1] = b[2];   //�~
        a[tetris->x+2][tetris->y] = b[3];
        break;
    case 16 :
        a[tetris->x][tetris->y+1] = b[1];     //�~�~
        a[tetris->x][tetris->y-1] = b[2];     //�~
        a[tetris->x+2][tetris->y-1] = b[3];   //�~
        break;
    case 17 :
        a[tetris->x-2][tetris->y] = b[1];     //�~�~�~
        a[tetris->x+2][tetris->y+1] = b[2];   //    �~
        a[tetris->x+2][tetris->y] = b[3];
        break;
    case 18 :
        a[tetris->x][tetris->y-1] = b[1];     //  �~
        a[tetris->x][tetris->y+1] = b[2];     //  �~
        a[tetris->x-2][tetris->y+1] = b[3];   //�~�~
        break;
    case 19 :
        a[tetris->x-2][tetris->y] = b[1];     //�~
        a[tetris->x-2][tetris->y-1] = b[2];   //�~�~�~
        a[tetris->x+2][tetris->y] = b[3];

    }
}

void PrintTetris(struct Tetris *tetris)     //��ӡ����˹����
{
    int i;
    for(i=0;i<4;i++)
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

