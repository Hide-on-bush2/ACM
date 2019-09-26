#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool putToBack(int value, vector<int>& Queue, vector<int>& position){
    for(int i = 0;i < position.size();i++){
        if(Queue[position[i]] > value){return true;}
    }
    return false;
}

void printVec(vector<int>& temp){
    for(int i = 0;i < temp.size();i++){cout << temp[i] << " ";}
    cout << endl;
}

int main(){
    int Case;
    cin >> Case;
    while(Case--){
        int n, m;
        cin >> n >> m;
        vector<int> Queue;
        vector<int> position(n);
        for(int j = 0;j < n;j++){
            int temp;
            cin >> temp;
            Queue.push_back(temp);
        }
        for(int i = 0;i < n;i++){position[i] = n - i - 1;}
        int time = 0;
        while(find(position.begin(), position.end(), m) != position.end()){
            int index = position.back();
            int value = Queue[index];
            position.pop_back();
            if(putToBack(value, Queue, position)){position.insert(position.begin(), index);}
            else{time += 1;}
        }
        cout << time << endl;
    }
}
