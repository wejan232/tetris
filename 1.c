#include<stdio.h>
#include<windows.h>


int color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
    return 0;
}

void main(){
    color(0);
    printf("0ºÅ\n");
    color(1);
    printf("1ºÅ\n");
    color(2);
    printf("2ºÅ\n");
    color(3);
    printf("3ºÅ\n");
    color(4);
    printf("4ºÅ\n");
    color(5);
    printf("5ºÅ\n");
    color(6);
    printf("6ºÅ\n");
    color(7);
    printf("7ºÅ\n");
    color(8);
    printf("8ºÅ\n");
    color(9);
    printf("9ºÅ\n");
    color(10);
    printf("10ºÅ\n");
    color(11);
    printf("11ºÅ\n");
    color(12);
    printf("12ºÅ\n");
    color(13);
    printf("13ºÅ\n");

}
