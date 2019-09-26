#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> a, b;
    int n;
    while(cin >> n && n){
        a.clear();
        b.clear();
        for(int i = 0;i < n;i++){
            int x;
            cin >> x;
            a.push_back(x);
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }
    return 0;
}