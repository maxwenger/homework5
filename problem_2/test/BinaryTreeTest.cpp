#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(inOrder, multiNodeTree) {
	TreeNode<int>* root = new TreeNode<int>(1);

	root->setLeft(new TreeNode<int>(2)); 
	root->getLeft()->setLeft(new TreeNode<int>(4));
	root->getLeft()->setRight(new TreeNode<int>(5));

	root->setRight(new TreeNode<int>(3));

	std::vector<int> answer;
	answer.push_back(4);
	answer.push_back(2);
	answer.push_back(5);
	answer.push_back(1);
	answer.push_back(3);

	BinaryTree<int> tree(root);
	ASSERT_EQ(tree.traverseInOrder(), answer);
}
	
TEST(postOrder, multiNodeTree) {
	TreeNode<int>* root = new TreeNode<int>(1);

	root->setLeft(new TreeNode<int>(2)); 
	root->getLeft()->setLeft(new TreeNode<int>(4));
	root->getLeft()->setRight(new TreeNode<int>(5));

	root->setRight(new TreeNode<int>(3));

	std::vector<int> answer;
	answer.push_back(1);
	answer.push_back(3);
	answer.push_back(2);
	answer.push_back(5);
	answer.push_back(4);

	BinaryTree<int> tree(root);
	ASSERT_EQ(tree.traversePostOrder(), answer);
}

BinaryTree<int> getLCATree() {
	TreeNode<int>* root = new TreeNode<int>(4);	
	
	root->setLeft(new TreeNode<int>(8));
	root->getLeft()->setLeft(new TreeNode<int>(7));
	root->getLeft()->setRight(new TreeNode<int>(3));

	root->setRight(new TreeNode<int>(6));
	root->getRight()->setLeft(new TreeNode<int>(2));
	root->getRight()->setRight(new TreeNode<int>(9));

	BinaryTree<int> tree(root);
	return tree;
}

TEST(LCA, 44) {
	BinaryTree<int> tree = getLCATree();
	ASSERT_EQ(tree.LCA(4, 4), 4);
}

TEST(LCA, 77) {
	BinaryTree<int> tree = getLCATree();
	ASSERT_EQ(tree.LCA(7, 7), 7);
}

TEST(LCA, 73) {
	BinaryTree<int> tree = getLCATree();
	ASSERT_EQ(tree.LCA(7, 3), 8);
}

TEST(LCA, 78) {
	BinaryTree<int> tree = getLCATree();
	ASSERT_EQ(tree.LCA(7, 8), 8);
}

TEST(LCA, 86) {
	BinaryTree<int> tree = getLCATree();
	ASSERT_EQ(tree.LCA(8, 6), 4);
}

TEST(LCA, 32) {
	BinaryTree<int> tree = getLCATree();
	ASSERT_EQ(tree.LCA(3, 2), 4);
}
	
