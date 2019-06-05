
int ifMove(struct Tetris *tetris){          //ÅÐ¶Ï·½¿éÄÜ·ñÒÆ¶¯
    if(a[tetris->x][tetris->y] != 0){
        return 0;
    }
    else {
         if(tetris->flag == 1 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0)  ||
            (tetris->flag == 2 && (a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y]==0 && a[tetris->x+4][tetris->y]==0))  ||
             (tetris->flag == 3 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x][tetris->y-2]==0 && a[tetris->x][tetris->y+1]==0))  ||
              (tetris->flag == 4 && (a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y]==0 && a[tetris->x][tetris->y+1]==0))  ||
               (tetris->flag == 5 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y]==0))  ||
                (tetris->flag == 6 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y]==0))  ||
                 (tetris->flag == 7 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0))  ||
                  (tetris->flag == 8 && (a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y+1]==0))  ||
                   (tetris->flag == 9 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x-2][tetris->y]==0 && a[tetris->x-2][tetris->y+1]==0))  ||
                    (tetris->flag == 10 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0))  ||
                     (tetris->flag == 11 && (a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y-1]==0 && a[tetris->x-2][tetris->y]==0))  ||
                      (tetris->flag == 12 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y-1]==0))  ||
                       (tetris->flag == 13 && (a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0))  ||
                        (tetris->flag == 14 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y+1]==0))  ||
                         (tetris->flag == 15 && (a[tetris->x-2][tetris->y]==0 && a[tetris->x-2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0))  ||
                          (tetris->flag == 16 && (a[tetris->x][tetris->y+1]==0 && a[tetris->x][tetris->y-1]==0 && a[tetris->x+2][tetris->y-1]==0))  ||
                           (tetris->flag == 17 && (a[tetris->x-2][tetris->y+1]==0 && a[tetris->x+2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0))  ||
                            (tetris->flag == 18 && (a[tetris->x][tetris->y-1]==0 && a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y+1]==0))  ||
                             (tetris->flag == 19 && (a[tetris->x-2][tetris->y]==0 && a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0))
             ){return 1;}
    }
    return 0;
}

void CleanTetris(struct Tetris *tetris)     //²Á³ý·½¿éÒÆ¶¯µÄºÛ¼£
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

void Del_Fullline(struct Tetris *tetris)    //É¾³ýÂúÐÐµÄ·½¿é
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
                                printf("¡ö ");
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

