
#ifndef GETCH_H_INCLUDED
#define GETCH_H_INCLUDED


#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>


int ch;
unsigned long wait=0;


int kbhit(void)
{
  struct termios oldt, newt;
  int oldf;


  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);


  ch = getchar();


  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);


  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }


  return 0;
}
#endif // GETCH_H_INCLUDED
 

int main(int argc, char *argv[])
{
    char pw[10],un[10];
    int i;
    printf("Enter username: \n");
    gets(un);
    printf("Enter password (6 digits)\n");
    for(i=0; i<6;i++)
    {
        while (!kbhit())
        {
            pw[i]=ch;
        }
    
        fseek(stdin,0,SEEK_END);
    }
    printf("\nYour password is: ");
    puts(pw);
    return 0;
    
}
