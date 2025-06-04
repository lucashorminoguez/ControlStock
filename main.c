#include "articulos.h"


int main(void){
    articulos_t articulos[CANT_ARTICULOS] = {0};

    printf("Bienvendio al final de Info 1\n\n");
    cargar_fichas(articulos);       //RECORDATORIO: articulos apunta a la direccion del primer elemento del vector que es de tipo struct  
    imprimir_fichas(articulos);     /*si paso &articulos es la misma direccion pero da error de tipo, porque espera la direccion
                                       de un elemento tipo struct, no un array tipo struct  */ 
    ordenar_por_stock(ASC, articulos); 

    imprimir_fichas(articulos);
    
    return 0;
}