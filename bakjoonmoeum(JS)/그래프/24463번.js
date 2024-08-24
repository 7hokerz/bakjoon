const filePath = process.platform === "linux" ? "/dev/stdin" : "io/input.txt"
const input = require("fs").readFileSync(filePath).toString().trim()
.split("\n")

const [N, M] = input.shift().split(' ').map(Number)
let map = input.map((el) => el.split(''))

const dx = [-1, 0, 1, 0]
const dy = [0, 1, 0, -1]

let visited = new Array(N).fill().map(() => new Array(M).fill(0))

let [st,en] = [[],[]]

for(let i=0;i<N;i++){
    for(let j=0;j<M;j++){
        if(i == 0 || j == 0 || i == N - 1 || j == M - 1){
            if(map[i][j] == '.' && !st.length) st = [j,i]
            else if(map[i][j] == '.' && !en.length) en = [j,i]
        }
    }
}

visited[st[1]][st[0]] = 1
dfs(st[0], st[1])

function dfs(x,y){ //console.log(y, x)
    if(x == en[0] && y == en[1]) return true;
    
    let chk = 0

    for(let i = 0;i<4;i++){
        let [nx, ny] = [x + dx[i], y + dy[i]]
        
        if(nx < 0 || ny < 0 || nx >= M || ny >= N || map[ny][nx] == '+') continue;

        if(!visited[ny][nx]){
            visited[ny][nx] = 1
            if(!dfs(nx,ny)) map[ny][nx] = '@'
            else chk = 1
        }
    }
    if(chk) return true
    else return false;
}

for(let i=0;i<N;i++)
    for(let j=0;j<M;j++)
        if(!visited[i][j] && map[i][j] == '.') map[i][j] = '@'
        
//console.log(map)
map.forEach((y) => {console.log(y.join(''))})
/*

*/