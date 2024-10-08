#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "abin.h"
#include "recorridos.h"
#include "pilaOperadores.h"
#include "pilaOperandos.h"

// Devuelve la prioridad del operador dentro de la pila.
// Prioridad('(')=0
int prioridadDentro(char op)
{
    int prior;
    switch (op)
    {
    case '^':
        prior = 3;
        break;
    case '*':
    case '/':
        prior = 2;
        break;
    case '+':
    case '-':
        prior = 1;
        break;
    case '(':
        prior = 0; // nunca va a entrar en la pila, provoca vaciado
        break;
    }
    return prior;
}

// Devuelve la prioridad del operador fuera de la pila.
// Prioridad('(')=4
int prioridadFuera(char op)
{
    int prior;
    switch (op)
    {
    case '^':
        prior = 3;
        break;
    case '*':
    case '/':
        prior = 2;
        break;
    case '+':
    case '-':
        prior = 1;
        break;
    case '(':
        prior = 4; // para que SIEMPRE entre en la pila
        break;
    }
    return prior;
}

// Devuelve 1 si c es un operador: +, -, /, *, ^, ()
unsigned esOperador(char c)
{
    unsigned ope;
    switch (c)
    {
    case '^':
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
        ope = 1;
        break;
    default:
        ope = 0;
    }
    return ope;
}

// Devuelve 1 si c es un operando: mayúsculas y minúsculas
// completar para caracteres 0 a 9
unsigned esOperando(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
        return 1;
    else
        return 0;
}

// Recibe una cadena de caracteres y devuelve el arbol de expresion

void mod_pilaOperandos(pilaOperadores *pila_operadores, pilaOperandos *pila_operandos)
{
    char caux = topeOperadores(*pila_operadores);
    popOperadores(pila_operadores);
    abin aux;
    crear(&aux);
    insizq(&aux, caux);
    insArbolder(&aux, topeOperandos(*pila_operandos));
    popOperandos(pila_operandos);
    insArbolizq(&aux, topeOperandos(*pila_operandos));
    popOperandos(pila_operandos);
    pushOperandos(pila_operandos, aux);
}
// DEBES ESCRIBIR ESTA FUNCIÓN

abin arbolExpresion(char *expr_infija)
{

    abin ret;
    abin aux;
    char c = expr_infija[0];
    pilaOperadores pila_operadores;
    pilaOperandos pila_operandos;
    crearPilaOperadores(&pila_operadores);
    crearPilaOperandos(&pila_operandos);

    for (int i = 1; c != '\0'; i++)
    {
        if (esOperando(c))
        {
            crear(&aux);
            insizq(&aux, c);
            pushOperandos(&pila_operandos, aux);
        }
        else if (esOperador(c))
        {
            while (!(esVaciaPilaOperadores(pila_operadores)) && (prioridadFuera(c) <= prioridadDentro(topeOperadores(pila_operadores))))
            {
                mod_pilaOperandos(&pila_operadores, &pila_operandos);
            }
            pushOperadores(&pila_operadores, c);
        }
        else if (c == ')')
        {
            while (topeOperadores(pila_operadores) != '(')
            {
                mod_pilaOperandos(&pila_operadores, &pila_operandos);
            }
            popOperadores(&pila_operadores);
        }
        c = expr_infija[i];
    }
    while (!esVaciaPilaOperadores(pila_operadores))
    {
        mod_pilaOperandos(&pila_operadores, &pila_operandos);
    }
    destruirPilaOperadores(&pila_operadores);
    ret = topeOperandos(pila_operandos);
    destruirPilaOperandos(&pila_operandos);
    return ret;
}
