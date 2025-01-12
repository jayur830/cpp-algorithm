#include <stdio.h>
#include <string.h>
#define ALPHABET_COUNT 26

char s[101];
int n[ALPHABET_COUNT] { 0, };

/**
 * 1. 알파벳 총 개수만큼의 int 배열 선언 후
 * 2. ASCII 'a'를 뺀 숫자로 인덱싱하여 카운팅한다.
 */
int main() {
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        n[s[i] - 'a']++;
    }
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
    return 0;
}
