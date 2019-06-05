void regulation()                           //游戏规格界面
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


void explation()                            //游戏按键说明界面
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
