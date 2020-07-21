#include <iostream>
#include <string>
using namespace std;

/**
 * LeetCode
 * 5. 最长回文子串
 * https://leetcode-cn.com/u/banana798/
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.size();
        if(s.empty() || strLen==0){
            return "";
        }
        if(s.size()==1){    //这里进行了小优化
            return s;
        }
        //maxLen为最长回文长度,maxStart为最长回文时起始位置
        int left=0,right=0,len=1,maxLen=0,maxStart=0;

        //对每个字符进行左右扩散
        for(int i=0; i<strLen; i++){
            left = i-1;
            right = i+1;

            while(left>=0 && s[left]==s[i]){
                left--;
                len++;
            }

            while(right<strLen && s[right]==s[i]){
                right++;
                len++;
            }

            while(left>=0 && right<strLen && s[left]==s[right]){
                left--;
                right++;
                len+=2;
            }

            if(len > maxLen){
                maxLen = len;
                maxStart = left<0?-1:left; //返回-1是因为下面maxStart+1
            }
            len = 1;    //恢复len=1
        }
        //返回从maxStart+1下表开始，长度为maxLen的字符串
        return s.substr(maxStart+1, maxLen);
    }
};

int main(){
    Solution solution;
    cout << solution.longestPalindrome("abcbaba");
}