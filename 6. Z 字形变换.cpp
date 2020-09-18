#include <iostream>
#include <string>
using namespace std;

/**
 * LeetCode
 * 6. Z 字形变换
 * https://space.bilibili.com/54183978
 */

class Solution {
public:
    string convert(string s, int numRows) {
         int size = s.size();
         string ans = "";

         if(numRows == 1){
             return s;
         }

         for(int i = 1; i <= numRows; i++){
             // 加第i行字符
             int j = i - 1;
             // 每行第一个字符
             ans += s[j];
             int money = 2*numRows-2;

             while(j < size){

                 if(money == 2*numRows-2 && i!=numRows){
                     // 消费补偿
                     j = j + money - (2*i - 2);
                     if(j >= size){
                         break;
                     }
                     ans += s[j];
                     money -= money - (2*i - 2);
                 } else{
                     // 消费剩余
                     j = j + money;
                     if(j >= size){
                         break;
                     }
                     ans += s[j];
                     money = 0;
                 }

                 if(money == 0){
                     money = 2*numRows-2;
                 }
             }
         }
         return ans;
    }
};

int main(){
    Solution solution;
    cout << solution.convert("A", 1);
}