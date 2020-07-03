//https://leetcode-cn.com/explore/interview/card/bytedance/246/dynamic-programming-or-greedy/1043/
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。


//第一反应想要去分支定界了，但是画一个折线图就能明白，其实思想很简单啊，当前找到了赚钱的机会后，究竟应该选择这时候卖还是等一会在卖呢？完全不用在意！
//不管后面的比你前面的大还是小你都不用管，后面的值大了的话，你把min设置为当前的值，买进再卖出，继续加；小了的话，把后面的值设置为起始值，买进，然后等有比min大的，再卖出

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0){
            return 0;
        }
        int min=prices[0];
        int max=0;
        int i=0;
        while(i<n){
            if(prices[i]>min){
                max=max+prices[i]-min;
                min=prices[i];
            }else{
                if(prices[i]<min){
                    min=prices[i];
                }
            }
            i=i+1;
        }
        return max;
    }
};
