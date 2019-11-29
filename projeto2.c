#include <stdio.h>

int fat(int n){
    if ((n == 1) || (n == 0)){
        return 1;
    }
    else{
        return n * fat(n-1);
    }
}


int bin(int n, int p){
    int numerator, denominator;
    numerator =  fat(n);
    denominator = fat(p) * fat(n - p);
    return numerator / denominator;
}


int main(){
    int line, qnt, div, aux, n;
    aux = n = 0;
    scanf("%d %d %d", & line, & qnt, & div);
    int qntDiv[2*qnt];

    while (n < qnt){
        for (int i = 0; (i <= line) && (n < qnt); i ++){
            if ((bin(line, i) % div) == 0){
                qntDiv[aux] = line;
                qntDiv[aux + 1] = i;
                aux = aux + 2;
            }
            n =n + 1;
        }
        line = line + 1;
    }
    printf("%d\n", aux/2);
    for (int i = 0; i < aux; i = i + 2){
        printf("(%d,%d)\n", qntDiv[i], qntDiv[i + 1]);
    }

    return 0;
}
