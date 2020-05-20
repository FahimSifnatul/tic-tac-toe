#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int easy(char name[],int *won,int *lost,int *draw);
int hard(char name[],int *won,int *lost,int *draw);
int twoplayers(char name1[],char name2[],int *won,int *lost,int *draw);
int settings(char name[],int *won,int *lost,int *draw,int *eh);
int settings(char name1[],char name[],int *won,int *lost,int *draw,int *eh);
int main()
{
    int i,j,n,cnt=1,d,won=0,lost=0,draw=0,eh=1;
    char name[255],name1[255],name2[255];

  printf("**********WELCOME TO THE GAME TIC-TAC-TOE**********\n\n");
  printf("At first, i am requesting to read the below manual very carefully\n");
  printf("\nSECTION 1(how to play):\n");
  printf(" | |\n-----\n | |\n-----\n | |\n");
  printf("\nabove platform is the tic-tac-toe platform\n");
  printf("\n1|2|3\n-----\n4|5|6\n-----\n7|8|9\n");
  printf("\nin above platform numbering is done. your work is to press the button between 1 to 9 where you want to put your X or O.\n");
  printf("and one thing to remember that if you play the game first time then by default the game mode be easy and against computer. you can change game mode in settings.\n");
  printf("\nSECTION 2(settings):\n");
  printf("in settings, you can change the player name, reset the trophy won, match lost ,game mode, difficulty level\n");
  printf("so no more talking. just play and have fun. And of course, never forget to give me a feedback ;)\n");

  while(true)
  {
  printf("\nWhat do you want to do?\n");
  printf("1.Play Game\n");
  printf("2.settings\n");
  printf("3.exit\n");
  printf("Enter your choice = ");
  scanf("%d",&n);
      if(n==1)
       {
         if(eh==1)
         {
           if(won+lost+draw==0)
           {
              printf("\nplayer name = ");
              scanf(" %[^\n]",name);
              cout<<endl;
              ++cnt;
           }
            easy(name,&won,&lost,&draw);
         }

         else if(eh==2)
         {
          if(won+lost+draw==0)
           {
              printf("\nplayer name = ");
              scanf(" %[^\n]",name);
              cout<<endl;
              ++cnt;
           }
             hard(name,&won,&lost,&draw);
         }
         else if(eh==3)
            twoplayers(name1,name2,&won,&lost,&draw);
       }
      else if(n==2)
      {
        if(eh==1 or eh==2)
        settings(name,&won,&lost,&draw,&eh);
        else
        settings(name1,name2,&won,&lost,&draw,&eh);
      }
      else if(n==3)
      {
          printf("\nthanks for visiting us ^_^ .....\n");
          break;
      }
      else
      {
           printf("\ninvalid choice and exit the game\n");
           break;
      }
      ++cnt;
      //cout<<won<<"  "<<lost<<"  "<<draw<<" "<<eh<<endl;
  }
  return 0;
}


