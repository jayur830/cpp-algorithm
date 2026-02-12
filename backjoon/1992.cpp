#include <bits/stdc++.h>
#define MAX 64
using namespace std;

int arr[MAX][MAX];

string make(int y, int x, int depth) {
    string str = "(";

    if (depth == 2) {
        if (arr[y][x] == arr[y][x + 1] && arr[y][x] == arr[y + 1][x] && arr[y][x] == arr[y + 1][x + 1]) {
            str = arr[y][x] + '0';
        } else {
            str += arr[y][x] + '0';
            str += arr[y][x + 1] + '0';
            str += arr[y + 1][x] + '0';
            str += arr[y + 1][x + 1] + '0';
            str += ")";
        }
    } else {
        string a = make(y, x, depth / 2);
        string b = make(y, x + depth / 2, depth / 2);
        string c = make(y + depth / 2, x, depth / 2);
        string d = make(y + depth / 2, x + depth / 2, depth / 2);

        if (a.size() == 1 && a == b && a == c && a == d) {
            str = a;
        } else {
            str += a + b + c + d + ")";
        }
    }

    return str;
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 1) {
        int v;
        scanf("%d", &v);
        printf("%d\n", v);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    printf("%s\n", make(0, 0, n).c_str());

    return 0;
}
