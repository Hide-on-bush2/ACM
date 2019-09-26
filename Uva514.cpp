#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        if(n == 0){break;}
        int temp;
        while(scanf("%d", &temp) == 1 && temp){
            stack<int> outQueue;
            outQueue.push(temp);
            for(int i = 1;i < n;i++){
                scanf("%d", &temp);
                outQueue.push(temp);
            }
            stack<int> inQueue, midQueue;
            midQueue.push(outQueue.top());
            outQueue.pop();
            while(!outQueue.empty()){
                while((!midQueue.empty() && !inQueue.empty() && inQueue.top() == midQueue.top() + 1) || (inQueue.empty() && midQueue.top() == n)){
                    inQueue.push(midQueue.top());
                    midQueue.pop();
                }
                midQueue.push(outQueue.top());
                outQueue.pop();
            }
            while(!midQueue.empty() && (inQueue.empty() || inQueue.top() > midQueue.top())){
                inQueue.push(midQueue.top());
                midQueue.pop();
            }
            if(midQueue.empty()){printf("Yes\n");}
            else{printf("No\n");}
        }
        printf("\n");
    }
    return 0;
}