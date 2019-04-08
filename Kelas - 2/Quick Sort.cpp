#include <chrono> 
#include <iostream> 
using namespace std; 
using namespace std::chrono;

void quick_sort(int[],int,int);
int partition(int[],int,int);

void quick_sort(int a[],int l,int u){
    int j;
    if(l<u){
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition(int a[],int l,int u){
    int v,i,j,temp;
    
    v=a[l];
    i=l;
    j=u+1;
    
    do {
        do i++; 
        while(a[i]<v&&i<=u);
        
        do j--;
        while(v<a[j]);
        
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}
 
int main(){
    auto start = high_resolution_clock::now();
    int a[50],n,i;
    
    cout<<"Enter total of elements: ";
    cin>>n;
    cout<<"Enter array elements: ";
    
    for(i=0;i<n;i++)
        cin>>a[i];
        
    quick_sort(a,0,n-1);
    cout<<"Array after sorting: ";
    
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
        
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout<<endl<<endl<<"Running time: "<<duration.count()<<" microseconds"<<endl;    
}
