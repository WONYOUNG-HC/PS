const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

n = Number(input[0]);
arr = input[1].split(" ").map(Number);
dp = new Array(n).fill(1);

for (let i = 1; i < n; i++) {
  for (let j = 0; j < i; j++) {
    if (arr[i] < arr[j]) {
      dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }
}

console.log(n - Math.max(...dp));
