#include<bits/stdc++.h>
using namespace std;

int main(){

    int ts;
    cin >> ts;

    while(ts--){

        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        bool found = false;

        for(int i = 0; i < n - 1 && !found; i++){

            int x = a[i];

            for(int j = i + 1; j < n; j++){

                int y = a[j];

                if(x != 0 && (y % x) % 2 == 0){

                    cout << x << " " << y << "\n";

                    found = true;
                    break;
                }
            }
        }

        if(!found){
            cout << -1 << "\n";
        }
    }

    return 0;
}