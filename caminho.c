#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void ter_baldio (int x0, int y0, int x1, int y1, double *h, double *e){

    double distancia = sqrt((pow(x1-x0,2)+pow(y1-y0,2)));
    *e = *e + distancia;
    *h = *h + distancia;

}

void ter_residencial (int x0, int y0, int x1, int y1, double *h, double *e){
    
    double distancia = (abs((x1-x0)) + abs((y1-y0)));
    *e = *e + distancia;
    *h = *h + distancia;

}

void parque (int x0, int y0, int x1, int y1, double *h, double *e){
    double distancia = sqrt((pow(x1-x0,2)+pow(y1-y0,2)));
    *e = *e + distancia;
    *h = *h + (abs((x1-x0)) + abs((y1-y0)));

}

int main () {

    int vet[500], n, num_baldio = 0, num_residencial = 0, num_parque = 0;
    double h = 0, e = 0;

    scanf ("%i", &n);

    if (n <= 0){
        printf ("Falha no processamento dos dados.");
        return 0;
    }

    for (int i = 0, k = 0; i <= n; i++, k = k + 3)
    {
        if (i < n) {
            scanf ("%i %i %i", &vet[k], &vet[k+1], &vet[k+2]);
            if (vet[k+2] < -1 || vet[k+2] > 1){
                printf ("Falha no processamento dos dados.");
                return 0;
            }
            //quando o i chegar em seu ultimo valor, ele fara o caminho de volta, ou seja, a distancia entre o ultimo ponto dado e o primeiro
        } else if (i == n){
            if (vet[k-1] == -1){
                ter_baldio(vet[0], vet[1], vet[k-3], vet[k-2], &h, &e);
                num_baldio++;
            } else if (vet[k-1] == 0){
                ter_residencial(vet[0], vet[1], vet[k-3], vet[k-2], &h, &e);
                num_residencial++;
            } else if (vet[k-1] == 1){
                parque(vet[0], vet[1], vet[k-3], vet[k-2], &h, &e);
                num_parque++;
            }
        }

        if (i > 0 && i < n) {
            if (vet[k-1] == -1){
                ter_baldio(vet[k-3], vet[k-2], vet[k], vet[k+1], &h, &e);
                num_baldio++;
            } else if (vet[k-1] == 0){
                ter_residencial(vet[k-3], vet[k-2], vet[k], vet[k+1], &h, &e);
                num_residencial++;
            } else if (vet[k-1] == 1){
                parque(vet[k-3], vet[k-2], vet[k], vet[k+1], &h, &e);
                num_parque++;
            }
        }
    }

    printf ("Ao todo, foi passado por %i terrenos baldios, %i terrenos residenciais e %i parques.\n", num_baldio, num_residencial, num_parque);
    printf ("A diferenca total de distancia percorrida foi de %.2f metros.", fabs(h - e));

    return 0;
}