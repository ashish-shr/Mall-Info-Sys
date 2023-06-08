#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "about_mall.c"
#include "about_system.c"
#include "panels.c"

#define MAX 100

void home();

void admin_log()
{
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");

  FILE *admin = fopen("data\\user_logs.txt", "r");
  if (admin == NULL)
  {
    printf("Error opening admin file");
    exit(1);
  }
  int user_id;
  char username[MAX], password[MAX], ouser[MAX], opass[MAX], type[MAX];
  printf("\n\t\t\xb3\xb0\xb3 Admin Login \xb3\xb0\xb3\n\n");
  // printf("\t\t[Admin Login]\n\n");
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
  while (fscanf(admin, "%d %s %s %s", &user_id, ouser, opass, type) != EOF)
  {
    if ((strcmp(ouser, username) == 0) && (strcmp(opass, password) == 0) && (strcmp(type, "admin") == 0))
    {
      found = 1;
      break;
    }
  }

  fclose(admin);

  if (found)
  {
    system("cls");
    admin_panel();
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
    printf("\t\t\t\t\t2. Return to home\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      admin_log();
    }

    else if (ch == '2')
    {
      system("cls");
      home();
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
      admin_log();
    }
    system("cls");
    system("color A");
  }
}

void user_log()
{
  int user_id;
  char username[MAX], password[MAX], ouser[MAX], opass[MAX], type[MAX];
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  user = fopen("data\\user_logs.txt", "r");
  if (user == NULL)
  {
    printf("Error opening user file");
    exit(1);
  }
  printf("\n\t\t\xb3\xb0\xb3 User Login \xb3\xb0\xb3\n\n");
  // printf("\t\t[User Login]\n\n");
  printf("\t\tUsername -> ");
  scanf("%s", username);
  printf("\t\tPassword -> ");
  int i = 0;
  char ch;
  while ((ch = getch()) != '\r')
  {
    if (ch == '\b')
    {
      if (i > 0)
      {
        i--;
        printf("\b \b");
      }
    }
    else
    {
      password[i] = ch;
      i++;
      printf("*");
    }
  }
  password[i] = '\0';
  int found = 0;
  while (fscanf(user, "%d %s %s %s", &user_id, ouser, opass, type) != EOF)
  {
    if ((strcmp(ouser, username) == 0) && (strcmp(opass, password) == 0) && (strcmp(type, "user") == 0))
    {
      found = 1;
      break;
    }
  }

  fclose(user);

  if (found)
  {
    system("cls");
    user_panel();
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
    printf("\t\t\t\t\t2. Return to home\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      user_log();
    }
    else if (ch == '2')
    {
      system("cls");
      home();
    }
    else if (ch != '1' && ch != '2')
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
      user_log();
    }
    system("cls");
    system("color A");
  }
}

void new_user()
{
  char username[MAX], password[MAX];
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Create New User \xb3\xb0\xb3\n\n");
  // printf("\t\t[Create New]\n\n");
  printf("\t\tUser ID -> ");
  scanf("%d", &user_id);
  printf("\t\tUsername -> ");
  scanf("%s", username); // Remove the extra getch() call
  scanf("%*c");          // Consume the newline character

  user = fopen("data\\user_logs.txt", "a+");
  if (user == NULL)
  {
    printf("Unable to open/create user_logs.txt file!\n");
    exit(1);
  }

  // Check if username already exists
  bool usernameExists = false;
  char storedUsername[MAX];
  while (fscanf(user, "%s", storedUsername) == 1)
  {
    if (strcmp(username, storedUsername) == 0)
    {
      usernameExists = true;
      break;
    }
  }

  if (usernameExists)
  {
    system("cls");
    system("color C");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\tUsername already exists! Please choose a different username.\n\n");
    printf("\t\t\t\t1. Try Again\n");
    printf("\t\t\t\t2. Return to home\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      new_user();
    }

    else if (ch == '2')
    {
      system("cls");
      home();
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
      new_user();
    }
    system("cls");
    system("color A");
  }

  // Clear the file pointer and move to the end of the file for writing
  fseek(user, 0, SEEK_END);

  printf("\t\tPassword -> ");

  int i = 0;
  while (1)
  {
    char ch = getch();
    if (ch == '\r') // If Enter key is pressed, break the loop
      break;
    else if (ch == '\b' && i > 0) // If Backspace key is pressed, decrement i and move back the cursor
    {
      i--;
      printf("\b \b");
    }
    else if (ch != '\b') // If any other key is pressed, store it in the password array and display asterisk on the screen
    {
      password[i] = ch;
      i++;
      printf("*");
    }
  }

  password[i] = '\0'; // Add null character to mark the end of the password array

  fprintf(user, "\n%d\t%s\t%s\t%s\n", user_id, username, password, "user");
  fclose(user);

  system("cls");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\tNew user created successfully!\n");
  printf("\n\t\t\tPress enter to login.\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  getch();
  system("cls");
  user_log();
}

void home()
{
  int option;
  int exitProgram = false; // Initialize exitProgram to false
  do
  {
    system("color A");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Home \xb3\xb0\xb3\n\n");
    printf("\t\t1. Admin Login\n");
    printf("\t\t2. User Login\n");
    printf("\t\t3. Create New User\n");
    printf("\t\t4. About Mall\n");
    printf("\t\t5. About System\n");
    printf("\t\t6. Exit\n");
    printf("\t\t-------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      system("cls");
      admin_log();
      break;
    case 2:
      system("cls");
      user_log();
      break;
    case 3:
      system("cls");
      new_user();
      break;
    case 4:
      system("cls");
      about_mall();
      break;
    case 5:
      system("cls");
      about_system();
      break;
    case 6:
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
  } while (!exitProgram); // Check the exitProgram flag

  // Exit the program
  system("cls");
  exit(0);
}
