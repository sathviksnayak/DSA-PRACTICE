#include <bits/stdc++.h>
using namespace std;
 
void solve(string s) {
    int n=s.size();
    if(n>10){
        string t;
        t+=s[0];
        t+=to_string(n-2);
        t+=s[n-1];
        cout<<t<<endl;
    }else{
        cout<<s<<endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        solve(s);
    }
 
 
 
    return 0;
}