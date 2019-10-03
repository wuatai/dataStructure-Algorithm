#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;

namespace Graph
{
	// 稠密图 - 邻接矩阵
	class DenseGraph{

	private:
		int n, m;       // 节点数和边数
		bool directed;  // 是否为有向图
		vector<vector<bool>> g; // 图的具体数据

	public:
		// 构造函数
		DenseGraph(int n, bool directed){
			assert(n >= 0);
			this->n = n;
			this->m = 0;    // 初始化没有任何边
			this->directed = directed;
			// g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
			g = vector<vector<bool>>(n, vector<bool>(n, false));
		}

		~DenseGraph(){ }

		int V(){ return n; } // 返回节点个数
		int E(){ return m; } // 返回边的个数

		// 向图中添加一个边
		void addEdge(int v, int w){

			assert(v >= 0 && v < n);
			assert(w >= 0 && w < n);

			if (hasEdge(v, w))
				return;

			g[v][w] = true;
			if (!directed)
				g[w][v] = true;

			m++;
		}

		// 验证图中是否有从v到w的边
		bool hasEdge(int v, int w){
			assert(v >= 0 && v < n);
			assert(w >= 0 && w < n);
			return g[v][w];
		}
	};

	// 稀疏图 - 邻接表
	class SparseGraph{

	private:
		int n, m;       // 节点数和边数
		bool directed;  // 是否为有向图
		vector<vector<int>> g;  // 图的具体数据

	public:
		// 构造函数
		SparseGraph(int n, bool directed){
			assert(n >= 0);
			this->n = n;
			this->m = 0;    // 初始化没有任何边
			this->directed = directed;
			// g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
			g = vector<vector<int> >(n, vector<int>());
		}

		~SparseGraph(){ }

		int V(){ return n; } // 返回节点个数
		int E(){ return m; } // 返回边的个数

		// 向图中添加一个边
		void addEdge(int v, int w){

			assert(v >= 0 && v < n);
			assert(w >= 0 && w < n);

			g[v].push_back(w);
			if (v != w && !directed)
				g[w].push_back(v);

			m++;
		}

		// 验证图中是否有从v到w的边
		bool hasEdge(int v, int w){

			assert(v >= 0 && v < n);
			assert(w >= 0 && w < n);

			for (int i = 0; i < g[v].size(); i++)
			if (g[v][i] == w)
				return true;
			return false;
		}

		// 显示图的信息
		void show(){

			for (int i = 0; i < n; i++){
				cout << "vertex " << i << ":\t";
				for (int j = 0; j < g[i].size(); j++)
					cout << g[i][j] << "\t";
				cout << endl;
			}
		}

		// 邻边迭代器, 传入一个图和一个顶点,
		// 迭代在这个图中和这个顶点向连的所有顶点
		class adjIterator{
		private:
			SparseGraph &G; // 图G的引用
			int v;
			int index;

		public:
			// 构造函数
			adjIterator(SparseGraph &graph, int v) : G(graph){
				this->v = v;
				this->index = 0;
			}

			~adjIterator(){}

			// 返回图G中与顶点v相连接的第一个顶点
			int begin(){
				index = 0;
				if (G.g[v].size())
					return G.g[v][index];
				// 若没有顶点和v相连接, 则返回-1
				return -1;
			}

			// 返回图G中与顶点v相连接的下一个顶点
			int next(){
				index++;
				if (index < G.g[v].size())
					return G.g[v][index];
				// 若没有顶点和v相连接, 则返回-1
				return -1;
			}

			// 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
			bool end(){
				return index >= G.g[v].size();
			}
		};
	};

	// 求图的连通分量
	class Component
	{
	private:
		SparseGraph &G;
		bool *visited;  //是否被遍历
		int ccount; //连通分量个数
		int *id;	//连通标记
	public:
		Component(SparseGraph &graph) : G(graph)
		{
			visited = new bool[G.V()];
			id = new int[G.V()];
			ccount = 0;
			for (int i = 0; i < G.V(); i++)
			{
				visited[i] = false;
				id[i] = -1;
			}

			for (int i = 0; i < G.V(); i++)
			{
				if (!visited[i]){
					dfs(i);
					ccount++;
				}
			}
		}

		~Component()
		{
			delete[] visited;
			delete[] id;
		}

		int count()
		{
			return ccount;
		}

		bool isConnect(int v, int w)
		{
			assert(v >=0 && v < G.V());
			assert(w >= 0 && w < G.V());
			return id[v] == id[w];
		}

	private:
		//深度优先遍历
		void dfs(int v)
		{
			visited[v] = true;
			id[v] = ccount;
			SparseGraph::adjIterator adj(G, v);
			for (int i = adj.begin(); !adj.end(); i = adj.next())
			{
				if (!visited[i])
					dfs(i);
			}
		}
	};

