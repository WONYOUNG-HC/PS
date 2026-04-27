const filePath = process.platform === "linux" ? "/dev/stdin" : "JS/input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [l, p] = input[0].split(" ").map(Number);
input[1].split(" ").map((i) => console.log(Number(i) - l * p));
