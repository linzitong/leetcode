//https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1038/
//反转一个单链表。
//进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
//首先是最简单的递归地反转，逐个读取链表并插入到新链表的头部
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
    ListNode* reverseList(ListNode* head) {
        //一定要注意输入为空的情况
        if(head==NULL){
            return NULL;
        }
        ListNode* index;
        index=head;
        ListNode* re=new ListNode(index->val);
        ListNode* h;
        h=re;
        while(index->next!=NULL){
            index=index->next;
            ListNode* n=new ListNode(index->val);
            n->next=h;
            h=n;
        }
        return h;
    }
};
