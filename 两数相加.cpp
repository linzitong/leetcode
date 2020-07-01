
//https://leetcode-cn.com/explore/interview/card/bytedance/244/linked-list-and-tree/1022/
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a=l1->val+l2->val;
        int add=0;
        if(a>=10){
            a=a-10;
            add=1;
        }
        ListNode* l3=new ListNode(a);
        ListNode* index;
        index=l3;
        while(l1->next!=NULL&&l2->next!=NULL){
            l1=l1->next;
            l2=l2->next;
            a=l1->val+l2->val+add;
            if(a>=10){
                a=a-10;
                add=1;
            }else{
                add=0;
            }
            ListNode* ll=new ListNode(a);
            index->next=ll;
            index=index->next;
        }
        while(l2->next!=NULL){
            l2=l2->next;
            a=l2->val+add;
            if(a>=10){
                a=a-10;
                add=1;
            }else{
                add=0;
            }
            ListNode* ll=new ListNode(a);
            index->next=ll;
            index=index->next;
        }
        while(l1->next!=NULL){
            l1=l1->next;
            a=l1->val+add;
            if(a>=10){
                a=a-10;
                add=1;
            }else{
                add=0;
            }
            ListNode* ll=new ListNode(a);
            index->next=ll;
            index=index->next;
        }
        if(add==1){
            ListNode* ll=new ListNode(add);
            index->next=ll;
        }
        return l3;
    }
};
