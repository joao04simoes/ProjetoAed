#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"



static int counter = 0;

//rever!!!
void procura_cima(Node *aux, Matriz *matrix) {
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    int j = 1;
    while (i - j >= 0) {
        if (aux->data[i] == aux->data[i - j]) {
            
            push(&(aux->data[i - j]));
            counter++;
            j++;
        } 
        else {
            break;  // Stop if not the same color
        }
    }
}


//rever!!!
void procura_baixo(Node *aux, Matriz *matrix) {
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    int j = 1;
    while ((i + j) < matrix->rows) {
        if (aux->data[i] == aux->data[i + j]) {
            
            push(&(aux->data[i + j]));
            counter++;
            j++;
        }
        else {
            break;  // Stop if not the same color
        }
    }
}


//rever!!!
void procura_direita(Node *aux, Matriz *matrix) {
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    Node *ptr;
    while (aux->next != NULL) {
        if (aux->data[i] == aux->next->data[i]) {
           
            push(&(aux->next->data[i]));
            counter++;
            procura_cima(aux->next, matrix);
            procura_baixo(aux->next, matrix);
        } 
        else {
            break;  // Stop if not the same color
        }
        ptr = aux->next;
        aux = ptr;
    }
}


//rever!!!
void procura_esquerda(Node *aux, Matriz *matrix) {
    int i = (matrix->rows == matrix->cordX) ? 0 : (matrix->rows - matrix->cordX);
    Node *ptr;
    while (aux->prev != NULL) {
        if (aux->data[i] == aux->prev->data[i]) {
           
            push(&(aux->prev->data[i]));
            counter++;
            procura_cima(aux->prev, matrix);
            procura_baixo(aux->prev, matrix);
        }
        else {
            break;  // Stop if not the same color
        }
        ptr = aux->prev;
        aux = ptr;
    }
}



int variante1(Matriz *matrix)
{
    Node *aux = matrix->head, *auxT;
    int valor_mancha;


    while (aux != NULL)
    {
        printf("loop procura\n");
        if (aux->indice == matrix->cordY)
        {
            printf("indice %d e cord %d \n ", aux->indice, matrix->cordY);
            break;                                                                              
        }
        auxT = aux->next;
        aux = auxT;
    }

    procura_cima(aux, matrix);
    procura_baixo(aux, matrix);
    procura_direita(aux, matrix);
    procura_esquerda(aux, matrix);


    valor_mancha = counter * (counter -1);

    return valor_mancha;  //como a variante 1 so pede o valor da mancha, para ja isto pode ficar assim, damos apenas return do valor da mancha 
}
