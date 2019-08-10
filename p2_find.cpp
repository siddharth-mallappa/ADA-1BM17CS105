#include <iostream>
#include <fstream>
using namespace std;
 
int main() {
	std::fstream myFile("/home/bmsce/Documents/sk1bm17cs105/algoClass/test.txt", std::ios_base::in);
	int t, arr[100], flag = -1;
	myFile >> t;
	for(int i = 0; i < t; i++) {
		int n, k;
		myFile >> n;
		myFile >> k;
		for(int j = 0; j < n; j++) {
			myFile >> arr[j];
			if(arr[j] == k) 
				flag = 1;
		}
		cout << flag << endl;
		flag = -1;
	}
	myFile.close();
}
