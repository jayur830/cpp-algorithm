#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int n, m, k, r = 0;
vector<int> a;
set<int> s;

/**
 * 1. `i번째 + j번째 == m`을 만족하는 경우 카운팅하고, j번째 숫자를 set 자료구조에 메모이제이션 한다.
 * 2. 다음에 1. 과정을 거칠 때 set 자료구조에 j번째 숫자가 있다면 해당 루프는 넘어간다.
 */
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        a.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s.count(a[j]) > 1) {
                continue;
            }
            if (a[i] + a[j] == m) {
                r++;
                s.insert(a[j]);
                break;
            }
        }
    }
    printf("%d\n", r);
    return 0;
}
