#include <stdio.h>
#include <string.h>

char s[101];

/** i번째 (length - i - 1)번째 문자를 비교한다. */
int main() {
    scanf("%s", s);
    const int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}
