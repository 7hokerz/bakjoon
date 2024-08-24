#include <iostream>
#include <deque>
using namespace std;
/*
카드를 옮기는 과정을 반대로 수행하면 된다.
책상위에 놓아진 카드에서 N부터 덱에 넣고 N-1을 앞에 넣은 후 가장 뒤에 있는 걸 가장 앞으로 옮긴다.(N-1번)
그 후 N-2를 가장 앞에 놓고 가장 뒤에 있는 걸 가장 앞으로 N-2번 옮긴다.
...반복
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <int> dq;
    int N;
    cin >> N;
    dq.push_back(N);
    
    for(int i = N-1;i>0;i--){
        dq.push_front(i);
        for(int j = 0;j<i;j++){
            dq.push_front(dq.back());//가장 뒤에 있는 걸 앞으로 삽입하고
            dq.pop_back();//뒤에 있던 건 지운다.
        }
    }   
    while(!dq.empty()){
        cout << dq.front() << ' ';
        dq.pop_front();
    }
}