int easy(char *name,int *won, int *lost,int *draw)
{
   int sym,cnt=0,flag=0;
   char c1,c2,ttt[5][5]={{' ','|',' ','|',' '},{'-','-','-','-','-'},{' ','|',' ','|',' '},{'-','-','-','-','-'},{' ','|',' ','|',' '}};
   printf("choose your symbol---->\n1. X\n2. O\n");
   printf("enter your choice = ");
   scanf("%d",&sym);
   if(sym==1)
   {
      c1='X';
      c2='O';
   }

   else if(sym==2)
   {
      c1='O';
      c2='X';
   }
   else
       goto yy;

   printf(" | |\n-----\n | |\n-----\n | |\n");
   while(cnt<9)
   {
   printf("press between 1 to 9 where you want to set your symbol = ");
   scanf("%d",&sym);
   if(sym==1 and cnt%2==0 and ttt[0][0]==' ')
      ttt[0][0]=c1;
   else if(sym==2 and cnt%2==0 and ttt[0][2]==' ')
       ttt[0][2]=c1;
   else if(sym==3 and cnt%2==0 and ttt[0][4]==' ')
       ttt[0][4]=c1;
   else if(sym==4 and cnt%2==0 and ttt[2][0]==' ')
       ttt[2][0]=c1;
   else if(sym==5 and cnt%2==0 and ttt[2][2]==' ')
       ttt[2][2]=c1;
   else if(sym==6 and cnt%2==0 and ttt[2][4]==' ')
       ttt[2][4]=c1;
   else if(sym==7 and cnt%2==0 and ttt[4][0]==' ')
       ttt[4][0]=c1;
   else if(sym==8 and cnt%2==0 and ttt[4][2]==' ')
       ttt[4][2]=c1;
   else if(sym==9 and cnt%2==0 and ttt[4][4]==' ')
       ttt[4][4]=c1;
   else
   {
     flag=3;
     break;
   }
    ++cnt;

   if(cnt>=4)
   {
       if(ttt[0][0]==c1 and ttt[0][2]==c1 and ttt[0][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][0]==c1 and ttt[2][0]==c1 and ttt[4][0]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][0]==c1 and ttt[2][2]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][2]==c1 and ttt[2][2]==c1 and ttt[4][2]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][4]==c1 and ttt[2][4]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][4]==c1 and ttt[2][2]==c1 and ttt[4][0]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[2][0]==c1 and ttt[2][2]==c1 and ttt[2][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[4][0]==c1 and ttt[4][2]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
   }

   if(cnt%2!=0)
   {
     if(ttt[0][0]==c1)
     {
         if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[4][0]==' ')
            ttt[4][0]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
     else if(ttt[0][4]==c1)
     {
         if(ttt[4][0]==' ')
            ttt[4][0]=c2;
         else if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
     else if(ttt[4][0]==c1)
     {
         if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
     else if(ttt[4][4]==c1)
     {
         if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else if(ttt[4][0]==' ')
            ttt[4][0]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
    else if(ttt[4][2]==c1)
     {
         if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else if(ttt[4][0]==' ')
            ttt[4][0]=c2;
         else if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
    else if(ttt[0][2]==c1)
     {
         if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[4][0]==' ')
            ttt[4][0]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
     else if(ttt[2][4]==c1)
     {
         if(ttt[4][0]==' ')
            ttt[4][0]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
     else if(ttt[2][0]==c1)
     {
         if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else if(ttt[4][0]==' ')
            ttt[4][0]=c2;
         else
            ttt[2][2]=c2;
         ++cnt;
     }
     else if(ttt[2][2]==c1)
     {
         if(ttt[0][2]==' ')
            ttt[0][2]=c2;
         else if(ttt[4][2]==' ')
            ttt[4][2]=c2;
         else if(ttt[2][0]==' ')
            ttt[2][0]=c2;
         else if(ttt[2][4]==' ')
            ttt[2][4]=c2;
         else if(ttt[0][0]==' ')
            ttt[0][0]=c2;
         else if(ttt[4][4]==' ')
            ttt[4][4]=c2;
         else if(ttt[0][4]==' ')
            ttt[0][4]=c2;
         else
            ttt[4][0]=c2;
         ++cnt;
     }
   }

   if(cnt>=5)
   {
       if(ttt[0][0]==c2 and ttt[0][2]==c2 and ttt[0][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][0]==c2 and ttt[2][0]==c2 and ttt[4][0]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][0]==c2 and ttt[2][2]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][2]==c2 and ttt[2][2]==c2 and ttt[4][2]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][4]==c2 and ttt[2][4]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][4]==c2 and ttt[2][2]==c2 and ttt[4][0]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[2][0]==c2 and ttt[2][2]==c2 and ttt[2][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[4][0]==c2 and ttt[4][2]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
   }
   for(int i=0;i<5;i++)
   {
    for(int j=0;j<5;j++)
      {
       printf("%c",ttt[i][j]);
      }
      printf("\n");
   }
   }
   xx:
   if(flag==0)
   {
       for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }
      ++*draw;
      cout<<"Ooopss "<<name<<"! game is drawn. try again please.\n\n";
   }

   else if(flag==1)
   {
    for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }
      cout<<"congratulations "<<name<<"! you have won the game.\n\n";
   }

   else if(flag==2)
   {
     for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }
      cout<<"oh "<<name<<"! you have lost the game. no matter. better luck next time.\n\n";
   }

   else if(flag==3)
   {
      cout<<"You have chosen the wrong position. possible reason is either you have chosen the position which is filled up earlier or your chosen position is not within the range between 1 to 9.\n\n";
   }
   yy: 
   return 0;
}

