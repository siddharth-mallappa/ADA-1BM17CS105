#include <iostream>
#include <chrono>
using namespace std;

void Merger(int arr[], int lo, int  mi, int hi){
    int *temp = new int[hi-lo+1];
    int i = lo, j = mi + 1;
    int k = 0;
    while(i <= mi && j <=hi){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mi)
        temp[k++] = arr[i++];
    while(j <= hi)
        temp[k++] = arr[j++];
    for(k = 0, i = lo; i <= hi; ++i, ++k)
        arr[i] = temp[k];
}
void MergeSortHelper(int arr[], int lo, int hi){
    int mid;
    if(lo < hi){
        mid = (lo + hi) >> 1;
        MergeSortHelper(arr, lo, mid);
        MergeSortHelper(arr, mid+1, hi);
        Merger(arr, lo, mid, hi);
    }
}
void MergeSort(int arr[], int arr_size){
    MergeSortHelper(arr, 0, arr_size-1);
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
	
    MergeSort(arr, n);
    cout << "Sorted array: \n";  
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	auto end = chrono::steady_clock::now();
		cout << "\nElapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
    return 0;  
}  

/*
Enter size of the array: 
5    
Enter the elements of the array
1
7
4
8
3
Sorted array: 
1 3 4 7 8 
Elapsed time in milliseconds : 9589 ms
*/
