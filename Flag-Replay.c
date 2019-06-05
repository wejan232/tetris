void Flag(struct Tetris *tetris)            //随机产生俄罗斯方块类型的序号
{
    tetris->number++;
    srand(time(NULL));
    if(tetris->number==1)
    {
        tetris->flag=rand()%19+1;

    }
    tetris->next=rand()%19+1;
}

void Gameplay(){                            //开始游戏
    int n;
    struct Tetris t, *tetris = &t;
    tetris->number = 0;
    tetris->speed = 300;
    tetris->score = 0;
    tetris->level = 1;
    while(1){
        Flag(tetris);
        Temp = tetris->flag;
        tetris->x = FrameX+2*Frame_width+10;
        tetris->y = FrameY+11;
        tetris->flag = tetris->next;
        PrintTetris(tetris);
        tetris->x = FrameX+Frame_width;
        tetris->y = FrameY-1;
        tetris->flag = Temp;

        while(1){                           //控制方向，直至方块不在下移
            label:PrintTetris(tetris);      //打印俄罗斯方块
            Sleep(tetris->speed);           //延缓时间
            CleanTetris(tetris);            //清除痕迹
            ShowGameframe();                //重新打印游戏边框
            Temp1 = tetris->x;              //记住中心方块横坐标的值
            Temp2 = tetris->flag;           //判断是否有键盘输入，有则用ch接收
            if(kbhit()){
                ch = getch();
                if(ch==75){                 //按←键向左移
                    tetris->x-=2;
                }
                if(ch==77){                 //按→键向右移
                    tetris->x+=2;
                }
                if(ch==80){                 //按↓ 加速下滑
                    if(ifMove(tetris)!=0){
                        tetris->y+=2;
                    }
                    if(ifMove(tetris)==0){
                        tetris->y = FrameY+Frame_height-2;  //防止一直按↓方块掉出边界
                    }
                }
                if(ch==72){                                     //按↑变换
                    if(tetris->flag>=2 && tetris->flag<=3){     //直线方块
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
                    PrintTetris(tetris);
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
                PrintTetris(tetris);
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
                gotoxy(44,18);
                printf("不玩了，退出吧-----------2");
                int n;
                gotoxy(32,20);
                printf("选择[1/2]");
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
        tetris->x = FrameX+2*Frame_width+10;
        tetris->y = FrameY+11;
        CleanTetris(tetris);
    }
}

void Replay(struct Tetris *tetris){         //重新开始
    system("cls");
    memset(a,0,6400*sizeof(int));
    ShowGameframe();
    Gameplay();
}

