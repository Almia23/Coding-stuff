#include <stdio.h>
#include <string.h>
#include <curses.h>
int main()
{
    char pw[10],un[10],ch;
    int i;
    initscr();
    printw("Enter username: \n");
    refresh();
    gets(un);
    printw("Enter password (6 digits)\n");
    refresh();
    for(i=0; i<6;i++)
    {
        pw[i]=getch();
        printf("*");
        refresh();
    }
    printf("\nYour password is: ");
    puts(pw);
    refresh();
    endwin();

    return 0;
}