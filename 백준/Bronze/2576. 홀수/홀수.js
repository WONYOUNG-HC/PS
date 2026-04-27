const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const arr = [];
for (let i = 0; i < 7; i++) {
  Number(input[i]) % 2 == 1 && arr.push(Number(input[i]));
}

console.log(
  arr.length
    ? arr.reduce((a, c) => a + c, 0).toString() +
        "\n" +
        Math.min(...arr).toString()
    : "-1"
);
