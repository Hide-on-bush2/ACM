
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;



bool beCovered(int midPoint, int height, vector< vector<int> >& tranversed){
    for(vector<int> building : tranversed){
        if(midPoint > building[0] && midPoint < building[0] + building[2] && height < building[4]){return true;}
    }
    return false;
}
struct node{
    int x;
    int y;
    int id;
    node(int a, int b, int i):x(a), y(b), id(i){}
};

struct cmp{
    bool operator()(node& a, node& b){
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    }
}myCmp;
int main(){
    int n;
    int i = 1;
    while(cin >> n){
        vector< vector<int> > myMap(n, vector<int>(5));
        vector<int> xCollection;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 5;j++){cin >> myMap[i][j];}
            if(find(xCollection.begin(), xCollection.end(), myMap[i][0]) != xCollection.end()){xCollection.push_back(myMap[i][0]);}
        }
        sort(xCollection.begin(), xCollection.end());
        vector<int> midPoint;
        for(int i = 0;i < xCollection.size() - 1;i++){midPoint.push_back((xCollection[i] + xCollection[i + 1]) / 2);}
        vector<node> res;
        for(int i = 0;i < n;i++){
            vector<int> building = myMap[i];
            vector<int> haveX;
            for(int point : midPoint){
                if(point > building[0] && point < building[0] + building[2]){haveX.push_back(point);}
            }
            bool ifCovered = false;
            for(int x : haveX){
                if(beCovered(x, building[4], myMap)){
                    ifCovered = true;
                    break;
                }
            }
            if(!ifCovered){res.push_back(node(building[0], building[1], i + 1));}
        }
        sort(res.begin(), res.end(), myCmp);
        cout << "For map #" << i++ << " , the visible building are numered as follows:" << endl;
        for(node n : res){cout << n.id << " ";}
        cout << endl;
    }
    return 0;
}