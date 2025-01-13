#include <bits/stdc++.h>
using namespace std;

int n;
string p, s;
char _p[101], _s[101];

/**
 * 1. 문자열 가운데 `'*'`를 중심으로 split 한다.
 * 2. `substr` 메소드를 이용하여 문자열의 양 끝을 비교한다.
 * 3. 단, 1.에서 나뉘어진 두 문자열을 합친 길이가 2.에서 대상이 되는 문자열의 길이보다 작거나 같아야 한다.
 */
int main() {
    scanf("%d %s", &n, _p);
    p = _p;
    const int f = p.find('*');
    const string b = p.substr(0, f);
    const string e = p.substr(f + 1);
    for (int i = 0; i < n; i++) {
        scanf("%s", _s);
        s = _s;
        const int s_len = s.size();
        const int b_len = b.size();
        const int e_len = e.size();
        printf(s_len >= b_len && s.substr(0, b_len) == b && s_len >= e_len && s.substr(s_len - e_len) == e && s_len >= b_len + e_len ? "DA\n" : "NE\n");
    }
    return 0;
}
