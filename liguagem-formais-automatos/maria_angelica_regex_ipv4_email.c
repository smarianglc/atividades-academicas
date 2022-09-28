#include <stdlib.h>
#include <stdio.h>
#include<string.h>

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
int tam = 0;
void adiconar_dados(char carcter, int indice, LISTA **l){
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
    FILE *arquivo = fopen("email.csv","r");
    int cont = 0;
    char var_email;

    if (arquivo == NULL){
        printf("ERRO AO LER O ARQUIVO \n");
    }
    else{
        printf("DEU BOM A LEITURA \n");
    }

    l[cont] = cria_Lista();
    //char caracter = fgetc(arquivo);

    while (var_email != EOF){
        if (var_email == ','){
            cont ++;
            l[cont] = cria_Lista();
            //l[cont] -> valor = 1;
            var_email = fgetc(arquivo);
            
        }
        adiconar_dados(var_email, cont, l);
        var_email = fgetc(arquivo);
    }
    
    fclose (arquivo);
}

void Ler_arquivo_ipv4(NOLISTA **l){
    FILE *arquivo_ipv4 = fopen("ipv4.csv","r");
    int cont = 0;
    char var_ipv4;

    if (arquivo_ipv4 == NULL){
        printf("ERRO AO LER O ARQUIVO \n");
    }
    else{
        printf("DEU BOM A LEITURA \n");
    }

    l[cont] = cria_Lista();
    //char caracter = fgetc(arquivo);

    while (var_ipv4 != EOF){
        if (var_ipv4 == ','){
            cont ++;
            l[cont] = cria_Lista();
            //l[cont] -> valor = 1;
            var_ipv4 = fgetc(arquivo_ipv4);
            
        }
        adiconar_dados(var_ipv4, cont, l);
        var_ipv4 = fgetc(arquivo_ipv4);
    }
    
    fclose (arquivo_ipv4);
}

void verifiacar_email(LISTA **l){
    //NOLISTA *aux = cria_noLista(caracter);

    int cont_ponto, val, flag;
    cont_ponto = 0;
    val = 0;
    flag = 0;

    int j, i, k, m;
    m = 0;
    j = 0;
    i = 0;

    char estudante[23] = {"@estudante.ifms.edu.br"};
    char professor[13] = {"@ifms.edu.br"};

    for(i = 0; i < tam; i++){
        NOLISTA *aux = l[i] -> inicio;

        while (aux){
            char *email = (char*)calloc(100, sizeof(char));

            while (aux->letras != '@'){
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
                for(k = 0; k < val -1; k++){
                    if(email[k] >= 'a' && email[k] <= 'z' || email[k] == '.'){
                        exit;
                    }
                    else{
                        flag++;
                    }
                }
            }
            else{
                flag++;
            }
            free(email);
            

            if(flag != 0){
                l[i] -> valor = 0;
            }

            char *email_final = (char*)calloc(80, sizeof(char));

            while (aux != NULL){
                email_final[m] = aux->letras;
                m++;
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
            free(email_final);            
        }
        printf("%d, %d",l, i);
    }
        
}

void imprimir(LISTA **l, int tam){
    NOLISTA *aux = l[tam]->inicio;

    FILE *arq_imp = fopen("resultado_email.csv","w");
    
    while (aux){
        fprintf(arq_imp, "%c", aux->letras);
        aux = aux->prox;
    }
    if(l[tam]->valor == 2){
        fprintf(arq_imp, "ESTUDADO VALIDO");
    }
    if(l[tam]->valor == 3){
        fprintf(arq_imp,"PROFESSOR VALIDO");
    }
    else{
        fprintf(arq_imp,"EMAIL INVALIDO");
    }
    
}

int main (void){

    LISTA **var = (LISTA**)malloc(100* sizeof(LISTA*));

    int num_usuario;
    printf("ESCOLHA UMA DAS OPCOES PARA VERIFICAR PRIMEIRO");    
    printf("\n1 -> email");
    printf("\n2 -> ipv4");
    printf("\n-------------------------------------------------");
    printf("\nOpcao: ");
    scanf("%d", &num_usuario);

    if(num_usuario == 1){
        ler_arquivo_email(var);
        verifiacar_email(var);
        printf("\nVALIDACAO CONCLUIDA COM SUCESSO");
        printf("\nFOI GERADO UM ARQUIVO COM O NOME - resultado_email.csv");
    }
    if(num_usuario == 2){
        Ler_arquivo_ipv4(var);
        printf("nao ta completa");
    }
    else{
        printf("OPCAO NAO EXISTE");
    }

    return 0;
}