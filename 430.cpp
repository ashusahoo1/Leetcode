class Solution {
public:
    Node* flatten(Node* head) {

       

        Node* temp = head;
        while(temp){
                Node* a = temp->next;
            if(temp->child){
                Node* c = temp->child;
                temp->child = NULL;
                c = flatten(c);
                temp->next = c;
                c->prev = temp;
                while(c->next){
                    c = c->next;
                }
                c->next = a;

                if(a){a->prev = c;}

            }
                temp = a;
        }
        return head;
        
    }
};
