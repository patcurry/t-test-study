#include <stdio.h>

int main()
{
  int n, i;
  float num[100], sum = 0.0, average;

  printf("How many values will you be entering? ");
  scanf("%d", &n);

  while (n > 100 || n <= 0)
  {
    printf("Error, there should be between 1 and 100 elements.\n");
    printf("Enter the number again: ");
    scanf("%d", &n);
  }

  for (i = 0; i < n; i++)
  {
    printf("%d. Enter number: ", i + 1);
    scanf("%f", &num[i]);
    sum += num[i];
  }

  average = sum / n;
  printf("Average = %.2f\n", average);

  return 0;
}
