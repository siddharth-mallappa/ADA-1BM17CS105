#include <iostream>
#include <cmath>
using namespace std;

int binaryRoot(int key)
{
    int start = 0, end = key;
    int mid;
    float ans;
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == key) {
            ans = mid;
            break;
        }
        if (mid * mid < key) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int key;
    cout << "X = ";
    cin >> key;
    cout << "\n OUTPUT: " << binaryRoot(key);
}

