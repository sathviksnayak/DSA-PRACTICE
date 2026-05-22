#include<bits/stdc++.h>
using namespace std;
 
int main(){
    vector<bool> seen(26,false);
    int count=0;
    string s;
    getline(cin,s);
    for(char a:s){
        if(!seen[a-'a']){
            count++;
            seen[a-'a']=true;
        }
        
    }
    if(count%2==0) cout<<"CHAT WITH HER!"<<"\n";
    else cout<<"IGNORE HIM!"<<"\n";
    
    
    
    return 0;
}