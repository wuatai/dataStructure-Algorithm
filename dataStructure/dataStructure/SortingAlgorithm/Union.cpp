#include "Union.h"
#include <assert.h>
Union::UnionFind::UnionFind(int n)
{
	count = n;
	id = new int[n];
	for (int i = 0; i < n; i++)
		id[i] = i;
}

Union::UnionFind::~UnionFind()
{
	delete[] id;
}

int Union::UnionFind::find(int p)
{
	assert(p >= 0 && p < count);
	return id[p];
}

bool Union::UnionFind::isConnected(int p, int q)
{
	return UnionFind::find(p) == UnionFind::find(q);
}

void Union::UnionFind::unionItem(int p, int q)
{
	int pId = find(p);
	int qId = find(q);

	if (pId == qId)
		return;
	for (int i = 0; i < count; i++)
		if (id[i] == pId)
			id[i] = qId;
}

Union::QuickUnion::QuickUnion(int count)
{
	parent = new int[count];
	this->count = count;
	for (int i = 0; i < count; i++)
		parent[i] = i;
}

Union::QuickUnion::~QuickUnion()
{
	delete[] parent;
}

int Union::QuickUnion::find(int p)
{
	assert(p >= 0 && p < count);
	while (parent[p] != p)
	{
		p = parent[p];
	}
	return p;
}

bool Union::QuickUnion::isConnected(int p, int q)
{
	return find(p) == find(q);
}

void Union::QuickUnion::unionItem(int p, int q)
{
	int pRoot = find(p);
	int qRoot = find(q);
	if (pRoot == qRoot)
		return;
	parent[pRoot] = qRoot;
}

Union::QuickUnionSize::QuickUnionSize(int count)
{
	parent = new int[count];
	sz = new int[count];
	this->count = count;
	for (int i = 0; i < count; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}
}

Union::QuickUnionSize::~QuickUnionSize()
{
	delete[] parent;
	delete[] sz;
}

int Union::QuickUnionSize::find(int p)
{
	assert(p >= 0 && p < count);
	while (parent[p] != p)
	{
		p = parent[p];
	}
	return p;
}

bool Union::QuickUnionSize::isConnected(int p, int q)
{
	return find(p) == find(q);
}

void Union::QuickUnionSize::unionItem(int p, int q)
{
	int pRoot = find(p);
	int qRoot = find(q);
	if (pRoot == qRoot)
		return;

	if (sz[pRoot] < sz[qRoot])
	{
		parent[pRoot] = qRoot;
		sz[qRoot] += sz[pRoot];
	}
	else
	{
		parent[qRoot] = pRoot;
		sz[pRoot] += sz[qRoot];
	}
}

Union::QuickUnionRank::QuickUnionRank(int count)
{
	parent = new int[count];
	rank = new int[count];
	this->count = count;
	for (int i = 0; i < count; i++)
	{
		parent[i] = i;
		rank[i] = 1;
	}
}

Union::QuickUnionRank::~QuickUnionRank()
{
	delete[] parent;
	delete[] rank;
}

int Union::QuickUnionRank::find(int p)
{
	assert(p >= 0 && p < count);
	while (parent[p] != p)
	{
		p = parent[p];
	}
	return p;
}

bool Union::QuickUnionRank::isConnected(int p, int q)
{
	return find(p) == find(q);
}

void Union::QuickUnionRank::unionItem(int p, int q)
{
	int pRoot = find(p);
	int qRoot = find(q);
	if (pRoot == qRoot)
		return;

	if (rank[pRoot] < rank[qRoot])
	{
		parent[pRoot] = qRoot;
	}
	else if (rank[pRoot] > rank[qRoot])
	{
		parent[qRoot] = pRoot;
	}
	else
	{
		parent[pRoot] = qRoot;
		rank[qRoot] += 1;
	}
}

Union::QuickUnionCompress::QuickUnionCompress(int count)
{
	parent = new int[count];
	rank = new int[count];
	this->count = count;
	for (int i = 0; i < count; i++)
	{
		parent[i] = i;
		rank[i] = 1;
	}
}

Union::QuickUnionCompress::~QuickUnionCompress()
{
	delete[] parent;
	delete[] rank;
}

int Union::QuickUnionCompress::find(int p)
{
	assert(p >= 0 && p < count);
	while (parent[p] != p)
	{
		parent[p] = parent[parent[p]];
		p = parent[p];
	}
	return p;
}

bool Union::QuickUnionCompress::isConnected(int p, int q)
{
	return find(p) == find(q);
}

void Union::QuickUnionCompress::unionItem(int p, int q)
{
	int pRoot = find(p);
	int qRoot = find(q);
	if (pRoot == qRoot)
		return;

	if (rank[pRoot] < rank[qRoot])
	{
		parent[pRoot] = qRoot;
	}
	else if (rank[pRoot] > rank[qRoot])
	{
		parent[qRoot] = pRoot;
	}
	else
	{
		parent[pRoot] = qRoot;
		rank[qRoot] += 1;
	}
}