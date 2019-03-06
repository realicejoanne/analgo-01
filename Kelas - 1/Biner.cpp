#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    int arr[] = { 21, 12, 34, 56, 67, 80, 3, 100, 96, 49 };
    int size = sizeof(arr) / sizeof(arr[0]);  //array 10 angka
    int n = 50; //masukkan input manual

    cout<<"Melakukan pencarian biner"<<endl;
    cout<<"Apakah angka "<<n<<" ada?"<<endl;

    bool ketemu = false;
    int left = 0, right = size-1;

    while (left <= right){
            int mid = left + (right - left) / 2;
            if (arr[mid] == n)
                ketemu = true;
            if (arr[mid] < n)
                left = mid + 1;
            else
                right = mid - 1;
    }

    cout<<"Jawab: "<<(ketemu == true ? "Ada!" : "Tidak ada!")<<endl;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout<<duration <<" microseconds" <<endl;
}
