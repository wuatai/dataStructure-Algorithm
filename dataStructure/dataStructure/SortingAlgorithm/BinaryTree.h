#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include <iostream>
#include <queue>

namespace BinaryTree
{
	//���ֲ��ҷ�
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
		// ǰ�����
		void preOrder()
		{
			preOrder(root);
		}
		// �������
		void inOrder()
		{
			inOrder(root);
		}
		// �������
		void postOrder()
		{
			postOrder(root);
		}

		// �������
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

		//�Ӷ�������ɾ����Сֵ���ڵĽڵ�
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
			// ����nodeΪ���Ķ����������У�����ڵ�(key, value)
			// ���ز����½ڵ��Ķ����������ĸ�
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

		// ����nodeΪ���Ķ�������������ǰ�����
		void preOrder(Node* node)
		{
			if (node != NULL)
			{
				std::cout << node->key << std::endl;
				preOrder(node->left);
				preOrder(node->right);
			}
		}

		// ����nodeΪ���Ķ��������������������
		void inOrder(Node* node)
		{
			if (node != NULL)
			{
				inOrder(node->left);
				std::cout << node->key << std::endl;
				inOrder(node->right);
			}
		}

		// ����nodeΪ���Ķ������������к������
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
		// �ҵ���nodeΪ���ڵ����С�ڵ㣬������
		Node* minimum(Node* node)
		{
			if (node->left == NULL)
				return node;
			return minimum(node->left);
		}

		// ɾ������nodeΪ���Ķ����������е���С�ڵ�
		// ����ɾ���ڵ���µĶ����������ĸ�
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

		// ɾ������nodeΪ���Ķ����������м�ֵΪkey�ڵ�
		// ����ɾ���ڵ���µĶ����������ĸ�
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
