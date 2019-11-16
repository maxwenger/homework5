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
        // homework, to be done iteratively
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
        // homework, to be done iteratively
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
        // homework
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
