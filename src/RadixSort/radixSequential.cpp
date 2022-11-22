#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Grabs the nth least significant digit (starting from right)
// Starts at n == 1
int nthDigit(int x, int n)
{
    if (n < 1)
        return -1;

    for (int i = 1; i < n; i++)
    {
        x /= 10;
    }

    return x % 10;
}

int howManyDigits(int x)
{
    if (x == 0)
        return 1;

    int digits = 0;
    while (x > 0)
    {
        digits++;
        x /= 10;
    }

    return digits;
}

int findMaxDigits(vector<int> &nums)
{
    int maxDigits = 1;
    for (const int &i : nums)
    {
        maxDigits = max(maxDigits, howManyDigits(i));
    }
    return maxDigits;
}

void radixSort(vector<int> &nums)
{
    if (nums.size() <= 1)
        return;
    array<queue<int>, 10> buckets;
    for (int i = 1; i <= findMaxDigits(nums); i++)
    {
        for (int &n : nums)
        {
            int digit = nthDigit(n, i);
            buckets[digit].push(n); // fill the buckets
        }
        nums.clear();
        for (int bIdx = 0; bIdx < 10; bIdx++)
        {
            int initialSize = buckets[bIdx].size();
            for (int j = 0; j < initialSize; j++)
            {
                // Empty buckets back into vector
                nums.push_back(buckets[bIdx].front());
                buckets[bIdx].pop();
            }
        }
    }
    return;
}

int main()
{
    vector<int> test = {1, 10, 9680, 577, 9420, 7, 5622, 4793, 2030,
                        3138, 82, 2599, 743};
    radixSort(test);
    for (const int &c : test)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}