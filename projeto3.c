#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char vetor[100][80], vetorFinal[100][80];
    for(int i = 0; i < 100; i++){
        scanf("%s", &vetor[i][0]);
    }
    for(int i = 0; i < 100; i++){
        strcpy(vetorFinal[i], vetor[i]);
    }
    // Lower case
    int j;
    for(int i = 0; i < 100; i++){
        j = 0;
        while (vetor[i][j] != '\0') {
             vetor[i][j] = tolower(vetor[i][j]);
             j++;
        }
    }
    
    // Ordenação utilizando insertion sort
    char key[80], keyFinal[80];
    for (int i = 1; i < 100; i++){
        j = i - 1;
        strcpy(key, vetor[i]);
        strcpy(keyFinal, vetorFinal[i]);
        while (j >= 0 && strcmp(vetor[j], key) > 0){
            strcpy(vetor[j+1], vetor[j]);
            strcpy(vetorFinal[j+1], vetorFinal[j]);
            j--;
        }
        strcpy(vetor[j+1], key);
        strcpy(vetorFinal[j+1], keyFinal);
    }
    for (int i = 0; i < 100; i++){
        puts(vetorFinal[i]);
    }
    
    return 0;
}