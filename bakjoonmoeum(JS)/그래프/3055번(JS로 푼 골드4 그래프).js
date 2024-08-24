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
        if(map[i][j] == 'S'){
            st = [j, i]
        }
        else if(map[i][j] == '*'){
            Q.push([j,i])
            water[i][j] = 0
        }
    }
}

while(Q.length + lQ.length){//fillwater
    if(!Q.length) while(lQ.length) Q.push(lQ.pop())
    let [x, y] = Q.pop();
    
    for(let i = 0;i<4;i++){
        let [nx,ny] = [x + dx[i], y + dy[i]]

        if(nx < 0 || ny < 0 || nx >= C || ny >= R || map[ny][nx] == 'X' || map[ny][nx] == 'D') continue;

        if(water[ny][nx] == -1){
            water[ny][nx] = water[y][x] + 1;
            lQ.push([nx,ny])
        }
    }
}//console.log(water)

Q.push(st)
visited[st[1]][st[0]] = 0

while(Q.length + lQ.length){//고슴도치
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
console.log("KAKTUS")
/*
첫 번째로 물이 차오르는 각각의 최단 시간을 좌표에 모두 기록하고
두 번째로 고슴도치 BFS를 돌려 물의 최단 시간과 비교하면서 진행한다.
BFS를 2번 돌리면 끝

실제로 두 BFS를 동시에 진행하면서 맵을 변경하면서 *를 퍼뜨리는 게 아니라 카운트만 기록하면 된다는 것이 포인트
*/