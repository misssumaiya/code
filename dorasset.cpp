#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int l,r;
    int even=0,odd=0;
    cin>>l>>r;
  if((r-l+1)<=2){
    cout<<0<<endl;
  }
  else if((r-l+1)%2==0){
    cout<<((r-l+1)/2)/2<<endl;
  }
  else{
    if(l%2==0){
        even = ((r-l+1)/2)+1;
        odd = (r-l+1)-even;
    }
    else{
    odd = ((r-l+1)/2) +1;
    even = (r-l+1)-odd;
    }
    cout<<odd/2<<endl;
  }

}

}
