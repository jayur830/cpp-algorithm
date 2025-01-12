#include <stdio.h>

int p[3], s, e, t[101] { 0, }, sum = 0, m = -999;

/**
 * 1. 카운팅 배열을 만들고
 * 2. s ~ e - 1 까지 1씩 카운팅한다.
 */
int main() {
    scanf("%d %d %d", &p[0], &p[1], &p[2]);
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &s, &e);
        m = m < e ? e : m;
        for (int j = s; j < e; j++) {
            t[j]++;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (t[i] > 0) {
            sum += p[t[i] - 1] * t[i];
        }
    }
    printf("%d\n", sum);
    return 0;
}
