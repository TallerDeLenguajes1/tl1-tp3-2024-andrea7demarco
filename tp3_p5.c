#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i,cant;
    char** nombres;
    char buff[100];
    printf("Ingrese la cant de nombres:\n");
    scanf("%d",&cant);
    printf("Ingresar los nombres:\n"),
    nombres=(char**) malloc(cant*sizeof(char));
    fflush(stdin);
    for(i=0;i<cant;i++){
    	nombres[i]=(char*) malloc((strlen(buff)+1) * sizeof(char));
        printf("%d:",i+1);
        fflush(stdin);
        gets(buff);
        strcpy(nombres[i],buff);
    
    }

    printf("NOMBRES INGRESADOS:\n");
    for(i=0;i<cant;i++){

        printf("%s\n",nombres[i]);


    }


    for(i=0;i<cant;i++){
        free(nombres[i]);

    }


    free(nombres);
    return 0;
}