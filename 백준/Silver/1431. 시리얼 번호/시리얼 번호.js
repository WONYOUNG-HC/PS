const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");
const n = parseInt(input[0]);

const arr = [];
for (let i = 1; i <= n; i++) {
  arr.push(input[i]);
}

arr.sort((left, right) => {
  if (left.length !== right.length) {
    return left.length - right.length;
  }

  let l = 0;
  for (let i = 0; i < left.length; i++) {
    let j = parseInt(left[i]);

    if (!isNaN(j)) {
      l += j;
    }
  }

  let r = 0;
  for (let i = 0; i < right.length; i++) {
    let j = parseInt(right[i]);

    if (!isNaN(j)) {
      r += j;
    }
  }

  if (l !== r) {
    return l - r;
  }

  return left.localeCompare(right);
});

for (let i = 0; i < n; i++) {
  console.log(arr[i]);
}
