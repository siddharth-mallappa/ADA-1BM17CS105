#include <iostream>
#include <chrono>
using namespace std; 

void bubbleSort(int arr[], int n)  {  
    int i, j;  
    for (i = 0; i < n-1; i++)      
		for (j = 0; j < n-i-1; j++)  
			if (arr[j] < arr[j+1])  {
				int temp = arr[j];  
				arr[j] = arr[j+1];  
				arr[j+1] = temp; 
			}
	}
	
void selectionSort(int arr[], int n)  {  
    int i, j, min_idx;  
    for (i = 0; i < n-1; i++)  {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
			
		int temp = arr[min_idx];  
		arr[min_idx] = arr[i];  
		arr[i] = temp;  
    }  
}  

int main() {
		auto start = chrono::steady_clock::now();
		int n, arr[100], k;
		cout << "Enter size of the array" << endl;
		cin >> n;
		cout << "Enter elements of the array" << endl;
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		bubbleSort(arr, n);
		//selectionSort(arr,n);
		cout << "Enter K:" << endl;
		cin >> k;
		cout << "The Kth elements are: " << endl;
		for(int i = 0; i < k; i++)
			cout << arr[i] << " " << endl;
		auto end = chrono::steady_clock::now();
		cout << "Elapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
}

/*
Enter size of the array
5
Enter elements of the array
4
6
5
1
9
Enter K:
3
The Kth elements are: 
9 
6 
5 
Elapsed time in milliseconds : 8597 ms
*/

