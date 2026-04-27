const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const [n, m] = input[0].split(" ").map(Number);

const a = [];
for (let i = 1; i <= n; i++) {
  a.push(input[i].split(" ").map(Number));
}
const b = [];
for (let i = n + 1; i <= 2 * n; i++) {
  b.push(input[i].split(" ").map(Number));
}

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    const c = a[i][j] + b[i][j];
    process.stdout.write(a[i][j] + b[i][j] + " ");
  }
  console.log();
}
