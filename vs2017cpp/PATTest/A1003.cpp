/*
TIP:
shortest path, non-neg weight
alg1: x ���ܻ�©�����м�ĳЩ�ȳ�·����
	1. �������·��sp
	2. Dijkstra��ÿ��u-v����Ϊspʱ����¼·��������team
alg2: x ͬ��
	Dijkstra��ÿ������U-V·��ʱ���жϵ�ǰSP�Ƿ���С������¼·��������team��
alg3: dp+Dijkstra
	�ڵ�u-v
	ÿ���ڵ㱣��l�����·�����ȣ�n�����·��������t�����team��
	if edge(u,v) selected:
		calc new v(l,n,t) from u
		if new v.l > old v.l: ignore
		if new v.l = old v.l: dup path, add n, replace t if bigger
		if new v.l < old v.l: shorter path, relpace l,n,t
	
1003. Emergency (25)
As an emergency rescue team leader of a city, you are given a special 
map of your country. The map shows several scattered cities connected 
by some roads. Amount of rescue teams in each city and the length of each 
road between any pair of cities are marked on the map. When there is an 
emergency call to you from some other city, your job is to lead your men 
to the place as quickly as possible, and at the mean time, call up as many 
hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line 
contains 4 positive integers: N (<= 500) - the number of cities (and the 
cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the 
cities that you are currently in and that you must save, respectively. 
The next line contains N integers, where the i-th integer is the number of 
rescue teams in the i-th city. Then M lines follow, each describes a road 
with three integers c1, c2 and L, which are the pair of cities connected by 
a road and the length of that road, respectively. It is guaranteed that there 
exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different 
shortest paths between C1 and C2, and the maximum amount of rescue teams you 
can possibly gather.
All the numbers in a line must be separated by exactly one space, and there 
is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/

#include <vector>
#include <iostream>
#include "patMain.h"

using namespace std;

class A1003Graph
{
private:
	struct Edge
	{
		int v = -1; // dst node
		int w = -1; // weight

		Edge(int _v, int _w) : v(_v), w(_w) {};
	};

	struct Node
	{
		int t = 0; // team count
		int s = 0; // length of SP
		int c = 0; // count of SP
		int r = 0; // total rescue team
		Node() {};
	};

	vector<Node> nodes;
	vector<vector<Edge>> adjs;
	int src = -1;
	int dst = -1;
public:
	void Read(void);
};

void A1003Graph::Read(void)
{
	int n, m, a;
	cin >> n >> m >> src >> dst;
	nodes.assign(n, Node());
	adjs.assign(n, vector<Edge>());
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		nodes[i].t = a;
	}
	int u, v, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		adjs[u].emplace_back(v, w);
		adjs[v].emplace_back(u, w);
	}
}

void A1003(void)
{
	RedirCin("data\\A1003-1.TXT");
	A1003Graph g;
	g.Read();
}