#include "articulos.h"

int agregar_index(char *descripcion, int *index, articulos_t *articulos){
    int i = 0;
    while (articulos[i].descripcion[0] && strcmp(descripcion, articulos[i].descripcion)) i++;
    *index = i;
    strcpy(articulos[i].descripcion, descripcion);
return 0;
}

void agregar_articulo(int *index, int *sucursal ,int *cantidad, articulos_t *articulos){
    articulos[*index].cantidad_sucursal[*sucursal-1] = *cantidad;
    for(int i=0;i<3;i++) articulos[*index].total += articulos[*index].cantidad_sucursal[i];
}

void intercambiar_articulos(articulos_t *a, articulos_t *b) {
    articulos_t aux = *a;  
    *a = *b;               
    *b = aux;             
}

void imprimir_fichas(articulos_t *articulos){
    int i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulos[i].descripcion[0]){
    printf("%s\t%14d\t%12d\t%12d\t%10d\n", articulos[i].descripcion, articulos[i].cantidad_sucursal[SUCURSAL_1], articulos[i].cantidad_sucursal[SUCURSAL_2], articulos[i].cantidad_sucursal[SUCURSAL_3],articulos[i].total);
        i++;
    }
}

void ordenar_por_stock(int orden, articulos_t *articulos){
    int ordenado = 0;
    while (ordenado == 0){
        ordenado = 1;
        for (int i = 0; articulos[i].total; i++){
                int comparacion;
                if (orden ==  ASC) {  //(menor a mayor segun aparicion en lista)
                    comparacion = articulos[i].total < articulos[i + 1].total;
                } else {          //(mayor a menor)
                    comparacion = articulos[i].total > articulos[i + 1].total;
                }
                if(comparacion){
                    intercambiar_articulos(&articulos[i], &articulos[i+1]);
                    ordenado = 0;
                } 
        } 
    }
    printf("\n\n###################################");
    printf("\n##############ORDENADO#############");
    printf("\n################################### \n");
}

void cargar_fichas(articulos_t *articulos){
    int  opc=0, articulo_index, sucursal, cantidad;
    char articulo[90];
    do{
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s",articulo);
        agregar_index(articulo,&articulo_index,articulos); //(descripcion, modifica el valor del index asignado en esta direccion) 
        printf("\n%s, Indice: %d\n", articulo, articulo_index);

        printf("Para que sucursal va a realizar la carga? (1,2,3)");
        scanf("%d", &sucursal);

        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d",&cantidad);
        agregar_articulo(&articulo_index,&sucursal,&cantidad,articulos);    
        printf("Desea ingresar otro articulo? 1-Si, 2-No");
        scanf("%d",&opc);
    } while (opc==1);
}
