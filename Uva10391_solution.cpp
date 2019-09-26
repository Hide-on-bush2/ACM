#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(){
    string str;
    set<string> mySet;
    while(cin >> str){
        mySet.insert(str);
    }
    set<string>::iterator it;
    for(it = mySet.begin();it != mySet.end();it++){
        string tempStr = *it;
        string left, right;
        for(int i = 0;i < tempStr.size();i++){
            left.assign(tempStr, 0, i);
            if(mySet.count(left)){
                right.assign(tempStr, i, tempStr.size() - i);
                if(mySet.count(right)){
                    cout << tempStr << endl;
                    break;
                }
            }
        }
    }
}