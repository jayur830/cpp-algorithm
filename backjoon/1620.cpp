#include <bits/stdc++.h>
using namespace std;

int n, m;
char t[21];
vector<string> s_arr;
map<string, int> s_map;

/**
 * 1. Array, Map 두 가지 자료구조를 준비한다.
 * 2. Array에 문자열을 저장하고, Map에는 문자열을 키로, 그에 해당하는 i번째 인덱스를 값으로 저장한다.
 * 3. 첫 글자 숫자 여부에 따라 숫자일 경우 Array로, 문자일 경우 Map으로 매핑하여 값을 도출한다.
 */
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", t);
        s_arr.push_back(t);
        s_map.insert({ t, i });
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", t);
        if (t[0] >= '0' && t[0] <= '9') {
            const int idx = atoi(t);
            printf("%s\n", s_arr[idx - 1].c_str());
        } else {
            printf("%d\n", s_map[t] + 1);
        }
    }
    return 0;
}
