#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tileblaster.h"

/*lista_manchas *fill_list(Matriz *newmatrix, lista_manchas *lista){
    Node *aux;
    No *newNode, *auxL;

    aux = newmatrix->head;
    auxL = lista->head;

    while(aux != NULL){
        for(int i = newmatrix->rows-1; i> -1; i--){
            if(aux->data[i] == -1)
                continue;
            if(auxL == NULL){
                newNode = novo_no(lista);
                newNode->cor = aux->data[i];
                newNode->count++;
            }
            while(auxL != NULL){
                if(find_color_first(lista, aux->data[i]) == 0){
                    newNode = novo_no(lista);
                    newNode->cor = aux->data[i];
                    newNode->count++;
                }
            }
        }
    }
    return lista;
}*/

lista_manchas *fill_list(Matriz *newmatrix, lista_manchas *lista)
{
    Node *aux = newmatrix->head;
    lista->n_cores = 0;

    while (aux != NULL)
    {
        for (int i = newmatrix->rows - 1; i >= 0; i--)
        {
            if (aux->data[i] != -1)
            {
                No *auxL = lista->head;
                int colorExists = 0;

                while (auxL != NULL)
                {
                    if (auxL->cor == aux->data[i])
                    {
                        colorExists = 1;
                        auxL->count++;
                        break;
                    }
                    auxL = auxL->next;
                }

                if (colorExists == 0)
                {
                    No *newNode = novo_no(lista);
                    newNode->cor = aux->data[i];
                    newNode->count++;
                    lista->n_cores++;
                }
            }
        }
        aux = aux->next;
    }

    return lista;
}

int thereishope_2(Matriz *newmatrix, lista_manchas *lista, int cor)
{

    No *auxL = lista->head;
    int bond = 0;

    while (auxL != NULL)
    {

        if (auxL->cor == cor)
        {

            auxL->count = auxL->count - newmatrix->pontSpot;
            lista->max = calcula_max(lista);

            if ((lista->max + (newmatrix->pontSpot * (newmatrix->pontSpot - 1)) + newmatrix->pont) >= newmatrix->variante)
            {

                lista->max = lista->max - (newmatrix->pontSpot * (newmatrix->pontSpot - 1));
                bond = 1;
            }
            else
            {

                auxL->count = auxL->count + newmatrix->pontSpot;

                bond = 0;
            }
            return bond;
        }
        auxL = auxL->next;
    }
    return bond;
}

int thereishope_3(Matriz *newmatrix, lista_manchas *lista, int cor, int maxPont)
{
    No *auxL = lista->head;
    int bond = 0;

    while (auxL != NULL)
    {

        if (auxL->cor == cor)
        {

            auxL->count = auxL->count - newmatrix->pontSpot;
            lista->max = calcula_max(lista);

            if ((lista->max + (newmatrix->pontSpot * (newmatrix->pontSpot - 1)) + newmatrix->pont) > maxPont)
            {

                lista->max = lista->max - (newmatrix->pontSpot * (newmatrix->pontSpot - 1));
                bond = 1;
            }
            else
            {
                auxL->count = auxL->count + newmatrix->pontSpot;

                bond = 0;
            }
            return bond;
        }
        auxL = auxL->next;
    }
    return bond;
}

void add_tiles(int size, lista_manchas *lista, int cor)
{
    No *auxL = lista->head;
    while (auxL != NULL)
    {
        if (auxL->cor == cor)
        {
            auxL->count = auxL->count + size;
        }
        auxL = auxL->next;
    }
}

No *novo_no(struct lista_manchas *lista)
{
    struct No *newNode = (struct No *)malloc(sizeof(struct No));
    No *aux;
    if (newNode == NULL)
    {

        exit(0);
    }
    newNode->cor = 0;
    newNode->count = 0;
    newNode->next = NULL;

    if (lista->head == NULL)
        lista->head = newNode;
    else
    {
        aux = lista->head;
        lista->head = newNode;
        lista->head->next = aux;
    }
    return newNode;
}
lista_manchas *init_listam()
{
    lista_manchas *lista = (lista_manchas *)malloc(sizeof(lista_manchas));
    if (lista == NULL)
    {

        exit(0);
    }
    lista->head = NULL;
    return lista;
}

/*int find_color_first(struct lista_manchas* lista, int cor){

    No *aux = lista->head;
    int flag = 0;
    while(aux != NULL){
        if(aux->cor == cor)
        {
            aux->count++;
            flag = 1;
            return flag;
        }
        else
            continue;
        aux = aux->next;
    }
    return  flag;
}*/

/*void clear_color(Matriz *newmatrix, lista_manchas *lista, int cor){
    Node *aux = newmatrix->head;
    No *auxL = lista->head;

    while(auxL->next != NULL){
        if(auxL->cor == cor)
            auxL->count -= newmatrix->pontSpot;

        else
            continue;
        aux = aux->next;
    }
}*/

int calcula_max(lista_manchas *lista)
{
    int max = 0;
    No *aux = lista->head;

    while (aux != NULL)
    {

        max = max + (aux->count * (aux->count - 1));
        aux = aux->next;
    }
    return max;
}

/*void revert_play(lista_manchas *lista, Matriz *matrix, int cor)
{
    No *aux = lista->head;

    while (aux != NULL)
    {
        if (aux->cor == cor)
        {
            aux->count += matrix->pontSpot;
            return;
        }
        else
            aux = aux->next;
    }
}*/

void free_lista_manchas(lista_manchas *lista)
{
    No *current = lista->head;
    while (current != NULL)
    {
        No *temp = current;
        current = current->next;
        free(temp);
    }
    lista->head = NULL;
    free(lista);
}
