#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int IDMap[10005][11];

map<string, int> IDCache;
vector<string> strCache;

int getID(string& s){
    if(IDCache.find(s) != IDCache.end()){return IDCache[s];}
    else{
        strCache.push_back(s);
        return IDCache[s] = strCache.size() - 1;
    }
}
