#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int board[100][100];
bool visited[100][100];

int dfs(int y, int x, const int m, const int n) {
    int sum = 1;
    visited[y][x] = true;
    if (y - 1 >= 0 && board[y - 1][x] == 0 && !visited[y - 1][x]) {
        sum += dfs(y - 1, x, m, n);
    }
    if (y + 1 < m && board[y + 1][x] == 0 && !visited[y + 1][x]) {
        sum += dfs(y + 1, x, m, n);
    }
    if (x - 1 >= 0 && board[y][x - 1] == 0 && !visited[y][x - 1]) {
        sum += dfs(y, x - 1, m, n);
    }
    if (x + 1 < n && board[y][x + 1] == 0 && !visited[y][x + 1]) {
        sum += dfs(y, x + 1, m, n);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> c;
    int m, n, k, count = 0;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for (int y = y_1; y < y_2; y++) {
            for (int x = x_1; x < x_2; x++) {
                board[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 && !visited[i][j]) {
                count++;
                c.push_back(dfs(i, j, m, n));
            }
        }
    }

    sort(c.begin(), c.end());

    printf("%d\n", count);
    for (const int v : c) {
        printf("%d ", v);
    }

    return 0;
}
