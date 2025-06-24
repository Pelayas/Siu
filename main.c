#include <stdio.h>
#include <string.h>

struct Producto{
    char Nombre[30];
    float precio;
};

struct Venta{
    char Cliente[30];
    int cedula;
    int productos;
    float venta;
};

struct Venta Ventas[30];
    int contadorventas = 0;


void eliminar(char Cadena[])
{
    int longitud;

    longitud = strlen(Cadena);

    for (int i = 0; i < longitud; i++) {
        if (Cadena[i] == '\n'){
            Cadena[i] = '\0';
        }
    }
}

void Producto1()
{
    struct Producto Producto1;
    strcpy(Producto1.Nombre, "Pasta de Dientes");
    Producto1.precio = 3.45;

    printf("Producto 1\n");
    printf("-Nombre del producto: %s\n", Producto1.Nombre);
    printf("-Precio del producto: %.2f\n", Producto1.precio);
}

void Producto2()
{
    struct Producto Producto2;
    strcpy(Producto2.Nombre, "Conflex");
    Producto2.precio = 1.75;
    printf("Producto 2\n");
    printf("-Nombre del producto: %s\n", Producto2.Nombre);
    printf("-Precio del producto: %.2f\n", Producto2.precio);
}

void enlistarproductos()
{
    Producto1();
    printf("\n");
    Producto2();
}

void venta()
{   

    int opc;

    printf("Ingrese el nombre del cliente: ");
    getchar();
    fgets(Ventas[contadorventas].Cliente, 30, stdin);
    eliminar(Ventas[contadorventas].Cliente);

    printf("Ingrese la cedula del cliente: ");
    scanf("%d", &Ventas[contadorventas].cedula);

    printf("Elija el producto que desearia comprar\n");

    Producto1();
    printf("\n");
    Producto2();

    printf("Seleccione entre 1 y 2 >>");
    scanf("%d", &opc);

    printf("Cuantos productos desea vender: ");
    scanf("%d", &Ventas[contadorventas].productos);

    if (opc == 1)
    {
        Ventas[contadorventas].venta = Ventas[contadorventas].productos * 3.45;
    }else if(opc == 2){
        Ventas[contadorventas].venta = Ventas[contadorventas].productos * 1.75;
    }else{
        printf("Opcion invalida\n");
    }

    printf("El precio total de la venta es de %.2f", Ventas[contadorventas].venta);

    contadorventas ++;

}

int menu()
{
    int opc; 

    printf("MENU\n");
    printf("1. Visualizar Productos\n");
    printf("2. Realizar Venta\n");
    printf(">>");
    scanf("%d", &opc);

    return opc;
}

int main()
{

    int opc;

    opc = menu();

    switch (opc)
    {
    case 1:
        enlistarproductos();
        break;
    
    case 2:
        venta();
        
        break;
    
    default:
        break;
    }

    return 0;
}