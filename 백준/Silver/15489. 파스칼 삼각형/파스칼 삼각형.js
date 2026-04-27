const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [r, c, w] = input[0].split(" ").map(Number);
const arr = Array.from(Array(r + w), () => Array(r + w).fill(0));

arr[1][1] = 1;
for (let i = 2; i < r + w; i++) {
  arr[i][1] = 1;
  for (let j = 2; j <= i; j++) {
    arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
  }
}

let ans = 0;
for (let i = r; i < r + w; i++) {
  for (let j = c; j <= c + i - r; j++) {
    ans += arr[i][j];
  }
}

console.log(ans);
