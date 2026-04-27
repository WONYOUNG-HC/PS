const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().trim();
const arr = input.split(" ").map((i) => parseInt(i));
arr.sort((a, b) => a - b);
console.log(...arr);
