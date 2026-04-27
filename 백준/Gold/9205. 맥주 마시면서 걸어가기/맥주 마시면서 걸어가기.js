const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
let t = parseInt(input[0]);
let idx = 1;

while (t--) {
  const n = parseInt(input[idx++]);

  const start = input[idx++].split(" ").map(Number);
  const arr = [];
  for (let i = 0; i < n + 1; i++) {
    arr.push(input[idx++].split(" ").map(Number));
  }
  const end = [...arr[n]];

  const vis = new Array(n + 1).fill(false);
  const q = [start];

  while (q.length !== 0) {
    const pos = q.shift();

    if (pos[0] == end[0] && pos[1] == end[1]) {
      break;
    }

    for (let i = 0; i <= n; i++) {
      if (vis[i]) {
        continue;
      }

      const dist = Math.abs(pos[0] - arr[i][0]) + Math.abs(pos[1] - arr[i][1]);
      if (dist > 1000) {
        continue;
      }

      vis[i] = true;
      q.push(arr[i]);
    }
  }

  console.log(vis[n] ? "happy" : "sad");
}
