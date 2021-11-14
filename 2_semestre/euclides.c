/*  Thierry de Souza Araújo - 12681094
    USP - São Carlos - ICMC
    Matemática Discreta              */
#include<stdio.h>
#include<stdlib.h>

typedef long int lint;

lint i, j;

/*  Retona o Menor Comum Divisor entre a e b, calculado pelo algoritmo de Euclides Estendido,
    além dos índices de a e b (i e j), que formam a combinação linear que encontra o MCD,
    tal que, j*b + i*a = d                                                                
    
    CÁLCULO:
    Se      c = a % b e q = a/b
    Então   c = a - q*b (Teorema da Divisão de Euclides) 

    MCD(a, b) = MCD(b, c) (Lema 6.1*)
    i*a + j*b = I*b + J*c
    i*a + j*b = I*b + J*(a - q*b)
              = I*b + J*a - J(q*b)
    i*a + j*b = (I - J*q)*b + J*a

    i = J e j = I - J*q                                          

    A recursão termina quando b = 0, ou seja, a é múltiplo de b, 
    I*a + J*b = b
    0*a + 1*b = b 
    A partir daqui, conseguimos obter os J's e I's anteriores, até chegar 
    na primeira recursão, que possuem os valores que demos como entrada          
    
        MDC(25, 14)    -> 25 = 1*14 + 11 (-> 11 = 25 - 1*14)
        MDC(14, 11)    -> 14 = 1*11 + 3  (->  3 = 14 - 1*11)
        MDC(11,  3)    -> 11 = 3* 3 + 2  (->  2 = 11 - 3* 3)
        MDC( 3,  2)    ->  3 = 1* 2 + 1  (->  1 =  3 - 2* 1)
        MDC( 2,  1)=1  ->  2 = 1* 2 + 0  
        MDC( 1,  0)    ->  return a
        
        1 = 3 - 2 = 3 - (11 - 3*3) = -11 + 3*(1 + 3)
          = (-1)*11 +  (4)*(14 - 11) = 4*14 + 11*(-1 - 4)
          = 4*14 + (-5)*(25 - 1*14)
          = { 9*14 + (-5)*25  = 1 }
    */
lint MCD(lint a, lint b) {
    if (b == 0) {
        i = 1;
        j = 0;
        return a;
    }

    lint I = 0;
    lint d = MCD(b, a % b);

    I = i;
    i = j;
    j = I - j * (a / b);
    //printf("%ld %ld\n", i, j);
    return d;
}

int main(int argc, char const* argv[]){

    if(argc != 3)
        return 1;

    lint a = atoi(argv[1]);
    lint b = atoi(argv[2]);
    
    if(b >= a || b < 0)
        return 1;

    lint resultado_MCD = MCD(a, b);

    printf("MCD(%ld,%ld) = %ld ", a, b, resultado_MCD);
    printf("-> (%ld * %ld) + (%ld * %ld) = %ld\n\n", j, b, i, a, resultado_MCD);
    
    if(resultado_MCD == 1){
    printf("x será inverso de b em Z(a) se: \nx*b + c*a = 1(mod a)\n \t\tsabendo que c*a = 0(mod a)\n"
           "x*b = 1(mod a)");
    printf("\n(Caso x seja negativo, para encontrar seu congruente em Z(a), basta somar a ao x)");  
        if(j < 0)
            j += a;

        printf("\n\nO inverso de %ld em Z%ld eh %ld\n", b, a, j);
    }
}




/*  *Lema 6.1
        Dados n, d, q, r ∈ Z tais que n = dq + r,
        MCD(d, n) = MCD(d, r)                    */