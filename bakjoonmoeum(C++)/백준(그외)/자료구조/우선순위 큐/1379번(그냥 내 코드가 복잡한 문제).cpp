#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, a, b, c;
bool comp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

struct cmp{
    bool operator()(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if(a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first > b.first.first;
    }
};
vector <pair<pair<int,int>,int>> vt;//시작 시간, 끝나는 시간, 강의 번호

priority_queue <pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, 
greater<pair<pair<int,int>,int>>> pq;//끝나는 시간, 강의 번호, 강의실 번호

vector <pair<int,int>> res;//강의 번호, 강의실 번호

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a >> b >> c;//강의 번호, 시작 시간, 끝나는 시간
        vt.push_back({{b,c},a});
    }
    sort(vt.begin(),vt.end());

    int cnt = 0;
    for(int i = 0;i<vt.size();i++){
        int num;
        if(!pq.empty() && pq.top().first.first <= vt[i].first.first){//강의 연결 가능하면
            num = pq.top().second;
            res.push_back({vt[i].second,num});
            pq.pop(); 
        }else{//불가능하면
            num = ++cnt;
            res.push_back({vt[i].second,num});
        }
        pq.push({{vt[i].first.second,vt[i].second},num});
    }
    cout << cnt << '\n';
    sort(res.begin(),res.end(), comp);
    for(int i = 0;i<res.size();i++){
        cout << res[i].second << '\n';
    }
}
/*
pq에는 종료 시간, 강의 번호를 저장
res에는 강의 번호, 강의실 번호를 저장
**종료 시간이 시작 시간보다 크거나 같으면 우큐에서 제거(아오...순서대로라고만 하면 무슨 순서대로라고 하는 지 알 수가 없잖아)
그 외에는 cnt++

출력할 때 입력 순서가 아닌 강의 번호 순서대로 출력해야 함.

8
2 5 1 2 3 5 1 4

번호 3 1 5 8 2 4 6 7 
시작 2 3 6 6 7 12 15 20
끝 14 8 20 27 13 18 21 25
1 2 3 4 5 2 5 1

3 
pq 14 cnt = 1;
1
pq 8 14 cnt = 2;
5
pq 8 14 20 cnt = 3;
8
pq 8 14 20 27 cnt = 4;
2
pq 8 13 14 20 27 cnt = 5;
4
pq 13 14 18 20 27
6
pq 14 18 20 21 27
7
pq 18 20 21 25 27
*/