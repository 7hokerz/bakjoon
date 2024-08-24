#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, m, r, x1, x2;
    cin >> N;
    vector <pair<int,int>> vt;
    stack <pair<int,int>> st;
    for(int i = 0;i<N;i++){
        cin >> m >> r;
        x1 = m-r;
        x2 = m+r;
        vt.push_back({x1,x2});
    }
    sort(vt.begin(), vt.end(), comp);//vt를 제거할 필요 없이 반복문으로 스캔

    for(int i = 0;i<vt.size();i++){
        cout << vt[i].first << ' ' << vt[i].second << '\n';
    }

    int cnt = 1;//원 밖의 영역 미리 계산
    stack <int> inc;//원이 포함될 경우 포함하는 원이 갈리는지 확인하는 스택
    for(int i = 0;i<vt.size();i++){
        if(!st.empty()){
            
        }else{
            st.push(vt[i]);
        }
    }
    cnt += st.size();
    cout << cnt;
}   
/*
1 3 >> -2 4
5 1 >> 4 6
원 2개 + 원 밖 1개 >> 3

2 2 >> 0 4
1 1 >> 0 2
3 1 >> 2 4
원 2개 + 원 2개에 의해 나눠진 한 원 영역 2개 + 원 밖 1개 >> 5

7 5 >> 2 12
-9 11 >> -20 2
11 9 >> 2 20
0 20 >> -20 20 
원 3개 + 원 2개에 의해 나눠진 한 원 영역 2개 + 원 밖 1개 >> 6

원 밖의 부분도 한 개의 영역으로 취급.
원이 다른 두 원에 의해 나눠졌을경우 위 아래 따로 영역 취급

한 원 안에 여러 원이 존재하고 그 원들 중 두 원 이상이 서로 접하여 한 원이 갈라진 경우를 어떻게 구하는가?
결국 한 원이 갈라짐을 확인하려면 
중간에 끊기지 않고, 여러 원이 연속해서 시작부터 끝까지 접하는 경우가 그렇다.

원은 x좌표가 같으면 더 큰 경우부터 주어진다.

경우의 수들
1. 포함하지도 않고 접하지 않는 경우 (한 원의 마지막 x좌표 < 다음 원의 시작 x좌표)
pop, cnt++ 후 단순 삽입


2. 포함되는데 시작 좌표를 접하는 경우 (포함하는 원의 시작 x좌표 == 다음 원의 시작 x좌표 && 포함원 마지막 x좌표 > 다음원 마지막 x좌표 )
이 때 포함하는 원의 마지막 좌표를 inc스택에 삽입 및 다음 원 st에 삽입


(포함하는 원을 여러 포함된 작은 원들이 서로 접해서 가르는 경우)
2-1. 탑 원과 접하면서 포함원의 마지막 x좌표와 접하는 경우 (탑 원의 마지막 x좌표 == 다음 원의 시작 x좌표 && inc.top() == 다음 원의 시작 y좌표)
inc스택 탑값과 포함원의 마지막 x좌표를 찾을 때까지 pop
while(st.top().second == inc.top()){
    cnt++;
    st.pop();
}
inc.pop();
cnt++;(2를 더하지 않는 이유는 이 포함원이 포함된 원일 경우를 고려하고, 어차피 제거될 때 cnt++을 하므로 굳이 2를 더할 필요 없음)

2.2 탑 원과 접하지 않게 된 경우 (사실 1과 같은 느낌이다.)(2 조건을 먼저 넣고, 1 조건을 나중에 넣어야 할 듯
2.1과 같은 과정을 수행하나
cnt++ 후 inc가 비어있는 지 확인한다.

4. 반복문이 끝나고 남아있는 원들에 대하여
이 경우는 다른 조건을 만족하는 경우가 없기 때문에 cnt += st.size();해준다.
*/