//不知道算法有什么问题....
#include<string>
#include<iostream>
#include<vector>

using namespace std;

string substraction(string& a, string& b){
    int i = 0;
    while(i < a.size() && i < b.size() && a[i] == b[i]){i++;}
    if(i == 0){return "";}
    if(i == a.size()){
        string res = "";
        while(i < b.size()){
            res += b[i];
            i++;
        }
        return res;
    }
    return "";
}

int main(){
    string s;
    vector<string> Str;
    while(cin >> s){
        Str.push_back(s);
    }
    for(int i = 0;i < Str.size() - 1;i++){
        string leftStr = substraction(Str[i], Str[i + 1]);
        if(leftStr != ""){
            for(int j = 0;j < Str.size();j++){
                if(Str[j] == leftStr){cout << Str[i + 1] << endl;}
            }
        }
    }
    return 0;
}