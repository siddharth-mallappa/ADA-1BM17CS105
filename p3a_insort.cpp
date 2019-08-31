//Implementing in sort using quick sort 
#include <iostream>
#include <chrono>
using namespace std;

	
int partition (int arr[], int low, int high)  {  
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)  {
        if (arr[j] < pivot)  {  
            i++; 
			int temp = arr[i];  
			arr[i] = arr[j];  
			arr[j] = temp;  
        }  
    }  
	int temp = arr[i+1];  
    arr[i+1] = arr[high];  
    arr[high] = temp;  
    return (i + 1);  
}  


void quickSort(int arr[], int low, int high)  {  
    if (low < high)  {  
        int index = partition(arr, low, high);  
        quickSort(arr, low, index - 1);  
        quickSort(arr, index + 1, high);  
    }  
}  

int main()  
{  
	auto start = chrono::steady_clock::now();
    int arr[100];
	int n;
	cout << "Enter size of the array: " << endl;
	cin >> n;
	cout << "Enter the elements of the array" << endl;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	auto end = chrono::steady_clock::now();
	
	cout << "Elapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
    return 0;  
}  

/* 
	Enter size of the array: 
	5
	Enter the elements of the array
	4 9 0 1 5
	Sorted array: 
	0 1 4 5 9 
*/
