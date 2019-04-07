#include<iostream>
#include<string.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

void countSort(char arr[]){
    char output[strlen(arr)];
    int count[255 + 1], i;  
    memset(count, 0, sizeof(count));  
 
    for(i = 0; arr[i]; ++i)  
        ++count[arr[i]];
    for (i = 1; i <= 255; ++i)  
        count[i] += count[i-1];
    for (i = 0; arr[i]; ++i){  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }
    for (i = 0; arr[i]; ++i)  
        arr[i] = output[i];  
}  

int main(){
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    
    char arr[] = "universitaspadjadjaran";
    cout<<"Array sebelum counting sort: "<<arr<<endl;
    countSort(arr);
    cout<<"Array setelah counting sort: "<<arr<<endl;
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout<<duration<<" microseconds"<<endl;
}

