#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

inline int calculatebIdx(int num, int exponent)
{
    return (num / exponent) % 10;
}

void radixSortPass(vector<int> &nums, int exponent)
{
    vector<int> output(nums.size());
    array<int, 10> count = {0};

    for (int i = 0; i < nums.size(); i++)
    {
        int bIdx = calculatebIdx(nums[i], exponent);
        count[bIdx]++;
    }

    // Calculate prefix sums
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int bIdx = calculatebIdx(nums[i], exponent);
        output[count[bIdx] - 1] = nums[i];
        count[bIdx]--;
    }

#pragma omp parallel for
    for (int i = 0; i < nums.size(); i++)
        nums[i] = output[i];
}

void radixSort(vector<int> &nums)
{
    int maximum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        maximum = max(maximum, nums[i]);
    }
    for (int e = 1; maximum / e > 0; e *= 10)
        radixSortPass(nums, e);
}

int main()
{
    vector<int> test = {1, 10, 9680, 577, 9420, 7, 5622, 4793, 2030,
                        3138, 82, 2599, 743};
    radixSort(test);
    return 0;
}