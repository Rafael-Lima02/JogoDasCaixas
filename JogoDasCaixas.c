#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    char nomeArq[200];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArq);
    fflush(stdin);

    int matriz[20][20];
    int matrizResultado[20][20];
    int size = 0;

    FILE *arq;
    arq = fopen(nomeArq, "r");
    //-------------------------------Variáveis de controle-----------------------------
    int x = 1;
    int soma1 = 0;
    int soma2 = 0;
    int k = 0;
    int l = 1;
    int maior = -1;
    int cMaior = 0;
    int fMaior = 0;
    //---------------------------------------------------------------------------------
    fscanf(arq, "%d", &num);
    
    for(int i = num; i > 0; i--){
        size += i;
    }
    //------------------------------Declaração de vetores--------------------------------
    int *vetSoma = malloc (num * 2 * sizeof (int));
    int *vetSoma2 = malloc (size * 2* sizeof (int));
    //------------------------------Zerando vetor e matriz--------------------------------
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            matriz[i][j] = 0;
        }
    }for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            matrizResultado[i][j] = 0;
        }
    }
    //------------------------------Passando os valores do aquivo para a matriz-----------
    for(int i = 0; i < num; i++){
        for(int j = 0; j < x; j++){
            fscanf(arq,"%d", &matriz[i][j]);
        }    
        x++;
    }
    x = 1;
    
    //------------------------------Pegando a soma dos valores de cada linha e guardando no vetor soma-----------
    for(int i = 1; i < num+1; i++){
        for(int j = 0; j < x; j++){
            soma1 += matriz[i-1][j];
        }
        vetSoma[k++] = soma1;
        soma1 = 0;
        x++; 
    }
    //------------------------------Somando cada elemento à soma dos elementos da linha acima-----------
    k = 0;
    x = 2;
    vetSoma2[0] = matriz[0][0];
    for(int i = 1; i <= num; i++){
        for(int y = 0; y < i; y++){
                soma2 += vetSoma[y];
        }
        
        for(int j = 0; j < x; j++){
            vetSoma2[l++] = soma2+matriz[i][j];
        }
        soma2 = 0;
        k++;
        x++;
    }
    
    for(int i = 0; i < size; i++){
        if(vetSoma2[i] > maior){
            maior = vetSoma2[i];
        }
    }
    //------------------------------Passa os valores das somas para outra matriz-----------
    x = 0;
    k = 0;

     for(int i = 0; i < num; i++){
        for(int j = 0; j <= x; j++){
            matrizResultado[i][j] = vetSoma2[k];
            k++;
        }
        x++;
    }
    //-----------------------------Acha a posição e valor do maior elemento das caixas--------
    for(int i = 0; i < num; i++){
        for(int j = 0; j <= x; j++){
            if(matrizResultado[i][j] == maior){
                cMaior = j;
                fMaior = i;
            }
        }
        x++;
    }
    if(num==0){
        printf("Resposta: fileira 0, caixa 0.");
    }
    else
        printf("Resposta: fileira %d, caixa %d.", fMaior+1,cMaior+1);
    free(vetSoma2);
    free(vetSoma);
    fclose(arq);
    return 0;
}