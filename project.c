#include<stdio.h>
#include<conio.h>
void input(int a[][4])
{
    int i,j;
    a[0][0]=5;
    a[0][1]=8;
    a[0][2]=6;
    a[0][3]=9;
    a[1][0]=14;
    a[1][1]=13;
    a[1][2]=3;
    a[1][3]=1;
    a[2][0]=2;
    a[2][1]=7;
    a[2][2]=15;
    a[2][3]=4;
    a[3][0]=12;
    a[3][1]=11;
    a[3][2]=10;
    a[3][3]=0;
}
void display(int a[][4])
{
    int i,j;
    printf("\n---------------------\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            printf("|%3c",' ');
          else
         printf(" |%3d" ,a[i][j]);
        }
        printf("|\n");
    }
    printf("\n--------------------\n");
}
int  check(int x[][4])
{
    int a[4][4],i,j;
    int k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            k++;
            a[i][j]=k;
        }
    }
    a[3][3]=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]!=x[i][j])
                return(-1);
        }
    }
    return(0);
}
void play(int a[][4])
{
    int i=3,j=3,temp,t=3,m=156,key=0,flag=0;
    unsigned char ch;
    char name[50];
    printf("ENTER PLAYER NAME");
     fgets(name,50,stdin);
    printf("\n LETS START THE GAME BY PRESSING YOUR CHOOSE ARROW KEY");
    ch=_getch();
    while(m>0)
    {
     printf("  HELLO  %s ",name);
     printf(" MOVE REMAMING IS %d",m);
     ch= _getch();
     system("cls");
     display(a);
     if(ch==0||ch==224)
     {
        switch(_getch())
     {
            // right
            case 77: if(j>0)
                    {
                    t=j-1;
                    temp=a[i][j];
                    a[i][j]=a[i][t];
                    a[i][t]=temp;
                    j--;
                    flag++;
                    }
                    break;
            // LEFT

            case 75: if(j<3)
                    {
                    t=j+1;
                    temp=a[i][j];
                    a[i][j]=a[i][t];
                    a[i][t]=temp;
                    j++;
                    }
                    break;
            // DOWN

            case 80:if(i<3)
                    {
                    t=i+1;
                    temp=a[i][j];
                    a[i][j]=a[t][j];
                    a[t][j]=temp;
                    i++;
                    }
                    break;
           // UP
            case 72:
                   if(flag)
                   {
                   if(i>0)
                   {
                   t=i-1;
                   temp=a[i][j];
                   a[i][j]=a[t][j];
                   a[t][j]=temp;
                   i--;
                   break;
                   }
                   }
    }
    }
    m--;
    key=check(a);
    if(key==0)
    {
        break;
    }
    }
    if(m==0)
        printf("YOU LOOSE");
}
void cond()
{
    system("COLOR FC");
    printf("\t \t \t RULE OF THE GAME");
    printf("\n 1. You can move only 1 step at time by arrow key");
    printf("\n Move Up: by arrow key");
    printf("\n Move down: by Down key");
    printf("\n Move left: by Left key");
    printf("\n Move Right: by Right key");
    printf("\n \n 2. You can move number at empty position only");
    printf("\n \n 3. For each valid move : your total number of move will decreased by 1");
    printf("\n 4.Winning situation : number in a 4*4 matrix should be  in order from 1 to 15");
    printf("\n 5. You can exit the game at any time by pressing e or E so try to win in minimum number of move");
    printf("\n \n \n \t \t HAPPY GAMING, GOOD LUCK");
    printf("enter any key to start");
    getch();
}
int main()
{
    int a[4][4],i,j;
    cond();
    printf("\n \n ");
    input(a);
    play(a);
    getch();
}
