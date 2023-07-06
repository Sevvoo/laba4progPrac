#include <stdio.h>

int countSequences(int n) {
    int mod = 12345; // �������� ������

    int dp[n + 1];
    dp[0] = 1; // ��������� �������� ��� ����������� �������� 0
    dp[1] = 2; // ��������� �������� ��� ����������� �������� 1
    dp[2] = 4; // ��������� �������� ��� ����������� �������� 2

    for (int i = 3; i <= n; i++) {
        // ���������� ������� ������������� ��� ������� i
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }

    return dp[n]; // ���������� ������� ������������� ��� ������� n
}

int main() {
    int n;
    printf("Enter a natural number n (1 < n < 150): ");
    scanf("%d", &n);

    // �������� �������� ��� �������� ����� n
    if (n <= 1 || n >= 150) {
        printf("Invalid input. Please enter a natural number n (1 < n < 150).\n");
        return 0;
    }

    int result = countSequences(n); // ���������� ������� �������������

    printf("The number of sequences: %d\n", result); // ��������� ������� �������������

    return 0;
}
