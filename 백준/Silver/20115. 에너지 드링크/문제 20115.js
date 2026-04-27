const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const n = Number(input[0]);
const arr = input[1].split(" ").map(Number);
arr.sort((l, r) => l - r);
for (let i = 0; i < n - 1; i++) {
  arr[n - 1] += arr[i] / 2;
}

console.log(arr[n - 1].toFixed(5));
