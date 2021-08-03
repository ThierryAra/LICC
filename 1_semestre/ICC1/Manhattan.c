#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void westeland (int x0, int y0, int x1, int y1, double *h, double *e){

    double distance = sqrt((pow(x1-x0,2)+pow(y1-y0,2)));
    *e = *e + distance;
    *h = *h + distance;

}

void residential (int x0, int y0, int x1, int y1, double *h, double *e){
    
    double distance = (abs((x1-x0)) + abs((y1-y0)));
    *e = *e + distance;
    *h = *h + distance;

}

void park (int x0, int y0, int x1, int y1, double *h, double *e){
    double distance = sqrt((pow(x1-x0,2)+pow(y1-y0,2)));
    *e = *e + distance;
    *h = *h + (abs((x1-x0)) + abs((y1-y0)));

}

int main () {

    int vet[500], n, amount_westeland = 0, amount_residential = 0, amount_park = 0;
    double h = 0, e = 0;

    scanf ("%i", &n);

    if (n <= 0){
        printf ("Falha no processamento dos dados."); // Data processing failure.
        return 0;
    }

    for (int i = 0, k = 0; i <= n; i++, k = k + 3)
    {
        if (i < n) {
            scanf ("%i %i %i", &vet[k], &vet[k+1], &vet[k+2]);
            if (vet[k+2] < -1 || vet[k+2] > 1){
                printf ("Falha no processamento dos dados."); // Data processing failure.
                return 0;
            }
            // When the var 'i' get its last value, it will make its way back
            // thatis, the distance between the last givern point and the first
        } else if (i == n){
            if (vet[k-1] == -1){
                westeland(vet[0], vet[1], vet[k-3], vet[k-2], &h, &e);
                amount_westeland++;
            } else if (vet[k-1] == 0){
                residential(vet[0], vet[1], vet[k-3], vet[k-2], &h, &e);
                amount_residential++;
            } else if (vet[k-1] == 1){
                park(vet[0], vet[1], vet[k-3], vet[k-2], &h, &e);
                amount_park++;
            }
        }

        if (i > 0 && i < n) {
            if (vet[k-1] == -1){
                westeland(vet[k-3], vet[k-2], vet[k], vet[k+1], &h, &e);
                amount_westeland++;
            } else if (vet[k-1] == 0){
                residential(vet[k-3], vet[k-2], vet[k], vet[k+1], &h, &e);
                amount_residential++;
            } else if (vet[k-1] == 1){
                park(vet[k-3], vet[k-2], vet[k], vet[k+1], &h, &e);
                amount_park++;
            }
        }
    }
            // In all, was passed trough %i vacant lots, %i residencial lots and %i parks.
    printf ("Ao todo, foi passado por %i terrenos baldios %i terrenos residenciais e %i parques.\n"
            , amount_westeland, amount_residential, amount_park);
    printf ("A diferenca total de distancia percorrida foi de %.2f metros.", fabs(h - e));
            // The total difference in distance coveres was %i meters.
    return 0;
}