#include <iostream>
#include <vector>

int maxChunksTobeSorted(const std::vector<int> &arr)
{
    int n = arr.size();
    int maxValue = 0;
    int chunks = 0;

    for (int i = 0; i < n; ++i)
    {
        maxValue = std::max(maxValue, arr[i]);
        if (i == maxValue)
        {
            chunks++;
        }
    }

    return chunks;
}

int main()
{

    int n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int ans = maxChunksTobeSorted(arr);

    std::cout << ans << std::endl;

    return 0;
}