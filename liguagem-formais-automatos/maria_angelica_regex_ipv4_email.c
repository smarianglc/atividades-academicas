#include <stdlib.h>
#include <stdio.h>

typedef struct no_lista{
    char letras;
    struct no_lista *prox;
    
}NOLISTA;

typedef struct lista{
    char vert;
    char estudante;
    char professor;
    int tam;
    NOLISTA *inicio;
    NOLISTA *fim;
    NOLISTA *p_adj;
}LISTA;

NOLISTA *cria_noLista (char caracteres){
    NOLISTA *no = (NOLISTA*)calloc(1, sizeof(NOLISTA));
    
    no -> letras = caracteres;
    no -> prox = NULL;

}

LISTA *cria_Lista(){
    LISTA *list = (LISTA*)calloc(1, sizeof(LISTA));
    
    list -> inicio = NULL;
    list -> fim = NULL;
}

void adiconar_dados(LISTA **l, char carcter, int indice){
    NOLISTA *aux = cria_noLista(carcter);

    if(l[indice]->inicio == NULL){
        l[indice] -> inicio = aux;
        l[indice] -> fim = aux;
    }
    else{
        l[indice]->fim->prox = aux;
        l[indice]->fim = l[indice]->fim->prox;
    }
}

void ler_arquivo(LISTA **l){
    FILE *arquivo = fopen("email.csv","r");

    if (arquivo == NULL){
        printf("ERRO AO LER O ARQUIVO \n");
    }
    else{
        printf("DEU BOM A LEITURA \n");
    }

    l[0] = cria_Lista();
    char caracter = fgetc(arquivo);
    int cont = 0;
    char var_email;

    while (caracter != EOF){
        if (caracter == ','){
            cont ++;
            l[cont] = cria_Lista();
            caracter = fgetc(arquivo);
            
        }
        adiconar_dados(l, caracter, cont);
        caracter = fgetc(arquivo);
    }
    
    fclose (arquivo);
}

void verifiacar_email(LISTA **l, char caracter){
    //NOLISTA *aux = cria_noLista(caracter);

    char letra_email[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int cont, i;

    for(i = 0; i < 100; i++){
        NOLISTA *aux = l[i] -> inicio;

    }


        
}

void imprimir(LISTA **l){
    NOLISTA *aux;
    int i;

    for(i = 0; i < 100; i++){
        aux = l[i] -> inicio;

        printf("inicio->");
        while (aux != NULL)
        {
            printf("%c", aux -> letras);
            aux = aux -> prox;
        }
        printf(" -> final \n");
    }
    
}

int main (void){

    LISTA **v_email = (LISTA**)malloc(100* sizeof(LISTA*));
    ler_arquivo(v_email);
    imprimir(v_email);

    return 0;
}