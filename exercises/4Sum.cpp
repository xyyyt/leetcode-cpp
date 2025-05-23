#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

namespace std
{
    template <>
    struct hash<std::vector<int>>
    {
        [[nodiscard]]
        size_t operator()(const std::vector<int>& v) const noexcept
        {
            size_t h = 0;

            for (auto n : v)
            {
                h ^= std::hash<int>()(n);
            }

            return h;
        }
    };

    template <>
    struct equal_to<std::vector<int>>
    {
        [[nodiscard]]
        bool operator()(
            const std::vector<int>& lhs, const std::vector<int>& rhs) const
        {
            if (lhs.size() != rhs.size())
            {
                return false;
            }

            std::vector<int> lhsCopy = lhs;
            std::vector<int> rhsCopy = rhs;

            std::sort(lhsCopy.begin(), lhsCopy.end());
            std::sort(rhsCopy.begin(), rhsCopy.end());

            return lhsCopy == rhsCopy;
        }
    };
}

class Solution
{
public :
    std::vector<std::vector<int>> fourSum(std::vector<int> nums, int target)
    {
        if (nums.empty())
        {
            return {};
        }

        std::unordered_set<std::vector<int>> quadruplets;

        for (int n = 0; n < nums.size() - 3; ++n)
        {
            for (int n2 = n + 1; n2 < nums.size() - 2; ++n2)
            {
                for (int n3 = n2 + 1; n3 < nums.size() - 1; ++n3)
                {
                    for (int n4 = n3 + 1; n4 < nums.size(); ++n4)
                    {
                        if (nums[n] + nums[n2] + nums[n3] + nums[n4] == target)
                        {
                            using InitList_t = std::initializer_list<int>;

                            quadruplets.emplace(
                                 InitList_t{nums[n], nums[n2], nums[n3], nums[n4]});
                        }
                    }
                }
            }
        }

        return std::vector<std::vector<int>>(
            std::move_iterator(quadruplets.begin()),
            std::move_iterator(quadruplets.end()));
    }
};

std::ostream& operator<<(
    std::ostream& os, const std::vector<std::vector<int>>& quadruplets) noexcept
{
    if (quadruplets.empty())
    {
        os << "EMPTY";

        return os;
    }

    for (const auto& triplet : quadruplets)
    {
        if (triplet.empty())
        {
            continue;
        }

        auto begin = triplet.cbegin();
        auto end = triplet.cend();

        os << '[' << *begin;
        ++begin;

        while (begin != end)
        {
            os << ", " << *begin;
            ++begin;
        }

        os << ']';
    }

    return os;
}

int main()
{
    std::cout << Solution().fourSum({1, 0, -1, 0, -2, 2}, 0) << '\n';
    std::cout << Solution().fourSum({2, 2, 2, 2, 2}, 8) << '\n';

    return 0;
}
