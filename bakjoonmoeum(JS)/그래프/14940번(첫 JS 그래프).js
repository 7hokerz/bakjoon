const filePath = process.platform === "linux" ? "/dev/stdin" : "io/input.txt"
const input = require("fs").readFileSync(filePath).toString().trim()
.split("\n").map(el => el.split(" ").map(Number));

const [N, M] = input.shift()

const dx = [-1, 0, 1, 0]
const dy = [0, 1, 0, -1]

let [Q, lQ] = [[],[]]//배열 구조 분해 할당?
let visited = new Array(N).fill().map(() => new Array(M).fill(0))
let ans = Array.from(Array(N), () => Array(M).fill(null))

const map = input

for(let i=0;i<N;i++){
    for(let j=0;j<M;j++){
        if(map[i][j] == 2){
            Q.push([j, i])
            visited[i][j] = 1
            ans[i][j] = 0
        }
        else if(map[i][j] == 0) ans[i][j] = 0
        else ans[i][j] = -1
    }
}

while(Q.length + lQ.length){
    if(!Q.length) while(lQ.length) Q.push(lQ.pop())//스택 2개로 큐를 만들어 버리다니...
    let [x, y] = Q.pop();
    
    for(let i = 0;i<4;i++){
        let [nx,ny] = [x + dx[i], y + dy[i]]

        if(nx < 0 || ny < 0 || nx >= M || ny >= N || map[ny][nx] == 0) continue;

        if(!visited[ny][nx]){
            visited[ny][nx] = 1
            ans[ny][nx] = ans[y][x] + 1
            
            lQ.push([nx,ny])
        }
    }
}

ans.forEach((y) => {console.log(y.join(' '))})
//2차원 배열을 출력할 때 사용
/*
JS가 익숙하지 않은 나는 헷갈려 죽겠다. 

여러가지 팁과 조작법에 대해서 익힐 수 있었다.

1. 큐를 shift 사용하지 않고 구현
let [Q, lQ] = [[],[]]
if(!Q.length) while(lQ.length) Q.push(lQ.pop())
실제 시복도는 O(1)은 아니나 O(N)도 아니다. O(1)에 가깝다?고 보면된다.

2. 
변수를 여러 개 선언
let [x, y] 로 선언하고 [j,i]로 넣어주면 된다. 
cnt도 넣고 싶다?
let [x, y, cnt] 이런 식으로 하자.


*/