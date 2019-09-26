//算法复杂度不够低

#include<iostream>
#include<vector>

using namespace std;

struct Student{
    int location;
    int target;
    bool compare;
    Student(int x, int y, bool com = false):location(x), target(y), compare(com){}
};

bool Compare(Student& stu, vector<Student>& Class){
    for(int i = 0;i < Class.size();i++){
        if(Class[i].compare == false && Class[i].location == stu.target && Class[i].target == stu.location){
            Class[i].compare = true;
            return true;
        }
    }
    return false;
}

void print(vector<Student>& Class){
    for(Student s : Class){
        cout << s.location << ", " << s.target << ", " << s.compare << endl;
    }
}

int main(){
    int n;
    while(cin >> n && n){
        vector<Student> Class;
        int location, target;
        for(int i = 0;i < n;i++){
            cin >> location >> target;
            Student tempStu(location, target);
            if(!Compare(tempStu, Class)){Class.push_back(tempStu);}
        }
        bool condition = true;
        for(int i = 0;i < Class.size();i++){
            if(Class[i].compare == false){
                condition = false;
                break;
            }
        }
        if(condition){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }   
}