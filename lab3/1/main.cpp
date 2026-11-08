#include <stdio.h>

long long n;

int pow(int a, int f)
{
   int g = 1;

   for (int i = 1; i <= f; i++)
   {
      g *= a;
   }
}

void to2(long long n)
{
   bool needPrint = false;
   int arr[16];
   int max_power = 0;
   while (n != 0)
   {

      while (pow(2, max_power) < n)
      {
         max_power++;
      }
      max_power--;

      arr[max_power] = 1;
      n = n - pow(2, max_power);
   }
   printf(0);
   for (int i = 15; i >= 0; i--)
   {
      if (arr[i] == 1) needPrint = true;
      if (needPrint) {
         printf("%d",arr[i]);
      }
   }
   
}
