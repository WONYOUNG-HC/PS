const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './JS/input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const maxNumber = Math.max(...input.slice(1).map(Number));
const dp = new Array(maxNumber + 1).fill(0);

dp[0] = 1;
dp[1] = 1;
dp[2] = 2;

for (let i = 3; i <= maxNumber; i++) {
  dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
}

for (let i = 1; i < input.length; i++) {
  console.log(dp[+input[i]]);
}
