const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [n, m] = input[0].split(" ").map(Number);
const arr = [];
for (let i = 1; i <= m; i++) {
  arr.push(Number(input[i]));
}

let ans = [0, 0];
arr.forEach((x) => {
  const sales = Math.min(arr.filter((y) => y >= x).length, n) * x;
  if (ans[1] < sales) {
    ans = [x, sales];
  }
});

console.log(...ans);
