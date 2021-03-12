#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void win(int player , int winner , int pos[])
{
      printf("\n");
      printf("%c|%c|%c\n",pos[0],pos[1],pos[2]);
      printf("-+-+-\n");
      printf("%c|%c|%c\n",pos[3],pos[4],pos[5]);
      printf("-+-+-\n");
      printf("%c|%c|%c\n",pos[6],pos[7],pos[8]);
      printf("-+-+-\n");
      
      if(winner)
      {
          printf("Le joueur N : %d est le gagnant ",player);
      }
      else {
          printf("Fin du jeu\n");
          printf("____________FELICITATIONS___________\n");
          printf("Le joueur N : %d est le gagnant ",player); 
        
      }
}


int main()
{
    int sign ;
    int index ;
    int pos[9];
    int count =0;
    int winner =0;
    int player ;
    int flag;
    int i , j ,k ;

    for(i=0;i<9;i++)
    {
        pos[i]=' ';
    }
    while(count <9 && winner !=1)
    { flag ==0;

      printf("\n");
      printf("%c|%c|%c\n",pos[0],pos[1],pos[2]);
      printf("-+-+-\n");
      printf("%c|%c|%c\n",pos[3],pos[4],pos[5]);
      printf("-+-+-\n");
      printf("%c|%c|%c\n",pos[6],pos[7],pos[8]);
      printf("-+-+-\n");
      if(count % 2 == 0)
      {
          player = 1;
          sign   = 'X';
      }
      else
      {
          player = 2;
          sign   ='O';
      }
      printf("C'est le tour du joueur N : %d\n",player);
      printf("Veuillez choisir [ 1 -- 9 ] : ");
      scanf("%d",&index);
      if(index<1 || index>9)
      {
          printf("Le coup n'est pas valide !!!");
          continue;
      }
      if(pos[index-1]=='X' || pos[index-1]=='O')
      {
          printf("Vous avez deja jouer ce coup !!!");
          continue;
      }
      pos[index-1]=sign;
      count ++;
      for(i=0;i<9;i++)
      {
          if(i % 3 == 0)
              flag = 0;
          if(pos[i]==sign)
              flag ++;
          if(flag == 3)
          {
              winner == 1 ;
              win(player,winner,pos);
          }
      }
      flag == 0;
      for(i=0;i<3;i++)
      {
          for(k=i;k<=i+6;k+=3)
          {
              if(pos[k]==sign)
              {
                   flag ++;
              }
              if(flag == 3)
              {
                  winner == 1;
                  win(player,winner,pos);
              }
          }
      }
      flag ==0;
      if((sign==pos[0] && sign==pos[4] && pos[8]==sign)||(sign==pos[2] && sign==pos[6] && sign==pos[4]))
      {
          winner == 1;
          win(player,winner,pos);
      }


    }
    return 0;
}
