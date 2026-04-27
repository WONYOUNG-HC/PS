const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const n = Number(input[0]);
const arr = new Array(3000000).fill(-1);
let front = 1500000,
  rear = 1500000,
  empty = true;

const res = [];
for (let i = 1; i <= n; i++) {
  const c = input[i].split(" ").map(Number);

  if (c[0] === 1) {
    empty ? (empty = false) : (front -= 1);
    arr[front] = c[1];
  } else if (c[0] === 2) {
    empty ? (empty = false) : (rear += 1);
    arr[rear] = c[1];
  } else if (c[0] === 3) {
    res.push(empty ? -1 : arr[front]);
    !empty && (front === rear ? (empty = true) : (front += 1));
  } else if (c[0] === 4) {
    res.push(empty ? -1 : arr[rear]);
    !empty && (front === rear ? (empty = true) : (rear -= 1));
  } else if (c[0] === 5) {
    const e = empty ? 0 : 1;
    res.push(rear - front + e);
  } else if (c[0] === 6) {
    res.push(empty ? 1 : 0);
  } else if (c[0] === 7) {
    res.push(empty ? -1 : arr[front]);
  } else if (c[0] === 8) {
    res.push(empty ? -1 : arr[rear]);
  }
}

console.log(res.join("\n"));
