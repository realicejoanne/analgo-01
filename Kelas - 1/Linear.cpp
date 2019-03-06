#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    int arr[] = { 21, 12, 34, 56, 67, 80, 3, 100, 96, 49 };
    int size = sizeof(arr) / sizeof(arr[0]);  //array 10 angka
    int n = 50; //masukkan input manual

    cout<<"Melakukan pencarian linear"<<endl;
    cout<<"Apakah angka "<<n<<" ada?"<<endl;

    bool ketemu = false;
    for (int i=0; i<size; i++){
        if (n == arr[i])
            ketemu = true;
    }

    cout<<"Jawab: "<<(ketemu == true ? "Ada!":"Tidak ada!")<<endl;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 )s.count();
    cout<<duration <<" microseconds" <<endl;
}
