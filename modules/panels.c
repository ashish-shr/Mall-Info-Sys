#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include "manage_users.c"
#define MAX 100

void home();
void store_panel();
void add_stores();
void remove_stores();
void update_stores();
void display_stores();
void search_stores();
void manage_users();
void item_panel();
void add_items();
void remove_items();
void update_items();
void display_items();
void search_items();

int i, user_id;
char ch;

void add_stores()
{
  mall_info info;
  FILE *mall = NULL;
  mall = fopen("data\\about.dat", "rb");
  fread(&info, sizeof(mall_info), 1, mall);
  int max_stores = info.mall_stores;
  system("color A");
  stores sto;
  int num;
  bool exists;
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Add Stores \xb3\xb0\xb3\n\n");

  store = fopen("data\\store.dat", "ab");
  FILE *store_del = NULL;
  int count = 0;
  if (store == NULL)
  {
    printf("Unable to access file.\n");
    exit(1);
  }
  while (fread(&sto, sizeof(stores), 1, store) == 1)
  {
    count++;
  }
  fclose(store);
  printf("\t\tNo. of stores -> ");
  scanf("%d", &num);
  if (count <= max_stores)
  {
    for (int i = 0; i < num; i++)
    {
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\xb3\xb0\xb3 Add Stores \xb3\xb0\xb3\n\n");
      store = fopen("data\\store.dat", "ab");
      exists = false;
      int tmp_id;
      printf("\t\tStore ID -> ");
      scanf("%d", &tmp_id);
      rewind(store); // Move the file pointer to the beginning
      while (fread(&sto, sizeof(stores), 1, store) == 1)
      {
        if (sto.store_id == tmp_id)
        {
          exists = true;
          break;
        }
      }
      if (exists)
      {
        fclose(store);
        system("cls");
        system("color E");
        printf("\t\t-------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
        printf("\t\t-------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t  Store with ID %d already exists.\n", tmp_id);
        printf("\n\t\t\t  Please enter a valid store ID.\n\n");
        printf("\n\t\t\t  1. Try again.\n");
        printf("\n\t\t\t  2. Go back.\n");
        printf("\t\t-------------------------------------------------------------------------------------------\n");
        printf("\t\tOption -> ");
        ch = getche();
        getch();
        if (ch == '1')
        {
          system("cls");
          system("color A");
          add_stores();
          break; // Exit the loop if the user chooses to go back
        }
        else if (ch == '2')
        {
          system("cls");
          system("color A");
          store_panel();
          break; // Exit the loop if the user chooses to go back
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
          add_stores();
        }
      }
      else
      {
        backup = fopen("backup\\store_rev.dat", "ab");
        store_del = fopen("trash\\store_del.dat", "ab");
        if (store == NULL)
        {
          printf("Unable to access file.\n");
          exit(1);
        }

        // If the ID doesn't exist, proceed to input other details and write to the
        sto.store_id = tmp_id;
        printf("\t\tStore Name -> ");
        getchar();
        scanf("%[^\n]s", sto.store_name);
        printf("\t\tStore Floor -> ");
        getchar();
        scanf("%d", &sto.store_floor);
        printf("\t\tStore Status -> ");
        getchar();
        scanf("%[^\n]s", sto.store_status);
        printf("\t\tStore Owner -> ");
        getchar();
        scanf("%[^\n]s", sto.store_owner);
        printf("\t\tStore Phone no. -> ");
        getchar();
        scanf("%[^\n]s", sto.store_phone);
        fwrite(&sto, sizeof(stores), 1, store);
        fwrite(&sto, sizeof(stores), 1, backup);
        fwrite(&sto, sizeof(stores), 1, store_del);
        printf("\n");
      }
      fclose(store);
      fclose(backup);
      fclose(store_del);
    }

    system("cls");
  }
  else
  {
    system("cls");
    system("color C");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tStores are at maximum capacity! Unable to add stores.\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("cls");
    system("color A");
    store_panel();
  }
}

void remove_stores()
{
  system("color A");
  stores sto;
  items itm;
  char store_name[MAX];
  char ch;
  int s_id;

  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Remove Stores \xb3\xb0\xb3\n\n");

  printf("\t\tEnter the ID of store to remove -> ");
  scanf("%d", &s_id);
  printf("\t\tEnter name of store to remove -> ");
  scanf(" %[^\n]", store_name); // Note the space before % to consume leading whitespace
  getchar();
  // Consume the newline character entered after the store name

  FILE *store = fopen("data\\store.dat", "rb+");
  FILE *item = fopen("data\\item.dat", "rb+");
  FILE *backup_store = fopen("backup\\store_rev.dat", "rb+");
  FILE *backup_item = fopen("backup\\item_rev.dat", "rb+");

  if (store == NULL)
  {
    printf("Unable to access store file.\n");
    exit(1);
  }
  if (item == NULL)
  {
    printf("Unable to access item file.\n");
    exit(1);
  }

  FILE *tmp_store_file = fopen("temp_store.dat", "wb");
  FILE *tmp_item_file = fopen("temp_item.dat", "wb");
  FILE *tmp_store_rev = fopen("temp_store_rev.dat", "wb");
  FILE *tmp_item_rev = fopen("temp_item_rev.dat", "wb");
  if (tmp_store_file == NULL || tmp_item_file == NULL)
  {
    printf("Unable to create the temporary files.\n");
    exit(1);
  }

  bool found = false;

  // Read records from the original store file and write to the temporary store file
  while (fread(&sto, sizeof(stores), 1, store) == 1)
  {
    if ((strcmp(strlwr(sto.store_name), strlwr(store_name)) == 0) && sto.store_id == s_id)
    {
      found = true; // Store name found in the file

      // Delete items associated with the store from item.dat
      while (fread(&itm, sizeof(items), 1, item) == 1)
      {
        if (strcmp(itm.sto_name, store_name) != 0)
        {
          fwrite(&itm, sizeof(items), 1, tmp_item_file);
          fwrite(&itm, sizeof(items), 1, tmp_item_rev);
        }
      }
    }
    else
    {
      fwrite(&sto, sizeof(stores), 1, tmp_store_file);
      fwrite(&sto, sizeof(stores), 1, tmp_store_rev);
    }
  }

  // Close the store and item files
  fclose(store);
  fclose(item);
  fclose(backup_store);
  fclose(backup_item);
  fclose(tmp_store_file);
  fclose(tmp_item_file);
  fclose(tmp_store_rev);
  fclose(tmp_item_rev);

  if (found)
  {
    // Delete the original store file
    remove("data\\store.dat");
    remove("backup\\store_rev.dat");

    // Delete the original item file
    remove("data\\item.dat");
    remove("backup\\item_rev.dat");

    // Rename the temporary store file to the original store file name
    rename("temp_store.dat", "data\\store.dat");
    rename("temp_store_rev.dat", "backup\\store_rev.dat");

    // Rename the temporary item file to the original item file name
    rename("temp_item.dat", "data\\item.dat");
    rename("temp_item_rev.dat", "backup\\item_rev.dat");

    system("cls");
    system("color E");

    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t  Store '%s' has been removed.\n", store_name);
    printf("\n\t\t\t\t\t  Press enter to continue.\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("color A");

    system("cls");
  }
  else
  {
    remove("temp_store.dat");
    remove("temp_item.dat");
    remove("temp_store_rev.dat");
    remove("temp_item_rev.dat");
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t    Store '%s' does not exist.\n\n", store_name);
    printf("\n\t\t\t\t\t    Please enter a valid store name.\n\n");
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
      remove_stores();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      store_panel();
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
      remove_stores();
    }
  }
}

void update_stores()
{
  system("color A");
  stores sto;
  int store_id;
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Update Stores \xb3\xb0\xb3\n\n");
  printf("\t\tEnter ID of store to update -> ");
  scanf("%d", &store_id);
  store = fopen("data\\store.dat", "rb+");
  backup = fopen("backup\\store_rev.dat", "rb+");
  if (store == NULL)
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tStore with ID %d does not exist.\n\n", store_id);
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
      update_stores();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      store_panel();
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
      update_stores();
    }
    getch();
  }

  // Search for the store based on the ID
  while (fread(&sto, sizeof(stores), 1, store) == 1)
  {
    if (sto.store_id == store_id)
    {
      found = true; // ID found in the file
      printf("\t\tStore Name (current: %s) -> ", sto.store_name);
      getchar();
      scanf("%[^\n]s", sto.store_name);
      printf("\t\tStore Floor (current: %d) -> ", sto.store_floor);
      getchar();
      scanf("%d", &sto.store_floor);
      printf("\t\tStore Status (current: %s) -> ", sto.store_status);
      getchar();
      scanf("%[^\n]s", sto.store_status);
      printf("\t\tStore Owner (current: %s) -> ", sto.store_owner);
      getchar();
      scanf("%[^\n]s", sto.store_owner);
      printf("\t\tStore Phone no. (current: %s) -> ", sto.store_phone);
      getchar();
      scanf("%[^\n]s", sto.store_phone);

      // Move the file pointer back to update the record
      fseek(store, -(long)sizeof(stores), SEEK_CUR);
      fwrite(&sto, sizeof(stores), 1, store);
      fseek(backup, -(long)sizeof(stores), SEEK_CUR);
      fwrite(&sto, sizeof(stores), 1, backup);

      break; // Exit the loop since the update is done
    }
  }

  // Close the file
  fclose(store);
  fclose(backup);
  if (found)
  {
    system("cls");
    system("color E");

    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\tStore with ID %d has been updated.\n", store_id);
    printf("\n\t\t\tPress enter to continue.\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("cls");
    system("color A");
  }
  else
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tStore with ID %d does not exist.\n\n", store_id);
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
      update_stores();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      store_panel();
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
      update_stores();
    }
    getch();
  }
}

