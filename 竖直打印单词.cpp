//链接：https://leetcode-cn.com/problems/print-words-vertically/
//给你一个字符串s。请你按照单词在 s 中的出现顺序将它们全部竖直返回。
//单词应该以字符串列表的形式返回，必要时用空格补位，但输出尾部的空格需要删除（不允许尾随空格）。
//每个单词只能放在一列上，每一列中也只能有一个单词。
//

//示例 1：
//
//输入：s = "HOW ARE YOU"
//输出：["HAY","ORO","WEU"]
//解释：每个单词都应该竖直打印。 
// "HAY"
//?"ORO"
//?"WEU"
//示例 2：
//
//输入：s = "TO BE OR NOT TO BE"
//输出：["TBONTB","OEROOE","   T"]
//解释：题目允许使用空格补位，但不允许输出末尾出现空格。
//"TBONTB"
//"OEROOE"
//"   T"
//示例 3：
//
//输入：s = "CONTEST IS COMING"
//输出：["CIC","OSO","N M","T I","E N","S G","T"]



//思路：暴力思路，先将该string以' '为分割符号进行分割，分割后存储在一个vector words内，存储的同时
//统计每个被分割的词的长度得到最大长度x。然后新建一个vector，向其中push_back共x个""，之后读
//每个单词，将单词的每个符号按照顺序拼接到vector中，如果vector数量超过单词数，那么其他的拼接' '
//拼接全部结束后，对vector进行处理，删除每个内容后面的空格，最终得到结果
//
//边界处理：
//1. 对初始的string进行分割的过程，使用的是s.find函数，通过寻找s中的' '来划分界限，单词的第一个位置是
//上一次的第二个位置+1，第二个位置是find到空格的位置，要注意最后一个单词find空格失败，真实的末位是s的末尾
//2. 无论拼接还是删除末尾空格都要注意最终一个的边界 

#include<vector>
#include<iostream>
#include<string>
#include<string.h>
#include <stdio.h>
using namespace std;
class Solution {
public:
    vector<string> printVertically(string s) {
		int pos1=0,pos2;
		pos2=s.find(' ');
		vector<string> words;
		int max_length=0;
		while(pos1<s.length()){
			string a=s.substr(pos1,pos2-pos1);
			int len=a.length();
			if(len>max_length){
				max_length=len;
			}
			words.push_back(a);
			pos1=pos2+1;
			pos2=s.find(' ',pos1);
			if(pos2==-1){
				pos2=s.length()+1;
			}
		}
		vector<string> result;
		for(int i=0;i<max_length;i++){
			result.push_back("");
		}
		for(int i=0;i<words.size();i++){
			int max=words[i].length();
			for(int j=0;j<max;j++){
				result[j]=result[j]+words[i][j];
			}
			for(int j=max;j<max_length;j++){
				result[j]=result[j]+" ";
			}
		}
		for(int i=0;i<max_length;i++){
			int last=0;
			for(int j=0;j<result[i].length();j++){
				if(result[i][j]!=' '){
					last=j;
				}
			}
			result[i]=result[i].substr(0,last+1);
		}
		return result;
    }
    
};
int main(){
	Solution s;
	vector<string> v=s.printVertically("AA BBB C DDDD EEEEE F");
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	
}
