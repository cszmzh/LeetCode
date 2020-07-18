#include<stdio.h>
/**
 * LeetCode
 * 3.无重复字符的最长子串
 * https://leetcode-cn.com/u/banana798/
 */

int lengthOfLongestSubstring(char * s){
    int tem[150]={0};
    int len = 0,i=1,result=0,tag=0;
    while(*s != '\0'){
        int a = s[0];
        if(tem[a]==NULL || tem[a]<tag){
            tem[a] = i; //标记该字符存在
            len++;
        }else{
            result=len>result?len:result;
            tag=tem[a];
            len=i-tag-1;
            tem[a]=NULL;
            continue;
        }
        s++;
        i++;
    }
    return len>result?len:result;
}

int main(){
    char *s="pwwkew";
    printf("%d",lengthOfLongestSubstring(s));
}
