#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
  int *ptr = malloc(12 * sizeof(int));

  if (ptr == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }

  int number;
  char passwd[] = "petrova";
  char user[8];

  ptr[0] = 1;
  ptr[1] = 2;
  ptr[2] = 3;
  ptr[3] = 4;
  ptr[4] = 5;
  ptr[5] = 6;
  ptr[6] = 7;
  ptr[7] = 8;
  ptr[8] = 9;
  ptr[9] = 10;
  ptr[10] = 11;
  ptr[11] = 12;

  printf("What's the magic word? ");
  scanf("%8s", user);

  if(strcmp(passwd, user) == 0){
      printf("Access granted!\n");

      printf("--------------------\n");
      printf("Multiplication Table\n");
      printf("--------------------\n");

      printf("Pick a number: ");
      
      if(scanf("%d", &number) != 1){
        printf("Invalid input!\n");
      }else{
        for(int i=0; i<12; i++){
          printf("%d\n", ptr[i]*number);
        }
      }
    }else{
      printf("Access denied!\n");
    }
  
  free(ptr);
  
  return 0;
}
