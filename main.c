#include <stdio.h>
#include <stdlib.h>
#include "FuncionesExpresion.h"
#include "pilaOperadores.h"
#include "pilaOperandos.h"
#include "recorridos.h"

#define MAX_SIZE 500

int main(int argc, char **argv)
{
    char exInfija[MAX_SIZE]; // Se puede pasar por linea de comados
    printf("Inserta la expresión infija: ");
    scanf("%s", exInfija);
    abin arbol = arbolExpresion(exInfija);
    printf("\nExpresion prefija: ");
    preorden(arbol);
    printf("\nExpresion infija: ");
    inorden(arbol);
    printf("\nExpresion postfija: ");
    postorden(arbol);
    destruir(&arbol);
    printf("\n");

    return 0;
}
