#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

int i, user_id;
char ch;
FILE *user = NULL, *backup = NULL, *tmp_file = NULL, *employee_del = NULL;
bool exitProgram = false, found = false;

typedef struct
{
  int employee_id;
  char employee_name[MAX];
  char employee_position[MAX];
  char employee_address[MAX];
  char employee_phone[MAX];
  float employee_salary;
} employee;

employee emp;

void home();
void manage_employee();
void add_employee();
void display_employee();
void remove_employee();
void update_employee();
void search_employee();

void add_employee()
{
  system("cls");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Add Employee \xb3\xb0\xb3\n\n");
  user = fopen("data\\employee.dat", "ab");
  backup = fopen("backup\\employee_rev.dat", "ab");
  employee_del = fopen("trash\\employee_del.dat", "ab");
  if (user == NULL)
  {
    fclose(user);
    fclose(backup);
    fclose(employee_del);
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t    Unable to create employee file.\n\n");
    printf("\t\t\t\t\t    1. Try Again\n");
    printf("\t\t\t\t\t    2. Go Back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getchar();
    getchar();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      add_employee();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      manage_employee();
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
      add_employee();
    }
  }
  int i, num;
  printf("\t\tNo. of employees -> ");
  scanf("%d", &num);
  for (i = 0; i < num; i++)
  {
    printf("\t\tEmployee ID -> ");
    scanf(" %d", &emp.employee_id);
    printf("\t\tEmployee Name -> ");
    scanf(" %[^\n]s", emp.employee_name);
    printf("\t\tEmployee Position -> ");
    scanf(" %[^\n]s", emp.employee_position);
    printf("\t\tEmployee Address -> ");
    scanf(" %[^\n]s", emp.employee_address);
    printf("\t\tEmployee Phone -> ");
    scanf(" %[^\n]s", emp.employee_phone);
    printf("\t\tEmployee Salary -> ");
    scanf(" %f", &emp.employee_salary);
    fwrite(&emp, sizeof(employee), 1, user);
    fwrite(&emp, sizeof(employee), 1, backup);
    fwrite(&emp, sizeof(employee), 1, employee_del);
  }
  fclose(user);
  fclose(backup);
  fclose(employee_del);
  system("cls");
}

void remove_employee()
{
  system("cls");
  system("color A");
  int e_id;
  char emp_name[MAX];
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Remove Stores \xb3\xb0\xb3\n\n");

  printf("\t\tEnter the ID of employee to remove -> ");
  scanf("%d", &e_id);
  printf("\t\tEnter the name of employee to remove -> ");
  scanf(" %[^\n]", emp_name);
  getchar();
  user = fopen("data\\employee.dat", "rb+");
  backup = fopen("backup\\employee_rev.dat", "rb+");
  if (user == NULL)
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t    Employee '%s' does not exist.\n\n", emp_name);
    printf("\n\t\t\t\t\t    Please enter a valid employee name.\n\n");
    printf("\t\t\t\t\t    1. Try Again\n");
    printf("\t\t\t\t\t    2. Go Back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getchar();
    getchar();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      remove_employee();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      manage_employee();
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
      remove_employee();
    }
  }
  FILE *tmp_emp_file = fopen("temp_emp.dat", "wb");
  FILE *tmp_emp_rev = fopen("temp_emp_rev.dat", "wb");
  if (tmp_emp_file == NULL)
  {
    printf("Unable to create the temporary files.\n");
    exit(1);
  }
  bool found = false;

  // Read records from the original store file and write to the temporary store file
  while (fread(&emp, sizeof(employee), 1, user) == 1)
  {
    if (emp.employee_id == e_id)
    {
      found = true;
    }
    else
    {
      fwrite(&emp, sizeof(employee), 1, tmp_emp_file);
      fwrite(&emp, sizeof(employee), 1, tmp_emp_rev);
    }
  }

  // Close the store and item files
  fclose(user);
  fclose(backup);
  fclose(tmp_emp_file);
  fclose(tmp_emp_rev);

  if (found)
  {
    // Delete the original store file
    remove("data\\employee.dat");
    remove("backup\\employee_rev.dat");

    // Rename the temporary store file to the original store file name
    rename("temp_emp.dat", "data\\employee.dat");
    rename("temp_emp_rev.dat", "backup\\employee_rev.dat");
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t  Employee '%s' has been removed.\n", emp_name);
    printf("\n\t\t\t\t\t  Press enter to continue.\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("color A");
    system("cls");
  }
  else
  {
    remove("temp_emp.dat");
    remove("temp_emp_rev.dat");
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t    Employee '%s' does not exist.\n\n", emp_name);
    printf("\n\t\t\t\t\t    Please enter a valid employee name.\n\n");
    printf("\t\t\t\t\t    1. Try Again\n");
    printf("\t\t\t\t\t    2. Go Back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getchar();
    getchar();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      remove_employee();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      manage_employee();
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
      remove_employee();
    }
  }
}

