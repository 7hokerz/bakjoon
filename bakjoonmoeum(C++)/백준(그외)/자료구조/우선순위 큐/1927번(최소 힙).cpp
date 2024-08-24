#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue <int, vector<int>, greater<int>> pq;//위와 같이 할 경우 작은 값이 우선된다. 즉 오름차순 정렬(최소 힙)
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