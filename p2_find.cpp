#include<iostream>
 
using namespace std;
 
int main() {
	int t, arr[100], flag = -1;
	cout << "Enter no of test cases" << endl;
	cin >> t;
	
	for(int i = 0; i < t; i++) {
		int n, k;
		cin >> n;
		cin >> k;
		for(int j = 0; j < n; j++) {
			cin >> arr[j];
			if(arr[j] == k) 
				flag = 1;
		}
		
		cout << flag << endl;
		flag = -1;
	}
}