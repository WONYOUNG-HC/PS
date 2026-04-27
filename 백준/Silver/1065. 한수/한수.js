const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const n = parseInt(input[0]);

let ans = n < 10 ? n : 9;
for (let i = 10; i <= n; i++) {
  const s = i.toString();
  const dif = s[0] - s[1];
  for (let j = 2; j < s.length; j++) {
    if (s[j - 1] - s[j] != dif) {
      ans -= 1;
      break;
    }
  }
  ans += 1;
}

console.log(ans);
