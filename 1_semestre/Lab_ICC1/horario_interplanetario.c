#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef unsigned long long int ull_int;

void calc_tempo(long long int seg, char planeta[], ull_int *d, ull_int *h, ull_int *m, ull_int *s){
    if (strcmp(planeta, "terra") == 0 || strcmp(planeta, "Terra") == 0){
        *d = abs(seg/(24*3600));
        seg -= *d * (24*3600);
    } else if (strcmp(planeta, "mercurio") == 0 || strcmp(planeta, "Mercurio") == 0){
        *d = abs(seg/(3600*((58*24) + 16)));
        seg -= *d * (3600*((58*24) + 16));    
    } else if (strcmp(planeta, "jupiter") == 0 || strcmp(planeta, "Jupiter") == 0){
        *d = abs(seg/((3600*9) + (56*60)));
        seg -= *d * ((3600*9) + (56*60));
        
    } else if (strcmp(planeta, "venus") == 0 || strcmp(planeta, "Venus") == 0){
        *d = abs(seg/((24*3600)*243));
        seg -= *d * ((24*3600)*243);
    }

    if (seg != 0){
        *h = abs(seg/3600);
        seg -= *h * (3600);
        if (seg != 0){
            *m = abs(seg/60);
            seg -= *m * (60);
            if (seg != 0){
                *s = abs(seg/1);
                seg -= *s;
            }
        }
    }
}

int main () {

    ull_int seg, d = 0, h = 0, m = 0, s = 0;
    char planeta[8] = {};

    scanf ("%llu", &seg);
    scanf (" %s", planeta);

    calc_tempo(seg, planeta, &d, &h, &m, &s);

    printf ("%llu segundos no planeta %s equivalem a:\n%llu dias, %llu horas, %llu minutos e %llu segundos\n", seg, planeta, d, h, m, s);

    return 0;
}