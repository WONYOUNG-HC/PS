const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

let ans = 0;
for (let i = 1; i <= Number(input[0]); i++) {
  const [a, b] = input[i].split(" ").map(Number);
  ans += a * b;
}
console.log(ans);
