#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int S, P, A, C, G, T;
    int res = 0, count = 0;
    string input;
    cin >> S >> P >> input;

    cin >> A >> C >> G >> T;

    for(int i = 0;i<input.length();i++){
        if(input[i] == 'A') A--;
        else if(input[i] == 'C') C--;
        else if(input[i] == 'G') G--;
        else if(input[i] == 'T') T--;
        
        count++;
        if(count == P+1){
            if(input[i-P] == 'A') A++;
            else if(input[i-P] == 'C') C++;
            else if(input[i-P] == 'G') G++;
            else if(input[i-P] == 'T') T++;
            count--;
        }
        if((count == P) && A < 1 && C < 1 && G < 1 && T < 1){
            res++;
        }
    }   
    cout << res;
}
/*
문자열은 모두 A,C,G,T 로만 이루어져있다.

반복문 돌려서 

9 8
CCTGGATTG 0
2 0 1 1

4 2
GATA 2
1 0 0 1

+ 슬라이딩 윈도우가 뭔지 찾아보니 말 그대로더라.
부분 배열 만큼 1칸씩 옆으로 이동하면서 푸는?(이 문제와 같이)

*/