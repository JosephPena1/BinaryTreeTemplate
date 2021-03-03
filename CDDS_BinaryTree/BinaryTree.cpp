#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove.
	//and another to hold a reference to its parent.
	int valRemove = value;
	TreeNode* nodeFound = m_root;
	TreeNode* parentNode = m_root;

	//Try to find the node that matches the value given and its parent in the tree.
	//If the node cannot be found return.
	while (nodeFound != nullptr)
	{
		if (nodeFound->getData() == value)
			break;

		//Checks if the value we want to remove from the tree is less than the value at the current node.
		if (value < nodeFound->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentNode = nodeFound;
			//Change the current node to be the child to its left and continue.
			nodeFound = nodeFound->getLeft();

			if (nodeFound == nullptr)
				return;

		}

		//Check if the value we want to remove from the tree is greater than the value at the current node.
		else if (value > nodeFound->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentNode = nodeFound;
			//Change the current node to be the child to its right and continue.
			nodeFound = nodeFound->getRight();
			if (nodeFound == nullptr)
				return;

		}
	}//end loop

	//if nodeFound is a nullptr, return.
	if (nodeFound == nullptr)
		return;

	//Check to see if nodeFound has a right child
	if (nodeFound->hasRight())
	{
		//Initialize two iterators to find the node whose data will be copied and its parent.
		//Set the first iterator to point to the right child of the node we want to remove.
		TreeNode* firstIter = nodeFound->getRight();
		TreeNode* secondIter = nodeFound;

		//Loop while the first iterator has a value to its left.
		while (firstIter->hasLeft())
		{
			//Set the second iterator to be the value of the first iterator.
			secondIter = firstIter;
			//Set the first iterator to be the value to the left of it.
			firstIter = firstIter->getLeft();
		}
		//end loop

		//Once the smallest value has been found, declare a variable to hold firstIter's data, set firstIter's data to nodeFound's data
		//copy the data in first iterator to the node we want to remove.
		int iterVal = firstIter->getData();
		firstIter->setData(nodeFound->getData());
		nodeFound->setData(iterVal);


		//Check if the second iterator has a left child.
		if (secondIter->hasLeft())
			//Check if the left child stores the same data as the value we want to remove.
			if (secondIter->getLeft()->getData() == value)
			{
				//Set the second iterators left child to be the first iterators right child.
				secondIter->setLeft(firstIter->getRight());
			}

		//Check if the second iterator has a right child.
		if (secondIter->hasRight())
			//Check if the right child contains the same data as the value we want to remove.
			if (secondIter->getRight()->getData() == value)
			{
				//Set the right child of the second iterator to be the right child of the first iterator.
				secondIter->setRight(firstIter->getRight());
			}

		delete firstIter;

		return;
	}
}

void BinaryTree::insert(int value)
{
	//If the tree is empty, set the root to be a new node with the given value.
	if (isEmpty())
		m_root = new TreeNode(value);

	//Create a TreeNode pointer that will act as an iterator pointing to the current node and set it to the root.
	//Create a TreeNode pointer that will act as an iterator pointing to the parent 
	//of the current node and set it to the root.
	TreeNode* iter = m_root;
	TreeNode* parentIter = m_root;

	//Loop until the the current node iterator reaches a nullptr.
	while (iter != nullptr)
	{
		//Check if the value we want to add to the tree is less than the value at the current node.
		if (value < iter->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentIter = iter;
			//Change the current node to be the child to its left and continue.
			iter = iter->getLeft();

			TreeNode* tempNode = new TreeNode(value);
			if (iter == nullptr)
			{
				iter = tempNode;
				parentIter->setLeft(iter);
			}
		}

		//Check if the value we want to add to the tree is greater than the value at the current node.
		else if (value > iter->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentIter = iter;
			//Change the current node to be the child to its right and continue.
			iter = iter->getRight();

			TreeNode* tempNode = new TreeNode(value);
			if (iter == nullptr)
			{
				iter = tempNode;
				parentIter->setRight(iter);
			}
		}

		//If the value is the same as a value already in the list return.
		if (value == iter->getData())
			return;

	}//end loop

	//If the value we want to add is less than the value of the parent node, insert the value to the left.
	if (value < parentIter->getData())
		parentIter->setLeft(iter);

	//Otherwise, insert the value to the right.
	else
		parentIter->setRight(iter);
}

