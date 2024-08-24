#include <iostream>
#include <stack>
using namespace std;
int N, M, input, map[1001][1001];
#define extent st.top().first//넓이
#define height st.top().second.first//높이
#define index st.top().second.second//인덱스

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        for(int i = 0;i<N;i++)//높이 대입
            for(int j = 0;j<M;j++){
                cin >> input;
                if(input == 1 && i > 0 && map[i-1][j] > 0) map[i][j] = input + map[i-1][j];
                else map[i][j] = input;
            }      
        
        int res = 0;
        for(int i = 0;i<N;i++){
            stack <pair<int,pair<int, int>>> st;//넓이, 높이, 인덱스
            int area = 0;
            for(int j = 0;j<M;j++){
                if(st.empty() || !st.empty() && map[i][j] > height){//
                    st.push({map[i][j],{map[i][j],j}});
                }
                else if(!st.empty() && map[i][j] < height){
                    int idx;//map[i][j]보다 더 작거나 같은 값의 탑 값+1의 인덱스를 기록함(즉 마지막에 지운 map[i][j]보다 큰 값)
                    while(!st.empty() && map[i][j] < height){
                        extent = height*(j - index);//여기는 단순 넓이
                        area = (extent>area)?extent:area;//최대 넓이를 기록하기 위한 area변수
                        idx = index;
                        st.pop();
                    }
                    if(!st.empty() && height == map[i][j]){//같은 높이면 또 스택에 삽입할 필요 없으므로
                        extent = height * (j - index+1);
                    }
                    else if(!st.empty() && height != map[i][j]){//높이가 다르면 새롭게 정보를 기록
                        st.push({map[i][j] * (j-idx+1),{map[i][j],idx}});
                    }
                    else{
                        st.push({map[i][j],{map[i][j],0}});//이전에 없던 새로운 최솟값이 등장한 경우이므로 0부터 시작한다.
                    }
                }
            }
            while(!st.empty()){
                extent = height*(M - index);//마지막 인덱스 - 현재 인덱스를 해야 길이가 나오므로
                area = (extent > area)?extent:area;
                st.pop();
            }
            res = (area>res)?area:res;
        }
        cout << res << '\n';
    }
}

/*   
진짜로 N번 만큼 히스토그램을 반복한다.
다만 그 전에 저 배열을 가지고 떠올리는 게 어려울 수 있음.

내가 쓴 아이디어는 
배열의 값을 받아서 넣는데 그냥 넣지 않고, 
(input == 1 && [i-1]의 값이 0이 아니면) 즉 연속이면 [i-1]의 값 + 1을 넣어주는 거다.
예시:
4 5
0 1 0 1 1
1 1 1 1 1
0 1 1 1 0
1 1 1 1 1
>>
0 1 0 1 1
1 2 1 2 2
0 3 2 3 0
1 4 3 4 1
*/