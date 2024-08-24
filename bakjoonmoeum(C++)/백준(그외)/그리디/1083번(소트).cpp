#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
제일 마지막에 있는 원소를 첫번째로 보내는 교환 횟수: N-1번
우선 최댓값을 찾아본다.
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque <int> q;
    int N, input, S;
    cin >> N;
    vector <int> arr;
    for(int i = 0;i<N;i++){
        cin >> input;
        arr.push_back(input);
    }
    cin >> S;
    while(S > 0){
        pair<int, int> maxv;
        maxv={arr[0],0};
        int n = arr.size();
        if(S-1>=n){
            for(int i = 0;i<n;i++){
                if(arr[i]>maxv.first){
                    maxv.first = arr[i];
                    maxv.second = i;
                }
            }
            S -= maxv.second;
        }else{
            for(int i = 0;(i<S+1 && i < n);i++){
                if(arr[i]>maxv.first){
                    maxv.first = arr[i];
                    maxv.second = i;
                }
            }
            S -= maxv.second;
        }
        if(arr.empty()) break;
        q.push_back(maxv.first);
        arr.erase(arr.begin() + maxv.second);
    }
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop_front();
    }
    while(!arr.empty()){
        q.push_back(arr.back());
        arr.pop_back();
    }
    while(!q.empty()){
        cout << q.back() << ' ';
        q.pop_back();
    }
}
/*
중간에 아웃오브바운드 때문에 시간이 많이 걸렸는데 아직도 정확한 원인은 모르겠다.
해결된 이유?(정확하지 않음)
1. maxv값 초기화 2. 벡터가 비어있을 때 브레이크 <<2번은 필수. 지워본 결과 오류 발생 

우선 경우가 2가지 존재한다.
1. S가 충분히 커서 모든 배열을 탐색하여 최댓값을 찾을 수 있는 경우
2. S가 작아서 S연산이 가능한 만큼의 최댓값을 찾는 경우

1의 경우는 S가 작아질 때까지 최댓값을 앞으로 보내면 된다.
2의 경우는 제한을 둬서 가능한 경우 중 최댓값을 찾아 앞으로 보낸다.

위 2개의 경우를 나누지 않고 단순히 뒤의 요소가 큰 경우만 앞으로 보내면 그리디한 값이 나오지 않음에 주의
이유는 S의 범위 내에서 가능한 최댓값이 존재하여 사전순으로 더욱 뒷서기가 가능하다.
*/