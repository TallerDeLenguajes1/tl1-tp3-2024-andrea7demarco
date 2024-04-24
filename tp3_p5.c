#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct {
    int ProductoID; // Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
} Cliente;

Cliente CargarClientes(Cliente *cliente, int cantidad);
void ImprimirListaDeClientes(Cliente *cliente, int cantidad);
float costoProducto(Producto prod);

int main() {
    int cantidadClientes, respuesta;

    printf("Ingrese la cantidad de clientes:\n");
    scanf("%d", &cantidadClientes);

    if (cantidadClientes > 0) {
        printf("¿Cargar los datos? (0 = sí, 1 = no)\n");
        scanf("%d", &respuesta);

        if (respuesta == 0) {
            Cliente *Pclientes = malloc(sizeof(Cliente) * cantidadClientes);
            fflush(stdin);

            *Pclientes = CargarClientes(Pclientes, cantidadClientes);
            ImprimirListaDeClientes(Pclientes, cantidadClientes);
            free(Pclientes);
        }
    }

    return 0;
}

Cliente CargarClientes(Cliente *cliente, int cantidad) {
    int i, j;

    for (i = 0; i < cantidad; i++) {
        cliente[i].ClienteID = i + 1;

        printf("Ingrese el nombre del cliente %d:\n", i + 1);
        char nombres[100];
        fflush(stdin);
        gets(nombres);

        int longitud = strlen(nombres) + 1;
        cliente[i].NombreCliente = (char *)malloc(longitud * sizeof(char));

        if (cliente[i].NombreCliente == NULL) {
            printf("Error al asignar memoria");
            exit(1);
        }

        strcpy(cliente[i].NombreCliente, nombres);

        int cantidadProductos;
        printf("Ingrese la cantidad de productos para el cliente %d:\n", i + 1);
        scanf("%d", &cantidadProductos);
        cliente[i].CantidadProductosAPedir = cantidadProductos;

        cliente[i].Productos = (Producto *)malloc(sizeof(Producto) * cantidadProductos);

        for (j = 0; j < cantidadProductos; j++) {
            cliente[i].Productos[j].ProductoID = j + 1;
            cliente[i].Productos[j].Cantidad = rand() % 10 + 1;
            int ProductoAleatorio = rand() % 5;
            cliente[i].Productos[j].TipoProducto = (char *)malloc((strlen(TiposProductos[ProductoAleatorio]) + 1) * sizeof(char));
            strcpy(cliente[i].Productos[j].TipoProducto, TiposProductos[ProductoAleatorio]);
            cliente[i].Productos[j].PrecioUnitario = rand() % 91 + 10; // entre 10 y 100
        }
    }

    return *cliente;
}

void ImprimirListaDeClientes(Cliente *cliente, int cantidad) {
    int i, j;
    printf("Lista de clientes y productos:\n");
    for (i = 0; i < cantidad; i++) {
        printf("Cliente ID: %d\n", cliente[i].ClienteID);
        printf("Nombre del cliente: %s\n", cliente[i].NombreCliente);
        printf("Cantidad de productos: %d\n", cliente[i].CantidadProductosAPedir);
        printf("Productos:\n");

        float total = 0;

        for (j = 0; j < cliente[i].CantidadProductosAPedir; j++) {
            printf("  Producto ID: %d\n", cliente[i].Productos[j].ProductoID);
            printf("  Tipo de producto: %s\n", cliente[i].Productos[j].TipoProducto);
            printf("  Cantidad: %d\n", cliente[i].Productos[j].Cantidad);
            printf("  Precio unitario: %.2f\n", cliente[i].Productos[j].PrecioUnitario);
            printf("  Costo total: %.2f\n", costoProducto(cliente[i].Productos[j]));
            total += costoProducto(cliente[i].Productos[j]);
        }

        printf("Total a pagar para el cliente %d: %.2f\n\n", cliente[i].ClienteID, total);
    }
}

float costoProducto(Producto prod) {
    return prod.Cantidad * prod.PrecioUnitario;
}
