#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int ts;
    cin>>ts;
    while(ts--){
        int n;
        cin>>n;
        
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        sort(a.begin()+1,a.end(),greater<int>());
        int h=0,sum=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            while(h<n && sum+b[h+1]<=i) {
               h++;
                sum+=b[h];
            
            }
            ans=max(ans,a[i]*1ll*h);
            
        }
        cout<<ans<<"\n";
        
    }
    
    return 0;
}