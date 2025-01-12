#include <stdio.h>

char s[31];
int n, a[26] { 0, };
bool p = false;

/** (각 문자열의 첫 문자 - ASCII 'a')번째 인덱스 카운팅 */
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        a[s[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] >= 5) {
            p = true;
            printf("%c", i + 'a');
        }
    }
    if (!p) {
        printf("PREDAJA");
    }
    printf("\n");
    return 0;
}
