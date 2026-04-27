const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
let input = require("fs").readFileSync(filePath).toString().split(" ");
[a, b] = input.map((i) => parseInt(i));
console.log(Math.abs(a - b));
