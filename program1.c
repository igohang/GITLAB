#include <stdio.h>
void main()
{
  int win_lottery_no[10] = {1522, 1711, 5515, 7233, 5614, 8876, 1215, 4232,
                                9155, 9995};
  float win_amount[10] = {50000, 10000, 10000, 5000, 5000, 5000, 5000, 3000,
                               3000, 3000};
  int N = 10;
  int i, won, search_lottery_no;  //won is 0 if not won, 1 if has won.
  // You may not use any more variable names

  printf("\nEnter your Lottery Number (0 to end): ");
  scanf("%d", &search_lottery_no);
  while(search_lottery_no!=0)
  {
      won=0;
  for  (i=0;i<10;i++)
  {
      if(search_lottery_no==win_lottery_no[i])
      {
      won=1;
      printf("Congratulations You Won %.2f Bath!!!",win_amount[i]);
      i=10;
      }
      else
      won=0;
  }
  if(won==0)
  {
     printf("Sorry Lottery Number %d did not win",search_lottery_no);
  }
  printf("\nEnter your Lottery Number (0 to end): ");
  scanf("%d", &search_lottery_no);
  }

   printf("\nGoodBye");
}
