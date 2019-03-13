#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    int i = 1;
    int j = sizeof(arr)/sizeof(arr[0]);
    int y = 3;
    int idx, mid;
    bool found = false;
  
    while(!found && i <= j){
        mid  = (i + j)/2;
        if(arr[mid] == y){
            found = true;
        }
        else if(arr[mid]< y){
                i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }
    
    if(found == true){
        idx = mid;
    }
    else idx = 0;
    
    cout<<"Hasil cari indeks elemen: "<<idx;
}
