#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
void hidecursor() {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void getup() {
    system("cls");
    gotoxy(10, 2);
    printf("Press X to Exit, Press Space to Jump");
    gotoxy(62, 2);
    printf("SCORE : ");
    gotoxy(1, 26);
    for (int x = 0; x < 79; x++)
        printf("-");
    hidecursor();
}
int t, speed = 50;
void ds(int jump = 0) {
    hidecursor();
    if (jump == 0)
        t = 0;
    else if (jump == 2)
        t--;
    else
        t++;
    gotoxy(20, 25 - t);
    if (jump != 0) {
        hidecursor();
        printf(" ");
    } 
    gotoxy(20, 24 - t);
    hidecursor();
    printf("S");
    delay(speed);
}
void obj() {
    hidecursor();
	 static int x=0,scr=0;
    if(x==56 && t<4)
    {
    scr=0;
    speed=50;
    gotoxy(36,8);
    printf("Game Over");
    getch();
    gotoxy(36,8);
    printf("          ");
    }
    gotoxy(73-x,24);
    printf("  x  " );
    x++;
    if(x==3){
    	gotoxy(3,24);
    	printf(" ");
	}
    if(x==73)
    {
    x=0;
    scr++;
    gotoxy(70,2);
    printf("     ");
    gotoxy(70,2);
    printf("%d",scr);
    if(speed>20)
        speed--;
    }
}
int main() {
    system("mode con: lines=29 cols=82");
    char ch;
    int i;
    hidecursor();
    getup();
    while (true) {
        hidecursor();
        while (!kbhit()) {
            hidecursor();
            ds();
            obj();
        }
        ch = getch();
        if (ch == ' ') {
            for (i = 0; i < 5; i++) {
                ds(1);
                obj();
            }
            for (i = 0; i < 5; i++) {
            ds(2);
              obj(); }
        } else if (ch == 'x')
            return (0);
    }
}
