#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue <pair<int, char>> q;//방향정보
    deque <pair<int, int>> dq;//꼬리정보
    int N, K, L, x, r;
    char c;
    int pos = 1, time = 0, length = 1;
    int rhead = 0, chead = 0, rtail = 0, ctail = 0;
    cin >> N >> K;
    int board[N][N];
    
    for(int i = 0;i<N;i++){//판 만들기
        for(int j = 0;j<N;j++){
            board[i][j] = 0;
        }
    }

    board[0][0] = 1;//뱀의 시작 위치
    for(int i = 0;i<K;i++){//사과가 있는 곳
        cin >> r >> c;
        board[r][c] = 2;
    }

    cin >> L;
    for(int i = 0;i<L;i++){//방향 변환 정보
        cin >> x >> c;
        q.push({x, c});
    }

    dq.push_back({rhead, chead});
    while(1){
        if(q.front().first == time){//방향 설정
            if(q.front().second == 'L'){//왼90
                pos = (pos+3)%4;
            }else{//오90
                pos = (pos+1)%4;
            }
        }
        

        switch (pos){//뱀의 진행 정보 갱신(머리)
            case 1:
            if(chead+1>=N) break;//배열범위를 넘으면
            if(board[rhead][chead+1] == 2){//사과를 발견하면
                length++;
                dq.push_back({rtail, ctail});
            }
            else if(board[rhead][chead+1] == 1){cout << time; return 0;}//뱀이 뱀끼리 충돌하면
            else{
                dq.push_back({rtail, ctail+1});
            }
            board[rhead][++chead] = 1;//머리부분 1로 채우기
            ctail++;
            break;
            case 2:
            if(rhead+1>=N) break;
            if(board[rhead+1][chead] == 2){
                length++;
                dq.push_back({rtail, ctail});
            }
            else if(board[rhead+1][chead] == 1){cout << time; return 0;}
            else{
                dq.push_back({rtail+1, ctail});
            }
            board[++rhead][chead] = 1;
            rtail++;
            break;
            case 3:
            if(chead-1 < 0) break;
            if(board[rhead][chead-1] == 2){
                length++;
                dq.push_back({rtail, ctail});
            }else if(board[rhead][chead-1] == 1){cout << time; return 0;}
            else{
                dq.push_back({rtail, ctail-1});
            }
            board[rhead][--chead] = 1;
            --ctail;
            break;
            case 0:
            if(rhead-1 < 0) break;
            else if(board[rhead-1][chead] == 2){
                length++;
                dq.push_back({rtail, ctail});
            }else if(board[rhead-1][chead] == 1){cout << time; return 0;}
            else{
                dq.push_back({rtail-1, ctail});
            }
            board[--rhead][chead] = 1;
            --rtail;
            break;
        }
        
        if(!dq.empty()){
            board[dq.front().first][dq.front().second] = 0;
            dq.pop_front();//꼬리 지우기
        }
        time++;
    }

}/*
보드판 크기의 배열을 만들고, 아무것도 없는 곳엔 0 사과가 있는 곳엔 2를 넣는다.
뱀을 1이라고 가정한다.

1. 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
2. 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
3. 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
4. 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 
즉, 몸길이는 변하지 않는다.


뱀은 처음에 오른쪽을 향한다.

pos에 따라 전진 방향 설정(1:오른쪽)

움직이면 현재 위치에 1을 채우고 전 위치를 0으로 채운다.

한 칸 이동할 때마다 방향에 따라서 머리값을 ++한 곳에 1을 넣는다.
어차피 머리는 항상 옮겨지기 때문

꼬리는 덱과 연계해서? 사용할 수 있나 생각해보자.

사과를 발견하면 길이를 1늘리고 제거 X


1. 방향 변경이 설정되면 pos값을 변경
2. 뱀의 머리 정보 갱신
2-1. 머리가 배열 범위를 벗어나면 break;
2-2. 사과를 발견하면 길이 증가 및 덱에 꼬리 삽입
2-3. 머리 1로 변경




*/