void update_employee()
{
  system("cls");
  system("color A");
  int emp_id;
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Update Employees \xb3\xb0\xb3\n\n");
  printf("\t\tEnter ID of employee to update -> ");
  scanf("%d", &emp_id);
  user = fopen("data\\employee.dat", "rb+");
  backup = fopen("backup\\employee_rev.dat", "rb+");
  if (user == NULL)
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tStore with ID %d does not exist.\n\n", emp_id);
    printf("\n\t\t\t\t\tPlease enter valid store id.\n\n");
    printf("\t\t\t\t\t1. Try Again\n");
    printf("\t\t\t\t\t2. Go Back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      update_employee();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      manage_employee();
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
      update_employee();
    }
  }

  // Search for the store based on the ID
  while (fread(&emp, sizeof(employee), 1, user) == 1)
  {
    if (emp.employee_id == emp_id)
    {
      found = true; // ID found in the file

      printf("\t\tEmployee ID (current: %d) -> ", emp.employee_id);
      getchar();
      scanf("%d", &emp.employee_id);
      printf("\t\tEmployee Name (current: %s) -> ", emp.employee_name);
      getchar();
      scanf("%[^\n]s", emp.employee_name);
      printf("\t\tEmployee Position (current: %s) -> ", emp.employee_position);
      getchar();
      scanf("%[^\n]s", emp.employee_position);
      printf("\t\tEmployee Address (current: %s) -> ", emp.employee_address);
      getchar();
      scanf("%[^\n]s", emp.employee_address);
      printf("\t\tEmployee Phone (current: %s) -> ", emp.employee_phone);
      getchar();
      scanf("%[^\n]s", emp.employee_phone);
      printf("\t\tEmployee Salary (current: %.2f) -> ", emp.employee_salary);
      getchar();
      scanf("%f", &emp.employee_salary);

      // Move the file pointer back to update the record
      fseek(user, -(long)sizeof(employee), SEEK_CUR);
      fwrite(&emp, sizeof(employee), 1, user);
      fseek(backup, -(long)sizeof(employee), SEEK_CUR);
      fwrite(&emp, sizeof(employee), 1, backup);

      break; // Exit the loop since the update is done
    }
  }

  // Close the file
  fclose(user);
  fclose(backup);

  if (found)
  {
    system("cls");
    system("color E");

    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\tEmployee with ID %d has been updated.\n", emp_id);
    printf("\n\t\t\tPress enter to continue.\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("color A");
  }

  else
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tStore with ID %d does not exist.\n\n", emp_id);
    printf("\n\t\t\t\t\tPlease enter valid store id.\n\n");
    printf("\t\t\t\t\t1. Try Again\n");
    printf("\t\t\t\t\t2. Go Back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      update_employee();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      manage_employee();
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
      update_employee();
    }
    getch();
  }
  system("cls");
}

