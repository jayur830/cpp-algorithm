#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define MAX 100
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int i, int j, const int n, const int h) {
    visited[i][j] = true;
    if (i - 1 >= 0 && !visited[i - 1][j] && arr[i - 1][j] > h) {
        dfs(i - 1, j, n, h);
    }
    if (i + 1 < n && !visited[i + 1][j] && arr[i + 1][j] > h) {
        dfs(i + 1, j, n, h);
    }
    if (j - 1 >= 0 && !visited[i][j - 1] && arr[i][j - 1] > h) {
        dfs(i, j - 1, n, h);
    }
    if (j + 1 < n && !visited[i][j + 1] && arr[i][j + 1] > h) {
        dfs(i, j + 1, n, h);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, max_h = -99999999, min_h = 99999999, r = -99999999;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            max_h = max(max_h, arr[i][j]);
            min_h = min(min_h, arr[i][j]);
        }
    }

    for (int h = min_h; h <= max_h; h++) {
        int count = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && arr[i][j] > h) {
                    ++count;
                    dfs(i, j, n, h);
                }
            }
        }
        r = max(r, count);
    }
    
    printf("%d\n", max(r, 1));

    return 0;
}
