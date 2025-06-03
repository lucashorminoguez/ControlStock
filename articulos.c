#include "articulos.h"

int agregar_index(char *descripcion, int *index){
    int i = 0;
    while (articulos[i].descripcion[0] && strcmp(descripcion, articulos[i].descripcion)) i++;
    *index = i;
    strcpy(articulos[i].descripcion, descripcion);
return 0;
}

void agregar_articulo(int *index, int *sucursal ,int *cantidad){
    articulos[*index].cantidad_sucursal[*sucursal-1] = *cantidad;
    for(int i=0;i<3;i++) articulos[*index].total += articulos[*index].cantidad_sucursal[i];
}

void intercambiar_articulos(articulos_t *a, articulos_t *b) {
    articulos_t aux = *a;  
    *a = *b;               
    *b = aux;             
}

void imprimir_fichas(){
    int i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulos[i].descripcion[0]){
    printf("%s\t%14d\t%12d\t%12d\t%10d\n", articulos[i].descripcion, articulos[i].cantidad_sucursal[SUCURSAL_1], articulos[i].cantidad_sucursal[SUCURSAL_2], articulos[i].cantidad_sucursal[SUCURSAL_3],articulos[i].total);
        i++;
    }
}

void ordenar_por_stock(int orden){
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
}
