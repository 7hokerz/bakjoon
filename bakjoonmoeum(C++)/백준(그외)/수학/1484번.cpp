#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <int> q;
    int G;
    cin >> G;

    for(long long i = 1LL;i<1000000LL;i++){
        double res = sqrt(i*i+G);
        int intpart = static_cast<int>(res);
        if(res - intpart == 0.0){
            q.push(res);
        }
    }
    if(q.empty()){
        cout << -1;
        return 0;
    }
    while(!q.empty()){
        cout << q.front() << '\n';
        q.pop();
    }
}
/*
x: 기억하고 있던 몸무게
y: 현재 몸무게

G = y^2-x^2

15 = y^2-x^2

가능한 y 출력(자연수)

y = sqrt(x^2+15)

y=4 x=1

y=5 x=루트10

x=루트51 y=8

y = sqrt(x^2+G) 
*/