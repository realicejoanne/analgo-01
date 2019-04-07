#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selectionSort (int arr[], int n){
	int i, j;
	for (i = 0; i < n; ++i){
		for (j = i+1; j < n; ++j){
			if (arr[i] > arr[j]){
				arr[i] = arr[i]+arr[j];
				arr[j] = arr[i]-arr[j];
				arr[i] = arr[i]-arr[j];
			}	
		}
	}	
}	
 
int main(){
	int n, i;
    	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	cout<<"Masukkan jumlah elemen data yang ingin diurutkan: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++){
		cout<<"Masukkan elemen ke-"<<i+1<<": ";
		cin>>arr[i];
	}
 
	selectionSort(arr, n);

	cout<<"\nArray yang telah diurutkan: ";
	for (i = 0; i < n; i++) cout<<" "<<arr[i];
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    	cout<<endl<<duration<<" microseconds" <<endl;
}
