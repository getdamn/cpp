//Gomoku_0.0.2 _ 틀 완성 (1 vs 1)

/*
제작자: 배지승
프로그램: 오목 프로그램
설명: 고등학생 때 동아리 프로젝트로 만든 프로그램
특징: 프로그램이 매우 조잡하고 허접함.
*/

#include <stdio.h>

#include <stdlib.h>

#include <windows.h>

#include <conio.h>

#pragma warning (disable:4996)



#define BK 1

#define WH -1



int field[15][15];

int cnt = 1;

int ROUND = 1;

int P1win = 0, P2win = 0;



int RULE(void);

int RULE33(void);

int RULE44(void);



int que(int len, int x, int y, int col);



void PRTF(void);

int PLAYER1(int Clr);

int PLAYER2(int Clr);

void COM(void);

int main(void)

{



 int i, j;



 for (i = 0; i < 14; i++)

 {

  for (j = 0; j < 14; j++)

  {

   field[i][j] = 0;

  }

 }

 /* printf("    ■■■■             ■■■■■            Ver. Alpha 0.0.2        \n");

 Sleep(300);

 printf("  ■        ■           ■      ■                                    \n");

 Sleep(300);

 printf("  ■        ■           ■■■■■                                    \n");

 Sleep(300);

 printf("  ■        ■               ■                                        \n");

 Sleep(300);

 printf("    ■■■■          ■■■■■■■■                                 \n");

 Sleep(300);

 printf("       ■                                                              \n");

 Sleep(300);

 printf("       ■               ■■■■■■                                   \n");

 Sleep(300);

 printf(" ■■■■■■■                   ■                                   \n");

 Sleep(300);

 printf("                                 ■                Made in ESD         \n");

 Sleep(300);



 Sleep(1000);

 */

 for (; ;)

 {

  PRTF();

  RULE();

  if (RULE() == -1)

  {

   P2win++;

   break;

  }

  PLAYER1(BK);

  cnt++;

  system("CLS");

  PRTF();

  if (RULE() == 1)

  {

   P1win++;

   break;

  }

  PLAYER2(WH);

  cnt++;

  system("CLS");

  

  //  PRTF();

  //  COM();

 }

 for (i = 0; i < 19; i++)

 {

  for (j = 0; j < 19; j++)

  {

   field[i][j] = 0;

  }

 }

 ROUND++;

 cnt = 1;

 for (; ;)

 {

  PRTF();

  RULE();

  if (RULE() == -1)

  {

   P1win++;

   break;

  }

  PLAYER2(BK);

  cnt++;

  system("CLS");

  PRTF();

  if (RULE() == 1)

  {

   P2win++;

   break;

  }

  

  PLAYER1(WH);

  cnt++;

  system("CLS");



  //  PRTF();

  //  COM();

 }

 if (P1win * P2win == 0)

 {

  printf("PLAYER1 : %d \nPLAYER2 : %d \n", P1win, P2win);

  if (P1win == 2)

   printf("PLAYER1 Win");

  else

   printf("PLAYER2 Win\n\n");

  return 0;

 }

 for (i = 0; i < 19; i++)

 {

  for (j = 0; j < 19; j++)

  {

   field[i][j] = 0;

  } 

 }

 ROUND++;

 cnt = 1;

 for (; ;)

 {

  PRTF();

  RULE();

  if (RULE() == -1)

  {

   P2win++;

   break;

  }

  PLAYER1(BK);

  cnt++;

  system("CLS");

  PRTF();

  if (RULE() == 1)

  {

   P1win++;

   break;

  }

  PLAYER2(WH);

  cnt++;

  system("CLS");



  //  PRTF();

  //  COM();

 }

 

 printf("PLAYER1 : %d \nPLAYER2 : %d \n", P1win, P2win);

 if (P1win == 2)

  printf("PLAYER1 Win");

 else

  printf("PLAYER2 Win\n\n");

 

 return 0;

}

void PRTF(void)

{   

 int i, j;

 

 printf("ROUND : %d ", ROUND);

 printf("PLAYER1 : %d, PLAYER2 : %d\n", P1win, P2win);

 for (i = 14; i >= 0; i--)

 {

  for (j = 0; j < 15; j++)

  {



   if (field[i][j] == 0)

   {

    if ((i == 0) && (j == 0))

    {

     printf("┗");

    }

    else if ((i == 0) && (j != 0) && (j != 14))

    {

     printf("┻");

    }

    else if ((i == 0) && (j == 14))

    {

     printf("┛");

    }

    else if ((j == 0) && (i != 14) && (i != 0))

    {

     printf("┣");

    }

    else if ((j == 14) && (i * j != 0) && (i * j != 14 * 14))

    {

     printf("┫");

    }

       else if ((i == 14) && (j == 0))

    {

     printf("┏");

    }

    else if ((i == 14) && (i * j != 14 * 14) && (j != 0))

    {

     printf("┳");

    }

    else if ((i == 14) && (j == 14))

    {

     printf("┓");

    }

    else if((i == 7)&&(j == 7))

    {

     printf("ㆍ");

    }

    else

    {

     printf("╋");

    }

   }

   if (field[i][j] == WH)

   {

    printf("●");

   }

   if (field[i][j] == BK)

   {

    printf("○");

   }

   if ((field[i][j] % 4) == 3)

   {

    printf("  ");

   }

  }

  printf("\n");

 }

 printf("이동 : →←↑↓ 착수 : 스페이스바");

 printf("\n");

 printf("%d\n", RULE6());



 if ((cnt % 2) == 1)

  printf("흑 착수");

 else

  printf("백 착수");

 printf("\n");

 printf("Count : %d", cnt);

 printf("\n");

}

