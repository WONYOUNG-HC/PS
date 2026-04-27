const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const arr = input[1].split(" ").map(Number);
const sum = arr.reduce((a, c) => (a += c), 0);
console.log(sum - Math.max(...arr));
