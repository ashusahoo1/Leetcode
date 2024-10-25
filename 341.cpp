// 341. Flatten Nested List Iterator


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        NestedInteger n;
        unravel(nestedList, q, n);
    }
    
    void unravel(vector<NestedInteger> &nestedList, queue<int>& q, NestedInteger n){
        for (int i=0; i<nestedList.size(); i++){
            if (nestedList[i].isInteger()){
                q.push(nestedList[i].getInteger());
            }
            else{
                unravel(nestedList[i].getList(), q, n);
                
            }
        }
        return ;
    }
    
    int next() {
        int x = q.front();
        q.pop();
        return x;
        
    }
    
    bool hasNext() {
       return !q.empty();        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
