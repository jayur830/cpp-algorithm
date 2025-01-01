#include <ostream>
using namespace std;

/** 배열 출력 */
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& arr) {
    os << '[';
    for (int i = 0; i < arr.size(); i++) {
        if (i > 0) os << ", ";
        os << arr[i];
    }
    os << ']';
    return os;
}
