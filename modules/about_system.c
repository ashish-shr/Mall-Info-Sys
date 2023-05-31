#include <stdio.h>
#include <stdlib.h>

void about_system()
{
  system("color B");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 About System \xb3\xb0\xb3\n\n");
  printf("\t\t--------------------------------------------------------------------------\n");
  printf("\t\t| System Name      || %s\n", "Mall InfoSys");
  printf("\t\t--------------------------------------------------------------------------\n");
  printf("\t\t| System Version   || %s\n", "V.1.0");
  printf("\t\t--------------------------------------------------------------------------\n");
  printf("\t\t| Languages Used   || %s\n", "C");
  printf("\t\t--------------------------------------------------------------------------\n");
  printf("\t\t| Libraries Used   || %s\n", "stdio, conio, string, windows, stdlib, stdbool");
  printf("\t\t--------------------------------------------------------------------------\n");
  printf("\t\t| Project Link     || %s\n", "https://github.com/ashish-shr");
  printf("\t\t--------------------------------------------------------------------------\n");
  printf("\t\t| COPYRIGHT %s\n", "2023. Mall InfoSys. All rights reserved.");
  printf("\t\t--------------------------------------------------------------------------\n");
  printf("\n\t\tPress enter to continue! ");
  getch();
  system("cls");
  system("color A");
}