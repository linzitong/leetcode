//https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1025/
//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//思路很简单，就是使用k最小堆，就是边界条件太麻烦，我因为NULL、empty这些边界条件浪费了太长时间

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void exchange(int i,int j,vector<ListNode*> &v){
        ListNode* index=v[i];
        v[i]=v[j];
        v[j]=index;
    }
    void init(vector<ListNode*> &list){
    	//删除NULL的元素
		for(int i=list.size()-1;i>=0;i--){
			if(list[i]==NULL){
				list.erase(list.begin()+i);
				//cout<<i;
			}
		} 
		//cout<<"size"<<list.size();
        for(int i=list.size()-1;i>0;i--){
            int p=(i-1)/2;
            if(list[i]->val<list[p]->val){
            	exchange(i,p,list);
            	int n=list.size()-1;
            	while(true){
            		if((2*(i+1))<=n){
						int left=1;
						if(list[(2*(i+1))]->val<list[(2*(i+1))-1]->val){
							left=0;
						}
						if(list[i]->val>list[(2*(i+1))-left]->val){
							exchange(i,(2*(i+1))-left,list);
							i=(2*(i+1))-left;
						}else{
							break;
						}
					}else if((2*(i+1))-1==n){
						if(list[i]->val>list[(2*(i+1))-1]->val){
							exchange(i,(2*(i+1))-1,list);
						}
						break;
					}else{
						break;
					}
				}
			} 
        }  
    }
    void delete1(vector<ListNode*> &list){
        //删除头部链表的头，如果变成空，那么删除这个元素，让尾部元素上来 
		//如果没有变成空，直接与子元素交换直到不可交换
		list[0]=list[0]->next;
		if(list[0]==NULL){
			if(list.size()==1){
				list.pop_back();
				return;
			}
			int n=list.size()-1;
			ListNode* top=list[n];
			list.pop_back();
			list[0]=top;
		}

		int n=list.size()-1;//index最大值 
		int i=0;
		while(true){
			if((2*(i+1))<=n){
				int left=1;
				if(list[(2*(i+1))]->val<list[(2*(i+1))-1]->val){
					left=0;
				}
				if(list[i]->val>list[(2*(i+1))-left]->val){
					exchange(i,(2*(i+1))-left,list);
					i=(2*(i+1))-left;
				}else{
					break;
				}
			}else if((2*(i+1))-1==n){
				if(list[i]->val>list[(2*(i+1))-1]->val){
					exchange(i,(2*(i+1))-1,list);
				}
				break;
			}else{
				break;
			}
		}
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        init(lists);
        //cout<<"listsize"<<lists.size();
        if(lists.size()==0){
            return NULL;
            //cout<<"empty";
        }
        ListNode* top=new ListNode(lists[0]->val);
        ListNode* index=top;
        delete1(lists);
        while(!lists.empty()){
        	//cout<<2;
        	int a=lists[0]->val;
        	//cout<<a<<endl;
        	ListNode* temp=new ListNode(a);
        	index->next=temp;
        	index=index->next;
        	delete1(lists);
		}
		return top;
    }
};
