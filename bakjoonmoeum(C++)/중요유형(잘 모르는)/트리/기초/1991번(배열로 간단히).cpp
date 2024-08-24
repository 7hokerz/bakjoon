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
char parent, leftn, rightn, tree[27][2];

void preorder(char root){
    char left = tree[root - 'A'][0];
    char right = tree[root - 'A'][1];

    cout << root;
    if(left != '.') preorder(left);
    if(right != '.') preorder(right);
}

void inorder(char root){
    char left = tree[root - 'A'][0];
    char right = tree[root - 'A'][1];

    if(left != '.') inorder(left);
    cout << root;
    if(right != '.') inorder(right);
}

void postorder(char root){
    
    char left = tree[root - 'A'][0];
    char right = tree[root - 'A'][1];

    if(left != '.') postorder(left);
    if(right != '.') postorder(right);
    cout << root;
}

int main() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> parent >> leftn >> rightn;
        tree[parent - 'A'][0] = leftn;
        tree[parent - 'A'][1] = rightn;
    }

    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A'); cout << '\n';
}
/*


*/ 