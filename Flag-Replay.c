void Flag(struct Tetris *tetris)            //�����������˹�������͵����
{
    tetris->number++;
    srand(time(NULL));
    if(tetris->number==1)
    {
        tetris->flag=rand()%19+1;

    }
    tetris->next=rand()%19+1;
}

void Gameplay(){                            //��ʼ��Ϸ
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

        while(1){                           //���Ʒ���ֱ�����鲻������
            label:PrintTetris(tetris);      //��ӡ����˹����
            Sleep(tetris->speed);           //�ӻ�ʱ��
            CleanTetris(tetris);            //����ۼ�
            ShowGameframe();                //���´�ӡ��Ϸ�߿�
            Temp1 = tetris->x;              //��ס���ķ���������ֵ
            Temp2 = tetris->flag;           //�ж��Ƿ��м������룬������ch����
            if(kbhit()){
                ch = getch();
                if(ch==75){                 //������������
                    tetris->x-=2;
                }
                if(ch==77){                 //������������
                    tetris->x+=2;
                }
                if(ch==80){                 //���� �����»�
                    if(ifMove(tetris)!=0){
                        tetris->y+=2;
                    }
                    if(ifMove(tetris)==0){
                        tetris->y = FrameY+Frame_height-2;  //��ֹһֱ������������߽�
                    }
                }
                if(ch==72){                                     //�����任
                    if(tetris->flag>=2 && tetris->flag<=3){     //ֱ�߷���
                        tetris->flag++;
                        tetris->flag%=2;
                        tetris->flag+=2;
                    }
                    if(tetris->flag>=4 && tetris->flag<=7){     //T ����
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=4;
                    }
                    if(tetris->flag>=8 && tetris->flag<=11){     //Z ����
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=8;
                    }
                    if(tetris->flag>=12 && tetris->flag<=15){     // 7 ����
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=12;
                    }
                    if(tetris->flag>=16 && tetris->flag<=19){     // ��7 ����
                        tetris->flag++;
                        tetris->flag%=4;
                        tetris->flag+=16;
                    }
                }
                if(ch==32){       //�ո�
                    PrintTetris(tetris);
                    while(1){
                        if(kbhit()){            //�ٰ��ո������Ϸ
                            ch=getch();
                            if(ch==32){
                                goto label;
                            }
                        }
                    }
                }
                if(ch==27){     //�˳���Ϸ
                    system("cls");
                    memset(a,0,6400*sizeof(int));       //��ʼ��BOX����
                    welcome();
                }
                if(ifMove(tetris)==0){     //������ɶ������������Ч
                    tetris->x = Temp1;
                    tetris->flag = Temp2;
                }
                else{                       //����ɶ���ִ�в���
                    goto label;
                }
            }
            tetris->y++;            //���û�в���ָ����������ƶ�
            if(ifMove(tetris)==0){  //��������ƶ��Ҳ��ɶ���������ڴ˴�
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
                printf("\t\t\t�~�~�~�~   �~      �~   �~�~�~       /n");
                printf("\t\t\t�~         �~�~    �~   �~    �~     /n");
                printf("\t\t\t�~�~�~�~   �~  �~  �~   �~     �~    /n");
                printf("\t\t\t�~         �~    �~�~   �~    �~     /n");
                printf("\t\t\t�~�~�~�~   �~      �~   �~�~�~       /n");
                gotoxy(17,18);
                color(14);
                printf("��Ҫ������һ��-----------1");
                gotoxy(44,18);
                printf("�����ˣ��˳���-----------2");
                int n;
                gotoxy(32,20);
                printf("ѡ��[1/2]");
                color(11);
                scanf("%d",&n);
                switch(n){
                case 1:
                    system("cls");
                    Replay(tetris);     //�ؿ���Ϸ
                    break;
                case 2:
                    exit(0);
                    break;
                }
            }
        }
        tetris->flag = tetris->next;       //�����һ������˹�����ͼ�Σ��ұߴ��ڣ�
        tetris->x = FrameX+2*Frame_width+10;
        tetris->y = FrameY+11;
        CleanTetris(tetris);
    }
}

void Replay(struct Tetris *tetris){         //���¿�ʼ
    system("cls");
    memset(a,0,6400*sizeof(int));
    ShowGameframe();
    Gameplay();
}

