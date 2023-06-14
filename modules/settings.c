#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
  char mall_name[MAX];
  char mall_address[MAX];
  int mall_floor;
  int mall_stores;
  char mall_phone[MAX];
  char mall_email[MAX];

} mall_info;

FILE *mall = NULL;

typedef struct
{
  int store_id;
  char store_name[MAX];
  int store_floor;
  char store_status[MAX];
  char store_owner[MAX];
  char store_phone[MAX];
} stores;

typedef struct
{
  int item_id;
  char sto_name[MAX];
  char item_name[MAX];
  char item_brand[MAX];
  float item_price;
  float item_quantity;
  char item_status[MAX];
} items;

void settings();
void home();
void add_log();
void reset();
void reset_log();

void reset_log()
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
    printf("\t\t\t\t\t2. Go back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      reset_log();
    }
    else if (ch == '2')
    {
      system("cls");
      settings();
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
      reset_log();
    }
    system("cls");
    system("color A");
  }
}
void reset()
{
  reset_log();
  system("color A");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Reset \xb3\xb0\xb3\n\n");
  int option;
  do
  {
    printf("\t\t1. Reset the system\n");
    printf("\t\t2. Go Back\n");
    printf("\t\t-------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      remove("data\\about.dat");
      remove("data\\employee.dat");
      remove("data\\item.dat");
      remove("data\\store.dat");
      remove("data\\user_logs.txt");
      remove("trash\\employee_del.dat");
      remove("trash\\item_del.dat");
      remove("trash\\store_del.dat");
      system("cls");
      system("color C");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\t\t\tSystem reset successfully! Please restart the program.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      system("color A");
      exit(1);
      break;

    case 2:
      system("cls");
      settings();
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
  } while (option != 2);
}

void backup_rev()
{
  system("color A");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Backup and Recovery \xb3\xb0\xb3\n\n");
  int option;
  do
  {
    printf("\t\t1. Begin Recovery\n");
    printf("\t\t2. Go Back\n");
    printf("\t\t-------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      stores sto;
      items itm;
      FILE *bck_store = NULL, *bck_item = NULL, *bck_emp = NULL;
      FILE *store = NULL, *item = NULL, *user = NULL;
      bck_store = fopen("backup\\store_rev.dat", "rb");
      bck_item = fopen("backup\\item_rev.dat", "rb");
      bck_emp = fopen("backup\\employee_rev.dat", "rb");
      store = fopen("data\\store.dat", "ab");
      item = fopen("data\\item.dat", "ab");
      user = fopen("data\\employee.dat", "ab");
      if (store == NULL || item == NULL || user == NULL)
      {
        while (fread(&sto, sizeof(stores), 1, bck_store) == 1)
        {
          fwrite(&sto, sizeof(stores), 1, store);
        }
        while (fread(&itm, sizeof(items), 1, bck_item) == 1)
        {
          fwrite(&itm, sizeof(items), 1, item);
        }
        while (fread(&emp, sizeof(employee), 1, bck_emp) == 1)
        {
          fwrite(&emp, sizeof(employee), 1, user);
        }
      }
      fclose(bck_store);
      fclose(bck_item);
      fclose(bck_emp);
      fclose(store);
      fclose(item);
      fclose(user);
      system("color E");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t      \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\t\t\tRecovery successful! Press enter to continue.\n\n");
      getch();
      system("cls");
      backup_rev();
      break;

    case 2:
      system("cls");
      settings();
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
  } while (option != 2);
}

void about_mall()
{
  system("color B");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 About Mall \xb3\xb0\xb3\n\n");
  mall_info info;
  mall = fopen("data\\about.dat", "rb");
  if (mall == NULL)
  {
    printf("About.dat unable to access!\n");
    exit(1);
  }
  while (fread(&info, sizeof(mall_info), 1, mall) == 1)
  {
    printf("\t\t------------------------------------------\n");
    printf("\t\t| Mall Name      || %s\n", info.mall_name);
    printf("\t\t------------------------------------------\n");
    printf("\t\t| Mall Address   || %s\n", info.mall_address);
    printf("\t\t------------------------------------------\n");
    printf("\t\t| Mall Floors    || %d\n", info.mall_floor);
    printf("\t\t------------------------------------------\n");
    printf("\t\t| Mall Stores    || %d\n", info.mall_stores);
    printf("\t\t------------------------------------------\n");
    printf("\t\t| Mall Phone No. || %s\n", info.mall_phone);
    printf("\t\t------------------------------------------\n");
    printf("\t\t| Mall Email     || %s\n", info.mall_email);
    printf("\t\t------------------------------------------\n");
  }
  fclose(mall);
  printf("\n\t\tPress enter to continue! ");
  getch();
  system("cls");
  system("color A");
}

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

void settings()
{
  int option;
  do
  {
    system("color A");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Settings \xb3\xb0\xb3\n\n");
    printf("\t\t1. Backup and Recovery\n");
    printf("\t\t2. Reset the system\n");
    printf("\t\t3. Manage users\n");
    printf("\t\t4. About Mall\n");
    printf("\t\t5. About System\n");
    printf("\t\t6. Go Back\n");
    printf("\t\t-------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      backup_rev();
      break;

    case 2:
      system("cls");
      reset();
      break;

    case 3:
      system("cls");
      add_log();
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
  } while (option != 6);
}