int hard(char name[],int *won, int *lost,int *draw)
{
   int sym,cnt=0,flag=0;
   char c1,c2,ttt[5][5]={{' ','|',' ','|',' '},{'-','-','-','-','-'},{' ','|',' ','|',' '},{'-','-','-','-','-'},{' ','|',' ','|',' '}};
   printf("choose your symbol---->\n1. X\n2. O\n");
   printf("enter your choice = ");
   scanf("%d",&sym);
   if(sym==1)
   {
      c1='X';
      c2='O';
   }

   else if(sym==2)
   {
      c1='O';
      c2='X';
   }
   else
      goto yy;
   printf(" | |\n-----\n | |\n-----\n | |\n");
   while(cnt<9)
   {
     printf("press between 1 to 9 where you want to set your symbol = ");
     scanf("%d",&sym);
    if(sym==1 and cnt%2==0 and ttt[0][0]==' ')
       ttt[0][0]=c1;
   else if(sym==2 and cnt%2==0 and ttt[0][2]==' ')
       ttt[0][2]=c1;
   else if(sym==3 and cnt%2==0 and ttt[0][4]==' ')
       ttt[0][4]=c1;
   else if(sym==4 and cnt%2==0 and ttt[2][0]==' ')
       ttt[2][0]=c1;
   else if(sym==5 and cnt%2==0 and ttt[2][2]==' ')
       ttt[2][2]=c1;
   else if(sym==6 and cnt%2==0 and ttt[2][4]==' ')
       ttt[2][4]=c1;
   else if(sym==7 and cnt%2==0 and ttt[4][0]==' ')
       ttt[4][0]=c1;
   else if(sym==8 and cnt%2==0 and ttt[4][2]==' ')
       ttt[4][2]=c1;
   else if(sym==9 and cnt%2==0 and ttt[4][4]==' ')
       ttt[4][4]=c1;
   else
   {
       flag=3;
       break;
   }
    ++cnt;

    if(cnt>=4)
   {
       if(ttt[0][0]==c1 and ttt[0][2]==c1 and ttt[0][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][0]==c1 and ttt[2][0]==c1 and ttt[4][0]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][0]==c1 and ttt[2][2]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][2]==c1 and ttt[2][2]==c1 and ttt[4][2]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][4]==c1 and ttt[2][4]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][4]==c1 and ttt[2][2]==c1 and ttt[4][0]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[2][0]==c1 and ttt[2][2]==c1 and ttt[2][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[4][0]==c1 and ttt[4][2]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
   }

   if(cnt%2!=0)
   {
     if(cnt==1)
     {
        if(ttt[2][2]==' ')
            ttt[2][2]=c2;
        else
            ttt[0][4]=c2;
        ++cnt;
     }
     else if(cnt==3)
     {
        if(ttt[0][0]==c1 and ttt[0][2]==c1)
            ttt[0][4]=c2;
        else if(ttt[0][0]==c1 and ttt[2][0]==c1)
            ttt[4][0]=c2;
        else if(ttt[0][2]==c1 and ttt[0][4]==c1)
            ttt[0][0]=c2;
        else if(ttt[0][4]==c1 and ttt[2][4]==c1)
            ttt[4][4]=c2;
        else if(ttt[2][4]==c1 and ttt[4][4]==c1)
            ttt[0][4]=c2;
        else if(ttt[4][2]==c1 and ttt[4][4]==c1)
            ttt[4][0]=c2;
        else if(ttt[4][0]==c1 and ttt[4][2]==c1)
            ttt[4][4]=c2;
        else if(ttt[2][0]==c1 and ttt[4][0]==c1)
            ttt[0][0]=c2;
        else if(ttt[0][2]==c1 and ttt[2][0]==c1)
            ttt[0][0]=c2;
        else if(ttt[0][2]==c1 and ttt[2][4]==c1)
            ttt[0][4]=c2;
        else if(ttt[2][4]==c1 and ttt[4][2]==c1)
            ttt[4][4]=c2;
        else if(ttt[2][0]==c1 and ttt[4][2]==c1)
            ttt[4][0]=c2;
        else if(ttt[2][0]==c1 and ttt[2][4]==c1)
            ttt[4][0]=c2;
        else if(ttt[0][2]==c1 and ttt[4][2]==c1)
            ttt[0][4]=c2;
        else if(ttt[2][0]==c1 and ttt[0][4]==c1)
            ttt[0][0]=c2;
        else if(ttt[2][0]==c1 and ttt[4][4]==c1)
            ttt[4][0]=c2;
        else if(ttt[0][0]==c1 and ttt[2][4]==c1)
            ttt[0][4]=c2;
        else if(ttt[2][4]==c1 and ttt[4][0]==c1)
            ttt[4][4]=c2;
        else if(ttt[0][0]==c1 and ttt[4][2]==c1)
            ttt[4][0]=c2;
        else if(ttt[0][4]==c1 and ttt[4][2]==c1)
            ttt[4][4]=c2;
        else if(ttt[0][2]==c1 and ttt[4][0]==c1)
            ttt[0][0]=c2;
        else if(ttt[0][2]==c1 and ttt[4][4]==c1)
            ttt[0][4]=c2;
        else if(ttt[0][0]==c1 and ttt[4][0]==c1)
            ttt[2][0]=c2;
        else if(ttt[0][0]==c1 and ttt[0][4]==c1)
            ttt[0][2]=c2;
        else if(ttt[0][4]==c1 and ttt[4][4]==c1)
            ttt[2][4]=c2;
        else if(ttt[4][0]==c1 and ttt[4][4]==c1)
            ttt[4][2]=c2;
        else if(ttt[0][0]==c1 and ttt[4][4]==c1)
            ttt[2][0]=c2;
        else if(ttt[0][4]==c1 and ttt[4][0]==c1)
            ttt[2][4]=c2;
        else if(ttt[0][0]==c1 and ttt[2][2]==c1)
            ttt[4][4]=c2;
        else if(ttt[0][2]==c1 and ttt[2][2]==c1)
            ttt[4][2]=c2;
        else if(ttt[2][4]==c1 and ttt[2][2]==c1)
            ttt[2][0]=c2;
        else if(ttt[4][4]==c1 and ttt[2][2]==c1)
            ttt[0][0]=c2;
        else if(ttt[4][2]==c1 and ttt[2][2]==c1)
            ttt[0][2]=c2;
        else if(ttt[4][0]==c1 and ttt[2][2]==c1)
            ttt[4][4]=c2;
        else if(ttt[2][0]==c1 and ttt[2][2]==c1)
            ttt[2][4]=c2;
        ++cnt;
     }
     else if(cnt==5)
     {
         if(ttt[2][2]==c2)
         {
           if(ttt[0][0]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
           else if(ttt[0][2]==c2 and ttt[4][2]==' ')
            ttt[4][2]=c2;
           else if(ttt[2][4]==c2 and ttt[2][0]==' ')
            ttt[2][0]=c2;
           else if(ttt[4][4]==c2 and ttt[0][0]==' ')
            ttt[0][0]=c2;
           else if(ttt[4][2]==c2 and ttt[0][2]==' ')
            ttt[0][2]=c2;
           else if(ttt[4][0]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
           else if(ttt[2][0]==c2 and ttt[2][4]==' ')
            ttt[2][4]=c2;
           else if(ttt[0][4]==c2 and ttt[4][0]==' ')
            ttt[4][0]=c2;
           else
           {
               for(int i=0;i<5;i++)
          {
           for(int j=0;j<5;j++)
            {
              if(ttt[i][j]==' ')
              {
                  ttt[i][j]=c2;
                  ++cnt;
                  goto zz;
              }
            }
          }
           }
         }
         else if(ttt[0][4]==c2)
         {
           if(ttt[4][4]==c2 and ttt[2][4]==' ')
            ttt[2][4]=c2;
           else if(ttt[2][4]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
           else if(ttt[0][2]==c2 and ttt[0][0]==' ')
            ttt[0][0]=c2;
           else if(ttt[0][0]==c2 and ttt[0][2]==' ')
            ttt[0][2]=c2;
           else if(ttt[2][2]==c1 and ttt[0][0]==c1 and ttt[4][4]==' ')
            ttt[4][4]=c2;
           else if(ttt[2][2]==c1 and ttt[0][2]==c1 and ttt[4][2]==' ')
            ttt[4][2]=c2;
           else if(ttt[2][2]==c1 and ttt[2][4]==c1 and ttt[2][0]==' ')
            ttt[2][0]=c2;
           else if(ttt[2][2]==c1 and ttt[4][4]==c1 and ttt[0][0]==' ')
            ttt[0][0]=c2;
           else if(ttt[2][2]==c1 and ttt[4][2]==c1 and ttt[0][2]==' ')
            ttt[0][2]=c2;
           else if(ttt[2][2]==c1 and ttt[4][0]==c1 and ttt[4][4]==' ')
            ttt[4][4]=c2;
           else if(ttt[2][2]==c1 and ttt[2][0]==c1 and ttt[2][4]==' ')
            ttt[2][4]=c2;
           else if(ttt[2][2]==c1 and ttt[0][4]==c1 and ttt[4][0]==' ')
            ttt[4][0]=c2;
           else
         {
         for(int i=0;i<5;i++)
          {
           for(int j=0;j<5;j++)
            {
              if(ttt[i][j]==' ')
              {
                  ttt[i][j]=c2;
                  ++cnt;
                  goto zz;
              }
            }
          }
         }

         }

         ++cnt;

   }
     else if(cnt==7)
     {
        if(ttt[0][0]==c2 and ttt[0][2]==c2 and ttt[0][4]==' ')
            ttt[0][4]=c2;
        else if(ttt[0][0]==c2 and ttt[2][0]==c2 and ttt[4][0]==' ')
            ttt[4][0]=c2;
        else if(ttt[0][2]==c2 and ttt[0][4]==c2 and ttt[0][0]==' ')
            ttt[0][0]=c2;
        else if(ttt[0][4]==c2 and ttt[2][4]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[2][4]==c2 and ttt[4][4]==c2 and ttt[0][4]==' ')
            ttt[0][4]=c2;
        else if(ttt[4][2]==c2 and ttt[4][4]==c2 and ttt[4][0]==' ')
            ttt[4][0]=c2;
        else if(ttt[4][0]==c2 and ttt[4][2]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[2][0]==c2 and ttt[4][0]==c2 and ttt[0][0]==' ')
            ttt[0][0]=c2;
        else if(ttt[0][2]==c2 and ttt[2][0]==c2 and ttt[0][0]==' ')
            ttt[0][0]=c2;
        else if(ttt[0][2]==c2 and ttt[2][4]==c2 and ttt[0][4]==' ')
            ttt[0][4]=c2;
        else if(ttt[2][4]==c2 and ttt[4][2]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[2][0]==c2 and ttt[4][2]==c2 and ttt[4][0]==' ')
            ttt[4][0]=c2;
        else if(ttt[0][0]==c2 and ttt[4][0]==c2 and ttt[2][0]==' ')
            ttt[2][0]=c2;
        else if(ttt[0][0]==c2 and ttt[0][4]==c2 and ttt[0][2]==' ')
            ttt[0][2]=c2;
        else if(ttt[0][4]==c2 and ttt[4][4]==c2 and ttt[2][4]==' ')
            ttt[2][4]=c2;
        else if(ttt[4][0]==c2 and ttt[4][4]==c2 and ttt[4][2]==' ')
            ttt[4][2]=c2;
        else if(ttt[0][0]==c2 and ttt[4][4]==c2 and ttt[2][0]==' ')
            ttt[2][0]=c2;
        else if(ttt[0][4]==c2 and ttt[4][0]==c2 and ttt[2][4]==' ')
            ttt[2][4]=c2;
        else if(ttt[0][0]==c2 and ttt[2][2]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[0][2]==c2 and ttt[2][2]==c2 and ttt[4][2]==' ')
            ttt[4][2]=c2;
        else if(ttt[2][4]==c2 and ttt[2][2]==c2 and ttt[2][0]==' ')
            ttt[2][0]=c2;
        else if(ttt[4][4]==c2 and ttt[2][2]==c2 and ttt[0][0]==' ')
            ttt[0][0]=c2;
        else if(ttt[4][2]==c2 and ttt[2][2]==c2 and ttt[0][2]==' ')
            ttt[0][2]=c2;
        else if(ttt[4][0]==c2 and ttt[2][2]==c2 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[2][0]==c2 and ttt[2][2]==c2 and ttt[2][4]==' ')
            ttt[2][4]=c2;
        else if(ttt[4][4]==c1 and ttt[2][2]==c1 and ttt[0][0]==' ')
            ttt[0][0]=c2;
        else if(ttt[2][4]==c1 and ttt[2][2]==c1 and ttt[2][0]==' ')
            ttt[2][0]=c2;
        else if(ttt[2][0]==c1 and ttt[2][2]==c1 and ttt[2][4]==' ')
            ttt[2][4]=c2;
        else if(ttt[4][2]==c1 and ttt[2][2]==c1 and ttt[0][2]==' ')
            ttt[0][2]=c2;
        else if(ttt[0][0]==c1 and ttt[2][2]==c1 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[0][0]==c1 and ttt[2][0]==c1 and ttt[4][0]==' ')
            ttt[4][0]=c2;
        else if(ttt[2][0]==c1 and ttt[4][0]==c1 and ttt[0][0]==' ')
            ttt[0][0]=c2;
        else if(ttt[4][0]==c1 and ttt[4][2]==c1 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[4][2]==c1 and ttt[4][4]==c1 and ttt[4][0]==' ')
            ttt[4][0]=c2;
        else if(ttt[0][0]==c1 and ttt[4][0]==c1 and ttt[2][0]==' ')
            ttt[2][0]=c2;
        else if(ttt[0][0]==c1 and ttt[4][4]==c1 and ttt[2][2]==' ')
            ttt[2][2]=c2;
        else if(ttt[0][2]==c1 and ttt[4][2]==c1 and ttt[2][2]==' ')
            ttt[2][2]=c2;
        else if(ttt[2][0]==c1 and ttt[2][4]==c1 and ttt[2][2]==' ')
            ttt[2][2]=c2;
        else if(ttt[4][0]==c1 and ttt[4][4]==c1 and ttt[4][2]==' ')
            ttt[4][2]=c2;
        else if(ttt[0][0]==c1 and ttt[0][2]==c1 and ttt[0][4]==' ')
            ttt[0][4]=c2;
        else if(ttt[2][4]==c1 and ttt[4][4]==c1 and ttt[0][4]==' ')
            ttt[0][4]=c2;
        else if(ttt[4][0]==c1 and ttt[2][2]==c1 and ttt[0][4]==' ')
            ttt[0][4]=c2;
        else if(ttt[4][0]==c1 and ttt[0][4]==c1 and ttt[2][2]==' ')
            ttt[2][2]=c2;
        else if(ttt[0][4]==c1 and ttt[2][4]==c1 and ttt[4][4]==' ')
            ttt[4][4]=c2;
        else if(ttt[0][4]==c1 and ttt[4][4]==c1 and ttt[2][4]==' ')
            ttt[2][4]=c2;
        else if(ttt[0][0]==c1 and ttt[0][4]==c1 and ttt[0][2]==' ')
            ttt[0][2]=c2;
        else if(ttt[0][4]==c1 and ttt[2][2]==c1 and ttt[4][0]==' ')
            ttt[4][0]=c2;
        else if(ttt[0][2]==c1 and ttt[0][4]==c1 and ttt[0][0]==' ')
            ttt[0][0]=c2;
        else
        {
         for(int i=0;i<5;i++)
          {
           for(int j=0;j<5;j++)
           {
             if(ttt[i][j]==' ')
             {
                 ttt[i][j]=c2;
                 ++cnt;
                 goto zz;
             }
           }

          }
        }

        ++cnt;
     }
   zz:
   if(cnt>=5)
   {
       if(ttt[0][0]==c2 and ttt[0][2]==c2 and ttt[0][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][0]==c2 and ttt[2][0]==c2 and ttt[4][0]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][0]==c2 and ttt[2][2]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][2]==c2 and ttt[2][2]==c2 and ttt[4][2]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][4]==c2 and ttt[2][4]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][4]==c2 and ttt[2][2]==c2 and ttt[4][0]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[2][0]==c2 and ttt[2][2]==c2 and ttt[2][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[4][0]==c2 and ttt[4][2]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
   }
   }
   for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }

   }
   xx:
   if(flag==0)
   {
      ++*draw;
      cout<<"Ooopss "<<name<<"! game is drawn. try again please.\n\n";
   }

   else if(flag==1)
   {
    for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }
      cout<<"congratulations "<<name<<"! you have won the game.\n\n";
   }

   else if(flag==2)
   {
     for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }
      cout<<"oh "<<name<<"! you have lost the game. no matter. better luck next time.\n\n";
   }

   else if(flag==3)
   {
      cout<<"You have chosen the wrong position. possible reason is either you have chosen the position which is filled up earlier or your chosen position is not within the range between 1 to 9.\n\n";
   }
   yy: 
   return 0;

}

