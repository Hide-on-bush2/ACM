#include<iostream>
#include<sstream>
#include<vector>

using namespace std;
//第i个单词的最大长度
int maxLength(vector< vector<string> >& map, int i){
    int res = 0;
    for(int j = 0;j < map.size();j++){
        if(map[j].size() > i){res = res > map[j][i].size() ? res : map[j][i].size();}
    }
    return res;
}
//单词最多的行
int maxLine(vector< vector<string> >& map){
    int res = 0;
    for(int i = 0;i < map.size();i++){res = res > map[i].size() ? res : map[i].size();}
    return res;
}

void pushToVec(string s, vector<string>& str){
    string temp = "";
    int i = 0;
    while(i < s.size()){
        if(s[i] == '\\' && i + 1 < s.size() && s[i + 1] == 'n'){
            str.push_back(temp);
            i += 2;
            temp = "";
            continue;
        }
        temp += s[i];
        i++;
    }
    if(temp.size() > 0){str.push_back(temp);}
}

int main(){
    string s;
    vector< vector<string> > map;
    while(getline(cin, s)){
        stringstream is(s);
        string temp;
        vector<string> str;
        while(is >> temp){pushToVec(temp, str);}
        map.push_back(str);
    }
    vector<int> len;
    int maxL = maxLine(map);
    for(int i = 0;i < maxL;i++){
        int maxLen = maxLength(map, i);
        len.push_back(maxLen);
    }
    for(int i = 0;i < map.size();i++){
        for(int j = 0;j < map[i].size();j++){
            cout << map[i][j];
            if(j != map[i].size() - 1){
                for(int k = 0;k < len[j] - map[i][j].size() + 1;k++){cout << " ";}
            }
        }
        if(i != map.size() - 1){cout << endl;}
    }
    return 0;
}