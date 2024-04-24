#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

const int dimension = 5;

int main()
{
    int i;
    char *nombres[dimension];
    char buffer[10];
    int largo;
    
    for(i = 0; i <dimension; i++)
    {
        printf("Ingrese el nombre %d :\n", i+1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        largo = strlen(buffer) + 1; //largo de la cadena
        nombres[i] = (char*)malloc(largo * sizeof(char));
        if(nombres[i] == NULL)
        {
            printf("Error al asignar memoria");
        }
        strcpy(nombres[i], buffer);
    }
    for(i=0;i<dimension;i++)
    {
    printf("Nombre %d, :%s\n",i+1,nombres[i]);
    }

    for(i=0;i<dimension;i++)
    {
        free(nombres[i]);
    }
    return 0;
    }



    /*int *pVect;
    int i;
    // casteo int xq sino me daria un void
    pVect = (int *)malloc(sizeof(int) * dimension);
    // acceder a los elementos , punteros normal, y subindexada
    for(i = 0; i< dimension ; i ++)
    {
        *(pVect + i) = i;
        printf("pvect[%d] = %d\n", i, *(pVect + i));
    }
    // subindex, los arreglos son punteros encubiertos
    for( i = 0; i < dimension; i++)
    {
        pVect[i] = i;
        printf("pVect[%d] = %d\n", i, pVect[i]);
    }

    free(pVect);// liberar memoria din
    getchar();
    return 0;
    */

