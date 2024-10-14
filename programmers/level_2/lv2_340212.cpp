/**
 * 문제 : 퍼즐 게임 챌린지
 * 링크 : https://school.programmers.co.kr/learn/courses/30/lessons/340212
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit)
{
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());
    int level = right;

    while (left <= right)
    {
        int prev_time = times[0];
        long long acc_time = times[0];

        int mid = (left + right) / 2;
        for (int i = 1; i < diffs.size() && acc_time <= limit; i++)
        {
            if (mid >= diffs[i])
            {
                acc_time += times[i];
            }
            else
            {
                acc_time += (diffs[i] - mid) * (prev_time + times[i]) + times[i];
            }
            prev_time = times[i];
        }

        if (acc_time <= limit)
        {
            level = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return level;
}