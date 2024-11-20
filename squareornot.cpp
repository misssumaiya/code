#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    char a[n];
    cin>>a;
   long long sq = sqrt(n);
   int count_one = 0;
   int count_zero = 0;
   if(sq*sq!=n){
    cout<<"NO"<<endl;
   }
   else{
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            count_one++;
        }
        else{
            count_zero++;
        }
    }
    if(((sq*4-4)==count_one)&&(count_zero==(n-(sq*4-4)))){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
   }

}

}
