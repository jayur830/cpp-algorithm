#include <stdio.h>
#include <string.h>
#define ALPHABET_COUNT 26

char s[101];
int n[ALPHABET_COUNT] { 0, };

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
