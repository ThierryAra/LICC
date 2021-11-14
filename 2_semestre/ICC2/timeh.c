#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long double llint;
#define VERBOSO 0

llint Fi (llint n){
    llint res = 1;
    while (n > 1) {
        res *= n;
        if (VERBOSO == 1) printf ("res=%Lf\n",res);
        n--;
    }
    return res;
}

llint Fr (llint n){

    if (n == 1)
        return 1;
    else
        return n*Fr(n-1);

}

int main (int argc, char* argv[]){
    
     if (argc < 3){
        printf ("Diga o numero a ser calculado e o modo de exibicao!\n\n");
        printf ("    NUMERO\n");
        printf ("    VERBOSO(1) OU NAO(2)\n\n");
        return 1;
    }

    if (atoi(argv[1]) < 0){
        printf ("O número deve ser maior que 0.\n");
        return 1;
    }

    clock_t c1, c2;

    c1 = clock();
    llint fi = Fi(atoi(argv[1]));
    c2 = clock();

    double tempo = (c2 - c1)/(double)CLOCKS_PER_SEC;
    printf ("\n\n%Lf, iterativa: %.7f seg\n\n", fi, tempo);

    c1 = clock();
    llint fr = Fr(atoi(argv[1]));
    c2 = clock();
    
    tempo = (c2 - c1)/(double)CLOCKS_PER_SEC;
    printf ("%Lf, recursao: %.15f seg\n\n", fr, tempo);
    return 0;
}