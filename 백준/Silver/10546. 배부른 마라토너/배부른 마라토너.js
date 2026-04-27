const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const n = parseInt(input[0]);
const m = new Map();
for (let i = 1; i <= n; i++) {
  m.set(input[i], m.get(input[i]) + 1 || 1);
}

for (let i = n + 1; i < input.length; i++) {
  m.set(input[i], m.get(input[i]) - 1);
}

m.forEach((value, key) => {
  if (value > 0) {
    console.log(key);
  }
});
