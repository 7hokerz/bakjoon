#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

/*
분리 집합(서로소 집합)(Disjoint Set)
특징: 전체 집합 U에 대해 U의 분리 집합 A, B는 다음 조건을 만족
1. A, B는 U의 부분 집합
2. A, B는 공통 원소를 가지지 않음.
3. A, B의 합집합이 곧 전체집합 U이다. (A, B에 속하지 않는 U의 원소가 없어야 함.)

즉, 이미 존재하는 집합 U에 대해 겹치는 부분이 발생하지 않도록 모든 원소들을 분리한 부분집합.


Union-Find 알고리즘(분리 집합을 구현하는 알고리즘)(각 그룹을 트리의 형태로 표현)
각 노드마다 그 노드의 부모 노드 번호를 기록한다.
이렇게 하면 항상 최상위 노드인 루트 노드를 가지게 된다. 이 루트 노드로 그룹을 구별한다.

필요한 연산
1. 루트 노드를 찾는 작업(Find)
2. 두 트리를 병합하는 작업(Union)

두 연산의 최적화
1. 경로 압축
2. Union by Rank(트리의 높이)
*/
int parent[101];

int find_root(int x){
    //x가 root면 x를 반환
    if(x == parent[x]) return x;
    //아니면 부모 노드에서 루트 노드 찾기를 반복
    return find_root(parent[x]);
}

int find_root_opt(int x){
    //x가 root면 x를 반환
    if(x == parent[x]) return x;
    //아니면 부모 노드에서 루트 노드 찾기를 반복
    //이 때 x의 부모 노드를 루트 노드로 갱신하기.
    return parent[x] = find_root_opt(parent[x]);
}

void union_root(int x, int y){
    //x와 y의 루트 노드를 찾는다.
    x = find_root(x);
    y = find_root(y);

    if(x != y){
        //서로 다른 트리에 속하면 한 쪽의 트리를 다른 쪽에 붙임.
        parent[x] = y;
    }
}

int node_rank[101];

void union_root_opt(int x, int y){
    //x와 y의 루트 노드를 찾는다.
    x = find_root(x);
    y = find_root(y);

    if(x != y){
        //서로 다른 트리에 속하면 한 쪽의 트리를 다른 쪽에 붙임.
        //항상 높이가 낮은 트리를 높이가 높은 트리에 붙인다.(높은 트리를 낮은 트리에 붙이면 높이가 더 커짐.)
        //만약 합친 두 트리의 높이가 같다면 합친 후 트리의 높이를 1 증가시킴.
        if(node_rank[x] < node_rank[y]) parent[x] = y;
        else if(node_rank[x] > node_rank[y]) parent[y] = x;
        else{
            parent[y] = x;
            node_rank[x]++;
        }
    }
}



int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    
}

/*



*/