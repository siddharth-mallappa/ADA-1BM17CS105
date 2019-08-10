#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int n, i, num;
	int high = 0;
	cout << "Enter n";
	cin >> n;
	
	cout << "Enter n numbers: \n";
	for(i = 0; i < n; i++){
		cin >> num;
		if(num > high)
			high = num;
	}
	
	cout << "Max number is: " << high << endl;
}
