#include <vector>
#include <iostream>
#include <cassert>

class Solution
{
public :
    std::vector<int> twoSum(std::vector<int> nums, int target)
    {
        for (int n = 0; n < nums.size() - 1; ++n)
        {
            for (int n2 = n + 1; n2 < nums.size(); ++n2)
            {
                if (nums[n] + nums[n2] == target)
                {
                    return {n, n2};
                }
            }
        }

        return {};
    }
};

std::ostream& operator<<(
    std::ostream& os, const std::vector<int>& indices) noexcept
{
    if (indices.empty())
    {
        os << "EMPTY";

        return os;
    }

    auto begin = indices.cbegin();
    auto end = indices.cend();

    os << *begin;
    ++begin;

    while (begin != end)
    {
        os << ", " << *begin;
        ++begin;
    }

    return os;
}

int main()
{
    std::cout << Solution().twoSum({2, 7, 11, 15}, 9) << '\n';
    std::cout << Solution().twoSum({3, 2, 4}, 6) << '\n';
    std::cout << Solution().twoSum({3, 3}, 6) << '\n';

    return 0;
}
