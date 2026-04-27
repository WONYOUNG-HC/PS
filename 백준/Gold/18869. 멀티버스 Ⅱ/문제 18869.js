const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const [m, n] = input[0].split(" ").map(Number);
const arr = [];
for (let i = 1; i <= m; i++) {
  arr.push(input[i].split(" ").map(Number));
}

function bs(arr, target) {
  let l = 0,
    r = n - 1;
  while (l <= r) {
    const mid = parseInt((l + r) / 2);
    if (arr[mid] === target) {
      return mid;
    } else if (arr[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return -1;
}

const cp = [];
arr.forEach((x) => {
  const sa = [...new Set([...x].sort((l, r) => l - r))];
  const na = [];
  x.forEach((y) => {
    na.push(bs(sa, y));
  });
  cp.push(na);
});

cp.sort((l, r) => {
  if (l.length !== r.length) {
    return l.length - r.length;
  }

  for (let i = 0; i < l.length; i++) {
    if (l[i] !== r[i]) {
      return l[i] - r[i];
    }
  }

  return 0;
});

let l = 0,
  r = 1,
  ans = 0;
while (r < m) {
  if (cp[l].length !== cp[r].length) {
    ans += ((r - l) * (r - l - 1)) / 2;
    l = r;
    r += 1;
    continue;
  }

  let flag = true;
  for (let i = 0; i < cp[l].length; i++) {
    if (cp[l][i] !== cp[r][i]) {
      flag = false;
      break;
    }
  }

  if (flag) {
    r += 1;
  } else {
    ans += ((r - l) * (r - l - 1)) / 2;
    l = r;
    r += 1;
  }
}

ans += ((r - l) * (r - l - 1)) / 2;
console.log(ans);
