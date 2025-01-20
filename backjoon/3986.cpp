#include <stdio.h>
#include <string.h>
#include <vector>
#define W_MAX_LENGTH 100000
using namespace std;

int n, c = 0;
char w[W_MAX_LENGTH + 1];

/**
 * 스택을 이용한 문제
 * 1. 스택의 최상단에 있는 문자와 현재 j번째 문자를 비교하여 같으면 pop, 아니면 push
 * 2. 스택 크기가 0이면 카운팅
 */
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", w);
        const int len = strlen(w);
        if (len % 2 != 0) {
            continue;
        }
        vector<char> b;
        for (int j = 0; j < len; j++) {
            if (b.size() == 0 || b.back() != w[j]) {
                b.push_back(w[j]);
            } else {
                b.pop_back();
            }
        }
        c += b.size() == 0;
    }
    printf("%d\n", c);
    return 0;
}
