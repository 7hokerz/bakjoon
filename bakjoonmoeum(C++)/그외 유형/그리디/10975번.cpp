#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, input;
    vector <int> dq;
    vector <pair<int,int>> sorted;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        sorted.push_back({input, i});
    }

    sort(sorted.begin(),sorted.end());

    int res = 0;
    for(int i = 0;i<N;i++){
        int cnt = 0;
        while(!sorted.empty() && sorted[cnt].second != i){
            cnt++;
        }
        bool chk = false;

        for(int j = 0;j<dq.size();j++){//소티드 요소의 양 쪽의 요소가 dq의 요소 중에서 존재한다는 것? 넣을 수 있다는 뜻
            if((cnt > 0 && sorted[cnt-1].first == dq[j]) || (cnt < sorted.size()-1 && sorted[cnt+1].first == dq[j])){
                chk = !chk;
                break;
            }   
        }
        dq.push_back(sorted[cnt].first);

        if(!chk) res++;//넣으면 오름차순이 무너지는 경우
    }
    cout << res;
}
/*
양 요소 사이에 수가 존재하나 안하나 확인(없다는 것은 어떤 수를 넣어도 오름차순 정렬에 문제가 없다는 뜻)
나중에 플레1 데크 소트를 풀 때 활용 가능할 듯

3 6 0 5 4 9 input
0 3 4 5 6 9 sorted

첫 수는 새로운 데크를 만들어 넣는다.
3

6 양쪽에 3이 존재하지 않으므로 새로운 데크
3
6

0의 옆에 3이 있으므로
0 3
6

5의 옆에 6이 있으므로
0 3
5 6

4의 옆에 5가 있으므로
0 3
4 5 6

0 3 4
5 6

9의 옆에 6이 있으므로
0 3
4 5 6 9

0 3 4
5 6 9



데크에 요소가 존재하는 경우는 원래 넣을 수 있는 경우로 본다.
6
0 1 2 3 4 5
3 6 0 9 6 3

2 0 5 1 4 3
0 3 3 6 6 9

중복 요소를 어떻게 처리하는 게 좋을까?

시나리오:
0 3 6 먼저 넣는다. 남은 것: 9 6 3
*/