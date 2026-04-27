const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

for (let i = 0; i < 3; i++) {
  const idx = input[i]
    .split(" ")
    .map(Number)
    .reduce((acc, cur) => (acc += cur));
  console.log(["D", "C", "B", "A", "E"][idx]);
}
