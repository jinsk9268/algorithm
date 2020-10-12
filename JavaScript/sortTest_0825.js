// 프로그래머스 문제
function solution(array, commands) {
  let answer = [];
  for (let i = 0; i < commands.length; i++) {
    let addArr = array.slice(commands[i][0] - 1, commands[i][1]);
    addArr.sort((a, b) => a - b);
    answer.push(addArr[commands[i][2] - 1]);
  }
  return answer;
}

console.log(
  solution(
    [1, 5, 2, 6, 3, 7, 4],
    [
      [2, 5, 3],
      [4, 4, 1],
      [1, 7, 3]
    ]
  )
);

// arrow function
const solutionArrow = (array, commands) => {
  return commands.map(command => {
    const [startIndex, endIndex, returnIndex] = command;
    const resultArray = array
      .filter(
        (value, index) => index >= startIndex - 1 && index <= endIndex - 1
      )
      .sort((a, b) => a - b);

    return resultArray[returnIndex - 1];
  });
};

console.log(
  solutionArrow(
    [1, 5, 2, 6, 3, 7, 4],
    [
      [2, 5, 3],
      [4, 4, 1],
      [1, 7, 3]
    ]
  )
);
