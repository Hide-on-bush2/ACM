#include<vector>
#include<utility>
#include<iostream>

using namespace std;

int main(){
    int Case;
    cin >> Case;
    while(Case--){
        int num;
        cin >> num;
        vector< pair<int, int> > points;
        int sum = 0;
        for(int i = 0;i < num;i++){
            int x, y;
            cin >> x >> y;
            sum += x * 2;
            points.push_back(make_pair(x * 2, y));
        }
        int condition = true;
        for(int i = 0;i < points.size();i++){
            pair<int, int> temp = points[i];
            bool haveMidPoint = false;
            for(pair<int, int> item : points){
                if(item.second == temp.second && (item.first + temp.first) * num == sum * 2){
                    haveMidPoint = true;
                    break;
                }
            }
            if(!haveMidPoint){
                condition = false;
                break;
            }
        }
        if(condition){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }
    return 0;
}