int PLAYER1(int Clr)

{

 int px = 7, py = 7;

 int ch;

 while (1)

 {

  ch = getch();

  if (field[py][px] == 0)

  {

   if (ch == 32)

   {

    field[py][px] = Clr;

    return 0;

   }

  }

  switch (ch)

  {

  case 77: // 오른쪽

  {

   px++;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  case 75: // 왼쪽

  {

   px--;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  case 72: // 윗쪽

  {

   py++;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  case 80: // 아래쪽

  {

   py--;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  }

 }

}

int PLAYER2(int Clr)

{

 int px = 7, py = 7;

 int ch;

 while (1)

 {

  ch = getch();

  if (field[py][px] == 0)

  {

   if (ch == 32)

   {

    field[py][px] = Clr;

    return 0;

   }

  }

  switch (ch)

  {

  case 77:

  {

   px++;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  case 75:

  {

   px--;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  case 72:

  {

   py++;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  case 80:

  {

   py--;

   int tmp = 0;

   tmp = field[py][px];

   field[py][px] = 3;

   system("CLS");

   PRTF();

   field[py][px] = tmp;

   break;

  }

  }

 }

}

int que(int len, int x, int y, int Clr)

{

 int l;

 int xplus = 0, yplus = -1;

 for (yplus; yplus < 2; yplus++)

 {

  for (xplus; xplus < 2; xplus++)

  {

   if ((x == 0) && (y == 0))

    continue;

   int tmpx = x, tmpy = y;

   int cnt = 0;

   for (l = 0; l < len; l++)

   {

    if (field[tmpy][tmpx] == Clr)

     cnt++;

    if (cnt == len)

    {

     if (Clr == BK)

      return BK;

     if (Clr == WH)

         return WH;

    }

    tmpx += xplus;

    tmpy += yplus;

   }

  }

 }

 return -1;

}

int RULE(void)

{

 if (RULE6() == -1)

 {

  printf("\n 백 승리\n");

  return -1;

 }



 int i , j;

 for (i = 0; i < 15; i++)

 {

  for (j = 0; j < 15; j++)

  {

   if (field[i][j] == 1)

   {

    int Yplus , Xplus;

    for (Yplus = -1; Yplus < 2; Yplus++)

    {

     for (Xplus = 0; Xplus < 2; Xplus++)

     {

      if ((Xplus == 0) && (Yplus == 0))

       continue;

      int l;

      int tmpi = i;

      int tmpj = j; 

      int cnt = 0;

      for (l = 0; l < 5; l++)

      {

       if (field[tmpi][tmpj] == BK)

        cnt++;

       tmpi = tmpi + Yplus;

       tmpj = tmpj + Xplus;

      }

      if (cnt == 5)

      {

       printf("\n 흑 승리\n");

       return 1;

      }

     }

    }

   }

   if (field[i][j] == -1)

   {

    int Yplus , Xplus;

    for (Yplus = -1; Yplus < 2; Yplus++)

    {

     for (Xplus = 0; Xplus < 2; Xplus++)

     {

      if ((Xplus == 0) && (Yplus == 0))

       continue;

      int l;

      int tmpi = i;

      int tmpj = j;

      int cnt = 0;

      for (l = 0; l < 5; l++)

      {

       if (field[tmpi][tmpj] == WH)

        cnt++;

       tmpi = tmpi + Yplus;

       tmpj = tmpj + Xplus;

      }

      if (cnt == 5)

      {

       printf("\n 백 승리\n");

       return -1;

      }

     }

    }

   }

  }

 }

 return 0;

}

int RULE33(void)

{

 

}

int RULE44(void)

{}

int RULE6(void)

{

 int i, j;

 for (i = 0; i < 15; i++)

 {

  for (j = 0; j < 15; j++)

  {

   if (abs(field[i][j]) == 1)

   {

    if (que(6, j, i, BK) == BK)

     return -1;

    if (que(6, j, i, WH) == WH)

     return 0;

   }

  }

 }

 return 0;

}

/*void COM(void)

{

defmod();

attmod();

}*/

