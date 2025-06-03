#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <stdio.h>
#include <string.h>

#define CANT_ARTICULOS 60
#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define TOTAL 4
#define ASC 1
#define DESC 0


typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3];
    int total;
} articulos_t;
articulos_t articulos[CANT_ARTICULOS];


int agregar_index(char *articulo,int *index);
void agregar_articulo(int *index, int *sucursal ,int *cantidad);
void imprimir_fichas();
void ordenar_por_stock(int orden);
void intercambiar_articulos(articulos_t *a, articulos_t *b);
//char buscar_por_index(int *index);

#endif