#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

int doSomething(std::string s)
{
    std::unordered_map<char, int> charMap;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        if (charMap.find(s[right]) != charMap.end())
        {
            left = std::max(left, charMap[s[right]] + 1);
        }
        charMap[s[right]] = right;
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main()
{
    // Exercise-1
    std::string input1 = "pqrsstu";
    std::cout << "Exercise-1 Output: " << doSomething(input1) << std::endl;

    // Exercise-2
    std::string input2 = "abbedfgi";
    std::cout << "Exercise-2 Output: " << doSomething(input2) << std::endl;

    return 0;
}