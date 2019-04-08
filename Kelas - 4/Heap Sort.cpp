#include <iostream>
#include <chrono>
using namespace std; 
using namespace std::chrono;

void heapify(int arr[], int n, int i){ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
   
    if (l < n && arr[l] > arr[largest]) 
        largest = l;
        
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
   
    if (largest != i){ 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 

    for (int i=n-1; i>=0; i--){ 
        swap(arr[0], arr[i]);
        heapify(arr, i, 0); 
    } 
} 
  
void printArray(int arr[], int n){ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
} 
  
int main(){ 
    high_resolution_clock::time_point t1 = high_resolution_clock ::now();
    int arr[] = {34, 25, 22, 56, 89, 12}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Array before heap sort: "; 
    printArray(arr, n);
    cout<<endl;
    
    heapSort(arr, n); 
  
    cout << "Array after heap sort: "; 
    printArray(arr, n);
    cout<<endl<<endl;
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout<<duration<<" microseconds"<<endl;
} 
