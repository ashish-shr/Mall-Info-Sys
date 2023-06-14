#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "home.c"

#define MAX 100

char ch;

void home();
void lock();

void login()
{
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  FILE *log = fopen("data\\user_logs.txt", "r");
  if (log == NULL)
  {
    printf("Error opening log file");
    exit(1);
  }
  int user_id;
  char username[MAX], password[MAX], ouser[MAX], opass[MAX];
  printf("\n\t\t\xb3\xb0\xb3 Login \xb3\xb0\xb3\n\n");
  printf("\t\tUsername -> ");
  scanf("%s", username);
  printf("\t\tPassword -> ");
  int i = 0;
  while ((ch = getch()) != '\r')
  {
    if (ch == '\b')
    {
      if (i > 0)
      {
        i--;
        printf("\b \b"); // Move cursor back, print space, move cursor back again
      }
    }
    else
    {
      password[i] = ch;
      i++;
      printf("*");
    }
  }

  password[i] = '\0'; // Null-terminate the password string

  int found = 0;
  while (fscanf(log, "%s\t%s\n", ouser, opass) != EOF)
  {
    if ((strcmp(ouser, username) == 0) && (strcmp(opass, password) == 0))
    {
      found = 1;
      break;
    }
  }
  fclose(log);
  if (found)
  {
    system("cls");
    home();
    exitProgram = false;
  }
  else
  {

    system("cls");
    system("color C");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tUsername or password is incorrect!\n\n");
    printf("\t\t\t\t\t1. Try Again\n");
    printf("\t\t\t\t\t2. Return to welcome screen\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      login();
    }
    else if (ch == '2')
    {
      system("cls");
      lock();
    }
    else
    {
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
      login();
    }
    system("cls");
    system("color A");
  }
}