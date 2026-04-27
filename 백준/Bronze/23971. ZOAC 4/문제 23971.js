const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [h, w, n, m] = input[0].split(" ").map(Number);
console.log(Math.ceil(h / (n + 1)) * Math.ceil(w / (m + 1)));
