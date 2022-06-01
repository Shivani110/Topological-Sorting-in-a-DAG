#include<bits/stdc++.h>
#include<list>
#include<stack>
using namespace std;

class T_Graph 
{
	int N;
	list<int>* adjacent;
	
void Topological_Sortfn(int x, bool Visit[], stack<int>& S)
{
	Visit[x] = true;
	list<int> ::iterator a;
	for (a = adjacent[x].begin(); a != adjacent[x].end(); ++a)
		if (!Visit[*a])
			Topological_Sortfn(*a, Visit, S);
	S.push(x);
}

public :
	T_Graph(int N)
	{
		this->N = N;
		adjacent = new list<int>[N];
	}
	
void edge_add(int s, int d)
{
	adjacent[s].push_back(d); 
}	

void topologicalsorting()
{
	stack<int> S;
	bool* Visit = new bool[N];
	for (int a = 0; a < N; a++)
		Visit[a] = false;
	for (int a = 0; a < N; a++)
		if (Visit[a] == false)
			Topological_Sortfn(a, Visit, S);
	while (S.empty() == false) 
	{
		cout << S.top() << " ";
		S.pop();
	}
}
};
int main()
{
	T_Graph o(7);
	o.edge_add(5, 2);
	o.edge_add(5, 0);
	o.edge_add(4, 0);
	o.edge_add(4, 3);
	o.edge_add(3, 3);
	o.edge_add(3, 2);
	o.edge_add(3, 1);
	o.edge_add(2, 1);
	
	cout << "Topological Sorting in a DAG :";
    o.topologicalsorting();
    return 0;
}
