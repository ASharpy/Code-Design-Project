#pragma once

template<class T, class U>
class BinaryTree
{


private:

	class TreeNode
	{
	public:


		T key;
		U value;

		TreeNode *left;
		TreeNode *right;
		TreeNode()
		{
			left = nullptr;
			right = nullptr;
		};

		TreeNode(T newkey, U newValue)
		{
			key = newkey;
			value = newValue;
			left = nullptr;
			right = nullptr;
		};
		~TreeNode() { value = 0; key = 0; };

	};

	//Private Functions 
	int leafNum = 0;
	TreeNode * Root;

	//bool isLeaf();
	void InsertTree(T keyNum, U valueNum, TreeNode *leaf)
	{
		if (keyNum < leaf->key)
		{
			if (leaf->left != nullptr)

			{
				InsertTree(keyNum, valueNum, leaf->left);
			}
			else
			{
				leaf->left = new TreeNode(keyNum, valueNum);
				leaf->left->key = keyNum;
				leaf->left->value = valueNum;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
				leafNum++;
			}
		}

		else if (keyNum >= leaf->key)
		{
			if (leaf->right != nullptr)
			{
				InsertTree(keyNum, valueNum, leaf->right);
			}
			else
			{
				leaf->right = new TreeNode(keyNum, valueNum);
				leaf->right->key = keyNum;
				leaf->right->value = valueNum;
				leaf->right->left = nullptr;
				leaf->right->right = nullptr;
				leafNum++;
			}
		}



	}

	U SearchTree(T keyNum, TreeNode *leaf)
	{
		if (leaf != nullptr)
		{
			if (keyNum == leaf->key)
			{
				return leaf->value;
			}
			else if (keyNum < leaf->key)
			{
				return SearchTree(keyNum, leaf->left);
			}
			else
			{
				return SearchTree(keyNum, leaf->right);

			}
		}

		else
		{
			throw("couldn't Find key");
		}

	}

	void DestroyTree(TreeNode *leaf)
	{
		if (leaf != nullptr)
		{
			DestroyTree(leaf->left);
			DestroyTree(leaf->right);
			delete leaf;
			Root = nullptr;
			leafNum--;
		}
	}
	//BinaryTree treeDeletion();


public:

	int	getLeafNum()
	{
		return leafNum;
	}

	BinaryTree()
	{
		Root = nullptr;
	}

	void insert(T KeyNum, U valueNum)

	{
		if (Root != nullptr)
		{
			InsertTree(KeyNum, valueNum, Root);
		}
		else
		{
			Root = new TreeNode(KeyNum, valueNum);
			Root->value = valueNum;
			Root->key = KeyNum;
			Root->left = nullptr;
			Root->right = nullptr;
			leafNum++;
		}
	};

	U Search(T keyNum)
	{
		return SearchTree(keyNum, Root);
	}

	void deleteTree()
	{
		DestroyTree(Root);
	}

	U operator [] (T newKey)
	{
		return SearchTree(newKey, Root);
	}

};

