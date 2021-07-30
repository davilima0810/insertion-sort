#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define TAM 10000

int insertion(int *v, int  tam);

int main(){
    int valor;
    FILE *fp = fopen("vetor10000.txt", "r");

    clock_t tempo;
    int i, j = TAM, //contadores 
        vetor[TAM],
        trocas; //numero de trocas


//CASOS DE TESTE SEM ARQUIVO
//------------------------------------------------------------------------
    /*for(i = 0; i < TAM; i++){//PIOR CASO: oredem decrescente
        vetor[i] = j;
        j--;
    }*/

    /*for(i = 0; i < TAM; i++){//MELHOR CASO: ordem crescente
        vetor[i] = i;
    }*/
//------------------------------------------------------------------------

//CASOS COM ARQUIVO
    i = 0;
    while((fscanf(fp,"%d\n",&valor)) != EOF){ //colocar os numeros do arquivo dentro de um vetor
        vetor[i] = valor;
        i++;
    }

    tempo = clock();
    trocas = insertion(vetor, TAM);
    tempo = clock() - tempo;

    /*printf("Ordenado: ");
    for(i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }*/
    printf("\nTempo de processamento %f s", ((float)tempo)/CLOCKS_PER_SEC);
    printf("\nNumero de troc    as = %d", trocas);
    return 0;
}

int insertion(int *v, int  tam){
    int i, j, //contadores
         aux, //variavel auxiliar
         nTrocas = 0; //numero de trocas
    bool trocou; //verifica se houve troca

    for(i = 0; i < tam - 1; i++){
        trocou = false;
        for(j = i + 1; j > 0; j--){
            if(v[j] < v[j-1]){
                aux    = v[j];
                v[j]   = v[j-1];
                v[j-1] = aux;
                trocou = true;   
            }
            if(trocou)
                nTrocas++;
        }
    }
    return nTrocas;
}
