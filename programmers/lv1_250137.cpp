/*
문제 : 붕대 감기
링크 : https://school.programmers.co.kr/learn/courses/30/lessons/250137
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int cur_health = health;

    int cur_time = 1;
    for (int i = 0; i < attacks.size(); i++)
    {
        int duration = attacks[i][0] - cur_time;
        cur_health += duration * bandage[1];

        int full_wraps = duration / bandage[0];
        if (full_wraps)
        {
            cur_health += full_wraps * bandage[2];
        }

        if (cur_health > health)
        {
            cur_health = health;
        }

        if ((cur_health -= attacks[i][1]) <= 0)
        {
            return -1;
        }

        cur_time = attacks[i][0] + 1;
    }

    return cur_health;
}