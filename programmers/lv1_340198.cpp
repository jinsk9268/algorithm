/*
문제 : 공원
링크 : https://school.programmers.co.kr/learn/courses/30/lessons/340198
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park)
{
    int n = park.size();
    int m = park[0].size();
    int largest_mat = -1;

    sort(mats.begin(), mats.end(), greater<int>());

    auto canMatPlace = [&](int x, int y, int mat_size) -> bool {
        if (x + mat_size > n || y + mat_size > m)
        {
            return false;
        }

        for (int i = 0; i < mat_size; i++)
        {
            for (int j = 0; j < mat_size; j++)
            {
                if (park[x + i][y + j] != "-1")
                {
                    return false;
                }
            }
        }

        return true;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (park[i][j] == "-1")
            {
                for (int k = 0; k < mats.size(); k++)
                {
                    if (canMatPlace(i, j, mats[k]))
                    {
                        largest_mat = max(largest_mat, mats[k]);
                        break;
                    }
                }
            }
        }
    }

    return largest_mat;
}