void search_employee()
{
  system("cls");
  system("color A");
  int option;
  int emp_id;
  char emp_name[MAX], emp_pos[MAX];
  do
  {
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Search Stores \xb3\xb0\xb3\n\n");
    printf("\t\t1. Search by id\n");
    printf("\t\t2. Search by name\n");
    printf("\t\t3. Search by position\n");
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
      printf("\n\t\t\xb3\xb0\xb3 Search by id \xb3\xb0\xb3\n\n");
      user = fopen("data\\employee.dat", "rb");
      if (user == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the ID -> ");
      scanf("%d", &emp_id);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-10s | %-20s | %-10s | %-12s \n", "ID", "Name", "Position", "Address", "Phone", "Salary");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&emp, sizeof(employee), 1, user) == 1)
      {
        if (emp.employee_id == emp_id)
        {
          printf("\t\t| %-4d | %-20s | %-10s | %-20s | %-10s | %-12.2f \n", emp.employee_id, emp.employee_name, emp.employee_position, emp.employee_address, emp.employee_phone, emp.employee_salary);
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
      printf("\n\t\t\xb3\xb0\xb3 Search by name \xb3\xb0\xb3\n\n");
      user = fopen("data\\employee.dat", "rb");
      if (user == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Employee name -> ");
      getchar();
      scanf("%[^\n]s", emp_name);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-10s | %-20s | %-10s | %-12s \n", "ID", "Name", "Position", "Address", "Phone", "Salary");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&emp, sizeof(employee), 1, user) == 1)
      {
        if (emp.employee_id == emp_id)
        {
          printf("\t\t| %-4d | %-20s | %-10s | %-20s | %-10s | %-12.2f \n", emp.employee_id, emp.employee_name, emp.employee_position, emp.employee_address, emp.employee_phone, emp.employee_salary);
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
      printf("\n\t\t\xb3\xb0\xb3 Search by name \xb3\xb0\xb3\n\n");
      user = fopen("data\\employee.dat", "rb");
      if (user == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Employee position -> ");
      getchar();
      scanf("%[^\n]s", emp_pos);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-10s | %-20s | %-10s | %-12s \n", "ID", "Name", "Position", "Address", "Phone", "Salary");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&emp, sizeof(employee), 1, user) == 1)
      {
        if (emp.employee_id == emp_id)
        {
          printf("\t\t| %-4d | %-20s | %-10s | %-20s | %-10s | %-12.2f \n", emp.employee_id, emp.employee_name, emp.employee_position, emp.employee_address, emp.employee_phone, emp.employee_salary);
        }
      }
      fclose(user);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 4:
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
  } while (option != 4);
}

void display_employee()
{
  system("cls");
  system("color A");
  user = fopen("data\\employee.dat", "rb");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  system("color B");
  printf("\t\t| %-4s | %-20s | %-10s | %-20s | %-10s | %-12s \n", "ID", "Name", "Position", "Address", "Phone", "Salary");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  while (fread(&emp, sizeof(employee), 1, user) == 1)
  {
    printf("\t\t| %-4d | %-20s | %-10s | %-20s | %-10s | %-12.2f \n", emp.employee_id, emp.employee_name, emp.employee_position, emp.employee_address, emp.employee_phone, emp.employee_salary);
  }
  fclose(user);
  printf("\n\t\tPress enter to continue! ");
  getch();
  system("cls");
  system("color A");
}

void add_log_emp()
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
    manage_employee();
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
      add_log_emp();
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
      add_log_emp();
    }
    system("cls");
    system("color A");
  }
}

void display()
{
  system("color A");
  printf("\t\t--------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t--------------------------------------------------------------------------------------------\n");
  user = fopen("data\\employee.dat", "rb");
  if (user == NULL)
  {
    printf("Unable to access file.\n");
    exit(1);
  }
  system("color B");
  printf("\t\t| %-3s | %-15s | %-15s | %-15s | %-8s | %-8s | %-8s\n", "ID", "Store", "Product", "Brand", "Price", "Quantity", "Status");
  printf("\t\t--------------------------------------------------------------------------------------------\n");
  while (fread(&emp, sizeof(employee), 1, user) == 1)
  {
    printf("\t\t| %-3d | %-15s | %-15s | %-15s | %-8.2s | %-8.2f\n", emp.employee_id, emp.employee_name, emp.employee_position, emp.employee_address, emp.employee_phone, emp.employee_salary);
  }
  fclose(user);
  printf("\n\t\tPress enter to continue! ");
  getch();
  system("cls");
  system("color A");
}

void manage_employee()
{
  int option;
  do
  {
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Manage Employees \xb3\xb0\xb3\n\n");
    printf("\t\t1. Add Employees\n");
    printf("\t\t2. Remove Employees\n");
    printf("\t\t3. Update Employees\n");
    printf("\t\t4. Search Employees\n");
    printf("\t\t5. Display Employees\n");
    printf("\t\t6. Go Back\n");
    printf("\t\t---------------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      add_employee();
      break;

    case 2:
      system("cls");
      remove_employee();
      break;

    case 3:
      system("cls");
      update_employee();
      break;

    case 4:
      system("cls");
      search_employee();
      break;

    case 5:
      system("cls");
      display_employee();
      break;

    case 6:
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
  } while (option != 6);

  return;
}