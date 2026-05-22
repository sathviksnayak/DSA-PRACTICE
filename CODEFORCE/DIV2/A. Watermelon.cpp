#include <bits/stdc++.h>
using namespace std;
 
void solve(int t) {
    if(t%2==0 && t>2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
solve(t);
 
    return 0;
}