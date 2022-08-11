#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct rest
{
  char name[1000];
  int price;
};

struct order
{
  char or_Name[1000];
  int or_Price;
} menu[100];
void quantity(char str, int price);
int main()
{
  FILE *p, *q;
  char iName[50], tname[50], ch[10], st[10], MENU[2500],n[5000];
  int pri[50], k = 0, c = 0, quant;

  char quantity[50];
  int v = 0;
  int date, month, year;
  char cname[100];
  p = fopen("invoice.txt", "a+");
  printf("Enter Today's Date (dd/mm/yyyy) :\n");
  scanf("%d%d%d", &date, &month, &year);
  fprintf(p, "%d/%d/%d\n", date, month, year);
  fprintf(p, "*******************************************\n");
  fclose(p);
  printf("*******************************************\n\n");
  struct rest food[19] = {
      "burger", 30,
      "pizza", 120,
      "momos", 35,
      "hotdog", 95,
      "sausage", 55,
      "swarma", 60,
      "roll", 60,
      "veg", 135,
      "nonveg", 145,
      "north", 155,
      "south", 165,
      "biryani", 90,
      "vtikka", 75,
      "nvtikka", 95,
      "clolipop", 80,
      "coke", 25,
      "pepsi", 25,
      "sprite", 25,
      "coldcoffee", 25};

  int g = 0;
  do
  {
    printf("\n\n========= Menu =========:\n");
    printf("1. Display Menu\n2. Ordering\n3. Bill\n4. Exit\n");
    printf("Enter your choice : \n");
    int n;
    scanf("%d", &n);
    printf("\n\n");

    switch (n)
    {
    case 1:
      q = fopen("MENU.txt", "r");
      do {
        n = fgetc(q);
        printf("%c", n);
    } while (n != EOF);
 
      printf("%s", MENU);
      fclose(q);
      break;
    case 2:
      do
      {
        printf("\n\n\n");
        printf("\t\tEnter the item name : ");
        scanf("%s", iName);

        for (int i = 0; i < 19; i++)
        {

          if (strcmp(food[i].name, iName) == 0)
          {
            strcpy(menu[g].or_Name, food[i].name);
            printf("%s\n", menu[g].or_Name);
            menu[g].or_Price = food[i].price;
            printf("%d\n", menu[g].or_Price);

            c++;
          }
        }
        g = g + 1;
        printf("\t\t\tMore order : (y/n)------|> ");
        scanf("%s", &ch);
      } while (strcmp(ch, "y") == 0);
      break;
    case 3:
      p = fopen("invoice.txt", "a+");
      printf("Enter Customer name : ");
      scanf("%s", &cname);
      printf("\n");
      fprintf(p, "== Mr/Mrs %s ==\n", cname);
      fclose(p);
      for (int i = 0; i < c; i++)
      {
        p = fopen("invoice.txt", "a+");
        printf("%s how many you wants : \n", menu[i].or_Name);
        scanf("%d", &quantity[i]);
        fprintf(p, "%s-->", menu[i].or_Name);
        fprintf(p, "%d\n", quantity[i]);
        fclose(p);
      }
      float sum = 0, sum2;
      int dinetake;
      printf("Would u like to \'dine in\' or \'takeaway\' \"press (dine in=1)/(takeaway=2)\"\n");
      scanf("%d", &dinetake);
      printf(" %d/%d/%d          Mr/Mrs %s\n", date, month, year, cname);
      printf("|------------------------------------------|\n");
      printf("|              ORIGINAL BILL               |\n");
      printf("|------------|--------------|--------------|\n");
      printf("|  Item      |     Qty      |     Price    |\n");
      printf("|------------|--------------|--------------|\n");

      for (int i = 0; i < c; i++)
      {
        printf("|\t%s\t|\t%d\t|\t%d\t|\n", menu[i].or_Name, quantity[i], menu[i].or_Price);
        sum = sum + menu[i].or_Price * quantity[i];
      }
      printf("|------------------------------------------|\n");
      if (dinetake == 1)
      {
        sum2 = (sum * 1.05);
        printf("\nBill Details : \n Item price : Rs %.2f + 2.5 %CGST + 2.5 %SGST ", sum);
        printf("\n-------------------------------------------");
        printf("\n Total Bill :           Rs %.2f ", sum2);
      }
      else
      {
        sum2 = (sum * 1.05) + 5;
        printf("Bill Details : \n Item price : Rs %.2f + 2.5 per.CGST + 2.5 per.SGST + Packing Charge ", sum);
        printf("\n-----------------------------------------------------------");
        printf("\n Total Bill :           Rs %.2f ", sum2);
      }
      p = fopen("invoice.txt", "a+");
      fprintf(p,"Total bill = %.2f\n", sum2);
      fclose(p);
      break;
    default:
      exit(1);
    }
    printf("\n\t\t\tYou want to perform further opertion (y/n):  ");
    scanf("%s", &st);

  } while (strcmp(st, "y") == 0);
  FILE *f;
  f = fopen("Rating.txt", "a+");
  int rate;
  printf("\n\nRate our Calculator out of 5 : ");
  scanf("%d", &rate);
  fprintf(f, "%d/5\n********\n", rate);
  fclose(f);
  return 0;
}