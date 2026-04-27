const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const [n, m] = input[0].split(" ").map(Number);

const arr = Array.from({ length: 1010 }, () => []);
for (let i = 1; i < n; i++) {
  const [a, b, c] = input[i].split(" ").map(Number);
  arr[a].push([b, c]);
  arr[b].push([a, c]);
}

for (let i = n; i < n + m; i++) {
  const [a, b] = input[i].split(" ").map(Number);

  const vis = Array.from({ length: 1010 }, () => false);
  const q = [[a, 0]];

  while (q.length !== 0) {
    const [cur, dist] = q.shift();

    if (cur === b) {
      console.log(dist);
      break;
    }

    if (vis[cur]) {
      continue;
    }
    vis[cur] = true;

    for (const next of arr[cur]) {
      if (vis[next[0]]) {
        continue;
      }

      q.push([next[0], dist + next[1]]);
    }
  }
}
