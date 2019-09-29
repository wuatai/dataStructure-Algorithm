#ifndef _UNION_FIND_H
#define _UNION_FIND_H

namespace Union
{
	class UnionFind
	{
	private:
		// id数组表示元素之间的连接关系
		int* id;
		int count;
	public:
		UnionFind(int n);
		~UnionFind();

		int find(int p);
		bool isConnected(int p, int q);

		void unionItem(int p, int q);
	};

	class QuickUnion
	{
	private:
		int* parent;
		int count;
	public:
		QuickUnion(int count);
		~QuickUnion();

		int find(int p);
		bool isConnected(int p, int q);
		void unionItem(int p, int q);
	};

	class QuickUnionSize
	{
	private:
		int* parent;
		int* sz;	//sz[i]为以i为根的集合元素个数
		int count;
	public:
		QuickUnionSize(int count);
		~QuickUnionSize();

		int find(int p);
		bool isConnected(int p, int q);
		void unionItem(int p, int q);
	};

	class QuickUnionRank
	{
	private:
		int* parent;
		int* rank;	//rank[i]为以i为根的集合所表示的树的层数
		int count;
	public:
		QuickUnionRank(int count);
		~QuickUnionRank();

		int find(int p);
		bool isConnected(int p, int q);
		void unionItem(int p, int q);
	};

	class QuickUnionCompress
	{
	private:
		int* parent;
		int* rank;	//rank[i]为以i为根的集合所表示的树的层数
		int count;
	public:
		QuickUnionCompress(int count);
		~QuickUnionCompress();

		int find(int p);
		bool isConnected(int p, int q);
		void unionItem(int p, int q);
	};
}

#endif