#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

int arr[50][50];
bool visited[50][50];

void dfs(int y, int x, const int n, const int m) {
    visited[y][x] = true;
    if (y - 1 >= 0 && x >= 0 && arr[y - 1][x] == 1 && !visited[y - 1][x]) {
        dfs(y - 1, x, n, m);
    }
    if (y + 1 < n && x >= 0 && arr[y + 1][x] == 1 && !visited[y + 1][x]) {
        dfs(y + 1, x, n, m);
    }
    if (y >= 0 && x - 1 >= 0 && arr[y][x - 1] == 1 && !visited[y][x - 1]) {
        dfs(y, x - 1, n, m);
    }
    if (y >= 0 && x + 1 < m && arr[y][x + 1] == 1 && !visited[y][x + 1]) {
        dfs(y, x + 1, n, m);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int m, n, k, count = 0;
        cin >> m >> n >> k;
    
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                arr[y][x] = 0;
                visited[y][x] = false;
            }
        }

        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (!visited[y][x] && arr[y][x] == 1) {
                    ++count;
                    dfs(y, x, n, m);
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
