const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [n, k] = input[0].split(" ").map(Number);
const cnt = new Array(100010).fill(0);
const arr = input[1].split(" ").map(Number);

cnt[arr[0]] += 1;
let ans = 1,
  l = 0,
  r = 0;

while (r < n) {
  if (cnt[arr[r]] > k) {
    cnt[arr[l++]] -= 1;
  } else {
    cnt[arr[++r]] += 1;
    ans = Math.max(ans, r - l);
  }
}

console.log(ans);
