#include <stdio.h>
#include <omp.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int start = 2;
    int end = 100;

    printf("Prime numbers in range %d to %d:\n", start, end);

    // Parallelize the for loop to find prime numbers
    #pragma omp parallel for
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