void display_stores()
{
  system("color A");
  stores sto;
  FILE *store = fopen("data\\store.dat", "rb");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  system("color B");
  printf("\t\t| %-4s | %-20s | %-7s | %-10s | %-20s | %-12s \n", "ID", "Name", "Floor", "Status", "Owner", "Phone");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  while (fread(&sto, sizeof(stores), 1, store) == 1)
  {
    printf("\t\t| %-4d | %-20s | %-7d | %-10s | %-20s | %-12s \n", sto.store_id, sto.store_name, sto.store_floor, sto.store_status, sto.store_owner, sto.store_phone);
  }
  fclose(store);
  printf("\n\t\tPress enter to continue! ");
  getch();
  system("cls");
  system("color A");
}

void search_stores()
{
  system("color A");
  stores sto;
  int option;
  int s_id, s_floor;
  char s_name[MAX], s_status[MAX], s_owner[MAX];
  FILE *store;
  do
  {
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Search Stores \xb3\xb0\xb3\n\n");
    printf("\t\t1. Search by id\n");
    printf("\t\t2. Search by name\n");
    printf("\t\t3. Search by floor\n");
    printf("\t\t4. Search by status\n");
    printf("\t\t5. Search by owner\n");
    printf("\t\t6. Go Back\n");
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
      store = fopen("data\\store.dat", "rb");
      if (store == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the ID -> ");
      scanf("%d", &s_id);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-7s | %-10s | %-20s | %-12s \n", "ID", "Name", "Floor", "Status", "Owner", "Phone");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&sto, sizeof(stores), 1, store) == 1)
      {
        if (sto.store_id == s_id)
        {
          printf("\t\t| %-4d | %-20s | %-7d | %-10s | %-20s | %-12s \n", sto.store_id, sto.store_name, sto.store_floor, sto.store_status, sto.store_owner, sto.store_phone);
        }
      }
      fclose(store);
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

      store = fopen("data\\store.dat", "rb");
      if (store == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Store name -> ");
      getchar();
      scanf("%[^\n]s", s_name);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-7s | %-10s | %-20s | %-12s \n", "ID", "Name", "Floor", "Status", "Owner", "Phone");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&sto, sizeof(stores), 1, store) == 1)
      {
        if (strcmp(strlwr(sto.store_name), strlwr(s_name)) == 0)
        {
          printf("\t\t| %-4d | %-20s | %-7d | %-10s | %-20s | %-12s \n", sto.store_id, sto.store_name, sto.store_floor, sto.store_status, sto.store_owner, sto.store_phone);
        }
      }
      fclose(store);
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
      printf("\n\t\t\xb3\xb0\xb3 Search by floor \xb3\xb0\xb3\n\n");
      store = fopen("data\\store.dat", "rb");
      if (store == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Floor -> ");
      scanf("%d", &s_floor);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-7s | %-10s | %-20s | %-12s \n", "ID", "Name", "Floor", "Status", "Owner", "Phone");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&sto, sizeof(stores), 1, store) == 1)
      {
        if (sto.store_floor == s_floor)
        {
          printf("\t\t| %-4d | %-20s | %-7d | %-10s | %-20s | %-12s \n", sto.store_id, sto.store_name, sto.store_floor, sto.store_status, sto.store_owner, sto.store_phone);
        }
      }
      fclose(store);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 4:
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\xb3\xb0\xb3 Search by status \xb3\xb0\xb3\n\n");
      store = fopen("data\\store.dat", "rb");
      if (store == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Status -> ");
      scanf("%s", s_status);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-7s | %-10s | %-20s | %-12s \n", "ID", "Name", "Floor", "Status", "Owner", "Phone");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&sto, sizeof(stores), 1, store) == 1)
      {
        if (strcmp(strlwr(sto.store_status), strlwr(s_status)) == 0)
        {
          printf("\t\t| %-4d | %-20s | %-7d | %-10s | %-20s | %-12s \n", sto.store_id, sto.store_name, sto.store_floor, sto.store_status, sto.store_owner, sto.store_phone);
        }
      }
      fclose(store);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 5:
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\xb3\xb0\xb3 Search by owner \xb3\xb0\xb3\n\n");
      store = fopen("data\\store.dat", "rb");
      if (store == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Owner -> ");
      getchar();
      scanf("%[^\n]s", s_owner);
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      system("color B");
      printf("\t\t| %-4s | %-20s | %-7s | %-10s | %-20s | %-12s \n", "ID", "Name", "Floor", "Status", "Owner", "Phone");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&sto, sizeof(stores), 1, store) == 1)
      {
        if (strcmp(strlwr(sto.store_owner), strlwr(s_owner)) == 0)
        {
          printf("\t\t| %-4d | %-20s | %-7d | %-10s | %-20s | %-12s \n", sto.store_id, sto.store_name, sto.store_floor, sto.store_status, sto.store_owner, sto.store_phone);
        }
      }
      fclose(store);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
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
      printf("\n\t\t\t\t\tInvalid option! Please enter a valid option.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      system("color A");
    }
  } while (option != 6);
}

void add_items()
{
  system("color A");
  stores sto;
  items itm;
  int num;
  bool found = false; // Initialize found flag as false
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Add Products \xb3\xb0\xb3\n\n");
  FILE *item_del = NULL;
  item = fopen("data\\item.dat", "ab");
  store = fopen("data\\store.dat", "rb");
  backup = fopen("backup\\item_rev.dat", "ab");
  item_del = fopen("trash\\item_del.dat", "ab");
  char store_name[MAX];
  int tmp_id;
  printf("\t\tProduct ID -> ");
  scanf("%d", &tmp_id);
  printf("\t\tStore Name -> ");
  scanf(" %[^\n]s", store_name);
  if (item == NULL && store == NULL)
  {
    fclose(item);
    fclose(store);
    fclose(backup);
    fclose(item_del);
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t%s store does not exist.\n", store_name);
    printf("\n\t\t\t\t\tPlease enter a valid store.\n\n");
    printf("\n\t\t\t\t\t1. Try Again\n");
    printf("\n\t\t\t\t\t2. Go Back\n\n");
    printf("\t\t------------------------------------------------------------------\n");
    printf("\t\tOption -> ");
    char ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      add_items();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      item_panel();
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
      add_items();
    }
  }

  while (fread(&sto, sizeof(stores), 1, store) == 1)
  {
    if ((strcmp(sto.store_name, store_name)) == 0)
    {
      found = true;
      break; // Found the store, no need to continue the loop
    }
  }
  if (found)
  {
    printf("\t\tNo. of items -> ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\xb3\xb0\xb3 Add Products \xb3\xb0\xb3\n\n");

      strcpy(itm.sto_name, store_name); // Assign the store name to the structure field

      itm.item_id = tmp_id;
      printf("\t\tProduct Name -> ");
      getchar();
      scanf("%[^\n]s", itm.item_name);
      printf("\t\tProduct Brand -> ");
      getchar();
      scanf("%[^\n]s", itm.item_brand);
      printf("\t\tProduct Price -> ");
      getchar();
      scanf("%f", &itm.item_price);
      printf("\t\tProduct Quantity -> ");
      getchar();
      scanf("%f", &itm.item_quantity);
      printf("\t\tProduct Status -> ");
      getchar();
      scanf("%[^\n]s", itm.item_status);
      fwrite(&itm, sizeof(items), 1, item);
      fwrite(&sto, sizeof(stores), 1, backup);
      fwrite(&itm, sizeof(items), 1, item_del);
    }
    fclose(item);
    fclose(store);
    fclose(backup);
    fclose(item_del);
    system("cls");
  }
  else
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t%s store does not exist.\n", store_name);
    printf("\n\t\t\t\t\tPlease enter a valid store.\n\n");
    printf("\n\t\t\t\t\t1. Try Again\n");
    printf("\n\t\t\t\t\t2. Go Back\n\n");
    printf("\t\t------------------------------------------------------------------\n");
    printf("\t\tOption -> ");
    char ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      add_items();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      item_panel();
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
      add_items();
    }
    fclose(item);
    fclose(store);
    fclose(backup);
    fclose(item_del);
  }
}

