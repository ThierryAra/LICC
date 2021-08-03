#include<stdio.h>
int main(int argc, char const *argv[])
{
    float Celsius, Farenheit;

    scanf("%f", &Farenheit);

    Celsius = ((5*Farenheit) - 160)/9;

    printf("%.2f \n", Celsius);
}
