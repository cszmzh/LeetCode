#include <iostream>
using namespace std;

/**
 * LeetCode
 * 7. 整数反转 - 取模反转法
 * https://space.bilibili.com/54183978
 */

class Solution {
public:
    int reverse(int x) {
       int ans = 0;
       while(x != 0){
           int tem = x % 10;
           // ans大于214748364 或者 ans=214748364且最后一位大于7
           if( ans > INT_MAX / 10 || (ans == INT_MAX / 10 && tem > 7)) return 0;
           // ans小于214748364 或者 ans=214748364且最后一位小于-8
           if( ans < INT_MIN / 10 || (ans == INT_MIN / 10 && tem < -8)) return 0;
           ans = ans*10 + tem;
           x = x / 10;
       }
        return ans;
    }
};

int main(){
    Solution solution;
    cout << solution.reverse(-123);
}