void remove_items()
{
  system("color A");
  items itm;
  int item_id;
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Remove Products \xb3\xb0\xb3\n\n");

  printf("\t\tEnter ID of product to remove -> ");
  scanf("%d", &item_id);
  FILE *item = fopen("data\\item.dat", "rb+");
  FILE *backup_item = fopen("backup\\item_rev.dat", "wb");
  if (item == NULL)
  {
    fclose(item);
    fclose(backup_item);
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tProduct with ID %d does not exist.\n\n", item_id);
    printf("\n\t\t\t\t\tPlease enter a valid product ID.\n\n");
    printf("\t\t\t\t\t1. Try Again\n");
    printf("\t\t\t\t\t2. Go Back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    char ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");
      remove_items(); // Call the function recursively to try again
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      item_panel(); // Go back to the item panel
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
      item_panel(); // Go back to the item panel
    }
  }
  FILE *tmp_file = fopen("temp.dat", "wb");
  FILE *tmp_item_rev = fopen("temp_item_rev.dat", "wb");

  bool found = false; // Flag to track if item was found

  // Read records from the original file and write to the temporary file
  while (fread(&itm, sizeof(items), 1, item) == 1)
  {
    if (itm.item_id == item_id)
    {
      found = true; // ID found in the file
    }
    else
    {
      fwrite(&itm, sizeof(items), 1, tmp_file);
      fwrite(&itm, sizeof(items), 1, tmp_item_rev);
    }
  }

  // Close all files
  fclose(item);
  fclose(tmp_file);
  fclose(backup_item);
  fclose(tmp_item_rev);

  if (found)
  {
    // Delete the original file
    remove("data\\item.dat");
    remove("backup\\item_rev.dat");

    system("cls");
    system("color E");

    // Rename the temporary file to the original file name
    rename("temp.dat", "data\\item.dat");
    rename("temp_item_rev.dat", "backup\\item_rev.dat");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\tProduct with ID %d has been removed.\n", item_id);
    printf("\n\t\t\tPress enter to continue.\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("color A");
    system("cls");
  }
  else
  {
    remove("temp.dat");
    remove("temp_item_rev.dat");
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tProduct with ID %d does not exist.\n\n", item_id);
    printf("\n\t\t\t\t\tPlease enter a valid product ID.\n\n");
    printf("\t\t\t\t\t1. Try Again\n");
    printf("\t\t\t\t\t2. Go Back\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n\n");
    printf("\t\tOption -> ");
    char ch = getche();
    getch();
    if (ch == '1')
    {
      system("cls");
      system("color A");

      remove_items(); // Call the function recursively to try again
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");

      item_panel(); // Go back to the item panel
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

      item_panel(); // Go back to the item panel
    }
  }
}

