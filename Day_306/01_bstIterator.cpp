// Question Link: https://www.interviewbit.com/problems/bst-iterator/

/*
BST Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Try to optimize the additional space complexity apart from the amortized time complexity.
*/



stack <TreeNode*>st;

BSTIterator::BSTIterator(TreeNode *root) {

    while(root!=NULL){
        st.push(root);
        root=root->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return st.size()>0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* temp=st.top();

    st.pop();
    BSTIterator(temp->right);

    return temp->val;
}
