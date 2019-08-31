#include <iostream>
#include <chrono>
using namespace std;
int ctr=0;

int bubbleSort(int arr[], int n)  {  
    int i, j;  
    for (i = 0; i < n-1; i++)      
		for (j = 0; j < n-i-1; j++)  
			if (arr[j] < arr[j+1])  {
				ctr++;
				int temp = arr[j];  
				arr[j] = arr[j+1];  
				arr[j+1] = temp; 
			}
	return ctr;
}
	
int selectionSort(int arr[], int n)  {  
    int i, j, min_idx;  
    for (i = 0; i < n-1; i++)  {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
			ctr++;
			if (arr[j] < arr[min_idx])  
				min_idx = j;  
			
		int temp = arr[min_idx];  
		arr[min_idx] = arr[i];  
		arr[i] = temp;  
    }
	return ctr;
}

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
int MergeSortHelper(int arr[], int lo, int hi){
    int mid;
    if(lo < hi){
		ctr++;
        mid = (lo + hi) >> 1;
        MergeSortHelper(arr, lo, mid);
        MergeSortHelper(arr, mid+1, hi);
        Merger(arr, lo, mid, hi);
    }
	return ctr;
}


int main() {
	auto start = chrono::steady_clock::now();
	int arr[100];
	int n;
	cout << "Enter size of the array: " << endl;
	cin >> n;
	cout << "Enter the elements of the array" << endl;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ctr = 0;
	int bcount = bubbleSort(arr, n);
	ctr = 0;
	int scount = selectionSort(arr, n);
	ctr = 0;
	int mcount = MergeSortHelper(arr, 0, n-1);
	
	cout << "Bubble sort: " << bcount << endl;
	cout << "Selection sort: " << scount << endl;
	cout << "Merge sort: " << mcount << endl;
	
	if(bcount < scount && bcount < mcount) {
		cout << "Bubble sort takes minimum" << endl;
	}
	else if(scount < bcount && mcount < bcount)
		cout << "Selection sort takes minimum " << endl;
	else
		cout << "Merge sort takes minimum" << endl;
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
2
3
4
5
Bubble sort: 10
Selection sort: 10
Merge sort: 4
Merge sort takes minimum

Elapsed time in milliseconds : 3613 ms
*/
