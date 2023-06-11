#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "manage_employees.c"
#include "settings.c"
#include "panels.c"

#define MAX 100

void home();
void lock();
void settings();
void backup_rev();
void trash();

void trash()
{
  system("color A");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Trash \xb3\xb0\xb3\n\n");
  int option;
  do
  {
    printf("\t\t1. Restore Store Data\n");
    printf("\t\t2. Restore Item Data\n");
    printf("\t\t3. Restore Employee Data\n");
    printf("\t\t4. Go Back\n");
    printf("\t\t-------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      stores sto;
      FILE *del_store = NULL;
      FILE *store = NULL;
      del_store = fopen("trash\\store_del.dat", "rb");
      store = fopen("data\\store.dat", "wb");

      if (store == NULL || del_store == NULL)
      {
        printf("Unable to access files.\n");
        exit(1);
      }

      while (fread(&sto, sizeof(stores), 1, del_store) == 1)
      {
        fwrite(&sto, sizeof(stores), 1, store);
      }

      fclose(store);
      fclose(del_store);
      system("color E");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t      \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\t\tStore data is restored successfully! Press enter to continue.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");

      getch();
      system("cls");
      trash();
      break;

    case 2:
      system("cls");
      items itm;
      FILE *del_item = NULL;
      FILE *item = NULL;
      del_item = fopen("trash\\item_del.dat", "rb");
      item = fopen("data\\item.dat", "wb");

      if (del_item == NULL)
      {
        printf("Unable to access files.\n");
        exit(1);
      }

      while (fread(&itm, sizeof(items), 1, del_item) == 1)
      {
        fwrite(&itm, sizeof(items), 1, item);
      }

      fclose(item);
      fclose(del_item);
      system("color E");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t      \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\t\tItem data is restored successfully! Press enter to continue.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      trash();
      break;

    case 3:
      system("cls");
      FILE *del_user = NULL;
      FILE *user = NULL;
      del_user = fopen("trash\\employee_del.dat", "rb");
      user = fopen("data\\employee.dat", "wb");

      if (del_user == NULL)
      {
        printf("Unable to access files.\n");
        exit(1);
      }

      while (fread(&emp, sizeof(employee), 1, del_user) == 1)
      {
        fwrite(&emp, sizeof(employee), 1, user);
      }

      fclose(user);
      fclose(del_user);
      system("color E");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t      \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\t\tEmployee data is restored successfully! Press enter to continue.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      trash();
      break;

    case 4:
      system("cls");
      home();
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

  } while (option != 4);
}

void new_user()
{
  system("color A");
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
    system("color E");

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
  system("color E");

  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\tNew user created successfully!\n");
  printf("\n\t\t\tPress enter to login.\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  getch();
  system("color A");
  system("cls");
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
    printf("\t\t1. Manage Stores\n");
    printf("\t\t2. Manage Products\n");
    printf("\t\t3. Manage Employees\n");
    printf("\t\t4. Trash\n");
    printf("\t\t5. Settings\n");
    printf("\t\t6. Logout\n");
    printf("\t\t-------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      system("cls");
      store_panel();
      break;

    case 2:
      system("cls");
      item_panel();
      break;

    case 3:
      system("cls");
      add_log_emp();
      break;

    case 4:
      system("cls");
      trash();
      break;

    case 5:
      system("cls");
      settings();
      break;

    case 6:
      lock(); // Update the exitProgram flag to true
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
