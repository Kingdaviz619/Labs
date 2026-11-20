#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolling(int arr[], int size)
{
  int random_index = rand() % size;
  return arr[random_index];
}

int main()
{
  srand(time(NULL));
  int number[] = {1, 2, 3, 4, 5, 6};
  int size;
  int user;

  printf("--------------------\n");
  printf("NUMBER-GUESSING-GAME\n");
  printf("--------------------\n\n");

  printf("Pick a number (1, 2, 3, 4, 5, 6): ");
  scanf("%d", &user);

  size = sizeof(number) / sizeof(number[0]);
  int choosen = rolling(number, size);

  if(choosen == user){
    printf("You win!\n\n");
    printf("Lucky number: %d\n", choosen);
  }else{
    printf("Better luck next time!\n\n");
    printf("Lucky number: %d\n", choosen);
  }
  return 0;
}
    



