#include <stdio.h>
#include <string.h>
#define S_MAX_LENGTH 50
#define C_CNT 26

char s[S_MAX_LENGTH + 1], r[S_MAX_LENGTH + 1], n = '\0';
int c[C_CNT] = { 0, }, m = 0, k = 0;

/**
 * 1. 알파벳 개수(26)만큼의 int 카운팅 배열을 준비한다.
 * 2. 문자열을 순회하며 알파벳 개수를 카운팅한다.
 * 3. 카운팅 배열을 순회하면서 0이면 남자답게 넘어가고, 아니면 2를 나눈 수만큼 반복하여 현재 인덱스에 맞는 문자를 출력한다.
 * 4. 현재 인덱스의 카운트가 2로 나누어 떨어지지 않는 횟수 또한 카운팅하며, 이 또한 1보다 클 경우 바로 "I'm Sorry Hansoo"를 출력한다.
 * 5. 4.에서 그 횟수가 1이면 그에 해당하는 문자를 바로 출력한다.
 * 6. 이제 카운팅 배열을 거꾸로 순회하면서 남은 문자들을 각 알파벳 카운트만큼 모조리 출력한다.
 */
int main() {
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        c[s[i] - 'A']++;
    }
    for (int i = 0; i < C_CNT; i++) {
        if (c[i] == 0) {
            continue;
        }
        for (int j = 0; j < c[i] / 2; j++) {
            r[k++] = 'A' + i;
        }
        if (c[i] % 2 != 0) {
            m++;
            n = 'A' + i;
        }
        c[i] /= 2;
        if (m > 1) {
            printf("I'm Sorry Hansoo\n");
            return 0;
        }
    }
    if (n != '\0') {
        r[k++] = n;
    }
    for (int i = C_CNT - 1; i >= 0; i--) {
        if (c[i] == 0) {
            continue;
        }
        for (int j = 0; j < c[i]; j++) {
            r[k++] = 'A' + i;
        }
    }
    r[k] = '\0';
    printf("%s\n", r);
    return 0;
}
