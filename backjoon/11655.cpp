#include <stdio.h>
#include <string.h>

char s[101];

/**
 * - 숫자, 공백의 경우 continue
 * - ASCII 문자에 13을 더했을 경우 'z' 또는 'Z'보다 큰지 여부를 확인
 */
int main() {
    scanf("%[^\n]s", s);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ' || (s[i] >= '0' && s[i] <= '9')) {
            continue;
        }
        if (s[i] >= 'a') {
            s[i] = s[i] + 13 > 'z' ? s[i] + 12 - 'z' + 'a' : s[i] + 13;
        } else {
            s[i] = s[i] + 13 > 'Z' ? s[i] + 12 - 'Z' + 'A' : s[i] + 13;
        }
    }
    printf("%s\n", s);
    return 0;
}
