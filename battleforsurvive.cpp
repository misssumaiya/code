#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    long long n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long sum=0;
    long long value;
    for(int i=0;i<n-2;i++){
       sum = sum + a[i];
    }
    value = a[n-1]-(a[n-2]-sum);
    cout<<value<<endl;
}
}
