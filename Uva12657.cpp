#include<iostream>
#include<cstdio>
#include<algorithm>



using namespace std;

const int maxn = 1000;
int Left[maxn], Right[maxn];

void link(int x, int y){
    Right[x] = y;
    Left[y] = x;
}

int main(){
    int n, m, Case = 0;
    while(scanf("%d %d", &n, &m) == 2){
        for(int i = 1;i <= n;i++){
            Left[i] = i - 1;
            Right[i] = i == n ? 0 : i + 1;
        }
        Right[n] = 1;
        Left[0] = n;
        int x, y, op;
        bool inv = false;
        while(m--){
            scanf("%d", &op);
            if(op == 4){inv = !inv;}
            else{
                scanf("%d %d", &x, &y);
                if(op == 3 && Right[y] == x){swap(x, y);}
                if(op != 3 && inv){op = 3 - op;}
                if(op == 1 && Left[y] == x){continue;}
                if(op == 2 && Right[y] == x){continue;}
                int lx = Left[x], rx = Right[x], ly = Left[y], ry = Right[y];
                if(op == 1){
                    link(lx, rx);
                    link(ly, x);
                    link(x, y);
                }
                else if(op == 2){
                    link(lx, ly);
                    link(y, x);
                    link(x, ry);
                }
                else if(op == 3){
                    if(Right[x] == y){
                        link(lx, y);
                        link(y, x);
                        link(x, ry);
                    }
                    else{
                        link(lx, y);
                        link(y ,rx);
                        link(ly, x);
                        link(x, ry);
                    }
                }
            }
            int b = 0;
            long long ans = 0;
            for(int i = 1;i <= n;i++){
                b = Right[b];
                if(i % 2){ans += b;}
            }
            if(inv && n % 2 == 0){ans = (long long)n * (n + 1) / 2 - ans;}
            printf("Case %d: %11d\n", ++Case, ans);
        }
    }
    return 0;
}
