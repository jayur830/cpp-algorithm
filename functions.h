#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

/** 조합 */
void combination(const vector<int> arr, const int N, const int K, vector<int> buf = vector<int>(), const int start = 0);

/** delimiter 기준으로 문자열 나누기 */
vector<string> split(const string s, const string delimiter);

#endif
