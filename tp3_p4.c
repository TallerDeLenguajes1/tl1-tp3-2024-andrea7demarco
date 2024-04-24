#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;


struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;
Cliente CargarClientes(Cliente *cliente, int cantidad);
void ImprimirListaDeClientes(Cliente *cliente, int cantidad);
float costoProducto(Producto prod);

int main()
{
    int cantidadClientes, i,respuesta;
    //interfaz por consola donde se solicita al usuario la cantidad de clientes
    printf("Ingrese la cantidad de clientes:\n");
    scanf("%d",&cantidadClientes);

    if(cantidadClientes > 0)
    {   
        printf("Cargara los datos? (0 = si, 1 = no)\n");
        scanf("%d",&respuesta);
        if(respuesta == 0)
        {
        //reserva de memoria dinámica para un arreglo de estructuras
        //Pclientes es un puntero que apunta a una estructura del tipo Cliente
        Cliente *Pclientes = malloc(sizeof(Cliente)*cantidadClientes);
        fflush(stdin);
        
        *Pclientes = CargarClientes(Pclientes,cantidadClientes);
        ImprimirListaDeClientes(Pclientes,cantidadClientes);
        free(Pclientes);
        }


    }

    return 0;

}

Cliente CargarClientes(Cliente *cliente, int cantidad)
{
    char nombres[cantidad];
    int longitud, i, j;
    int ProductoAleatorio;

    for(i=0; i<cantidad; i++)
    {
        cliente[i].ClienteID = i + 1;
        printf("Ingrese el nombre:\n");
        fflush(stdin);
        gets(nombres);
        longitud = strlen(nombres) + 1; //largo de la cadena
        cliente[i].NombreCliente = (char*)malloc(longitud * sizeof(char));
        if(cliente[i].NombreCliente == NULL)
        {
            printf("Error al asignar memoria");
        }
        strcpy(cliente[i].NombreCliente, nombres);

        cantidad = 1 + rand () % 4; //entre 1 y 5 inclusive

        cliente[i].CantidadProductosAPedir = cantidad;

        cliente[i].Productos = (Producto*)malloc(sizeof(Producto)*cantidad);

        for(j = 0; j < cantidad; j ++)
        {
          cliente[i].Productos[j].ProductoID = j;
          cliente[i].Productos[j].Cantidad = rand () % 9;
          ProductoAleatorio = rand() % 4;
          longitud = strlen(TiposProductos[ProductoAleatorio]) + 1;
          cliente[i].Productos[j].TipoProducto = (char*)malloc(longitud * sizeof(char));
          cliente[i].Productos[j].TipoProducto[ProductoAleatorio];
          cliente[i].Productos[j].PrecioUnitario = rand()% 90 + 10;

        }

        
    }

    return (*cliente);
}


void ImprimirListaDeClientes(Cliente *cliente, int cantidad)
{
    int largo;
    int i,j;
    float total;
    printf("Lista de cliente y productos\n");
    for(i = 0; i < cantidad; i ++)
    {
     printf("///////Cliente:///////\n");
     printf("Nombre:\n");
     puts(cliente[i].NombreCliente);
     printf("Cantidad de productos: %d\n", cliente[i].CantidadProductosAPedir);
     printf("Lista de productos:\n");

    }
    largo = cliente[i].CantidadProductosAPedir;
    for(j=0; j<largo; j++)
    {
     printf(" ID Producto : %d\n", cliente[i].Productos[j].ProductoID);
     printf("Cantidad : %d\n", cliente[i].Productos[j].Cantidad);
     printf("Producto:%s\n", cliente[i].Productos[j].TipoProducto);
     printf("Precio Unitario:$%.2f\n", cliente[i].Productos[j].PrecioUnitario);
     total += costoProducto(cliente[i].Productos[j]);
    }

    printf("Total a pagar : %.2f\n", total);
}


float costoProducto(Producto prod){

    float total;
    total= prod.Cantidad * prod.PrecioUnitario;
    return (total);
}