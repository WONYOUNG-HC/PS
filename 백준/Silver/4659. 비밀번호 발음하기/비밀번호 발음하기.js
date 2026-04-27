const filePath = process.platform === "linux" ? "/dev/stdin" : "input.txt";
const input = require("fs").readFileSync(filePath).toString().split("\n");

const vowel = ["a", "e", "i", "o", "u"];

while (true) {
  const str = input.shift();

  if (str === "end") {
    break;
  }

  let c = 0;
  let v = 0;
  let flag = false;
  for (let i = 0; i < str.length; i++) {
    if (vowel.includes(str[i])) {
      flag = true;
      c = 0;
      v += 1;
    } else {
      v = 0;
      c += 1;
    }

    if (c >= 3 || v >= 3) {
      flag = false;
      break;
    }

    if (i > 0 && str[i] === str[i - 1] && str[i] !== "e" && str[i] !== "o") {
      flag = false;
      break;
    }
  }

  const accept = flag ? "acceptable" : "not acceptable";
  console.log(`<${str}> is ${accept}.`);
}
