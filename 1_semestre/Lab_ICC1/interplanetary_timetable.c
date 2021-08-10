// Interplanetary_timetable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef unsigned long long int ull_int;

void calculate_time(long long int seconds, char planet[], ull_int *d, ull_int *h, ull_int *m, ull_int *s);

int main () {

    ull_int sec, days = 0, hours = 0, minutes = 0, seconds = 0;
    char planet[8] = {};

    scanf ("%llu", &sec);
    scanf (" %s", planet);

    calculate_time(sec, planet, &days, &hours, &minutes, &seconds);

    printf ("%llu segundos no planet %s equivalem a:\n%llu dias, %llu horas, %llu minutos e %llu segundos\n", 
            seconds, planet, days, hours, minutes, seconds);

    return 0;
}

void calculate_time(long long int seconds, char planet[], ull_int *d, ull_int *h, ull_int *m, ull_int *s){
    if (strcmp(planet, "terra") == 0 || strcmp(planet, "Terra") == 0){
        *d = abs(seconds/(24*3600));
        seconds -= *d * (24*3600);
    } else if (strcmp(planet, "mercurio") == 0 || strcmp(planet, "Mercurio") == 0){
        *d = abs(seconds/(3600*((58*24) + 16)));
        seconds -= *d * (3600*((58*24) + 16));    
    } else if (strcmp(planet, "jupiter") == 0 || strcmp(planet, "Jupiter") == 0){
        *d = abs(seconds/((3600*9) + (56*60)));
        seconds -= *d * ((3600*9) + (56*60));
        
    } else if (strcmp(planet, "venus") == 0 || strcmp(planet, "Venus") == 0){
        *d = abs(seconds/((24*3600)*243));
        seconds -= *d * ((24*3600)*243);
    }

    if (seconds != 0){
        *h = abs(seconds/3600);
        seconds -= *h * (3600);
        if (seconds != 0){
            *m = abs(seconds/60);
            seconds -= *m * (60);
            if (seconds != 0){
                *s = abs(seconds/1);
                seconds -= *s;
            }
        }
    }
}