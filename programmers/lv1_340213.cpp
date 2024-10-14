/*
문제 : 동영상 재생기
링크 : https://school.programmers.co.kr/learn/courses/30/lessons/340213
*/

#include <string>
#include <vector>

using namespace std;

int time_to_sec(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

int get_pos(int start, int end, int pos)
{
    if (start <= pos && pos <= end)
    {
        return end;
    }

    return pos;
}

string sec_str(int sec)
{
    if (sec == 0)
    {
        return "00";
    }
    else if (sec < 10)
    {
        return "0" + to_string(sec);
    }
    else
    {
        return to_string(sec);
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    int video_sec = time_to_sec(video_len);
    int op_start_sec = time_to_sec(op_start);
    int op_end_sec = time_to_sec(op_end);
    int pos_sec = get_pos(op_start_sec, op_end_sec, time_to_sec(pos));

    for (string &c : commands)
    {
        if (c == "prev")
        {
            pos_sec -= 10;

            if (pos_sec < 10)
            {
                pos_sec = 0;
            }
        }
        else
        {
            pos_sec += 10;

            if (video_sec - pos_sec < 10)
            {
                pos_sec = video_sec;
            }
        }

        pos_sec = get_pos(op_start_sec, op_end_sec, pos_sec);
    }

    return sec_str(pos_sec / 60) + ":" + sec_str(pos_sec % 60);
}