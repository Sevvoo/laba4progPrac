#include <stdio.h>

int countSequences(int n) {
    int mod = 12345; // Значення модуля

    int dp[n + 1];
    dp[0] = 1; // Початкове значення для послідовності довжиною 0
    dp[1] = 2; // Початкове значення для послідовності довжиною 1
    dp[2] = 4; // Початкове значення для послідовності довжиною 2

    for (int i = 3; i <= n; i++) {
        // Обчислення кількості послідовностей для довжини i
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }

    return dp[n]; // Повернення кількості послідовностей для довжини n
}

int main() {
    int n;
    printf("Enter a natural number n (1 < n < 150): ");
    scanf("%d", &n);

    // Перевірка обмежень для вхідного числа n
    if (n <= 1 || n >= 150) {
        printf("Invalid input. Please enter a natural number n (1 < n < 150).\n");
        return 0;
    }

    int result = countSequences(n); // Обчислення кількості послідовностей

    printf("The number of sequences: %d\n", result); // Виведення кількості послідовностей

    return 0;
}
