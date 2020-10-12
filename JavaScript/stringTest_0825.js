// 프로그래머스 문제
// 1
const solution1 = n => {
  const firstWord = '수';
  const fullWord = '수박';
  let resultArr1 = [];
  for (let i = 1; i <= n / 2; i++) {
    resultArr1.push(i);
  }
  return n % 2 === 0
    ? resultArr1.map(num => fullWord).join('')
    : resultArr1.map(num => fullWord).join('') + firstWord;
};

console.log(solution1(3));
console.log(solution1(6));

// 2
const solution2 = n => {
  let resultArr2 = [];
  for (let i = 1; i <= n / 2; i++) {
    resultArr2.push(i);
  }
  return resultArr2.map(num => '수박').join('') + (n % 2 === 0 ? '' : '수');
};

console.log(solution2(3));
console.log(solution2(6));

// 3
const solution3 = n => {
  let resultArr3 = [];
  if (n === 1) {
    return '수';
  }
  for (let i = 1; i <= n / 2; i++) {
    resultArr3.push(i);
  }
  return resultArr3.map(num => '수박').join('') + (n % 2 === 0 ? '' : '수');
};

console.log(solution3(3));
console.log(solution3(6));
