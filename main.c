#include <stdio.h>

int main() {
    int p;
    printf("Введіть значення р: ");
    scanf("%d", &p);

    if (p < 1) {
        printf("Значення р має бути не менше 1\n");
        return 1;
    }

    long long dp[p + 1][2];
    
    dp[1][0] = 2; 
    dp[1][1] = 0; 

    for (int i = 2; i <= p; i++) {
        dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1] * 2; 
        dp[i][1] = dp[i-1][0] * 2; 
    }

    long long result = dp[p][0] + dp[p][1];
    printf("Кількість чисел із %d розрядів: %lld\n", p, result);

    return 0;
}
