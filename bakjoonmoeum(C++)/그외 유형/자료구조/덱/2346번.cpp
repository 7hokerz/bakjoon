#include <iostream>
#include <deque>
#include <stdlib.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <pair<int,int>> dq, tmp;
    int n, input;
    cin >> n;
    for(int i = 1;i<n+1;i++){
        cin >> input;
        dq.push_back({input,i});
    }
    while(!dq.empty()){
        cout << dq.front().second << ' ';
        if(dq.front().first>0){
            tmp.push_back(dq.front());
            dq.pop_front();
            for(int i = 1;i<tmp.front().first;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            tmp.push_back(dq.front());
            dq.pop_front();
            for(int i = 0;i<-tmp.front().first;i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        tmp.pop_back();
    }
}
/*
음...솔직히 아직도 조금 헷갈려

모든 확인은 덱의 front에서 하기로 기준
1. front가 양수인지 음수인지 구분해야 한다.
2.1 양수면 우선 미리 front를 제거하고 
front-1만큼 front를 뒤로 옮긴다.
2.2 음수면 미리 front를 제거 후
양수와 다르게 반대로 옮겨야 하므로
back에 있는 요소를 front로 옮겨준다.
여기서 양수와 다른 점은 -front만큼 옮겨준다는 것이다.
-는 부호가 음수이기 때문이고, front에서 확인해야하므로
한 번 더 back에서 front로 옮겨야 정상적인 답이 나온다.
(사실 이해했다기 보단 이렇게 하니 됐네? 느낌이다.)

*/