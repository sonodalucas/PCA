#include <stdio.h>
#include <stdbool.h>

int main(){
    int mainList[100], primos[100], maisDiv[100], menosDiv[100];
    int maior, auxPrimos, auxDiv, n, maiorDiv, menorDiv, ordKey, x;
    _Bool bPrimo;
    bPrimo = true;
    maior = auxPrimos = auxDiv = n = menorDiv= maiorDiv = ordKey = x = 0;

    for (int i = 0; i < 100; i++ ){
        scanf("%d", &mainList[i]);
    }
    for (int i = 0; i < 100; i++){
        n = 0;
        bPrimo = true;
        menorDiv = mainList[i];
        for (int j = 2; j < mainList[i]; j++){
            if ((menorDiv % j) == 0){
                menosDiv[n] = j;
                n = n + 1;
            }
        }
        if (n > auxDiv){
            maiorDiv = menorDiv;
            auxDiv = n;
            for (int j = 0; j < n; j++){
                maisDiv[j] = menosDiv[j];
            }
        }
        if (mainList[i] > maior){
            maior = mainList[i];
        }
        for (int j = 2; (j < mainList[i] && bPrimo == true); j++){
            if ((mainList[i]%j) == 0){
                bPrimo = false;
            }
        }
        if (bPrimo == true){
            if (mainList[i] != 0 && mainList[i] != 1){
                primos[auxPrimos] = mainList[i];
                auxPrimos = auxPrimos + 1;
            }
        }
    }
    for (int i = 1; i < auxPrimos; i++){
        ordKey = primos[i];
        x = i - 1;
        while (x >= 0 && primos[x] > ordKey){
            primos[x+1] = primos[x];
            x = x - 1;
        }
        primos[x+1] = ordKey;
    }
    printf("%d: ", maiorDiv);
    for (int i = 0; i < auxDiv; i++){
        printf("%d ", maisDiv[i]);
    }
    printf("\n%d\n", maior);
    for (int i = 0; i < auxPrimos; i++){
        printf("%d ", primos[i]);
    }
    printf("\n");

    return 0;
}