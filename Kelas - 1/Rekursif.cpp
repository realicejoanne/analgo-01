#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

int pangkat(int a, int b){
    if (b==0){
        return (1);
    }
    else {
        return (a*pangkat (a, b-1));
    }
}

int main(int argc, char *argv[]) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    //masukkan input manual
    int a=2, b=30;
    
    cout<<"Menghitung 2 Pangkat n Rekursif"<<endl;
    cout<<endl<<"Pangkat: "<<b;
    cout<<endl<<"Hasil: ";
    cout<<pangkat(a,b)<<endl;
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout<<duration <<" microseconds"<<endl;
}
