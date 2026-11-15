#include <stdio.h>

long long fibonacci(int n) {


    long long F2 = 0; 
    long long F1 = 1; 
    long long current = 0;
    printf("%lld %lld", F2 ,F1 );
    for (int i = 0; i < n; i++) {
        current = F1 + F2;
        F2 = F1;
        F1 = current;
        printf(" %lld", current);
    }
    
    return current;
}

int main() {
    int n;
    scanf("%d", &n);
    
    fibonacci(n);
    
}
