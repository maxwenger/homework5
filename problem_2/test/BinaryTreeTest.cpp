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

TEST(LCA, givenLCATree) {

}

	
