#include <iostream>
#include <time.h>
using namespace std;

clock_t start, end;
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
    start = clock();
    {
         int key;
        cout << "X = ";
        cin >> key;
        cout << "\n OUTPUT: " << binaryRoot(key);
    }
   end = clock();
   cout << "\n \nTime taken: " << (end-start)/CLK_TCK << "ms.";
}

/*
    X = 5000
    OUTPUT: 70
    Time taken: 4ms

    X = 500
    OUTPUT: 22
    Time taken: 10ms

    X = 999
    OUTPUT: 31
    Time taken: 1ms
*/
