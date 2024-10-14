/*
문제 : 지폐 접기
링크 : https://school.programmers.co.kr/learn/courses/30/lessons/340199
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill)
{
    int answer = 0;

    auto need_folding = [&]() -> bool {
        return min(bill[0], bill[1]) > min(wallet[0], wallet[1]) || max(bill[0], bill[1]) > max(wallet[0], wallet[1]);
    };

    while (need_folding())
    {
        if (bill[0] > bill[1])
        {
            bill[0] /= 2;
        }
        else
        {
            bill[1] /= 2;
        }

        answer += 1;
    }

    return answer;
}