// 116. Populating Next Right Pointers in Each Node


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //base case
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root); //push root 
        while(!q.empty()){
            int len = q.size(); //initially size is 1 and is changing acc. to no. of child
            Node* prev = NULL; //to track the prev element
            while(len--){
                Node* temp = q.front(); 
                q.pop();
               if(prev) { //if it is connected to prev pointer connect to curr pointer
                prev->next = temp;
               }
                prev = temp; //prev++
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        prev->next = NULL; //no right next node ,pointer become null
        }
      return root;
    }
};
