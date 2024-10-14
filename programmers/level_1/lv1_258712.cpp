/**
 * 문제 : 가장 많이 받은 선물
 * 링크 : https://school.programmers.co.kr/learn/courses/30/lessons/258712
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

pair<string, string> parse_gift(string name)
{
    int split_idx = name.find(" ");

    return {name.substr(0, split_idx), name.substr(split_idx + 1)};
}

int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;

    unordered_map<string, int> gift_index;
    unordered_map<string, unordered_map<string, int>> record;
    for (string &sender : friends)
    {
        for (string &receiver : friends)
        {
            record[sender][receiver] = 0;
        }
    }

    for (string &name : gifts)
    {
        auto [sender, receiver] = parse_gift(name);

        record[sender][receiver]++;
        gift_index[sender]++;
        gift_index[receiver]--;
    }

    for (auto &sender : record)
    {
        int received_gifts = 0;

        for (auto &receiver : sender.second)
        {
            int receiver_to_sender = record[receiver.first][sender.first];

            bool more_send = receiver.second > receiver_to_sender;
            bool bigger_gift_index =
                receiver.second == receiver_to_sender && gift_index[sender.first] > gift_index[receiver.first];

            if (more_send || bigger_gift_index)
            {
                received_gifts++;
            }
        }

        answer = max(answer, received_gifts);
    }

    return answer;
}