void update_items()
{
  system("color A");
  items itm;
  int item_id;
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Update Products \xb3\xb0\xb3\n\n");
  printf("\t\tEnter ID of store to update -> ");
  scanf("%d", &item_id);

  item = fopen("data\\item.dat", "rb+");
  backup = fopen("backup\\item_rev.dat", "rb+");

  if (item == NULL)
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tProduct with ID %d does not exist.\n\n", item_id);
    printf("\n\t\t\t\t\tPlease enter valid product id.\n\n");
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
      update_items();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      item_panel();
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
      update_items();
    }
  }

  // Search for the store based on the ID
  while (fread(&itm, sizeof(items), 1, item) == 1)
  {
    if (itm.item_id == item_id)
    {
      found = true; // ID found in the file

      printf("\t\tProduct Name (current: %s) -> ", itm.item_name);
      getchar();
      scanf("%[^\n]s", itm.item_name);
      printf("\t\tProduct Brand (current: %s) -> ", itm.item_brand);
      getchar();
      scanf("%[^\n]s", itm.item_brand);
      printf("\t\tProduct Price (current: %.2f) -> ", itm.item_price);
      getchar();
      scanf("%f", &itm.item_price);
      printf("\t\tProduct Quantity (current: %.2f) -> ", itm.item_quantity);
      getchar();
      scanf("%f", &itm.item_quantity);
      printf("\t\tProduct Status (current: %s) -> ", itm.item_status);
      getchar();
      scanf("%[^\n]s", itm.item_status);

      // Move the file pointer back to update the record
      fseek(item, -(long)sizeof(items), SEEK_CUR);
      fwrite(&itm, sizeof(items), 1, item);
      fseek(backup, -(long)sizeof(items), SEEK_CUR);
      fwrite(&itm, sizeof(items), 1, backup);

      break; // Exit the loop since the update is done
    }
  }
  system("cls");

  // Close the file
  fclose(item);
  fclose(backup);
  if (found)
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Notify\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\tProduct with ID %d has been updated.\n", item_id);
    printf("\n\t\t\tPress enter to continue.\n\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    getch();
    system("color A");
    system("cls");
  }
  else
  {
    system("cls");
    system("color E");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    \xdb\xdb\xdb\xb3Warning\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tProduct with ID %d does not exist.\n\n", item_id);
    printf("\n\t\t\t\t\tPlease enter valid product id.\n\n");
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
      update_items();
    }
    else if (ch == '2')
    {
      system("cls");
      system("color A");
      item_panel();
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
      update_items();
    }
    getch();
  }
}

