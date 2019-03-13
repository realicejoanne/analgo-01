#include <iostream>
using namespace std;

int main(){
    int arr[5] = {2,1,3,5,4};
    int panjangArr = sizeof(arr)/sizeof(*arr);
    int i, j, insert;

	for (i = 1; i < panjangArr; i++){
		insert = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > insert){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		
		arr[j+1] = insert;
	}
	
	for (j = 0; j < panjangArr; j++){
	    cout<<arr[j];
	}
}
