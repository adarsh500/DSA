//  Count the number of disjoint components (subgraphs which are not connected to each other)
// and store them in a variable , say 'components'// Each component must have a single Temple
// So cost of temple in each component is A * components// Further there are (x-1) roads 
// required in each component where x is no of vertices in that component. Sum of roads in 
// all components = (n - components) , n is no of nodes in adjacency list Multiply that with B , 
// cost to repair each road Cost so far , cost = A*component + B * (n-components)
// But there are some vertices that do not form any edges Some vertices which stand alone 
// and each of these vertices must have a temple of its own Since they do not form any edge , 
// there count is not included in the adjacency list No of such nodes is (V - n) 
// ...where V is total no of nodes and n is no of nodes that form an edge and are 
// part of previously counted components Since each of these nodes must have a 
// temple Total cost = A*components + B*(n-component) + A*(V-n)

// Do not forget to consider the base case when A<=B. If cost of constructing temples in each 
// city is less than repairing roads , simply build temples in all cities and return V*A .
// C++ Code


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int

class Graph
{
private:
    ll V;
    map<ll, list<ll>> adjList;

public:
    Graph(ll v)
    {
        V = v;
    }
    void addEdge(ll u, ll v)
    {
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(ll node, map<ll, bool> &visited)
    {

        visited[node] = true;

        for (ll child : adjList[node])
        {
            if (!visited[child])
            {
                dfsHelper(child, visited);
            }
        }
    }

    ll dfsReligiousPeople(ll src, ll a, ll b)
    {

        //If cost of constructing temples in each city is less than repairing roads , simply build temples in all cities
        if (a <= b)
        {
            return V * a;
        }

        map<ll, bool> visited;
        ll components = 1;
        dfsHelper(src, visited);

        for (auto i : adjList)
        {
            ll city = i.first;
            if (!visited[city])
            {
                dfsHelper(city, visited);
                components++;
            }
        }

        ll n = adjList.size();
        ll totalCost = a * components + b * (n - components) + a * (V - n);

        return totalCost;
    }
};

int main()
{
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll n; //No of cities (nodes)
        ll m; //No of roads  (edges)
        ll a; //Cost to construct a temple
        ll b; //Cost to repair a road

        cin >> n >> m >> a >> b;

        Graph g(n);
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        //  g.printAdjList();

        cout << g.dfsReligiousPeople(1, a, b) << endl;
    }

    return 0;
}
