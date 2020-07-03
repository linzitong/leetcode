//https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1029/
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//如果全是负数，那么挑选最大的负数；如果有正数存在，那么寻找当前正和串以及这一串正和与后面的值相加是否能获取更大的正和的串

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int max=nums[0];
        int max_c=nums[0];
        for(int i=1;i<nums.size();i++){
        //如果最大串当前为负数，那么只要是大于当前串和的值，都可以替换最大穿
        //如果最大串为正数了，记录这个最大串和，并记录串与后面一连串数的和，如果累加和大于当前max，那么替换为max
            if(max<0){
                if(nums[i]>max){
                    max=nums[i];
                    max_c=nums[i];
                }
            }else{
            //如果这一串已经小于0了说明已经无法从max的头开始获取超过max的值了，那么最大值最多就是从当前位置开始；
            //如果max_c的串值大于零，还有可能通过后续的拼接超过max
                if(max_c<=0){
                    max_c=nums[i];
                }else{
                    max_c=max_c+nums[i];
                }
                if(max_c>max){
                    max=max_c;
                }
            }
        }
        return max;
    }
};
