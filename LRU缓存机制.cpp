//https://leetcode-cn.com/explore/interview/card/bytedance/245/data-structure/1032/
//运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
//获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
//写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//思路：使用一个链表，链表长度最长位k。每次get的时候找得到就返回value，找不到就返回-1；每次put的时候，首先看是否有key，有就替换，没有就查看是否超出长度限制，超出的话删除最后一位并在头部插入key，value
//其中符合LRU思路的就是每次操作完一个位置，就把这个位置提到链表的头部。


class LRUCache {
public:
    struct lists{
        int key;
        int value;
        lists *next;
        lists(int k,int v):key(k),value(v),next(NULL){}
    };
    lists* l;
    int k;
    LRUCache(int capacity) {
        k=capacity;
        l=NULL;
    }
    
   // void print1(lists* ll){
   //     lists *index=ll;
   //     while(index!=NULL){
   //         cout<<index->key<<'-'<<index->value<<' ';
   //         index=index->next;
   //     }
   //     cout<<endl;
   // }
    
    int get(int key) {
        //print1(l);
        if(l==NULL){
            return -1;
        }
        lists *index=l;
        if(l->key==key){
            return l->value;
        }
        while(index->next!=NULL){
            if(index->next->key==key){
                int v=index->next->value;
                index->next=index->next->next;
                lists *temp=l;
                l=new lists(key,v);
                l->next=temp;
                return v;
            }else{
                index=index->next;
            }
        }
        return -1;
    }
    
    
    void put(int key, int value) {
        bool flag=false;
        if(l==NULL){
            l=new lists(key,value);
            return;
        }
        if(l->key==key){
            l->value=value;
            return;
        }
        lists *index=l;
        while(index->next!=NULL){
            if(index->next->key==key){
                index->next=index->next->next;
                flag=true;
                lists *temp=l;
                l=new lists(key,value);
                l->next=temp;
                //提到前面去
            }else{
                index=index->next;
            }
        }
        if(!flag){
            //插入
            int count=0;
            lists *temp=l;
            if(k==1){
                l=new lists(key,value);
                return;
            }
            while(temp!=NULL){
                count=count+1;
                if(count==k-1){
                    temp->next=NULL;
                    break;
                }
                temp=temp->next;
            }
            lists *t=l;
            l=new lists(key,value);
            l->next=t;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
