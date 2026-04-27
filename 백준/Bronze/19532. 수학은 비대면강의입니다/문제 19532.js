const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const coef = input[0].split(" ").map(Number);
const f1 = (x, y) => coef[0] * x + coef[1] * y === coef[2];
const f2 = (x, y) => coef[3] * x + coef[4] * y === coef[5];

for (let x = -999; x <= 999; x++) {
  for (let y = -999; y <= 999; y++) {
    if (f1(x, y) && f2(x, y)) {
      console.log(x, y);
      process.exit(0);
    }
  }
}