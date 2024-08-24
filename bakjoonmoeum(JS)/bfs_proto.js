const filePath = process.platform === "linux" ? "/dev/stdin" : "io/input.txt"
const input = require("fs").readFileSync(filePath).toString().trim()
.split("\n")

const [R, C] = input.shift().split(' ').map(Number)
const map = input.map((el) => el.split(''))

const dx = [-1, 0, 1, 0]
const dy = [0, 1, 0, -1]

let [Q, lQ] = [[],[]]
let water = new Array(R).fill().map(() => new Array(C).fill(-1))
let visited = new Array(R).fill().map(() => new Array(C).fill(-1))

let st = []

for(let i=0;i<R;i++){
    for(let j=0;j<C;j++){
        
    }
}

Q.push(st)
visited[st[1]][st[0]] = 0

while(Q.length + lQ.length){
    if(!Q.length) while(lQ.length) Q.push(lQ.pop())//스택 2개로 큐를 만들어 버리다니...
    let [x, y] = Q.pop();

    if(map[y][x] == 'D'){
        console.log(visited[y][x])
        return 0;
    }
    
    for(let i = 0;i<4;i++){
        let [nx,ny] = [x + dx[i], y + dy[i]]

        if(nx < 0 || ny < 0 || nx >= C || ny >= R || map[ny][nx] == 'X') continue;

        if(visited[ny][nx] == -1 && (water[ny][nx] == -1 || water[ny][nx] > visited[y][x] + 1)){
            visited[ny][nx] = visited[y][x] + 1;
            lQ.push([nx,ny])
        }
    }
}//console.log(visited)


/*

*/