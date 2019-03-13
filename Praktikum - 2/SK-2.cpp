#include <iostream>
using namespace std;

int main(){
  int arr[5] = {1,2,3,4,5};
  int panjangArr = sizeof(arr)/sizeof(arr[0]);
  int i = 1;
  int y = 3;
  int idx;
  bool found = false;

  while(i <= panjangArr && !found){
    if(arr[i] == y){
        found = true;
    }
    else i++;
  }
  
  if(found == true){
    idx = i;
  }
  else idx = 0; //jika tidak ditemukan idx = 0
  
  cout<<"Hasil cari index elemen: "<<idx;
}
