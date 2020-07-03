//https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1042/
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
//注意：你不能在买入股票前卖出股票。
//最直接的思路就是两次遍历对比所有元素差选取最大的，但是这样一定会超时的，毕竟也提示了这需要动态规划或者贪心来解决嘛
//那其实转念一想，只要存储当前位置以前最小的那个值，然后与当前的位置相减，找到最大的就好啦
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[j]-prices[i]>max){
                    max=prices[j]-prices[i];
                }
            }
        }
        return max;
    }
};
