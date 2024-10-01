#include <stdlib.h>
#include "abin.h"
// Implementacion TAD pila

// CONTENIDO DE CADA ELEMENTO DE LA PILA
// MODIFICAR: PARA LA PILA DE OPERADORES: char
// MODIFICAR: PARA LA PILA DE OPERANDOS: abin
typedef abin tipoelemOperandos;
///////////////////////////////////////////////////////

// Definicion del tipo de datos pila
struct tipo_celda
{
    tipoelemOperandos elemento;
    struct tipo_celda *sig;
};

typedef struct tipo_celda *pilaOperandos;
/////////////////////////////////////////////////////////

void crearPilaOperandos(pilaOperandos *P)
{
    *P = NULL;
}

void destruirPilaOperandos(pilaOperandos *P)
{
    pilaOperandos aux;
    aux = *P;
    while (aux != NULL)
    {
        aux = aux->sig;
        free(*P);
        *P = aux;
    }
}

unsigned esVaciaPilaOperandos(pilaOperandos P)
{
    return P == NULL;
}

tipoelemOperandos topeOperandos(pilaOperandos P)
{
    if (!esVaciaPilaOperandos(P)) /*si pila no vacia*/
        return P->elemento;
}

void pushOperandos(pilaOperandos *P, tipoelemOperandos E)
{
    pilaOperandos aux;
    aux = (pilaOperandos)malloc(sizeof(struct tipo_celda));
    aux->elemento = E;
    aux->sig = *P;
    *P = aux;
}

void popOperandos(pilaOperandos *P)
{
    pilaOperandos aux;
    if (!esVaciaPilaOperandos(*P)) /*si pila no vacia*/
    {
        aux = *P;
        *P = (*P)->sig;
        free(aux);
    }
}
