let input = require("fs").readFileSync("dev/stdin").toString().split("\n");
//let input = require("fs").readFileSync("예제.txt").toString().split("\n");
let n = parseInt(input[0]);
let d = 2;

while (n !== 1) {
  if (n % d === 0) {
    console.log(d);
    n /= d;
  } else {
    d += 1;
  }
}
