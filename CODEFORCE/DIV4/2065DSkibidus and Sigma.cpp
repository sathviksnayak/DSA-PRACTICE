#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>n>>m;
        
        vector<vector<int>> ans(n,vector<int>(m+1));
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m+1;j++){
                cin>>ans[i][j];
            }
        }
        for(auto &it:ans){
            int total=0;
            for(int i=1;i<it.size();i++){
                total+=it[i];
            }
            it[0]=total;
        }
 
sort(ans.begin(),ans.end(),greater<vector<int>>());
long long sum=0,pref=0;
 
for(int i=0;i<n;i++){
    for(int j=1;j<m+1;j++){
        pref+=ans[i][j];
        sum+=pref;
    }
}
    cout<<sum<<"\n";
 
    }
    
    
    return 0;
}