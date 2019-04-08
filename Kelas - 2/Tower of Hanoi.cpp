#include <chrono> 
#include <iostream> 
using namespace std; 
using namespace std::chrono;  
  
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){  
    if (n == 1){  
        cout<<"Move disk 1 from rod "<<from_rod<<"to rod "<<to_rod<<endl;  
        return;  
    }  
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);  
    cout<<"Move disk "<<n<<"from rod "<<from_rod<<"to rod "<<to_rod<<endl;  
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);  
}  

int main(){  
    int n = 4; // Number of disks  
    auto start = high_resolution_clock::now(); 
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout<<"Running time: "<<duration.count()<<" microseconds"<<endl;
}  
  
