#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int N, M, K;
ll arr[1'000'001];
vector <ll> segTree;

ll make_SegTree(int node, int start, int end){//현재 노드 번호, 시작 범위, 마지막 범위

    if(start == end) return segTree[node] = arr[start];
    //시작 범위 == 끝 범위인 경우 값은 하나

    int mid = (start + end) / 2;//중간으로 나눈다.
    ll Left_Result = make_SegTree(node * 2, start, mid);
    ll Right_Result = make_SegTree(node * 2 + 1, mid + 1, end);
    segTree[node] = Left_Result + Right_Result;

    return segTree[node];
}

ll sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;//1
    if(left <= start && right >= end) return segTree[node];//2

    //3
    int mid = (start + end) / 2;
    ll Left_Result = sum(node * 2, start, mid, left, right);
    ll Right_Result = sum(node * 2 + 1, mid + 1, end, left, right);
    
    return Left_Result + Right_Result;
}

void update(int node, int start, int end, int index, ll diff){
    if(index < start || index > end) return;
    segTree[node] = segTree[node] + diff;

    if(start != end){
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> K;
    
    for(int i = 1;i<N+1;i++) cin >> arr[i];

    segTree.resize(N * 4);
    make_SegTree(1, 1, N);

    for(int i = 0;i<M+K;i++){
        int num; cin >> num;
        
        if(num == 1){
            ll idx, val; cin >> idx >> val;

            ll diff = val - arr[idx];
            arr[idx] = val;
            update(1, 1, N, idx, diff);
        }
        else{
            int l, r; cin >> l >> r;
            cout << sum(1, 1, N, l, r) << '\n';
        }
    }
}
/*
for(int i = 1;i<N+1;i++){
            cout << arr[i] << ' ';
        }cout << '\n';

크기가 N인 배열이 존재할 때
1. 트리의 높이 = ceil(log2(N))
2. 세그먼트 트리의 크기 = (1 << (트리의 높이 + 1))

세그먼트 트리 만들기

과정:
1. 주어진 범위를 반으로 나눈다.
2. 나눠진 2개의 범위에 대해서 '왼쪽범위'에 대한 재귀호출을 한다.
3. 나눠진 2개의 범위에 대해서 '오른쪽범위'에 대한 재귀호출을 한다.
4. 위의 과정을 반복한다.


구간 합 구하기
1. 현재 우리가 탐색하는 범위가, 우리가 찾고자 하는 구간과 완전히 겹쳐지지 않는 경우.
>> 더 탐색할 필요가 없다.

2. 현재 우리가 탐색하는 범위가, 우리가 찾고자 하는 구간에 완전히 속해있는 경우.
>> node의 값을 return

3. 1, 2번 경우를 제외한 나머지 경우. 즉, 일부만 걸쳐있는 경우.
>> 추가적인 탐색을 진행한다.


값 바꾸기
1. 바꾸고자 하는 Index값이, 현재 우리가 탐색하는 범위 내에 속해있는 경우.
>> 값을 바꿔준 후 탐색을 이어서 진행한다.

2. 바꾸고자 하는 Index값이, 현재 우리가 탐색하는 범위 내에 속해있지 않은 경우.
>> 탐색 종료
*/