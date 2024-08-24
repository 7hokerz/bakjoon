#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue <int, vector<int>, less<int>> pq;//less를 쓰면 최대 힙으로 동작(사실 그냥 안쓰고 해도 됨.)
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