const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const tc = parseInt(input[0]);
for (let i = 1; i <= tc; i++) {
  const [a, b] = input[i].split(" ").map((n) => parseInt(n));
  let ans = 0;
  for (let i = a; i <= b; i++) {
    i.toString()
      .split("")
      .forEach((n) => {
        n === "0" && ans++;
      });
  }
  console.log(ans);
}
