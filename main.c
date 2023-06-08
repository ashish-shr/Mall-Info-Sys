#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "modules/home.c"
#include "modules/loading_screen.c"

#define MAX 100

void loadingScreen();
void credits();

void mall_details()
{
  system("color A");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Mall Details \xb3\xb0\xb3\n\n");
  mall_info info;
  FILE *mall;
  mall = fopen("data\\about.dat", "wb");
  if (mall == NULL)
  {
    printf("Failed to create about.dat\n");
    exit(1);
  }

  printf("\t\tMall Name -> ");
  scanf(" %[^\n]s", info.mall_name);
  printf("\t\tMall Address -> ");
  scanf(" %[^\n]s", info.mall_address);
  printf("\t\tMall Floors -> ");
  scanf("%d", &info.mall_floor);
  printf("\t\tMall Stores -> ");
  scanf("%d", &info.mall_stores);
  printf("\t\tMall Phone -> ");
  scanf(" %[^\n]s", info.mall_phone);
  printf("\t\tMall Email -> ");
  scanf(" %[^\n]s", info.mall_email);
  fwrite(&info, sizeof(mall_info), 1, mall);
  printf("Press enter to continue!");
  getch();
  fclose(mall);
  system("cls");
}

void credits()
{
  system("color B");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t\xdb\xdb\xdb\xb3Support this project\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t|| Contribute and Share\n");
  printf("\t\t\t\t\t\t|| Give star on Github\n");
  printf("\t\t\t\t\t\t|| %s\n", "https://github.com/ashish-shr");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\tPress enter to exit! ");
  getch();
  system("cls");
  system("color A");
}

int main()
{
  system("cls");
  system("color A");
  loadingScreen();
  mall = fopen("data\\about.dat", "rb");
  if (mall == NULL)
  {
    mall_details();
  }
  home();
  system("cls");
  credits();
  system("cls");
  return 0;
}
