#include "articulos.h"


int main(void){
    int  opc=0, articulo_index, sucursal, cantidad;
    char articulo[90];

    printf("Bienvendio al final de Info 1\n\n");
    do
    {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s",articulo);
        agregar_index(articulo,&articulo_index); //(descripcion, modifica el valor del index asignado en esta direccion) 
        printf("\n%s, Indice: %d\n", articulo, articulo_index);

        printf("Para que sucursal va a realizar la carga? (1,2,3)");
        scanf("%d", &sucursal);

        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d",&cantidad);
        agregar_articulo(&articulo_index,&sucursal,&cantidad);    
        printf("Desea ingresar otro articulo? 1-Si, 2-No");
        scanf("%d",&opc);
    } while (opc==1);

    imprimir_fichas();

    ordenar_por_stock(ASC); 

    printf("\n\n###################################");
    printf("\n##############ORDENADO################");
    printf("\n################################### \n");

    imprimir_fichas();
    
    return 0;
}