#include <iostream>
#include <vector>
#include <string>
#include "./meta.cpp"
using namespace std;

void combination(const vector<int> arr, const int N, const int K, vector<int> buf = vector<int>(), const int start = 0) {
    if (buf.size() == K) {
        cout << buf << endl;
        return;
    }

    for (int i = start; i < N; i++) {
        buf.push_back(arr[i]);
        combination(arr, N, K, buf, i + 1);
        buf.pop_back();
    }
}

vector<string> split(const string s, const string delimiter) {
    vector<string> arr;
    string tmp = s;
    while (tmp.size() > 0) {
        const int delimiter_pos = tmp.find(delimiter);
        if (delimiter_pos == string::npos) {
            arr.push_back(tmp);
            break;
        }
        arr.push_back(tmp.substr(0, delimiter_pos));
        tmp = tmp.substr(tmp.find(delimiter) + 1);
    }
    return arr;
}