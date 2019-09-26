#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        vector<int> card;
        for(int i = n;i > 0;i--){card.push_back(i);}
        if(n == 1){cout << "Discarded cards:";}
        else{cout << "Discarded cards: ";}
        if(card.size() > 1){
            int discarded = card.back();
            cout << discarded;
            card.pop_back();
            int nextTop = card.back();
            card.pop_back();
            card.insert(card.begin(), nextTop);
        }
        while(card.size() != 1){
            int discarded = card.back();
            cout << ", " << discarded;
            card.pop_back();
            int nextTop = card.back();
            card.pop_back();
            card.insert(card.begin(), nextTop);
        }
        cout << "\nRemaining card: " << card[0] << endl;
    }
}