#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tileblaster.h"

int variante1(Matriz *matrix)
{
    Node *aux = matrix->head, *auxT, *ptr;
    int count = 0;
    int valor_mancha;


    while (aux != NULL)
    {
        printf("loop procura\n");
        if (aux->indice == matrix->cordY)
        {
            printf("indice %d e cord %d e %d \n ", aux->indice, matrix->cordY, aux->data[...]); //quero dar print ao numero que é suposto localizarmos
            break;                                                                              //assim posso usa-lo para fazer a procura da mancha
        }
        auxT = aux->next;
        aux = auxT;
    }
    // aux->data[matrix->cordY-1];

    //procurar para a direita , precisamos de verificar se estamos fora ou dentro da matriz ? Nao pus nenhuma condição que indique isso...
    if(aux->next->data[...] == aux->data[...]) {
        ptr = &(aux->next->data[...]);
        push(ptr);
        count++;
    }
        
    
    //procurar para esquerda
    if(aux->prev->data[...] == aux->data[...]) {
        ptr = &(aux->prev->data[...]);
        push(ptr);
        count++;
    }

    //procurar para baixo
    if(aux->data[...] == aux->data[...+1]) {
        ptr = aux->data[...+1];
        push(ptr);
        count++;
    }

    //procurar para cima
    if(aux->data[...] == aux->data[...-1]) {
        ptr = aux->data[...-1];
        push(ptr);
        count++;
    }

    valor_mancha = count*(count-1);

    return valor_mancha;  //como a variante 1 so pede o valor da mancha, para ja isto pode ficar assim, damos apenas return do valor da mancha 
}
