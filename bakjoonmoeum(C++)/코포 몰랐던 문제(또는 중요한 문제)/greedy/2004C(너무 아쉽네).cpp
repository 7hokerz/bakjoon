#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
 
int T, N, M, inp, ret = 0;
 
int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        int K;
        cin >> N >> K;
        vector <int> vt;
 
        for(int i = 1;i<N+1;i++){
            cin >> inp;
            vt.push_back(inp);
        }
        sort(vt.rbegin(), vt.rend());
 
        ll val = 0;

        for(int i = 1;i<vt.size();i += 2) val += abs(vt[i] - vt[i-1]);
        
        //cout << val << '\n';
        
        if(val - K < 0) val = 0;
        else val -= K;

        if(N % 2) val += vt[N-1];
        cout << val << '\n';
    }
}
/*
엘리스가 가져간 물건의 가격과 차이가 최대한 덜 나는 물건을 밥은 가져가려 할 것이다.

짝수일 땐 2개씩, 홀수일 땐 3개, 2개씩

그리디하게?
짝수일 때는 결국 홀수번째 합 - 짝수번째 합이 점수가 됨.

다른 풀이 보니...내림차순 정렬 후 위와 같은 과정을 수행하고 홀수일 때 남은 한 원소를 더해주는 방식으로 끝냈는데,
하...뭔가 허탈하네 
오름차순으로 정렬한 내가 잘못이다 썅

항상 큰 거를 선택하는 그리디임을 알았음에도 오름차순으로 정렬해버린 나...
*/