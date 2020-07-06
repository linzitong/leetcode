//https://leetcode-cn.com/explore/interview/card/bytedance/242/string/1016/
//给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
//换句话说，第一个字符串的排列之一是第二个字符串的子串。
//最无脑的做法，就是分别从s2的第i位开始寻找是否有连续的包含于s1内的字符串，找的方式是找到一个对应的s1的串erase掉s1对应的字符，接着找。这样的复杂度为mn，显然太复杂。
//我的做法相似，所以复杂度比较高，只超出了9%的人，我的做法是如果找不到s1中对应的字符的时候，不会从第i+1位重新开始找，而是将第i位的字符添加回s1，这样就相当于从i+1位到当前位已经找过了，减少了一些重复的寻找


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        string d_s1=s1;
        int last_i=0;
        for(int i=0;i<s2.length();i++){
            int j=0;
            bool flag=false;
            if(d_s1==s1){
            	last_i=i;
			}
			//cout<<s2.substr(i)<<endl;
            for(int j=0;j<d_s1.length();j++){
            	if(d_s1[j]==s2[i]){
            		d_s1.erase(j,1);
            		if(d_s1.length()==0){
            			return true;
					}
            		flag=true;
            		break;
				}
			}
			if(!flag){
                if(s1.find(s2[i])==-1){
                    d_s1=s1;
                    continue;
                }
                if(d_s1.length()<s1.length()){
                    d_s1=d_s1+s2[last_i];
                    last_i=last_i+1;
                    i=i-1;
                }else{
                    d_s1=s1;
                }
			}
        }
        return false;
    }
};
