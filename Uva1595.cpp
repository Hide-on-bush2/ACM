#include<map>
#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

struct point{
    int x;
    int y;
    point(int a, int b):x(a), y(b){}
};

int main(){
    int Case;
    scanf("%d", &Case);
    while(Case--){
        int num;
        scanf("%d", &num);
        vector<point> points;
        map<double, int> hash;
        for(int i = 0;i < num;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            points.push_back(point(x, y));
        }
        for(int i = 0;i < points.size();i++){
            point temp = points[i];
            for(int j = i + 1;j < points.size();j++){
                if(points[j].y == temp.y){
                    if(points[j].x == temp.x){hash[temp.x] += 2;}
                    else{
                        hash[temp.x] += 1;
                        hash[points[j].x] += 1;
                        hash[double(temp.x + points[j].x) / 2] += 2;
                    }
                }
            }
        }
        map<double, int>::iterator it;
        bool condition = false;
        for(it = hash.begin();it != hash.end();it++){
            if(it->second >= num){
                condition = true;
                break;
                }
        }
        if(condition){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }
    return 0;
}