	// 路径查询
	class Path{

	private:
		SparseGraph &G;   // 图的引用
		int s;      // 起始点
		bool* visited;  // 记录dfs的过程中节点是否被访问
		int * from;     // 记录路径, from[i]表示查找的路径上i的上一个节点

		// 图的深度优先遍历
		void dfs(int v){

			visited[v] = true;

			SparseGraph::adjIterator adj(G, v);
			for (int i = adj.begin(); !adj.end(); i = adj.next()){
				if (!visited[i]){
					from[i] = v;
					dfs(i);
				}
			}
		}

	public:
		// 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
		Path(SparseGraph &graph, int s) :G(graph){

			// 算法初始化
			assert(s >= 0 && s < G.V());

			visited = new bool[G.V()];
			from = new int[G.V()];
			for (int i = 0; i < G.V(); i++){
				visited[i] = false;
				from[i] = -1;
			}
			this->s = s;

			// 寻路算法
			dfs(s);
		}

		// 析构函数
		~Path(){

			delete[] visited;
			delete[] from;
		}

		// 查询从s点到w点是否有路径
		bool hasPath(int w){
			assert(w >= 0 && w < G.V());
			return visited[w];
		}

		// 查询从s点到w点的路径, 存放在vec中
		void path(int w, vector<int> &vec){

			assert(hasPath(w));

			stack<int> s;
			// 通过from数组逆向查找到从s到w的路径, 存放到栈中
			int p = w;
			while (p != -1){
				s.push(p);
				p = from[p];
			}

			// 从栈中依次取出元素, 获得顺序的从s到w的路径
			vec.clear();
			while (!s.empty()){
				vec.push_back(s.top());
				s.pop();
			}
		}

		// 打印出从s点到w点的路径
		void showPath(int w){

			assert(hasPath(w));

			vector<int> vec;
			path(w, vec);
			for (int i = 0; i < vec.size(); i++){
				cout << vec[i];
				if (i == vec.size() - 1)
					cout << endl;
				else
					cout << " -> ";
			}
		}
	};

	// 寻找无权图的最短路径
	class ShortestPath{

	private:
		SparseGraph &G;       // 图的引用
		int s;          // 起始点
		bool *visited;  // 记录dfs的过程中节点是否被访问
		int *from;      // 记录路径, from[i]表示查找的路径上i的上一个节点
		int *ord;       // 记录路径中节点的次序。ord[i]表示i节点在路径中的次序。

	public:
		// 构造函数, 寻找无权图graph从s点到其他点的最短路径
		ShortestPath(SparseGraph &graph, int s) :G(graph){

			// 算法初始化
			assert(s >= 0 && s < graph.V());

			visited = new bool[graph.V()];
			from = new int[graph.V()];
			ord = new int[graph.V()];
			for (int i = 0; i < graph.V(); i++){
				visited[i] = false;
				from[i] = -1;
				ord[i] = -1;
			}
			this->s = s;

			// 无向图最短路径算法, 从s开始广度优先遍历整张图
			queue<int> q;

			q.push(s);
			visited[s] = true;
			ord[s] = 0;
			while (!q.empty()){

				int v = q.front();
				q.pop();

				SparseGraph::adjIterator adj(G, v);
				for (int i = adj.begin(); !adj.end(); i = adj.next())
				if (!visited[i]){
					q.push(i);
					visited[i] = true;
					from[i] = v;
					ord[i] = ord[v] + 1;
				}
			}

		}

		// 析构函数
		~ShortestPath(){

			delete[] visited;
			delete[] from;
			delete[] ord;
		}

		// 查询从s点到w点是否有路径
		bool hasPath(int w){
			assert(w >= 0 && w < G.V());
			return visited[w];
		}

		// 查询从s点到w点的路径, 存放在vec中
		void path(int w, vector<int> &vec){

			assert(w >= 0 && w < G.V());

			stack<int> s;
			// 通过from数组逆向查找到从s到w的路径, 存放到栈中
			int p = w;
			while (p != -1){
				s.push(p);
				p = from[p];
			}

			// 从栈中依次取出元素, 获得顺序的从s到w的路径
			vec.clear();
			while (!s.empty()){
				vec.push_back(s.top());
				s.pop();
			}
		}

		// 打印出从s点到w点的路径
		void showPath(int w){

			assert(w >= 0 && w < G.V());

			vector<int> vec;
			path(w, vec);
			for (int i = 0; i < vec.size(); i++){
				cout << vec[i];
				if (i == vec.size() - 1)
					cout << endl;
				else
					cout << " -> ";
			}
		}

		// 查看从s点到w点的最短路径长度
		int length(int w){
			assert(w >= 0 && w < G.V());
			return ord[w];
		}
	};
}
#endif
