#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

class Answer
{
public:
    int findMaxLen(vector<int> &nums)
    {
        int ret = 0;
        int num = nums.size();
        int sum = 0;
        map<int, int> m;
        m[0] = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 1 ? 1 : -1;

            if (m.count(sum))
            {
                ret = max(ret, i - m[sum]);
            }
            else
            {
                m[sum] = i;
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> v = {0, 0, 0, 1, 1, 1, 1, 0};
    Answer ob;
    cout << (ob.findMaxLen(v));

    return 0;
}