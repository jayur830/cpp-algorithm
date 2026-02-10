#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <queue>
#define MAX_N 100
#define MAX_M 100
using namespace std;

int board[MAX_N][MAX_M], visited[MAX_N][MAX_M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = 1;

    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        const int v = visited[y][x] + 1;

        if (y - 1 >= 0 && x >= 0 && board[y - 1][x] == 1 && !visited[y - 1][x]) {
            visited[y - 1][x] = v;
            q.push({ y - 1, x });
        }
        if (y + 1 < n && x >= 0 && board[y + 1][x] == 1 && !visited[y + 1][x]) {
            visited[y + 1][x] = v;
            q.push({ y + 1, x });
        }
        if (y >= 0 && x - 1 >= 0 && board[y][x - 1] == 1 && !visited[y][x - 1]) {
            visited[y][x - 1] = v;
            q.push({ y, x - 1 });
        }
        if (y >= 0 && x + 1 < m && board[y][x + 1] == 1 && !visited[y][x + 1]) {
            visited[y][x + 1] = v;
            q.push({ y, x + 1 });
        }
    }

    printf("%d\n", visited[n - 1][m - 1]);

    return 0;
}
