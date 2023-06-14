#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

void home();
void add_log();
void login();
void manage_users();
void create_users();
void display_users();
void remove_users();
void update_users();
void search_users();

int i, user_id;
char ch;
FILE *store = NULL, *item = NULL;

void create_users()
{
  char username[MAX], password[MAX];
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Create User \xb3\xb0\xb3\n\n");

  FILE *user = NULL;
  user = fopen("data\\user_logs.txt", "a+");
  if (user == NULL)
  {
    printf("Unable to access file.\n");
    exit(1);
  }
  printf("\t\tNew username -> ");
  scanf("%s", username);

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
      create_users();
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
      create_users();
    }
    system("cls");
    system("color A");
  }

  // Clear the file pointer and move to the end of the file for writing
  fseek(user, 0, SEEK_END);

  printf("\t\tNew password -> ");

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

  fprintf(user, "\n%s\t%s\t%s", username, password, "user");
  fclose(user);
  system("cls");
  system("color E");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\tNew user created successfully!\n");
  printf("\n\t\t\tPress enter to continue.\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  getch();
  system("cls");
  system("color A");
}

void remove_users()
{
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Remove Users \xb3\xb0\xb3\n\n");
  bool found_user = false;
  int user_id, tmp_id;
  char tmp_user[MAX];
  printf("\t\tEnter ID of user to remove -> ");
  scanf("%d", &user_id);
  user = fopen("data\\user_logs.txt", "r");
  tmp_file = fopen("temp.dat", "w");
  if (user == NULL || user == NULL || tmp_file == NULL)
  {
    printf("Unable to remove users!\n");
    exit(1);
  }
  while (fscanf(user, "%d %[^\n]\n", &tmp_id, tmp_user) != EOF)
  {
    if (tmp_id == user_id)
    {
      found_user = true;
    }
    else
    {
      fprintf(tmp_file, "%d %s\n", tmp_id, tmp_user);
    }
  }
  fclose(user);
  fclose(tmp_file);
  if (found_user)
  {
    system("cls");
    system("color E");
    remove("data\\user_logs.txt");
    rename("temp.dat", "data\\user_logs.txt");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t  User with ID %d has been removed from user_logs.txt.\n", user_id);
    printf("\n\t\t\t\t\t  Press enter to continue.\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("color A");

    system("cls");
  }
  else
  {
    system("cls");
    system("color E");
    remove("temp.dat");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t  User with ID %d does not exist.\n\n", user_id);
    printf("\n\t\t\t\t\t  Press enter to continue.\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("color A");
    system("cls");
  }
}

void update_users()
{
  int tmp_id;
  char tmp_uname[MAX], tmp_upass[MAX], tmp_type[MAX];
  char uname[MAX], upass[MAX], type[MAX];
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Update Users \xb3\xb0\xb3\n\n");
  printf("\t\tEnter ID of user to update -> ");
  scanf("%d", &user_id);
  user = fopen("data\\user_logs.txt", "r+");
  if (user == NULL)
  {
    printf("Unable to access file.\n");
    exit(1);
  }
  tmp_file = fopen("temp.dat", "w");
  if (tmp_file == NULL)
  {
    printf("Unable to create temporary file.\n");
    fclose(user);
    exit(1);
  }

  // Search for the user based on the ID
  while (fscanf(user, "%d %s %s %s", &tmp_id, tmp_uname, tmp_upass, tmp_type) != EOF)
  {
    if (tmp_id == user_id)
    {
      found = true; // ID found in the file

      printf("\t\tUser name (current: %s) -> ", tmp_uname);
      scanf("%s", uname);
      printf("\t\tPassword (current: %s) -> ", tmp_upass);
      scanf("%s", upass);

      // Write the updated record to the temporary file
      fprintf(tmp_file, "%d %s %s %s\n", user_id, uname, upass, tmp_type);
    }
    else
    {
      // Write the existing record to the temporary file
      fprintf(tmp_file, "%d %s %s %s\n", tmp_id, tmp_uname, tmp_upass, tmp_type);
    }
  }

  // Close the files
  fclose(user);
  fclose(tmp_file);

  // Remove the original file and rename the temporary file
  remove("data\\user_logs.txt");
  rename("temp.dat", "data\\user_logs.txt");

  if (found)
  {
    system("cls");
    printf("\t\t------------------------------------------------------------------\n");
    printf("\n\t\t\tUser with ID %d has been updated.\n", user_id);
    printf("\n\t\t\tPress enter to continue.\n\n");
    printf("\t\t------------------------------------------------------------------\n");
    getch();
    system("cls");
  }
  else
  {
    remove("temp.dat");
    system("cls");
    system("color E");
    printf("\t\t------------------------------------------------------------------\n");
    printf("\n\t\t\tUser with ID %d does not exist.\n", user_id);
    printf("\n\t\t\t 1. Try Again\n");
    printf("\n\t\t\t 2. Go Back\n\n");
    printf("\t\t------------------------------------------------------------------\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      update_users();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      manage_users();
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
      update_users();
    }
    getch();
  }
}

void search_users()
{
  int option;
  int u_id;
  int tmp_id;
  char u_name[MAX], u_type[MAX];
  char tmp_name[MAX], tmp_pass[MAX], tmp_type[MAX];
  int goBack = 0; // Flag variable to control going back

  do
  {
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Search Users \xb3\xb0\xb3\n\n");
    printf("\t\t1. Search by id\n");
    printf("\t\t2. Search by username\n");
    printf("\t\t3. Search by type\n");
    printf("\t\t4. Go Back\n");
    printf("\t\t---------------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      user = fopen("data\\user_logs.txt", "r");
      if (user == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the ID -> ");
      scanf("%d", &u_id);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-15s | %-20s | %-20s | %-10s \n", "I.D.", "Username", "Password", "Type");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fscanf(user, "%d %s %s %s", &tmp_id, tmp_name, tmp_pass, tmp_type) != EOF)
      {
        if (tmp_id == u_id)
        {
          printf("\t\t| %-15d | %-20s | %-20s | %-10s \n", tmp_id, tmp_name, tmp_pass, tmp_type);
        }
      }
      fclose(user);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 2:
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      user = fopen("data\\user_logs.txt", "r");
      if (user == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the username -> ");
      scanf("%s", u_name);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-15s | %-20s | %-20s | %-10s \n", "I.D.", "Username", "Password", "Type");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fscanf(user, "%d %s %s %s", &tmp_id, tmp_name, tmp_pass, tmp_type) != EOF)
      {
        if (strcmp(strlwr(tmp_name), strlwr(u_name)) == 0)
        {
          printf("\t\t| %-15d | %-20s | %-20s | %-10s \n", tmp_id, tmp_name, tmp_pass, tmp_type);
        }
      }
      fclose(user);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 3:
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      user = fopen("data\\user_logs.txt", "r");
      if (user == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the type -> ");
      scanf("%s", u_type);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-15s | %-20s | %-20s | %-10s \n", "I.D.", "Username", "Password", "Type");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fscanf(user, "%d %s %s %s", &tmp_id, tmp_name, tmp_pass, tmp_type) != EOF)
      {
        if (strcmp(strlwr(tmp_type), strlwr(u_type)) == 0)
        {
          printf("\t\t| %-15d | %-20s | %-20s | %-10s \n", tmp_id, tmp_name, tmp_pass, tmp_type);
        }
      }
      fclose(user);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 4:
      goBack = 1; // Set the flag to go back
      system("cls");
      break;

    default:
      system("cls");
      system("color C");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\t\t\tInvalid option! Please enter a valid option.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      system("color A");
    }

  } while (!goBack);
  return;
}

void display_users()
{
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  FILE *user = fopen("data\\user_logs.txt", "r");
  i = 1;
  system("color B");
  printf("\t\t| %-20s | %-20s | %-10s \n", "Username", "Password", "Type");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  char username[MAX], password[MAX], type[MAX];
  while (fscanf(user, "%s\t%s\t%s\n", username, password, type) != EOF)
  {
    printf("\t\t| %-20s | %-20s | %-10s \n", username, password, type);
  }
  printf("\n\t\tPress enter to continue! ");
  getch();
  system("cls");
  system("color A");
  fclose(user);
}

void add_log()
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
  while (fscanf(admin, "%s\t%s\t%s\n", ouser, opass, type) != EOF)
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
    manage_users();
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
      add_log();
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
      add_log();
    }
    system("cls");
    system("color A");
  }
}

void manage_users()
{
  int option;
  int goBack = 0; // Flag variable to control going back

  do
  {
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Manage Users \xb3\xb0\xb3\n\n");
    printf("\t\t1. Create New User\n");
    printf("\t\t2. Remove Users\n");
    printf("\t\t3. Update Users\n");
    printf("\t\t4. Search Users\n");
    printf("\t\t5. Display Users\n");
    printf("\t\t6. Go Back\n");
    printf("\t\t---------------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      create_users();
      break;

    case 2:
      system("cls");
      remove_users();
      break;

    case 3:
      system("cls");
      update_users();
      break;

    case 4:
      system("cls");
      search_users();
      break;

    case 5:
      system("cls");
      display_users();
      break;

    case 6:
      goBack = 1; // Set the flag to go back
      system("cls");
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
    if (goBack)
    {
      break; // Exit the outer loop if goBack flag is set
    }

  } while (1); // Infinite loop for managing users

  // Return to the calling function (admin_panel) when goBack is set
  return;
}