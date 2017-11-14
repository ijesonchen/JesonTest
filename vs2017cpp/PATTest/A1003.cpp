/*
TIP:
shortest path, non-neg weight
alg1: x 可能会漏掉（中间某些等长路径）
	1. 计算最短路径sp
	2. Dijkstra，每次u-v长度为sp时，记录路径数量及team
alg2: x 同上
	Dijkstra，每次碰到U-V路径时，判断当前SP是否最小，并记录路径数量及team数
alg3: dp+Dijkstra
	节点u-v
	每个节点保存l：最短路径长度，n：最短路径数量，t：最大team数
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

using namespace std;

class A1003Graph
{
private:
	struct Edge
	{
		int t = -1; // to indx;
		int w = -1; // weight
	};

	struct Dist
	{
		int l = -1; // length of SP
		int n = -1; // count of SP
		int t = -1; // max team
	};

	vector<int> teams;
	vector<vector<Edge>> adj;
	int src = -1;
	int dst = -1;
public:
};

void A1003(void)
{
	;
}