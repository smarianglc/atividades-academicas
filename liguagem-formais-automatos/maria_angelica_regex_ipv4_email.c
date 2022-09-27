#include <stdlib.h>
#include <stdio.h>

tam = 0;

typedef struct no_lista{
    char letras;
    struct no_lista *prox;
    
}NOLISTA;

typedef struct lista{
    int valor;
    NOLISTA *inicio;
    NOLISTA *fim;
}LISTA;

NOLISTA *cria_noLista (char caracteres){
    NOLISTA *no = (NOLISTA*)malloc(sizeof(NOLISTA));
    
    no -> letras = caracteres;
    no -> prox = NULL;

}

LISTA *cria_Lista(){
    LISTA *list = (LISTA*)malloc(sizeof(LISTA));
    
    list -> inicio = NULL;
    list -> fim = NULL;
    list -> valor = 1;
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
    tam++;
}

void ler_arquivo_email(LISTA **l){
    int cont = 0;
    char var_email;

    FILE *arquivo = fopen("email.csv","r");

    if (arquivo == NULL){
        printf("ERRO AO LER O ARQUIVO \n");
    }
    else{
        printf("DEU BOM A LEITURA \n");
    }

    l[cont] = cria_Lista();
    char caracter = fgetc(arquivo);

    while (caracter != EOF){
        if (caracter == ','){
            cont ++;
            l[cont] = cria_Lista();
            l[cont] -> valor = 1;
            caracter = fgetc(arquivo);
            
        }
        adiconar_dados(l, caracter, cont);
        caracter = fgetc(arquivo);
    }
    
    fclose (arquivo);
}

void verifiacar_email(LISTA **l){
    //NOLISTA *aux = cria_noLista(caracter);

    int cont_ponto, val, flag;
    cont_ponto = 0;
    val = 0;
    flag = 0;

    int cont, j, i, k;
    cont = 0;
    j = 0;
    i = 0;

    char estudante[23] = {"@estudante.ifms.edu.br"};
    char professor[23] = {"@ifms.edu.br"};

    for(i = 0; i < tam; i++){
        NOLISTA *aux = l[i] -> inicio;

        while (aux){
            char *email = (char*)calloc(80, sizeof(char));

            while (aux -> letras != '@'){
                email[j] = aux->letras;
                j++;
                val++;
                aux = aux->prox;

            }

            for(k = 0; k < val; k++){
                if(email[k] == '.'){
                    cont_ponto++;
                }
            }

            if(cont_ponto == 1){
                for(k = 0; k < val -1; cont_ponto++){
                    if(email[k] >= 'a' && email[k] <= 'z' || email[k] == '.'){
                        exit;
                    }
                    else{
                        flag++;
                    }
                }
            }
            free(email);

            if(email != 0){
                l[i] -> valor = 0;
            }

            char *emial_final = (char*)calloc(80, sizeof(char));

            while (aux != NULL){
                emial_final[cont] = aux->letras;
                cont++;
                aux = aux->prox;
            }

            if(strcmp(email, estudante) == 0){
                if(l[i]->valor != 0){
                    l[i]->valor = 2;
                }
            }
            if(strcmp(email, professor) == 0){
                if(l[i]->valor != 0){
                    l[i]->valor = 3;
                }
            }
            else{
                l[i]->valor = 0;
            }

            break;
            free(emial_final);            
        }
        printf(l, i);
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

    printf("NO MOMENTO O CODIGO ESTA SOMENTE FAZENDO VALIDAÇÃO DE EMIAL");

    LISTA **v_email = (LISTA**)malloc(100* sizeof(LISTA*));
    ler_arquivo(v_email);
    imprimir(v_email);

    return 0;
}