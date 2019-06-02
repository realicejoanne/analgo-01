#include<iostream>
using namespace std;

int cost[10][10],stk[10],visit[10],visited[10];
int i,j,k,m,n,top,v;

int main(){
    cout <<"Masukkan jumlah simpul: ";
    cin >> n;
    cout <<"Masukkan jumlah tepian: ";
    cin >> m;

    cout <<"\nTEPIAN \n";
    for(k=1; k<=m; k++){
        cin >>i>>j;
        cost[i][j]=1;
    }

    cout <<"Masukkan titik awal yang akan dilewati: ";
    cin >>v;
    cout <<"Simpul yang dilewati: ";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n){
        for(j=n; j>=1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1){
                visit[j]=1;
                stk[top]=j;
                top++;
            }
        v=stk[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
}
