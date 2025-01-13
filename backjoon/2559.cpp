#include <stdio.h>
#define max(a, b) a > b ? a : b

int n, k, l, m = -999999;

/**
 * 1. 누적합을 구해놓는다.
 * 2. i번째부터 (i + k - 1)번째까지 더한 값을 1.에서 구한 누적합 뺄셈으로 구한다.
 * 3. max를 계속 취해간다.
 */
int main() {
    scanf("%d %d", &n, &k);
    int* sums = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l);
        sums[i] = l + (i > 0 ? sums[i - 1] : 0);
    }
    for (int i = 0; i < n - k + 1; i++) {
        m = max(m, sums[i + k - 1] - (i > 0 ? sums[i - 1] : 0));
    }
    delete[] sums;
    printf("%d\n", m);
    return 0;
}
