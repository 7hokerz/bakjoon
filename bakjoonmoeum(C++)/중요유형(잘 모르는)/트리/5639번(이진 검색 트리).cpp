#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef pair<int,int> pii; typedef pair<pii,int> lpii; typedef pair<int,pii> rpii;
typedef pair<pii,pii> piiii;//더블 pii
#define mod 1'000'000'009
#define INF 2'000'000'001
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int input, n = 0, i; vector <int> vt;

void postorder(int s, int e){
    if(s >= e) return;

    for(i = s + 1;i<e;i++){//s보다 더 큰 노드를 찾으면 중지
        if(vt[s] < vt[i]) break;
    }
    
    postorder(s + 1, i);//왼쪽 서브트리
    postorder(i, e);//오른쪽 서브 트리
    cout << vt[s] << '\n';//루트 노드
}


int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(cin >> input) { 
        vt.push_back(input); 
        n++;
    }

    postorder(0, n);//노드 번호
}
/*                         
기존 C언어로 구현한 코드를 갖다 쓰면 200ms 이상 소요
다른 풀이 보고 한 코드는 36ms 소요

전위 순회: 루트 >> 왼쪽 >> 오른쪽
후위 순회: 왼쪽 >> 오른쪽 >> 루트

이진 검색 트리는 왼쪽 서브트리의 키값이 항상 작고, 오른쪽 서브트리의 키값이 항상 크다.

과정:
1. 먼저 벡터에 전위 순회 값을 저장한다.
2. 이진 검색 트리는 위와 같은 규칙이 존재하므로 값의 대소 비교를 통해 알아낼 수 있다.
따라서 0 인덱스에서 시작하여 더 큰 노드를 찾으면 중지하고 재귀로 새로 서브트리를 탐색한 후 노드를 출력한다.
*/

//+ 후위를 전위로
vector <int> res;
void preorder(int s, int e){
    if(s >= e) return;

    for(i = s + 1;i<e;i++){//s보다 더 작은 노드를 찾으면 중지
        if(vt[s] > vt[i]) break;
    }

    preorder(s + 1, i);
    preorder(i, e);
    res.push_back(vt[s]);//루트
}
//크게 달리진 건 없고, 루트를 먼저 출력하고 왼쪽 , 오른쪽을 탐색하는 것이 달리졌고,
//크기 비교 부분도 달라졌다. 다만 후위 값을 받아들인 후 뒤집고 탐색하고 res에 담은 후 다시 뒤집고 출력해야 한다.
//(아마 더 쉬운 방법이 있을수도?)

