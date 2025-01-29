#include <stdio.h>
#include <math.h>

long long a, b, c;

/**
 * (a ** b) % c 를 그대로 연산하기엔 시간초과 + 값이 자료형 타입 범위를 벗어남
 * b를 2씩 나누면서 c를 나눈 나머지를 재귀적으로 리턴
 */
const long long solution(const long long _a, const long long _b) {
    if (_b == 1) {
        return _a % c;
    }
    const long long v = solution(_a, _b / 2);
    const long long r = (v * v) % c;
    if (_b % 2 == 0) {
        return r;
    }
    return (r * _a) % c;
}

int main() {
    scanf("%llu %llu %llu", &a, &b, &c);
    printf("%llu\n", solution(a, b));
    return 0;
}
