const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString();
let [a, b] = input.split("\n");
b = parseInt(b);
let [h, m] = a.split(" ").map((t) => parseInt(t));
let end = (h * 60 + m + b) % (60 * 24);
console.log(parseInt(end / 60), end % 60);