void BinaryTree::remove(int value)
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove.
	//and another to hold a reference to its parent.
	TreeNode* nodeFound = m_root;
	TreeNode* parentNode = m_root;

	//Try to find the node that matches the value given and its parent in the tree.
	//If the node cannot be found return.
	while (nodeFound != nullptr)
	{
		if (nodeFound->getData() == value)
			break;

		//Checks if the value we want to remove from the tree is less than the value at the current node.
		if (value < nodeFound->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentNode = nodeFound;
			//Change the current node to be the child to its left and continue.
			nodeFound = nodeFound->getLeft();

			if (nodeFound == nullptr)
				return;

		}

		//Check if the value we want to remove from the tree is greater than the value at the current node.
		else if (value > nodeFound->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			parentNode = nodeFound;
			//Change the current node to be the child to its right and continue.
			nodeFound = nodeFound->getRight();
			if (nodeFound == nullptr)
				return;

		}
	}//end loop

	//if nodeFound is a nullptr, return.
	if (nodeFound == nullptr)
		return;

	//Check to see if nodeFound has a right child
	if (nodeFound->hasRight())
	{
		//Initialize two iterators to find the node whose data will be copied and its parent.
		//Set the first iterator to point to the right child of the node we want to remove.
		TreeNode* firstIter = nodeFound->getRight();
		TreeNode* secondIter = nodeFound;

		//Loop while the first iterator has a value to its left.
		while (firstIter->hasLeft())
		{
			//Set the second iterator to be the value of the first iterator.
			secondIter = firstIter;
			//Set the first iterator to be the value to the left of it.
			firstIter = firstIter->getLeft();
		}
		//end loop

		//Once the smallest value has been found, declare a variable to hold firstIter's data, set firstIter's data to nodeFound's data
		//copy the data in first iterator to the node we want to remove.
		int iterVal = firstIter->getData();
		firstIter->setData(nodeFound->getData());
		nodeFound->setData(iterVal);


		//Check if the second iterator has a left child.
		if (secondIter->hasLeft())
			//Check if the left child stores the same data as the value we want to remove.
			if (secondIter->getLeft()->getData() == value)
			{
				//Set the second iterators left child to be the first iterators right child.
				secondIter->setLeft(firstIter->getRight());
			}

		//Check if the second iterator has a right child.
		if (secondIter->hasRight())
			//Check if the right child contains the same data as the value we want to remove.
			if (secondIter->getRight()->getData() == value)
			{
				//Set the right child of the second iterator to be the right child of the first iterator.
				secondIter->setRight(firstIter->getRight());
			}

		//Delete the first iterator
		delete firstIter;

		return;
	}

	//Otherwise, if the nodeFound doesn't have a right child
	else
	{
		//check if the parent of the nodeFound has a left child.
		if (parentNode->hasLeft())
			//Check if the data that the left child holds is the same as the value we want to remove.
			if (parentNode->getLeft()->getData() == value)
			{
				//Set the left child of the parent node to be the left child of nodeFound.
				parentNode->setLeft(nodeFound->getLeft());
			}

		//Check if the parent of the nodeFound has a right child.
		if (parentNode->hasRight())
			//Check if the data the right child holds is the same as the value we want to remove.
			if (parentNode->getRight()->getData() == value)
			{
				//Set the right child of the parent node to be the left child of nodeFound.
				parentNode->setRight(nodeFound->getLeft());
			}

		//Check if the node we want to remove is the root.
			//Set the root to be its left child.
		if (value == m_root->getData())
			m_root = m_root->getLeft();
	}
}

TreeNode* BinaryTree::find(int value)
{
	//Initialize an iterator starting at the root.
	TreeNode* iter = m_root;

	//Loop through the tree while the iterator isn't nullptr.
	while (iter != nullptr)
	{
		//Check if the node has the data we want
		if (iter->getData() == value)
			return iter;

		//If the node doesn't have the data we want, check to see if it's higher in value.
		if (iter->getData() < value)
			//Set the iterator to be its current right child.
			iter = iter->getRight();

		//If the node doesn't have the data we want, check to see if it's lower in value.
		if (iter->getData() > value)
			//Set the iterator to be its current left child.
			iter = iter->getLeft();

	}//end loop

	//Return nullptr
	return nullptr;
}

void BinaryTree::draw(TreeNode* selected)
{
	draw(m_root, 400, 50, 400, selected);
}

bool BinaryTree::findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent)
{
	//Create two iterators: one that will point to the current node to compare the search value to,
	//and the other to hold a reference to the parent.
	TreeNode* iter = m_root;
	TreeNode* parentIter = m_root;

	//Loop while the current node iterator isn't nullptr
	while (iter != nullptr)
	{
		//Check if the search value is the same as the current nodes data.
		if (searchValue == iter->getData())
		{
			//Set the node found argument to be the current node and the parent node to be the parent node iterator.
			nodeFound = iter;
			nodeParent = parentIter;
			//Return true.
			return true;
		}

		//Check if the search value is greater than the value at the current node.
		if (searchValue > iter->getData())
		{
			//Set the parent node to be the current node.
			parentIter = iter;
			//Set the current node to be the child to the right of the current node.
			iter = iter->getRight();
		}

		//Check if the search value is less than the value at the current node.
		if (searchValue < iter->getData())
		{
			//Set the parent node to be the current node.
			parentIter = iter;
			//Set the current node to be its left child.
			iter = iter->getLeft();
		}
	}//end loop

	return false;
}

void BinaryTree::draw(TreeNode* currentNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	//decrease the horizontal space as the nodes draw
	horizontalSpacing /= 2;

	//Checks if the current node is null
	if (currentNode)
	{
		//Draws the left child if this node has one
		if (currentNode->hasLeft())
		{
			//Draws a line between the left child and the current node
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child if this node has one
		if (currentNode->hasRight())
		{
			//Draws a line between the right child and the current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//Draws the current node
		currentNode->draw(x, y, (selected == currentNode));
	}
}