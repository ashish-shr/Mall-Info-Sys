#include <stdio.h>
#include <stdlib.h>

void loadingScreen()
{
  system("color F");
  printf("\n\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Version 2.0.\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\t\t\t\t    \xb3\xb0\xb3 Loading \xb3\xb0\xb3");
  printf("\n\t\t\t\t\t\t    ");
  for (int i = 0; i < 15; i++)
  {
    printf(".");
    Sleep(500);
  }
  system("cls");
}
