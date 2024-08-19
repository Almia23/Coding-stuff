/*Declare a structure called cricket that contains the following details, Player name, team name, batting average. Create a player array with 30 players of the
type cricket. Write a C program to read details of players and print a team-wise
sorted list containing player’s names and batting average.*/

struct cricket{
    char name[20];
    char tname[20];
    int bavg;
};
#include <stdio.h>
#include <string.h>
int main()
{
    int n,i;
    char tlist[10][20];
    printf("Enter number of players: \n");
    scanf("%d",&n);
    struct cricket players[n],t;
    printf("Enter Name, Team name, Batting average\n");
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d",&players[i].name,&players[i].tname,&players[i].bavg);
    }
    
    //sorting
    for(i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(strcmp(players[j-1].tname,players[j].tname)>0)
			{
				t=players[j-1];
				players[j-1]=players[j];
				players[j]=t;
			}
		}
	}

    printf("After sorting: ");
    for(i=0;i<n;i++)
    printf("\n%s %s %d",players[i].name,players[i].tname,players[i].bavg);
    return 0;
}