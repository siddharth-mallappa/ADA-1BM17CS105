
#include <bits/stdc++.h> 
using namespace std; 
int countc=0;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
int selectionSort(int arr[], int n)  
{  
    int i, j, min_idx,ctr=0;  
    for (i = 0; i < n-1; i++)  {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  {
				ctr++;
			if (arr[j] < arr[min_idx])  {

				min_idx = j;  
			}
			}
		}
			
		int temp = arr[min_idx];  
		arr[min_idx] = arr[i];  
		arr[i] = temp;  
	return ctr;
}  
  
  int bubbleSort(int arr[], int n)  
{  
    int i, j,counterb;  
    for (i = 0; i < n-1; i++)     
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)
	{
		counterb++;
	  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);
			}

return counterb;
} 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
	
	
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
	countc+=5;
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 	countc++;
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
	return countc;
} 

/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver program to test above functions  
int main()  
{  
	
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    int c1=selectionSort(arr, n); 

    cout << "Selection sort Sorted array: \n";  
	cout<<c1<<" selection sort";
    printArray(arr, n);  
	int c2=bubbleSort(arr, n);  
    cout<<" bubble sort Sorted array: \n"; 
	cout<<c2<<"Bubble sort";
    printArray(arr, n); 
	
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\n Merg sort Sorted array is \n"); 
    printArray(arr, arr_size); 
    return 0;  
}  
