#include <iostream>
using namespace std;

/**
 * LeetCode
 * 7. 整数反转 - 字符串方法（效率很低）
 * https://space.bilibili.com/54183978
 */

class Solution {
public:
    int reverse(int x) {
        string ans = "";
        int flag = 0;
        if(x < 0){
            flag = 1;
            ans = "-";
        }
        while(x!=0){
            if(flag){
                ans = ans + to_string(-(x%10));
            } else{
                ans = ans + to_string(x%10);
            }
            x /= 10;
        }
        try{
            return stoi(ans);
        } catch (std::invalid_argument) {
            return 0;
        } catch (std::out_of_range&) {
            return 0;
        }
    }
};

int main(){
    Solution solution;
    cout << solution.reverse(-123);
}