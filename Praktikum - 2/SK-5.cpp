#include <iostream>
using namespace std;

int main(){
    int arr[5] = {2,1,3,5,4};
    int panjangArr = sizeof(arr)/sizeof(*arr);
    
    for(int i = 0; i < panjangArr - 1; i++){
        int minIdx = i;
        for(int j = i + 1; j < panjangArr; j++){
            if(arr[j] < arr[minIdx]) minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
    
    for(int i = 0; i < panjangArr; i++){
        cout<<arr[i];
    }
}
