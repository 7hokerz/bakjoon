const filePath = process.platform === "linux" ? "/dev/stdin" : "io/input.txt"
const input = require("fs").readFileSync(filePath).toString().trim().split(" ");

let x = input[0]
let y = input[1]
let w = input[2]
let h = input[3]

let can = [x, y, w - x, h - y]

console.log(Math.min.apply(null, can))