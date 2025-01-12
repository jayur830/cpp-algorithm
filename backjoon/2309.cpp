#include <bits/stdc++.h>
#define SIZE 9
#define TARGET 7
using namespace std;

int arr[SIZE];

/**
 * 첫 번째 방법 (순열)
 * 1. 정렬한다.
 * 2. 앞 7개를 sum해서 그게 100인지 확인한다.
 * 3. 맞으면 출력하고 끝, 아니면 배열 순서를 재배열한 뒤 1. ~ 3.을 다시 진행한다.
 */
void solution1() {
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + SIZE);
    do {
        int sum = 0;
        for (int i = 0; i < TARGET; i++) {
            sum += arr[i];
        }
        if (sum == 100) {
            sort(arr, arr + TARGET);
            for (int i = 0; i < TARGET; i++) {
                printf("%d\n", arr[i]);
            }
            break;
        }
    } while (next_permutation(arr, arr + SIZE));
}

/**
 * 두 번째 방법 (조합)
 * 1. sum
 * 2. sum에서 배열의 요소 두 개를 뺀 값이 100인지 확인한다.
 * 3. 맞으면 출력하고 끝, 아니면 배열의 요소 두 개를 다시 선택한 뒤 2.부터 다시 진행한다.
 */
void solution2() {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                const int a = arr[i], b = arr[j];
                sort(arr, arr + SIZE);
                for (int k = 0; k < SIZE; k++) {
                    if (arr[k] != a && arr[k] != b) {
                        printf("%d\n", arr[k]);
                    }
                }
                return;
            }
        }
    }
}

int main() {
    // solution1();
    solution2();
    return 0;
}
