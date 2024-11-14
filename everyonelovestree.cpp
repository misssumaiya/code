#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    if(n==1||n==3){
        cout<<-1<<endl;
    }
    else if(n==2){
        cout<<66<<endl;
    }
    else if(n%2==0){
        for(int i=0;i<n-2;i++){
            cout<<3;
        }
        for(int i=n-2;i<n;i++){
            cout<<6;
        }
        cout<<endl;
    }
    else if(n%2!=0){
        for(int i=0;i<n-4;i++){
            cout<<3;
        }
        cout<<6366<<endl;
    }

}

}

