#include <iostream>
using namespace std;

int main(){
    int arr[5] = {12,24,96,64,48};
    int panjangArr = sizeof(arr)/sizeof(arr[0]);
    int maks = arr[0];
    int i = 2;
    
    while(i<panjangArr){
        if(arr[i] > maks){
            maks = arr[i];
        }
        i++;
    }
    
    cout<<"Nilai maks dari array: "<<maks;
}