int twoplayers(char name1[],char name2[],int *won,int *lost,int *draw)
{
   int sym,cnt=0,flag=0;
   char c1,c2,ttt[5][5]={{' ','|',' ','|',' '},{'-','-','-','-','-'},{' ','|',' ','|',' '},{'-','-','-','-','-'},{' ','|',' ','|',' '}};
   if(*won+*lost+*draw==0)
   {
       printf("NAME OF PLAYER 1 = ");
       scanf(" %[^\n]",name1);
       printf("NAME OF PLAYER 2 = ");
       scanf(" %[^\n]",name2);
   }
   printf("choose %s's symbol---->\n1. X\n2. O\n",name1);
   printf("enter choice = ");
   scanf("%d",&sym);
   if(sym==1)
   {
      c1='X';
      c2='O';
   }

   else if(sym==2)
   {
      c1='O';
      c2='X';
   }
   else
      goto yy;
   printf(" | |\n-----\n | |\n-----\n | |\n");
   while(cnt<9)
   {
     printf("%s's turn = ",name1);
     scanf("%d",&sym);
    if(sym==1 and ttt[0][0]==' ')
       ttt[0][0]=c1;
   else if(sym==2 and ttt[0][2]==' ')
       ttt[0][2]=c1;
   else if(sym==3 and ttt[0][4]==' ')
       ttt[0][4]=c1;
   else if(sym==4 and ttt[2][0]==' ')
       ttt[2][0]=c1;
   else if(sym==5 and ttt[2][2]==' ')
       ttt[2][2]=c1;
   else if(sym==6 and ttt[2][4]==' ')
       ttt[2][4]=c1;
   else if(sym==7 and ttt[4][0]==' ')
       ttt[4][0]=c1;
   else if(sym==8 and ttt[4][2]==' ')
       ttt[4][2]=c1;
   else if(sym==9 and ttt[4][4]==' ')
       ttt[4][4]=c1;
   else
   {
       flag=3;
       break;
   }
   ++cnt;
   if(cnt>=4)
   {
       if(ttt[0][0]==c1 and ttt[0][2]==c1 and ttt[0][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][0]==c1 and ttt[2][0]==c1 and ttt[4][0]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][0]==c1 and ttt[2][2]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][2]==c1 and ttt[2][2]==c1 and ttt[4][2]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][4]==c1 and ttt[2][4]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[0][4]==c1 and ttt[2][2]==c1 and ttt[4][0]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[2][0]==c1 and ttt[2][2]==c1 and ttt[2][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
       else if(ttt[4][0]==c1 and ttt[4][2]==c1 and ttt[4][4]==c1)
       {
         ++*won;
         flag=1;
         goto xx;
       }
   }
   for(int i=0;i<5;i++)
   {
    for(int j=0;j<5;j++)
      {
       printf("%c",ttt[i][j]);
      }
      printf("\n");
   }
   if(ttt[0][0]!=' ' and ttt[0][2]!=' ' and ttt[0][4]!=' ' and ttt[2][0]!=' ' and ttt[2][2]!=' ' and ttt[2][4]!=' ' and ttt[4][0]!=' ' and ttt[4][2]!=' ' and ttt[4][4]!=' ')
   goto xx;
   printf("%s's turn = ",name2);
     scanf("%d",&sym);
    if(sym==1 and ttt[0][0]==' ')
       ttt[0][0]=c2;
   else if(sym==2 and ttt[0][2]==' ')
       ttt[0][2]=c2;
   else if(sym==3 and ttt[0][4]==' ')
       ttt[0][4]=c2;
   else if(sym==4 and ttt[2][0]==' ')
       ttt[2][0]=c2;
   else if(sym==5 and ttt[2][2]==' ')
       ttt[2][2]=c2;
   else if(sym==6 and ttt[2][4]==' ')
       ttt[2][4]=c2;
   else if(sym==7 and ttt[4][0]==' ')
       ttt[4][0]=c2;
   else if(sym==8 and ttt[4][2]==' ')
       ttt[4][2]=c2;
   else if(sym==9 and ttt[4][4]==' ')
       ttt[4][4]=c2;
   else
   {
       flag=3;
       break;
   }
   ++cnt;
   if(cnt>=5)
   {
       if(ttt[0][0]==c2 and ttt[0][2]==c2 and ttt[0][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][0]==c2 and ttt[2][0]==c2 and ttt[4][0]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][0]==c2 and ttt[2][2]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][2]==c2 and ttt[2][2]==c2 and ttt[4][2]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][4]==c2 and ttt[2][4]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[0][4]==c2 and ttt[2][2]==c2 and ttt[4][0]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[2][0]==c2 and ttt[2][2]==c2 and ttt[2][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
       else if(ttt[4][0]==c2 and ttt[4][2]==c2 and ttt[4][4]==c2)
       {
         ++*lost;
         flag=2;
         goto xx;
       }
   }
   for(int i=0;i<5;i++)
   {
    for(int j=0;j<5;j++)
      {
       printf("%c",ttt[i][j]);
      }
      printf("\n");
   }

   }
   xx:
   if(flag==0)
   {
      ++*draw;
      cout<<"Ooopss ! game is drawn. "<<name1<<" and "<<name2<<" , both played well.\n\n";
   }

   else if(flag==1)
   {
    for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }
      cout<<"congrqatulations "<<name1<<"! you have won the game.\nno matter "<<name2<<" may be you will be lucky next time\n\n";
   }

   else if(flag==2)
   {
     for(int i=0;i<5;i++)
      {
        for(int j=0;j<5;j++)
        {
          printf("%c",ttt[i][j]);
        }
        printf("\n");
      }
      cout<<"congrqatulations "<<name2<<"! you have won the game.\nno matter "<<name1<<" may be you will be lucky next time\n\n";
   }

   else if(flag==3)
   {
      cout<<"the wrong position is chosen. possible reason is either you have chosen the position which is filled up earlier or your chosen position is not within the range between 1 to 9.\n\n";
   }
   yy:
   return 0;
}

