#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 999999999
//중요! 가중치 값에 -1가 들어가면 안됨.
int start = 1, n, m;//노드의 개수, 간선의 개수

vector <pair<int,int>> gr[100001];//노드, 거리

//최단거리 테이블
vector <int> dist(100001,INF);//dist: 해당 정점까지의 최소 비용(최단 거리)을 저장하는 배열

void dij_pq(){
    priority_queue<pair<int,int>> pq;//거리, 노드

    pq.push({0,start});//시작 노드로 가기 위한 최단경로는 0
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;//-?최대 힙이므로 -를 넣어 최단 거리가 앞에 오도록 하기 위해
        int cur = pq.top().second;//현재 노드
        pq.pop();

        if(dist[cur] < cost) continue;//기록된 값보다 cost가 높다는 건 최단 거리가 아니므로 스킵

        for(int i = 0;i<gr[cur].size();i++){
            int nx = gr[cur][i].first;
            int nx_dist = cur + gr[cur][i].second;

            if(nx_dist < dist[nx]){//기록값 값보다 더 최단거리인 경우
                dist[nx] = nx_dist;
                pq.push({-nx_dist, nx});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    
}