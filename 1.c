#include<stdio.h>
#include<windows.h>


int color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
    return 0;
}

void main(){
    color(0);
    printf("0��\n");
    color(1);
    printf("1��\n");
    color(2);
    printf("2��\n");
    color(3);
    printf("3��\n");
    color(4);
    printf("4��\n");
    color(5);
    printf("5��\n");
    color(6);
    printf("6��\n");
    color(7);
    printf("7��\n");
    color(8);
    printf("8��\n");
    color(9);
    printf("9��\n");
    color(10);
    printf("10��\n");
    color(11);
    printf("11��\n");
    color(12);
    printf("12��\n");
    color(13);
    printf("13��\n");

}