int settings(char name[],int *won,int *lost,int *draw,int *eh)
{
    int n;
    char c;
    printf("\nwhat do you want to do?\n");
    printf("1. change player name\n");
    printf("2. player statistics\n");
    printf("3. game mode\n");
    printf("4. difficulty level\n");
    printf("enter your choice = ");
    scanf(" %d",&n);
    if(n==1)
    {
        printf("PLAYER NAME = ");
        scanf(" %[^\n]",name);
    }
    else if(n==2)
    {
        printf("---------------%s's statistics---------------\n",name);
        printf("MATCH PLAYED = %d\n",*won+*lost+*draw);
        printf("TROPHY WON = %d\n",*won);
        printf("MATCH LOST = %d\n",*lost);
        printf("MATCH DRAWN = %d\n\n",*draw);
        printf("Do you want to reset??\n");
        printf("press Y/N to continue = ");
        scanf(" %c",&c);
        if(c=='Y' or c=='y')
        {
           *won=0;
           *lost=0;
           *draw=0;
        }
    }
    else if(n==3)
    {
        printf("CHOOSE GAME MODE----\n");
        printf("1. single player\n");
        printf("2. two player\n");
        printf("enter your choice = ");
        scanf("%d",&n);
        if(n==2)
        {
           *won=0;
           *lost=0;
           *draw=0;
           *eh=3;
        }
    }
    else if(n==4)
    {
        printf("CHOOSE THE DIFFICULTY LEVEL------\n");
        printf("1. easy\n");
        printf("2. hard\n");
        printf("enter your choice = ");
        scanf(" %d",&n);
        if(n==1)
            *eh=1;
        else if(n==2)
            *eh=2;
    }
    return 0;
}

