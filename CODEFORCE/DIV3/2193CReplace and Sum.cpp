#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            if(b[i]>a[i]){
                a[i]=b[i];
            }
             
            }
        for(int i=n-2;i>=0;i--){
            a[i]=max(a[i],a[i+1]);
        }
        vector<long long> psum(n+1,0);
        for(int i=0;i<n;i++){
            psum[i+1]=psum[i]+a[i];
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<psum[r+1]-psum[l]<<" ";
 
        }
        cout<<"\n";
    }
    
    return 0;
}