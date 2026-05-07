//This C program performs complex number multiplication
#include <stdio.h>

struct ComplexNum{
    float real;
    float img;
};

struct ComplexNum multiply(struct ComplexNum a, struct ComplexNum b);

int main(){
    struct ComplexNum a, b;
    printf("Enter real part of first number:\n");
    scanf("%f", &a.real);
    printf("Enter imaginary part of the first number:\n");
    scanf("%f", &a.img);

    printf("Enter real part of second number:\n");
    scanf("%f", &b.real);
    printf("Enter imaginary part of the second number:\n");
    scanf("%f", &b.img);
    
    struct ComplexNum p = multiply(a, b);

    printf("Product is : %f + i%f\n", p.real, p.img);

    return 0;
}

struct ComplexNum multiply(struct ComplexNum a, struct ComplexNum b){
    struct ComplexNum z;
    z.real = a.real * b.real - a.img * b.img;
    z.img = a.real * b.img + a.img * b.real;
    
    return z;
    
}
