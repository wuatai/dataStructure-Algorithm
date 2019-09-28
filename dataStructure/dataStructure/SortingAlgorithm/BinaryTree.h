#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include <iostream>
#include <queue>

namespace BinaryTree
{
	//二分查找法
	int binarySearch(int arr[], int n, int target);

	template <typename Key, typename Value>
	class BinarySearchTree
	{
	private:
		struct Node
		{
			Key key;
			Value value;
			Node* left;
			Node* right;

			Node(Key key, Value value)
			{
				this->key = key;
				this->value = value;
				this->left = this->right = NULL;
			}

			Node(Node* node)
			{
				this->key = node->key;
				this->value = node->value;
				this->left = node->left;
				this->right = node->right;
			}
		};

		Node* root;
		int count;
	public:
		BinarySearchTree()
		{
			root = NULL;
			count = 0;
		}
		~BinarySearchTree()
		{
			destory(root);
		}

		int size(){ return count; }
		bool isEmpty(){ return count == 0; }
		void insert(Key key, Value value)
		{
			root = insert(root, key, value);
		}
		bool contain(Key key)
		{
			return contain(root, key);
		}
		Value* search(Key key)
		{
			return search(root, key);
		}
		// 前序遍历
		void preOrder()
		{
			preOrder(root);
		}
		// 中序遍历
		void inOrder()
		{
			inOrder(root);
		}
		// 后序遍历
		void postOrder()
		{
			postOrder(root);
		}

		// 层序遍历
		void levelOrder()
		{
			std::queue<Node*> q;
			q.push(root);
			while (!q.empty())
			{
				Node* node = q.front();
				q.pop();

				std::cout << node->key << std::endl;
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}

		//从二叉树中删除最小值所在的节点
		void removeMin()
		{
			if (root)
			{
				root = removeMin(root);
			}
		}

		void remove(Key key)
		{
			root = remove(root, key);
		}

		Node* minimum()
		{
			return minimum(root);
		}
	private:
		Node* insert(Node *node, Key key, Value value)
		{
			// 向以node为根的二叉搜索树中，插入节点(key, value)
			// 返回插入新节点后的二叉搜索树的根
			if (node == NULL)
			{
				count++;
				return new Node(key, value);
			}
			if (key == node->key)
				node->value = value;
			else if (key < node->key)
				node->left = insert(node->left, key, value);
			else
				node->right = insert(node->right, key, value);
			return node;
		}

		bool contain(Node* node, Key key)
		{
			if (node == NULL)
				return false;
			if (key == node->key)
				return true;
			else if (key < node->key)
				return contain(node->left, key);
			else
				return contain(node->right, key);
		}
		Value* search(Node* node, Key key)
		{
			if (node == NULL)
				return NULL;
			if (key == node->key)
				return &(node->value);
			else if (key < node->key)
				return search(node->left, key);
			else
				return search(node->right, key);
		}

		// 对以node为根的二叉搜索树进行前序遍历
		void preOrder(Node* node)
		{
			if (node != NULL)
			{
				std::cout << node->key << std::endl;
				preOrder(node->left);
				preOrder(node->right);
			}
		}

		// 对以node为根的二叉搜索树进行中序遍历
		void inOrder(Node* node)
		{
			if (node != NULL)
			{
				inOrder(node->left);
				std::cout << node->key << std::endl;
				inOrder(node->right);
			}
		}

		// 对以node为根的二叉搜索树进行后序遍历
		void postOrder(Node* node)
		{
			if (node != NULL)
			{
				postOrder(node->left);
				postOrder(node->right);
				std::cout << node->key << std::endl;
			}
		}

		void destory(Node* node)
		{
			if (node != NULL)
			{
				destory(node->left);
				destory(node->right);
				delete node;
				count--;
			}
		}
		// 找到以node为根节点的最小节点，并返回
		Node* minimum(Node* node)
		{
			if (node->left == NULL)
				return node;
			return minimum(node->left);
		}

		// 删除掉以node为根的二分搜索树中的最小节点
		// 返回删除节点后新的二分搜索树的根
		Node* removeMin(Node* node)
		{
			if (node->left == NULL)
			{
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}
			node->left = removeMin(node->left);
			return node;
		}

		// 删除掉以node为根的二分搜索树中键值为key节点
		// 返回删除节点后新的二分搜索树的根
		Node* remove(Node* node, Key key)
		{
			if (node == NULL)
				return NULL;
			if (key < node->key)
			{
				node->left = remove(node->left, key);
				return node;
			}
			else if (key > node->key)
			{
				node->right = remove(node->right, key);
				return node;
			}
			else
			{
				if (node->left == NULL)
				{
					Node* rightNode = node->right;
					delete node;
					count--;
					return rightNode;
				}
				if (node->right == NULL)
				{
					Node* leftNode = node->left;
					delete node;
					count--;
					return leftNode;
				}
				Node* delNode = node;
				Node* successor = new Node(minimum(node->right));
				count++;
				successor->right = removeMin(node->right);
				successor->left = node->left;
				delete delNode;
				count--;
				return successor;
			}
		}
	};
}

#endif // !_BINARY_TREE_H
