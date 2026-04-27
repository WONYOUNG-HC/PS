const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const x = Number(input[0]);
const n = Number(input[1]);

y = 0;
for (let i = 2; i < 2 + n; i++) {
  [a, b] = input[i].split(" ").map(Number);
  y += a * b;
}

console.log(x === y ? "Yes" : "No");
