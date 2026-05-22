#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,ans=0;
    cin>>n;
    while(n--){
        int sum=0;
        int i;
        for(int j=0;j<3;j++){
            cin>>i;
            sum+=i;
        }if(sum>=2) ans++;
    }
    cout<<ans<<endl;
 
    return 0;
}