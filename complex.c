#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} complex;

complex sum(complex z1, complex z2) {
    complex resultado;
    resultado.real = z1.real + z2.real;
    resultado.imag = z1.imag + z2.imag;
    return resultado;
}

complex diff(complex z1, complex z2) {
    complex resultado;
    resultado.real = z1.real - z2.real;
    resultado.imag = z1.imag - z2.imag;
    return resultado;
}

complex mul(complex z1, complex z2) {
    complex resultado;
    resultado.real = z1.real * z2.real - z1.imag * z2.imag;
    resultado.imag = z1.real * z2.imag + z1.imag * z2.real;
    return resultado;
}

complex conjugado(complex z) {
    z.imag = -z.imag;
    return z;
}

complex div(complex z1, complex z2) {
    z2 = conjugado(z2);
    complex nmrdr = mul(z1, z2);
    double denominquad = z2.real * z2.real + z2.imag * z2.imag;
    complex resultado;
    resultado.real = nmrdr.real / denominquad;
    resultado.imag = nmrdr.imag / denominquad;
    return resultado;
}

void printComplex(complex z) {
    if (z.imag >= 0)
        printf("%.2f + %.2fi\n", z.real, z.imag);
    else
        printf("%.2f - %.2fi\n", z.real, -z.imag);
}

void printVetorComplex(complex c[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Complex %d: ", i + 1);
        printComplex(c[i]);
    }
}

int main() {
    complex c1 = {4, 2}; //4+2i + 3-1i  , 4+2i - 3-1i 
    complex c2 = {3, -1}; //4+2i * 3-1i , 4+2i / 3-1i 

    complex su = sum(c1, c2);
    complex di = diff(c1, c2);
    complex mu = mul(c1, c2);
    complex co = conjugado(c2);
    complex dv = div(c1, c2);

	printf("Pares: \n");
	printf("Su:( %.2f , %.2f )\n", su.real, su.imag);
	printf("Di:( %.2f , %.2f )\n", di.real, di.imag);
	printf("Mu:( %.2f , %.2f )\n", mu.real, mu.imag);
	printf("Co:( %.2f , %.2f )\n", co.real, co.imag);
	printf("Di:( %.2f , %.2f )\n\n", di.real, di.imag);
	
    printf("Resultado algébrico:\n");
    printf("Su: ");
    printComplex(su);
    printf("Di: ");
    printComplex(di);
    printf("Mu: ");
    printComplex(mu);
    printf("Co: ");
    printComplex(co);
    printf("Dv: ");
    printComplex(dv);

    complex k[4] = {su, di, mul(c1, c2), dv};

	printf("\n");
    printf("Vetor de Complexos:\n");
    printVetorComplex(k, 4);

    return 0;
}