#include<stdio.h>
int main(int argc, char const *argv[])
{
    float C, F;

    scanf("%f", &F);

    C = ((5*F) - 160)/9;

    printf("%.2f \n", C);
}
