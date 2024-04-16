#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{
  int M[5][12]; //fila año columna mes
  int i,j;
  srand(time(NULL));
  
  for( i = 0; i  < 5; i++) {
    for(j = 0; j < 12; j++)
    {
    M[i][j]=(rand()%40001)+10000;
    }
  }


  printf("Matriz de valores\n");
    for( i = 0; i  < 5; i++) {
    for(j = 0; j < 12; j++)
    {
    printf( "%d ",M[i][j]);

    }

    printf("\n");

  }
}

