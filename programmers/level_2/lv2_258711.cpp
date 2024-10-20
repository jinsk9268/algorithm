/**
 * 문제: 도넛과 막대 그래프
 * https://school.programmers.co.kr/learn/courses/30/lessons/258711
 */

#include <iostream>
#include <vector>

using namespace std;

int graph_type(const vector<vector<int>> &out_vertices, int v)
{
    int start = v;
    while (true)
    {
        if (out_vertices[v].empty())
        {
            return 2;
        }

        if (out_vertices[v].size() > 1)
        {
            return 3;
        }

        if (out_vertices[v][0] == start)
        {
            return 1;
        }

        v = out_vertices[v][0];
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4, 0);

    int max_size = 0;
    for (auto &edge : edges)
    {
        max_size = max(max_size, max(edge[0], edge[1]));
    }

    vector<vector<int>> out_vertices(max_size + 1, vector<int>());
    vector<int> in_count(max_size + 1, 0);

    int graph_num = 0;
    for (auto &edge : edges)
    {
        out_vertices[edge[0]].push_back(edge[1]);
        in_count[edge[1]]++;

        if (out_vertices[edge[0]].size() >= graph_num && in_count[edge[0]] == 0)
        {
            graph_num = out_vertices[edge[0]].size();
            answer[0] = edge[0];
        }
    }

    for (int v : out_vertices[answer[0]])
    {
        int type = graph_type(out_vertices, v);
        answer[type]++;
    }

    return answer;
}