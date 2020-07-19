#include <iostream>
#include <vector>
using namespace std;

/**
 * LeetCode
 * 4. 寻找两个正序数组的中位数
 * https://leetcode-cn.com/u/banana798/
 */

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)  //保证数组1一定最短,这样二分效率最高
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

        while (lo <= hi)   //二分
        {
            c1 = (lo + hi) / 2;  //c1是二分的结果
            //这里C2怎么推导呢，我们可以知道改良后的数组有2m+1+2n+1=2m+2n+2个元素，为偶数个
            //偶数进行切割时会把一个元素切割开，变成2个，因此切割后总数其实是2m+2n+4
            //切割后左边元素整体为c1+1+c2+1
            //则有2m+2n+4-(c1+1+c2+1) = c1+1+c2+1 可推出c2
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};


int main()
{
    // [#2#3#5#]
    vector<int> nums1 = {5,9,10};
    // [#1#4#7#9#]
    vector<int> nums2 = {2,6};

    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    return 0;
}