#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<new>
using namespace std;

const int max_time = 1001;

bool zero(int size, int* tuple){
    for(int i = 0;i < size;i++){
        if(tuple[i] != 0){return false;}
    }
    return true;
}

bool zeroOrLoop(int size, int* tuple){
    int time = 0;
    while(time < max_time && !zero(size, tuple)){
        int first_one = tuple[0];
        for(int i = 0;i < size - 1;i++){tuple[i] = abs(tuple[i] - tuple[i + 1]);}
        tuple[size - 1] = abs(tuple[size - 1] - first_one);
        time++;
    }
    if(zero(size, tuple)){return true;}
    return false;
}

int main(){
    int Case;
    scanf("%d", &Case);
    while(Case--){
        int size;
        scanf("%d", &size);
        int* tuple = new int[size + 1];
        for(int i = 0;i < size;i++){
            scanf("%d", &tuple[i]);
        }
        bool res = zeroOrLoop(size, tuple);
        if(res){cout << "ZERO" << endl;}
        else{cout << "LOOP" << endl;}
    }
}