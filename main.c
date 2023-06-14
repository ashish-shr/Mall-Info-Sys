#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include "modules/login.c"
#include "modules/loading_screen.c"

#define MAX 100

void loadingScreen();
void lock();
void credits();
void login();

void lock()
{
  int option;
  int exitProgram = false; // Initialize exitProgram to false
  do
  {
    system("cls");
    system("color A");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Welcome \xb3\xb0\xb3\n\n");
    printf("\t\t1. Login\n");
    printf("\t\t2. Exit\n");
    printf("\t\t-------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      login();
      break;

    case 2:
      exitProgram = true; // Update the exitProgram flag to true
      break;

    default:
      system("cls");
      system("color C");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\t\t\tInvalid option! Press enter to continue.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      system("color A");
    }
    if (!exitProgram)
    {
      system("cls");
    }
  } while (!exitProgram);

  system("cls");
  credits();
  system("cls");
  exit(0);
}

void ac_set()
{
  system("color A");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Create Account \xb3\xb0\xb3\n\n");
  char user_name[MAX], password[MAX];
  FILE *user;
  user = fopen("data\\user_logs.txt", "w");
  if (user == NULL)
  {
    printf("Failed to create about.dat\n");
    exit(1);
  }
  printf("\t\tUsername -> ");
  scanf(" %[^\n]s", user_name);
  printf("\t\tPassword -> ");
  scanf(" %[^\n]s", password);
  fprintf(user, "\n%s\t%s\t%s", user_name, password, "admin");
  printf("\t\tPress enter to continue!");
  getch();
  fclose(user);
  system("cls");
}

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
  printf("\t\tPress enter to continue!");
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
  user = fopen("data\\user_logs.txt", "r");
  if (mall == NULL || user == NULL)
  {
    mall_details();
    ac_set();
  }
  fclose(mall);
  fclose(user);
  lock();
  home();
  system("cls");
  return 0;
}
