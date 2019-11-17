#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"
#include <stack>

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
		std::vector<T> victor;

		if(root == nullptr) {
			return victor;
		}

		std::stack<TreeNode<T>*> st; 
	    TreeNode<T>* curr = root; 
		  
	    while (curr != NULL || st.empty() == false) 
	    { 
			while (curr !=  NULL) {
				st.push(curr); 
			    curr = curr->left; 
			} 
								  
			curr = st.top(); 
		    st.pop(); 
												  
			victor.push_back(curr->val);

			curr = curr->right; 
																  
		} 

		return victor;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
		return std::vector<T>();
    }

    std::vector<T> traversePostOrder() override {
		std::vector<T> victor;

		std::stack<TreeNode<T>*> st;
		st.push(root);

		while (!st.empty())
		{
			TreeNode<T>* curr = st.top();
			st.pop();

			victor.push_back(curr->val);

			if (curr->left)
				st.push(curr->left);

			if (curr->right)
				st.push(curr->right);
		}
		
		return victor;	
    }

    virtual ~BinaryTree() {
		if(root == nullptr) {
			return;
		}	

		std::stack<TreeNode<T>*> nodesToDelete; 
		std::stack<TreeNode<T>*> nodeStack; 
	    nodeStack.push(root); 
		  
	    while (nodeStack.empty() == false) 
	    { 
			struct TreeNode<T>* node = nodeStack.top(); 
			nodesToDelete.push(node);
		    nodeStack.pop(); 
		                     
		    if (node->right) 
			    nodeStack.push(node->right); 
		    if (node->left) 
				 nodeStack.push(node->left); 
	    } 

		while(!nodesToDelete.empty()) {
			delete nodesToDelete.top();
			nodesToDelete.pop();
		}
    }

    T LCA(T node1, T node2) {
    }

    bool add(const T &) override {
        // not implemented yet
		return false;
    }

    bool remove(const T &) override {
        // not implemented yet
		return false;
    }

    int height() override {
        return height(root);
    }

};
