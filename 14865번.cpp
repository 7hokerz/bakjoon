#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x1, y1;
    cin >> n;
    vector <pair<int,int>> vt, vt2;
    for(int i = 0;i<n;i++){//(1)
        cin >> x1 >> y1;
        if(!vt.empty() && vt.back().first == x1 && ((y1>0 && vt.back().second>0) || (y1<0 && vt.back().second<0))){
            vt.pop_back();
            continue;
        }
        vt.push_back({x1,y1});
    }
    if(vt[0].first != vt[1].first && vt[0].first == vt.back().first){//(2)
        if(vt[0].second > 0){
            vt.insert(vt.begin(), vt.back());
            vt.pop_back();
        }else{
            vt.push_back(vt.front());
            vt.erase(vt.begin());
        }
    }else if(vt[0].first == vt[1].first){//(3)
        if(vt[0].second > 0 && vt[1].second < 0){//방향이 양>>음이어서 잘못된 봉우리가 표현되는 경우 뒤에 있는 2개를 앞으로
            vt.insert(vt.begin(), vt.back());
            vt.pop_back();
            vt.insert(vt.begin(), vt.back());
            vt.pop_back();
        }
    }

    for(int i = 2;i<vt.size();i+=4){//(4)
        if(vt[i].first > vt[i-2].first){
            vt2.push_back({vt[i-2].first, vt[i].first});
        }else{
            vt2.push_back({vt[i].first, vt[i-2].first});
        }
    }
    
    sort(vt2.begin(),vt2.end(), comp);//굳이 빼면서 스택에 넣을 필요 없이 반복문으로 스캔하면 됨.
    
    /*for(int i = 0;i<vt2.size();i++){
        cout << vt2[i].first << ' ' << vt2[i].second << '\n';
    }*/

    //(5)
    stack <pair<int,int>> st[2];//(1), (2)
    for(int i = 0;i<vt2.size();i++){//(1)
        if(st[0].empty() || (!st[0].empty() && st[0].top().second < vt2[i].first)){
            st[0].push(vt2[i]);
        }

        if(!st[1].empty() && st[1].top().second > vt2[i].first){
            st[1].pop();
        }
        st[1].push(vt2[i]);
    }
    cout << st[0].size() << ' ' << st[1].size();
}   
/*
이해가 우선인 스택을 이용한 구현 문제
과정
1. 입력값을 벡터에 저장하는데, x좌표가 같으면서 y좌표의 부호가 다른 경우만 저장한다. 부호가 같은 경우는 x축을 교차하지 않기 때문

2. 시작 x좌표가 다음 x좌표와 다른 경우 이 때는 y좌표의 부호를 확인하여 양수면 back에 있는 얘를 데려오고,
음수면 시작좌표를 뒤로 보낸다. 
이유: y좌표가 양수여야 유효한 봉우리임을 알 수 있기 때문

3. 시작 x좌표가 다음 x좌표와 같을 때, 둘의 y좌표를 비교한다. 이 때 시작y좌표가 양수고 다음y좌표가 음수면 
유효하지 않은 봉우리(-봉우리)를 표현하게 되므로 back의 좌표를 앞으로 데려온다.

4. 비교를 왼쪽>>오른쪽으로 할 것이므로 새로운 벡터에 더 작은 좌표를 first에 넣고 큰 좌표를 second에 넣은 후 오름차순 정렬한다.

5. 벡터를 순회하며 두 경우의 수를 각각 구해준다.
(1) 다른 봉우리에 포함되지 않음을 확인하려면 첫 x좌표의 끝보다 다음 요소의 x시작 좌표가 더 크면 첫 봉우리가 포함되지 않음을 알 수 있음.
(2) 다를 봉우리를 포함하지 않음을 확인하려면 첫 x좌표의 끝보다 다음 요소의 x시작 좌표가 더 크면 첫 봉우리가 포함하지 않음을 알 수 있음.


아래는 풀면서 쓴 풀이
봉우리? 시작점과 끝 점이 x축 상에 있는 곡선 부분과 x축으로 둘러싸인 영역을 말한다. 즉, 어떤 선의 x축에 접하는 양 점을 확인하면 됨.
문제 그림에 있는 봉우리의 개수
1개 3개(1개가 각 2개를 둘러싸고 있음) 1개
이때 다른 봉우리에 의해 포함되지 않는 봉우리 개수와 다른 봉우리를 포함하지 않는 봉우리 개수를 구해야 한다.
그림에선 각각 3개, 4개다. 

좌표 및 봉우리를 구하는 과정
좌표는 x좌표가 같은 2개의 경우를 짝짓고, 만약 두 y값의 부호가 다르면 x를 기록, 다르지 않으면 기록하지 않도록 한다.

여기서 중요한 건 처음들어오는 x좌표와 두번째들어오는 x좌표를 짝지어줘야 한다. 이유는 그것이 하나의 봉우리로 완성되기 때문.

다른 봉우리에 의해 포함되지 않는 봉우리 개수(1)와 다른 봉우리를 포함하지 않는 봉우리 개수(2)?
두 개의 스택을 만들어서 따로 구한다.

(1) xa1<xb1, xb2>xa2인 경우 a2는 다른 봉우리에 의해 포함되지 않는 경우이다.

(2) xa1<xb1, xb2>xa2를 만족하는 b가 없다면 a는 다른 봉우리를 포함하지 않는 경우이다.

(1)을 구하는 법
(xa1,xa2)가 스택에 저장되어있다고 할 때, top.second < xb1인 경우 포함되어있지 않다고 볼 수 있다.
이때 스택에 삽입한다.
만약 top.second > xb1인 경우는 포함된다는 뜻으로 볼 수 있다. 이 때는 삽입하지 않음.
요약: xa2의 좌표보다 xb1의 좌표가 크면 스택에 삽입하고 아니면 삽입하지 아니하면 된다. 스택에 남은 개수가 (1)의 개수이다.

(2)를 구하는 법
(xa1,xa2)가 스택에 저장되어있다고 할 때, top.second < xb1인 경우 다음의 모든 요소는 xa2보다 항상 큰 좌표이므로 xa2를 남기고 xb를 삽입한다.
만약 top.second > xb1인 경우 xa가 xb를 포함하는 경우이므로 xa를 제거한다.
요약: xa안에 다른 xb가 없는 요소만 스택에 남게 된다.

시작점이 x축 아래고, 다음 주어진 좌표의 x좌표가 다를 경우 처음 입력된 좌표를 뒤로
시작점이 x축 위고, 다음 주어진 좌표의 x좌표가 다를 경우 마지막에 입력된 좌표를 앞으로
***다음 주어진 x좌표가 같아도 결정 필요
*/