void regulation()                           //��Ϸ������
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


void explation()                            //��Ϸ����˵������
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
