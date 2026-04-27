const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [n, g] = input[0].split(" ");
const s = new Set();
for (let i = 1; i <= Number(n); i++) {
  const str = input[i];
  s.add(str);
}

let ans = 0;
if (g == "Y") {
  ans = s.size;
} else if (g == "F") {
  ans = s.size / 2;
} else {
  ans = s.size / 3;
}
console.log(parseInt(ans));
