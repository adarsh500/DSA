
#include <iostream>
#include<unordered_map>
#include<set>
#include<climits>
#include<list>
using namespace std;
template<typename T>
class Graph{
    private:
    unordered_map<T, list<pair<T, pair<int, int>>>> l;
    int V; // number of vertices

    public:
    void addEdge(T x, T y, int trainFare, int flightFare){
        pair<int, int> p= make_pair(trainFare, flightFare);
        l[x].push_back(make_pair(y, p));
        l[y].push_back(make_pair(x, p));
    }


    unordered_map<T, int> Dijkstra(T source){

        //first set the distance of all the nodes from the source = INT_MAX
        //for that we will maintain a hashmap
        unordered_map<T, int>distance;
        for(pair<T, list<pair<T, pair<int, int>>>> p: l){
            T node= p.first;
            distance[node]= INT_MAX;
        }
        distance[source]=0;

        //let's make a set to store the vertices inorder to get the minimum one
        set<pair<int, T>>s;
        s.insert(make_pair(distance[source], source));
        while(!s.empty()){
            // set<pair<int, T>>::iterator it= s.begin();
            auto it= s.begin();

            T node= (*it).second;
            int nodeDist= (*it).first;

            s.erase(it);

            //now we will update the distance of all the neighbours of the current node.
            for(auto p: l[node]){
                T dest= p.first;                    //neighbour of the node(that we just popped from the set)
                int weight= p.second.first;         // edge weight
                int destDistance= distance[dest];  //current distance of the destination node

                if(nodeDist+ weight < destDistance){
                    auto it2 = s.find(make_pair(destDistance, dest));
                    //agar set me already hai then pop kar do.
                    if(it2 != s.end()){
                        s.erase(it2);
                    }
                    distance[dest]= nodeDist+weight;
                    s.insert(make_pair(distance[dest], dest));
                }
            }
        }
        /*
            for(auto p: l){
                T node= p.first;
                cout<<"Distance of "<<node<<" from "<<source<<" is "<<distance[node]<<endl;
            }
            cout<<"\n\n";
        */
        return distance;
    }

    int mincost(T src, T dest){
        unordered_map<T, int> distance1= Dijkstra(src);
        unordered_map<T, int> distance2= Dijkstra(dest);
        int ans= INT_MAX;
        int cur_value;
        for(auto it= l.begin(); it != l.end(); it++){
            cur_value=0;
            auto p= *it;
            auto ptr= it;
            // ptr= ++ptr;
            T node= p.first;
            
            cur_value= distance1[node];
            //if we are already at the destination, we don't need flight.
            if(ptr != l.end() and node != dest){
                for(auto nbr: l[node]){
                    cur_value= distance1[node];
                    int flightFare= nbr.second.second;
                    cur_value+=(flightFare+distance2[nbr.first]);
                    ans= min(ans, cur_value);
                }
            }
            ans= min(ans, cur_value);
        }
        return ans;
    }


};
int main() {
    Graph<string> india;

    india.addEdge("Amritsar", "Delhi", 1, 2);
    india.addEdge("Amritsar", "Jaipur", 4, 5);
    india.addEdge("Jaipur", "Delhi", 2, 7);
    india.addEdge("Jaipur", "Mumbai", 8, 4);
    india.addEdge("Bhopal", "Agra", 2, 1);
    india.addEdge("Mumbai", "Bhopal", 3, 3);
    india.addEdge("Agra", "Delhi", 1, 6);
    

    cout<<india.mincost("Amritsar", "Bhopal")<<endl;
}
