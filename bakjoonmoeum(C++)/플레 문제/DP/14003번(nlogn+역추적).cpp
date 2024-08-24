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
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 1'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \
//3차원 map 출력
#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int N, input, length;
vector <int> vt, LIS, Idx, res;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        vt.push_back(input);
    }
    LIS.push_back(vt[0]); Idx.push_back(1);
    for(int i = 1;i<N;i++){
        int idx = lower_bound(LIS.begin(), LIS.end(), vt[i]) - LIS.begin();
        //cout << idx << ' ';
        if(idx == LIS.size()){
            LIS.push_back(vt[i]);
        }
        else{
            LIS[idx] = vt[i];
        }
        Idx.push_back(idx+1);//LIS는 0~N이므로 실제 인덱스를 고려하여 +1
    }
    length = LIS.size();
    cout << length << '\n';
    
    for(int i = Idx.size()-1;i>=0;i--){
        if(Idx[i] == length){//최초로 나오는 수에 대해서 기록하고 length-1의 값을 찾으러 간다.
            res.push_back(vt[i]);
            length--;
        }
    }
    for(int i = res.size()-1;i>=0;i--) cout << res[i] << ' ';
}
/*
10 20 10 30 20 50

10 20 30 50
1 2 1 3 2 4
10 20 10 30 20 50

-61 -28 -72 59 13 -21 84 -76 -52 -1
'1'  '2'  1  3  3  '3' 4   1   2 '4'

-61 -28 -21 -1

최장 길이부터 가장 최근에 기록된 수를 4 > 3 > 2 > 1로 찾아가는데, 
처음 4 다음에 가장 최근에 기록된 3, 3 다음에 가장 최근에 기록된 2...순으로 찾아간다.

구하는 방법 참고
https://kimmessi.tistory.com/191

이 글을 참고하면 왜 그런지 이해가 더 쉬울 수 있다.
https://eatchangmyeong.github.io/2022/01/20/why-is-lis-algorithm-so-confusing.html

for(int i = 0;i<Idx.size();i++){
    cout << Idx[i] << ' ';
}
*/