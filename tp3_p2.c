#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define F 5
#define C 12


int main()
{
  int M[F][C]; //fila año columna mes
  int i,j, Max = 0, Min = 99999;
  float prom;
  int anio_max  = 0, anio_min = 0, mes_max = 0 , mes_min = 0;
  int gananciaTotal;
  srand(time(NULL));
  
  for( i = 0; i  < F; i++) {
    for(j = 0; j < C; j++)
    {
    M[i][j]=rand()%40001+10000;
    }
  }


  printf("Matriz de valores\n");
    for( i = 0; i  < F; i++) {
    for(j = 0; j < C; j++)
    {
    printf( "%d ",M[i][j]);

    }

    printf("\n");

  }

  // promedio de ganancias por año 
    for( i = 0; i  < F; i++) {
    gananciaTotal = 0; 
    for(j = 0; j < C; j++)
    { 
    gananciaTotal +=  M[i][j];

    }
    prom =  ((float)gananciaTotal/12);
    printf("promedio ganancia del año %d : %.2f\n",i +1 ,prom );

  }

  // obtener max y minimo de ganancias 
  //mostart año y mes que ocurrió
   for( i = 0; i < F; i++ ) {

    for (j = 0; j < C; j ++ )
    {
     if( M[i][j] > Max )
     {
      Max = M[i][j];
      anio_max=i + 1;
      mes_max=j + 1;
     } else {
      if( M[i][j] < Min)
      {
        Min = M[i][j];
        mes_min = j + 1;
        anio_min = i +1 ;
        
      }
     }
    }


   }

   
   

  printf("Max : %d, mes : %d, anio : %d\n",Max , mes_max, anio_max);
  printf("Min : %d, mes : %d, anio : %d\n", Min, mes_min, anio_min);


  

  return 0;
}

