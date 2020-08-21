//Autor: Gustavo Fernandes
#include <stdio.h>
#include <stdlib.h>

typedef struct listaNomes
    {
        char nome;
        struct listaNomes * proximo;
        
    }s_listaNomes;

    static void reverter(struct listaNomes** ini_nome){
        struct listaNomes* anterior = NULL;
        struct listaNomes* atual = *ini_nome;
        struct listaNomes* prox = NULL;
        while (atual != NULL) {
            
            prox = atual->proximo;

            atual->proximo = anterior;

            anterior = atual;

            atual = prox;
        }
        *ini_nome = anterior;
    }

int main(int argc, char const *argv[])
{

    int total;
    int verifica = 0;

    s_listaNomes * ini_nome;
    s_listaNomes * proximo_nome;    

    ini_nome = (s_listaNomes *) malloc(sizeof(s_listaNomes));
    proximo_nome = ini_nome;

    printf("digite quantos nomes irá digitar: \n");
    scanf("%d",&total);

    while (verifica < total)
    {
        printf("digite um nome: ");
        scanf("%s", &proximo_nome->nome);   

        proximo_nome->proximo = (s_listaNomes *) malloc(sizeof(s_listaNomes));
        proximo_nome = proximo_nome->proximo;

        verifica++;
    }
    
    proximo_nome->proximo = NULL;

    reverter(&ini_nome);

    while (proximo_nome != NULL)
        {
            printf("%s \n", &proximo_nome->nome);
            proximo_nome = proximo_nome->proximo;
        }

    return 0;
    


}
