const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const n = Number(input[0]);
const m = Number(input[1]);
const arr = input[2]
  .split(" ")
  .map(Number)
  .sort((l, r) => l - r);

let l = 0,
  r = n - 1,
  sum = arr.at(0) + arr.at(-1),
  cnt = 0;

while (l < r) {
  if (sum < m) {
    sum = sum - arr[l] + arr[++l];
  } else if (sum > m) {
    sum = sum - arr[r] + arr[--r];
  } else {
    cnt += 1;
    sum = sum - arr[l] - arr[r];
    sum = sum + arr[++l] + arr[--r];
  }
}

console.log(cnt);
