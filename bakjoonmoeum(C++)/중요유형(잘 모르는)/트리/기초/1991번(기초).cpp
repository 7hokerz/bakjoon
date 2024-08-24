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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define mod 1'000'000'007
//int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};
int N, M;
char parent, leftn, rightn;

vector <pair<char,char>> gr[27];//left, right

void inorder(char root){
    if(!gr[root - 'A'].empty()){
        char left = gr[root - 'A'][0].first;
        char right = gr[root - 'A'][0].second;

        if(left != '.'){
            inorder(gr[root - 'A'][0].first);
        }
        cout << root;
        if(right != '.'){
            inorder(gr[root - 'A'][0].second);
        }    
    }
}

void preorder(char root){
    if(!gr[root - 'A'].empty()){
        char left = gr[root - 'A'][0].first;
        char right = gr[root - 'A'][0].second;

        cout << root;
        if(left != '.'){
            preorder(gr[root - 'A'][0].first);
        }
        if(right != '.'){
            preorder(gr[root - 'A'][0].second);
        }  
    }
}

void postorder(char root){
    if(!gr[root - 'A'].empty()){
        char left = gr[root - 'A'][0].first;
        char right = gr[root - 'A'][0].second;

        if(left != '.'){
            postorder(gr[root - 'A'][0].first);
        }
        if(right != '.'){
            postorder(gr[root - 'A'][0].second);
        } 
        cout << root;
    }
}

int main() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> parent >> leftn >> rightn;
        gr[parent - 'A'].push_back({leftn, rightn});
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A'); cout << '\n';
}
/*


*/ 