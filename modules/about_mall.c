#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

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

void about_mall()
{
  system("color B");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t  \xdb\xdb\xdb\xb3Mall InfoSys\xb3\xdb\xdb\xdb\n");
  printf("\t\t-------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\xb3\xb0\xb3 Mall Details \xb3\xb0\xb3\n\n");
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