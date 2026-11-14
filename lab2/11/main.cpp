#include <stdio.h>

long long fibonacci(int n) {


    long long F2 = 0; 
    long long F1 = 1; 
    long long current = 0;

    for (int i = 2; i <= n; i++) {
        current = F1 + F2;
        F2 = F1;
        F1 = current;
    }

    return current;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", fibonacci(n));
    
}
