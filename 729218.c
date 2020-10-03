// ATIVIDADE PARA COMPUTO DE FREQUENCIA - F5
//Informações do estudante
// Nome: Hiago Rafael de Souza
// Curso: Engenharia de Computação  
// RA: 729218

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo No de uma fila implementada usando lista ligada
typedef struct no{
    int info;
    struct no * prox;
}No;

//retorna um ponteiro para o inicio da fila criada
No * cria(){

  No *inicio;
  inicio = NULL;

  return inicio;

}

No *fim = NULL; //ponteiro que será usado para apontar para o fim da lista

//recebe o inicio da fila e o valor do no a ser inserido
//retorna um ponteiro atualizado para o inicio da fila
No * entra(No * inicio, int val){
    No *new;
    new = (No*) malloc(sizeof(No));
    new->info = val;

    if(inicio==NULL)
        inicio=new;

    else
        fim->prox = new;

    fim = new;
    new->prox = NULL;
    return inicio;
}

//recebe o inicio da fila e  um ponteiro para uma variavel cujo valor vai sair da fila
//retorna um ponteiro atualizado para o inicio da fila

No * sai(No * inicio, int * val){
    No *saindo;
    saindo = inicio;
    *val = saindo->info;
    inicio=inicio->prox;
    free(saindo);
    saindo=NULL;
    return inicio;
}

//recebe o inicio da fila
//retorna 1 se fila vazia, 0 caso contrario
int vazia(No * inicio){

    if(inicio==NULL)
        return 1;
    else
        return 0;
}


int main(int argc, char *argv[])
{


    No * fila = NULL; //aponta para o inicio da fila

    fila = cria();

    int n, i, x;

    //leitura do inteiro que indicara o numero de elementos da fila
    scanf("%d", &n);

    //entra os elementos de 0 a n-1 na fila
    for ( i = 0; i < n; i++)
        fila = entra(fila,i);

    //imprime(fila); //so usada para verificacao de insercao, nao pertence ao TAD fila

    //sai os elementos que entraram na fila
    for ( i = 0; i < n; i++){
        fila = sai(fila,&x);
        printf("%d",x);
    }

    return 0;
}