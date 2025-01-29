#include <stdio.h>

int n;

/**
 * 오직 1만으로 이루어진 n의 배수 중 최솟값 찾기
 * 1 % n == 0, 11 % n == 0, 111 % n == 0, ... 를 계속해나감
 * 핵심은 `r = (r * 10 + 1) % n` 부분임. 루프가 반복될 때마다 n을 계속 모듈러 연산을 수행함.
 * => a % n == a % n % n 법칙 성립
 */
int main() {
    while (scanf("%d", &n) != EOF) {
        int c = 1;
        for (long long r = 1; true; r = (r * 10 + 1) % n, c++) {
            if (r % n == 0) {
                printf("%d\n", c);
                break;
            }
        }
    }
    return 0;
}
