#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, first = 0, second = 0;
    cin >> N;
    string input;
    char coin[N][N];
    char coin2[N][N];
    for(int i = 0;i<N;i++){
        cin >> input;
        for(int j = 0;j<N;j++){
            coin[i][j] = input[j];
            coin2[i][j] = input[j];
        }
    }

    for(int k = 0;k<1000000;k++){
        for(int i = 0;i<N;i++){
            int countT = 0, countH = 0;
            for(int j = 0;j<N;j++){
                if(coin[i][j] == 'T') countT++;
                else countH++;
            }
            if(countT>=countH){
                for(int j = 0;j<N;j++){
                    if(coin[i][j] == 'T') coin[i][j] = 'H';
                    else coin[i][j] = 'T';
                }
            }
        }
        for(int i = 0;i<N;i++){
            int countT = 0, countH = 0;
            for(int j = 0;j<N;j++){
                if(coin[j][i] == 'T') countT++;
                else countH++;
            }
            if(countT>=countH){
                for(int j = 0;j<N;j++){
                    if(coin[j][i] == 'T') coin[j][i] = 'H';
                    else coin[j][i] = 'T';
                }
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(coin[i][j] == 'T') first++;
        }
    }

    for(int k = 0;k<1000000;k++){
        for(int i = 0;i<N;i++){
            int countT = 0, countH = 0;
            for(int j = 0;j<N;j++){
                if(coin2[j][i] == 'T') countT++;
                else countH++;
            }
            if(countT>=countH){
                for(int j = 0;j<N;j++){
                    if(coin2[j][i] == 'T') coin2[j][i] = 'H';
                    else coin2[j][i] = 'T';
                }
            }
        }
        for(int i = 0;i<N;i++){
            int countT = 0, countH = 0;
            for(int j = 0;j<N;j++){
                if(coin2[i][j] == 'T') countT++;
                else countH++;
            }
            if(countT>=countH){
                for(int j = 0;j<N;j++){
                    if(coin2[i][j] == 'T') coin2[i][j] = 'H';
                    else coin2[i][j] = 'T';
                }
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(coin2[i][j] == 'T') second++;
        }
    }
    
    //cout << first << ' ' << second;
    cout << min(first, second);
}