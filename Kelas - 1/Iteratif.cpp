#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

int pangkat (int a, int b){
    int hasil=1;
    for (int i=1;i<=b;i++){
        hasil=hasil*a;
    }
    return hasil;
}
    
int main(){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    //masukkan input manual
    int a=2, b=30;
    
    cout<<"Menghitung 2 Pangkat n Iteratif"<<endl;
    cout<<endl<<"Pangkat: "<<b;
    cout<<endl<<"Hasil: ";
    cout<<pangkat(a,b)<<endl;
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout<<duration <<" microseconds"<<endl;
}
