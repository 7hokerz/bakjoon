#include <iostream>
#include <queue>
#include <functional>
#include <math.h>
using namespace std;

struct cmp{//기본적으로 절댓값으로 값을 비교해서 top에 배치하고 절댓값이 같은 경우는 두 수를 비교해서 배치시킨다.
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a>b;//절댓값이 같으면 부호가 더 큰 게 뒤로
        return abs(a)>abs(b);//절댓값이 더 큰 값이 뒤로
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue <int, vector<int>, cmp> pq;
    int n, input; cin >> n;

    for(int i = 0;i<n;i++){
        cin >> input;
        if(input != 0){
            pq.push(input);
        }else{
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
/*

*/