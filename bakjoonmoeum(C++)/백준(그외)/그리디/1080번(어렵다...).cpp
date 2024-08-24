#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, count = 0;
    cin >> N >> M;
    int A[N][M];
    int B[N][M];
    char tmp[M];
    for(int i = 0;i<N;i++){
        cin >> tmp;
        for(int j = 0;j<M;j++){
            A[i][j] = tmp[j] - '0';
        }
    }
    for(int i = 0;i<N;i++){
        cin >> tmp;
        for(int j = 0;j<M;j++){
            B[i][j] = tmp[j] - '0';
        }
    }

    for(int i = 0;i<N-2;i++){
        for(int j = 0;j<M-2;j++){
            if(A[i][j] != B[i][j]){
                for(int k = i;k<i+3;k++){
                    for(int h = j;h<j+3;h++){
                        if(A[k][h] == 0) A[k][h] = 1;
                        else A[k][h] = 0;
                    }
                }
                count++;
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(A[i][j] != B[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << count;
}   
/*
이걸 어떻게 풀지 참 감이 안와서 결국 다른 사람 질문을 보다가 풀었다.

쉽게 말해 3*3 부분 행렬을 한 칸씩 +1 해나가면서 만약 
A에서 해당 부분행렬의(0,0)이 B와 다르면 교체하고 아니면 건너뛴다.
그 후 행렬을 검사하여 동일하면 카운트 출력, 아니면 -1을 출력한다.

다른 사람의 답변:

동일한 부분행렬이 2회 뒤집히면 
안 뒤집힌 것과 다르지 않아 뒤집는 의미가 없어서 그렇습니다.

부분행렬은 시작점 (i,j)를 정하고 해당 영역부터 3x3을 보면 됩니다. 
동일한 시작점을 갖는 부분행렬을 2회 이상 뒤집지 않으면서 A=B를 
달성하려면, 모든 가능한 시작점 쌍에 대해서 0회 혹은 1회 뒤집어져야 
하는지만 살펴보면 됩니다. 단, 1번이라도 살펴보지 않으면 A=B를 
달성할 수 없기에 적어도 각 부분행렬을 1번은 살펴봐야합니다.

따라서, 모든 부분행렬(모든 i,j)조합을 1회 살펴보는 것이 최소값이 됩니다.
*/