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

void cargar_fichas(articulos_t *articulos);
int agregar_index(char *articulo,int *index, articulos_t *articulos);
void agregar_articulo(int *index, int *sucursal ,int *cantidad, articulos_t *articulos);
void imprimir_fichas(articulos_t *articulos);
void ordenar_por_stock(int orden, articulos_t *articulos);
void intercambiar_articulos(articulos_t *a, articulos_t *b);


#endif