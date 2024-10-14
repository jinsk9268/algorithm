/**
 * 문제 : 데이터 분석
 * 링크 : https://school.programmers.co.kr/learn/courses/30/lessons/250121
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int get_index(const string &key)
{
    static unordered_map<string, int> mapping = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};

    return mapping[key];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
    vector<vector<int>> answer;

    int ext_index = get_index(ext);
    int sort_index = get_index(sort_by);

    for (auto &item : data)
    {
        if (item[ext_index] < val_ext)
        {
            answer.push_back(item);
        }
    }

    sort(answer.begin(), answer.end(),
         [&](vector<int> &i, vector<int> &j) -> bool { return i[sort_index] < j[sort_index]; });

    return answer;
}