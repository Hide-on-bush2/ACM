#include<string>
#include<iostream>
#include<cstdio>
#include<utility>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector< vector<int> > matrix;
    getchar();
    while(n--){
        vector<int> temp(2);
        char c;
        scanf("%c%d%d", &c, &temp[0], &temp[1]);
        matrix.push_back(temp);
        getchar();
    }
    string s;
    while(cin >> s){
        stack< pair<int, int> > S;
        int sum = 0;
        bool print = true;
        for(int i = 0;i < s.size();i++){
            char temp = s[i];
            if(s[i] == '('){S.push(make_pair(-1, -1));}
            else if(s[i] == ')'){
                pair<int, int> cur;
                if(!S.empty()){
                    cur = S.top();
                    S.pop();
                }
                bool con = true;
                while(!S.empty() && S.top() != make_pair(-1, -1)){
                    pair<int, int> temp = S.top();
                    S.pop();
                    if(temp.second != cur.first){
                        con = false;
                        break;
                    }
                    sum += temp.first * temp.second * cur.second;
                    cur = make_pair(temp.first, cur.second);
                }
                if(!con){
                    printf("error\n");
                    print = false;
                    break;
                }
                if(!S.empty()){
                    S.pop();
                    S.push(cur);
                }
            }
            else{
                if(S.empty()){break;}
                pair<int, int> cur = make_pair(matrix[temp - 'A'][0], matrix[temp -'A'][1]);
                S.push(cur);
            }
        }
        if(print){printf("%d\n", sum);}
    }
}