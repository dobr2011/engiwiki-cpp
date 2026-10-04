#include <stdio.h>


int main()
{
int n;
int f;
int g = 1;
scanf("%d %d", &n, &f);
for (int i = 1;i <= f;i++)
{
   g *= n;
}

printf("%d",g);



}
