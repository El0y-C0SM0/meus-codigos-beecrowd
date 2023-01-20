#include <stdio.h>
 
int main() {
    double r, a;
    
    scanf("%lf", &r);
    
    a = (r * r) * 3.14159;
    
    printf("A=%.4f\n", a);
 
    return 0;
}