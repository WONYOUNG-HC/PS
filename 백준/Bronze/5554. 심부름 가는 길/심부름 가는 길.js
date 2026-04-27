const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

let t = input.map(Number).reduce((a, b) => (a += b));
console.log(parseInt(t / 60));
console.log(t % 60);
