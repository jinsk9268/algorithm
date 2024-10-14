/**
 * 충돌위험 찾기 - vector 사용
 * https://school.programmers.co.kr/learn/courses/30/lessons/340211
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int encode_coord(int r, int c)
{
    return r * 100 + c;
}

int find_duplicates(vector<int> &count)
{
    if (count.size() <= 1)
    {
        return 0;
    }

    int duplicates = 0;
    vector<int> check(100 * 100 + 101, 0);

    for (auto &coord : count)
    {
        check[coord]++;
    }

    for (auto &data : check)
    {
        if (data > 1)
        {
            duplicates++;
        }
    }

    return duplicates;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int answer = 0;
    int m = routes[0].size();

    unordered_map<int, vector<int>> count;
    for (const auto &path : routes)
    {
        int sec = 0;

        for (int i = 0; i < m - 1; i++)
        {
            vector<int> from = points[path[i] - 1];
            vector<int> to = points[path[i + 1] - 1];

            int r_dir = from[0] < to[0] ? 1 : -1;
            int c_dir = from[1] < to[1] ? 1 : -1;

            for (int r = from[0]; r != to[0]; r += r_dir)
            {
                count[sec++].push_back(encode_coord(r, from[1]));
            }

            for (int c = from[1]; c != to[1]; c += c_dir)
            {
                count[sec++].push_back(encode_coord(to[0], c));
            }

            if (i + 1 == m - 1)
            {
                count[sec].push_back(encode_coord(to[0], to[1]));
            }
        }
    }

    for (auto &data : count)
    {
        answer += find_duplicates(data.second);
    }

    return answer;
}