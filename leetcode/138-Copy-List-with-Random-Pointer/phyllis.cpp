/**
 * Definition for singly-linked list with a random pointer.
 */     
struct RandomListNode {
        int label;
        RandomListNode *next, *random;
        RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head){ 
        RandomListNode *oldCur, *newCur, *newHead;
        std::map<RandomListNode *, RandomListNode *> map;
        std::map<RandomListNode *, RandomListNode *>::iterator it;
     
        RandomListNode newDummyNode(0);
        oldCur = head;
        newCur = newHead = &newDummyNode;
        
        while(oldCur != NULL) {
            newCur->next = new RandomListNode(oldCur->label);
            map.insert(std::pair<RandomListNode*,RandomListNode*>(oldCur,newCur->next));
            oldCur = oldCur->next;
            newCur = newCur->next;
        }
        
        oldCur = head;
        newCur = newHead -> next;
     
        while(oldCur != NULL){
            if(oldCur->random != NULL && (it = map.find(oldCur->random)) != map.end()){
                newCur->random = it->second;   
            }
           
            oldCur = oldCur->next;
            newCur = newCur->next;
        }
        
        return newHead->next;
    }
};
