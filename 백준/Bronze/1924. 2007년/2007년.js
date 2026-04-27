const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [x, y] = input[0].split(" ").map(Number);
const date = new Date(`2007-${x}-${y}`);
const day = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
console.log(day[date.getDay()]);
