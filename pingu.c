#include<stdio.h>

int main () {

    int m, n, p, pinguins = 0, cont = 1, turno = 1;
    //char vet1[8] = "pinguins", vet2[7] = "no gelo", vet3[5] = "uhuu!";

    scanf ("%i %i %i", &n, &m, &p);

    if (p < 1 || p > m || m < 2 || n < 1){
        return 0;
    }

    while (cont <= n)
    {
        for (int i = 0; i < turno; i++)
        {

            if (cont > n){
                break;
            }

            if ((cont % m) == 0) {
                pinguins++;
                turno++;
            }

            if (cont == (p + (m * pinguins))) {
                if (turno == 1){
                    printf ("1 pinguins\n");
                } else {
                    printf ("%i pinguins\n", pinguins);
                }
            }
            cont++;
        }

        for (int i = 0; i < turno; i++)
        {
            if (cont > n){
                break;
            }

            if ((cont % m) == 0) {
                pinguins++;
                turno++;
            }

             if (cont == (p + (m * pinguins))) {
                printf ("no gelo\n");
            }
            cont++;
        }
        for (int i = 0; i < turno; i++)
        {
            if (cont > n){
                break;
            }

            if ((cont % m) == 0) {
                pinguins++;
                turno++;
            }

             if (cont == (p + (m * pinguins))) {
                printf ("uhuu!\n");
            }
            cont++;
        }
        pinguins++;
    }
    
    return 0;
}