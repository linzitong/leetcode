//https://leetcode-cn.com/explore/interview/card/bytedance/247/bonus/1045/
//计算并返回 x 的平方根，其中 x 是非负整数。
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//疑惑，不懂这道题考什么……不过我只超越了59%的人，说明有比调用函数更快速的方案


class Solution {
public:
    int mySqrt(int x) {
        double a=sqrt(x);
        int b=floor(a);
        return b;
    }
};
