#include<bits/stdc++.h>
using namespace std;
int main(){
 
    long t; 
    cin>>t;
    while(t--){
        long n;
        
        cin>>n;
        vector<long> v(n);
        for(long p = 0; p < n; p++){
            cin>>v[p];
        }
        long mxlen=0;
        for(long p = 0; p < n; p++){
            long cnt=1;
            for(long q = p + 1; q < n; q++){
                cnt += (v[q] <= v[p]);
                
            }
            mxlen = (mxlen > cnt ? mxlen : cnt);
        }
 
       cout<<n-mxlen<<"\n";
    }
return 0;
}