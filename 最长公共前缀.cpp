//https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1014/
//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。
//简单，就是遍历
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string same=strs[0];
        for(int i=1;i<strs.size();i++){
            bool flag=true;
            int j=0;
            for(;j<strs[i].length();j++){
                if(same[j]!=strs[i][j]){
                    flag=false;
                    break;
                }
            }
            if(flag&&same.length()>strs[i].length()){
                flag=false;
            }
            
            if(!flag){
                same=same.substr(0,j);
            }
            if(same==""){
                break;
            }
        }
        return same;
    }
};