int settings(char name1[],char name2[],int *won,int *lost,int *draw,int *eh)
{
    int n;
    char c;
    printf("\nwhat do you want to do?\n");
    printf("1. change player name\n");
    printf("2. player statistics\n");
    printf("3. game mode\n");
    printf("enter your choice = ");
    scanf(" %d",&n);
    if(n==1)
    {
        printf("\nplayer 1 = ");
        scanf(" %[^\n]",name1);
        printf("player 2 = ");
        scanf(" %[^\n]",name2);
    }
    else if(n==2)
    {
        printf("---------------%s's statistics---------------\n",name1);
        printf("MATCH PLAYED = %d\n",*won+*lost+*draw);
        printf("TROPHY WON = %d\n",*won);
        printf("MATCH LOST = %d\n",*lost);
        printf("MATCH DRAWN = %d\n\n",*draw);
        printf("---------------%s's statistics---------------\n",name2);
        printf("MATCH PLAYED = %d\n",*won+*lost+*draw);
        printf("TROPHY WON = %d\n",*lost);
        printf("MATCH LOST = %d\n",*won);
        printf("MATCH DRAWN = %d\n\n",*draw);
        printf("Do you want to reset??\n");
        printf("press Y/N to continue = ");
        scanf(" %c",&c);
        if(c=='Y' or c=='y')
        {
           *won=0;
           *lost=0;
           *draw=0;
        }
    }
    else if(n==3)
    {
        printf("CHOOSE GAME MODE----\n");
        printf("1. single player\n");
        printf("2. two player\n");
        printf("enter your choice = ");
        scanf("%d",&n);
        if(n==1)
        {
            *won=0;
            *lost=0;
            *draw=0;
            *eh=1;
        }
        else if(n==2)
          *eh=3;
    }
  return 0;
}


















