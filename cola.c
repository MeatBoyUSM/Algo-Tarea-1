#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

tCola * newCola(int capacidad){
    tCola *cola;
    cola = (tCola *)malloc(sizeof(tCola));
    cola ->contenido = (tCoordenada **)malloc(sizeof(tCoordenada *) * capacidad);
    cola ->size = 0;
    cola ->maximoElementos = capacidad;
    cola ->primero = 0;
    cola ->final = -1;
    return cola;
}

int SCola(tCola *Q){
    return Q->size;
}

tCoordenada * dequeue(tCola * cola){
    tCoordenada * elemento;
    if(cola ->size == 0){
        printf("La cola está vacia men\n");
    }
    else{
        elemento = cola->contenido[cola->primero];
        cola->size--;
        cola->primero++;
        if(cola->primero ==cola->maximoElementos){
            cola->primero = 0;
        }
    }
    return elemento;
}

int enqueue(tCola * cola, tCoordenada * elemento){
    if(cola->size == cola->maximoElementos){
        printf("Cola llena, no se puede encolar algo más :(\n");
        return 0;
    }
    else{
        cola->size++;
        cola->final = cola->final + 1;
        if(cola->final == cola->maximoElementos){
            cola->final = 0;
        }
        cola->contenido[cola->final] = elemento;
    }
    return 1;
}

void destroy(tCola * cola){
    int i, n = cola->maximoElementos;
    for(i = 0; i < n; i++){
        free(cola->contenido[i]);
    }
    free(cola->contenido);
    free(cola);
    return;
}

tCoordenada * newCoordenada(int fila, int columna){
    tCoordenada * newCoordenada = (tCoordenada *)malloc(sizeof(tCoordenada));
    newCoordenada->fila = fila;
    newCoordenada->columna = columna;
    return newCoordenada;
}
/*
int main(){
    tCoordenada * co1 = (tCoordenada *)malloc(sizeof(tCoordenada));
    tCoordenada * co2 = (tCoordenada *)malloc(sizeof(tCoordenada));
    co1->fila=1;
    co1->columna=10;
    co2->fila=35;
    co2->columna=2;
    tCola * cola = newCola(3);
    enqueue(cola, co1);
    enqueue(cola, co2);
    tCoordenada * co3;
    co3 = dequeue(cola);
    printf("fila: %d columna: %d\n",co3->fila,co3->columna);
    destroy(cola);
    free(co3);
    free(co1);
    free(co2);
    return 0;
}*/
