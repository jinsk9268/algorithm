/**
 * 문제 : 이웃한 칸
 * 링크 : https://school.programmers.co.kr/learn/courses/30/lessons/250125
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w)
{
    int answer = 0;

    string color = board[h][w];
    vector<int> direction = {-1, 1};
    for (int i : direction)
    {

        if ((h + i >= 0 && h + i < board.size()) && board[h + i][w] == color)
        {
            answer += 1;
        }

        if ((w + i >= 0 && w + i < board[0].size()) && board[h][w + i] == color)
        {
            answer += 1;
        }
    }

    return answer;
}