void display_items()
{
  system("color A");
  items itm;
  printf("\t\t--------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t--------------------------------------------------------------------------------------------\n");
  FILE *item = fopen("data\\item.dat", "rb");
  system("color B");
  printf("\t\t| %-3s | %-15s | %-15s | %-15s | %-8s | %-8s | %-8s\n", "ID", "Store", "Product", "Brand", "Price", "Quantity", "Status");
  printf("\t\t--------------------------------------------------------------------------------------------\n");
  while (fread(&itm, sizeof(items), 1, item) == 1)
  {
    printf("\t\t| %-3d | %-15s | %-15s | %-15s | %-8.2f | %-8.2f | %-8s\n", itm.item_id, itm.sto_name, itm.item_name, itm.item_brand, itm.item_price, itm.item_quantity, itm.item_status);
  }
  fclose(item);
  printf("\n\t\tPress enter to continue! ");
  getch();
  system("cls");
  system("color A");
}

void search_items()
{
  system("color A");
  items itm;
  int option;
  int i_id;
  float i_price, i_quantity;
  char s_name[MAX], i_name[MAX], i_brand[MAX], i_status[MAX];
  do
  {
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Search Products \xb3\xb0\xb3\n\n");
    printf("\t\t1. Search by id\n");
    printf("\t\t2. Search by store\n");
    printf("\t\t3. Search by product\n");
    printf("\t\t4. Search by brand\n");
    printf("\t\t5. Search by status\n");
    printf("\t\t6. Go Back\n");
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
      item = fopen("data\\item.dat", "rb");
      if (item == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the ID -> ");
      scanf("%d", &i_id);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-6s | %-20s | %-15s | %-10s | %-12s |  %s\n", "ID", "Product", "Brand", "Price", "Quantity", "Status");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&itm, sizeof(items), 1, item) == 1)
      {
        if (itm.item_id == i_id)
        {
          printf("\t\t| %-6d | %-20s | %-15s | %-10.2f | %-12.2f |  %s\n", itm.item_id, itm.item_name, itm.item_brand, itm.item_price, itm.item_quantity, itm.item_status);
        }
      }
      fclose(item);
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
      printf("\n\t\t\xb3\xb0\xb3 Search by store \xb3\xb0\xb3\n\n");
      item = fopen("data\\item.dat", "rb");
      if (item == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Store name -> ");
      getchar();
      scanf("%[^\n]s", s_name);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-6s | %-20s | %-15s | %-10s | %-12s |  %s\n", "ID", "Product", "Brand", "Price", "Quantity", "Status");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&itm, sizeof(items), 1, item) == 1)
      {
        if (strcmp(strlwr(itm.sto_name), strlwr(s_name)) == 0)
        {
          printf("\t\t| %-6d | %-20s | %-15s | %-10.2f | %-12.2f |  %s\n", itm.item_id, itm.item_name, itm.item_brand, itm.item_price, itm.item_quantity, itm.item_status);
        }
      }
      fclose(item);
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
      printf("\n\t\t\xb3\xb0\xb3 Search by product \xb3\xb0\xb3\n\n");
      item = fopen("data\\item.dat", "rb");
      if (item == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Item name -> ");
      getchar();
      scanf("%[^\n]s", i_name);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-6s | %-20s | %-15s | %-10s | %-12s |  %s\n", "ID", "Product", "Brand", "Price", "Quantity", "Status");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&itm, sizeof(items), 1, item) == 1)
      {
        if (strcmp(strlwr(itm.item_name), strlwr(i_name)) == 0)
        {
          printf("\t\t| %-6d | %-20s | %-15s | %-10.2f | %-12.2f |  %s\n", itm.item_id, itm.item_name, itm.item_brand, itm.item_price, itm.item_quantity, itm.item_status);
        }
      }
      fclose(item);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 4:
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\xb3\xb0\xb3 Search by brand \xb3\xb0\xb3\n\n");
      item = fopen("data\\item.dat", "rb");
      if (item == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Brand -> ");
      getchar();
      scanf("%[^\n]s", i_brand);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-6s | %-20s | %-15s | %-10s | %-12s |  %s\n", "ID", "Product", "Brand", "Price", "Quantity", "Status");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&itm, sizeof(items), 1, item) == 1)
      {
        if (strcmp(strlwr(itm.item_brand), strlwr(i_brand)) == 0)
        {
          printf("\t\t| %-6d | %-20s | %-15s | %-10.2f | %-12.2f |  %s\n", itm.item_id, itm.item_name, itm.item_brand, itm.item_price, itm.item_quantity, itm.item_status);
        }
      }
      fclose(item);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
      break;

    case 5:
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\n\t\t\xb3\xb0\xb3 Search by status \xb3\xb0\xb3\n\n");
      item = fopen("data\\item.dat", "rb");
      if (item == NULL)
      {
        printf("Unable to access file!\n");
        exit(1);
      }
      printf("\t\tEnter the Status -> ");
      scanf("%s", i_status);
      system("color B");
      system("cls");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      printf("\t\t| %-6s | %-20s | %-15s | %-10s | %-12s |  %s\n", "ID", "Product", "Brand", "Price", "Quantity", "Status");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      while (fread(&itm, sizeof(items), 1, item) == 1)
      {
        if (strcmp(strlwr(itm.item_status), strlwr(i_status)) == 0)
        {
          printf("\t\t| %-6d | %-20s | %-15s | %-10.2f | %-12.2f |  %s\n", itm.item_id, itm.item_name, itm.item_brand, itm.item_price, itm.item_quantity, itm.item_status);
        }
      }
      fclose(item);
      printf("\n\t\tPress enter to continue! ");
      getch();
      system("cls");
      system("color A");
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
      printf("\n\t\t\t\t\tInvalid option! Please enter a valid option.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      system("color A");
    }

  } while (option != 6);
}

void store_panel()
{
  system("color A");
  int option;
  do
  {
    system("color A");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Manage Stores \xb3\xb0\xb3\n\n");
    printf("\t\t1. Add Stores\n");
    printf("\t\t2. Remove Stores\n");
    printf("\t\t3. Update Stores\n");
    printf("\t\t4. Search Stores\n");
    printf("\t\t5. Display Stores\n");
    printf("\t\t6. Go Back\n");
    printf("\t\t---------------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    getchar(); // Clear the newline character from the input buffer

    switch (option)
    {
    case 1:
      system("cls");
      add_stores();
      break;

    case 2:
      system("cls");
      remove_stores();
      break;

    case 3:
      system("cls");
      update_stores();
      break;

    case 4:
      system("cls");
      search_stores();
      break;

    case 5:
      system("cls");
      display_stores();
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

void item_panel()
{
  system("color A");
  int option;
  do
  {
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
    printf("\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\xb3\xb0\xb3 Manage Products \xb3\xb0\xb3\n\n");
    printf("\t\t1. Add Products\n");
    printf("\t\t2. Remove Products\n");
    printf("\t\t3. Update Products\n");
    printf("\t\t4. Search Products\n");
    printf("\t\t5. Display Products\n");
    printf("\t\t6. Go Back\n");
    printf("\t\t---------------------\n");
    printf("\t\tOption -> ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      system("cls");
      add_items();
      break;

    case 2:
      system("cls");
      remove_items();
      break;

    case 3:
      system("cls");
      update_items();
      break;

    case 4:
      system("cls");
      search_items();
      break;

    case 5:
      system("cls");
      display_items();
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
      printf("\n\t\t\t\t\tInvalid option! Please enter a valid option.\n\n");
      printf("\t\t-------------------------------------------------------------------------------------------\n");
      getch();
      system("cls");
      system("color A");
    }
  } while (option != 6);
}