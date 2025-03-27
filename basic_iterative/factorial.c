#include <stdio.h>
int factorial(int n) {
    if (n <= 1) return 1;

    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result; 
}

int main() {
    int n = 5;
    printf("Factorial of %d is: %d\n", n, factorial(n));
    return 0;
}