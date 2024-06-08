#include "Graph.h"
#include "DisjointSet.cpp"
#include <fstream>
#include <sstream>
#include <queue>
#include <limits.h>
#include <cfloat>
#include <algorithm>
#include <unordered_set>


void Graph::addEdge(const string& u, const string& v, double w) {
    edges.emplace_back(w, u, v);
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

Graph::Graph(const char* const & edgelist_csv_fn) { 
    numEdges = 0;  
    ifstream edgeList(edgelist_csv_fn);      
    string line;         
    while(getline(edgeList, line)) {
        istringstream ss(line);           
        string u, v, w;                   
        getline(ss, u, ',');  
        getline(ss, v, ',');      
        getline(ss, w, '\n');    

        addEdge(u, v, stod(w));        
        ++numEdges;
    }
    numNodes = adj.size();
    sort(edges.begin(), edges.end()); 

    edgeList.close();                
}

unsigned int Graph::num_nodes() {
    return numNodes;
}

vector<string> Graph::nodes() {
    vector<string> nodeLabels;
    for (const auto& node : adj) {
         nodeLabels.push_back(node.first);
    }
    return nodeLabels;
}

unsigned int Graph::num_edges() {
    return numEdges;
}

unsigned int Graph::num_neighbors(string const & node_label) {
    return adj[node_label].size();
}

double Graph::edge_weight(string const & u_label, string const & v_label) {
    auto uVector = adj[u_label];
    for (auto it = uVector.begin(); it != uVector.end(); ++it) {
        if (it->first == v_label) {
            return it->second;
        }
    }
    return -1;
}

vector<string> Graph::neighbors(string const & node_label) {
    vector<string> nodeNeighbors;
    auto uVector = adj[node_label];
    for (auto it = uVector.begin(); it != uVector.end(); ++it) {
        nodeNeighbors.push_back(it->first);
    }
    return nodeNeighbors;
}

void Graph::unweightedBFS(string const & startLabel, unordered_map<string, pair<string, int>> & nodeDistances) {
    queue<string> nodeQueue;
    nodeDistances[startLabel].second = 0;
    nodeQueue.push(startLabel);

    while (!nodeQueue.empty()) {
        string currLabel = nodeQueue.front();
        nodeQueue.pop();

        for (string neighborLabel: neighbors(currLabel)) {
            int currDistance = nodeDistances[currLabel].second;
            pair<string, int>* neighborNode = &nodeDistances[neighborLabel];
            string* neighborParent = &neighborNode->first;
            int* neighborDistance = &neighborNode->second;

            if (*neighborDistance != INT_MAX) { continue; }
            *neighborParent = currLabel;
            *neighborDistance = currDistance + 1;
            nodeQueue.push(neighborLabel);
        }
    }
}

vector<string> Graph::shortest_path_unweighted(string const & start_label, string const & end_label) {
    unordered_map<string, pair<string, int>> nodeDistances;

    vector<string> nodeLabels = nodes();
    for (string node: nodeLabels) {
        nodeDistances[node] = make_pair("", INT_MAX);
    }

    unweightedBFS(start_label, nodeDistances);

    vector<string> pathNodes;
    if (nodeDistances[end_label].second == INT_MAX) {
        return pathNodes;
    }

    pathNodes.push_back(end_label);
    string parentNode = nodeDistances[end_label].first;
    string currentNode = end_label;
    while (parentNode != "") {
        pathNodes.insert(pathNodes.begin(), parentNode);
        currentNode = parentNode;
        parentNode = nodeDistances[currentNode].first;
    }

    return pathNodes;
}

vector<tuple<string,string,double>> Graph::shortest_path_weighted(string const & start_label, string const & end_label) {
    vector<tuple<string, string, double>> path;
    if (start_label == end_label) {
        path.emplace_back(start_label, start_label, -1);
    }
    
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;
    unordered_map<string, double> nodeDistances;
    unordered_map<string, string> nodeParents;

    for (auto node : adj) {
        nodeDistances[node.first] = DBL_MAX;
    }
    
    nodeDistances[start_label] = 0;
    pq.push({0, start_label});

    while (!pq.empty()) {
        auto curr = pq.top().second;
        pq.pop();

        for (auto neighbor : adj[curr]) {
            string edgeLabel = neighbor.first;
            double edgeWeight = neighbor.second;

            if (nodeDistances[curr] + edgeWeight < nodeDistances[edgeLabel]) {
                nodeDistances[edgeLabel] = nodeDistances[curr] + edgeWeight;
                nodeParents[edgeLabel] = curr;
                pq.push({nodeDistances[edgeLabel], edgeLabel});
            }
        }
    }

    if (nodeDistances[end_label] == DBL_MAX) {
        return {};
    }

    string currNode = end_label;
    while (currNode != start_label) {
        string prevNode = nodeParents[currNode];
        double edgeWeight = nodeDistances[currNode] - nodeDistances[prevNode];
        path.emplace_back(prevNode, currNode, edgeWeight);
        currNode = prevNode;
    }
    reverse(path.begin(), path.end());
    return path;
}


vector<string> Graph::componentBFS(string const & startLabel, double const & threshold) {
    queue<string> nodeQueue;
    unordered_map<string, bool> visitedNodes; 

    nodeQueue.push(startLabel);
    while (!nodeQueue.empty()) {
        string currLabel = nodeQueue.front();
        nodeQueue.pop();

        if (visitedNodes[currLabel]) { continue; }
        visitedNodes[currLabel] = true;

        for (auto neighbor: adj[currLabel]) {
            string neighborLabel = neighbor.first;
            if (visitedNodes[neighborLabel]) { continue; }

            double edgeWeight = neighbor.second;            
            if (edgeWeight > threshold) { continue; }

            nodeQueue.push(neighborLabel);
        }
    }

    vector<string> component;
    for (auto it = visitedNodes.begin(); it != visitedNodes.end(); ++it) {
        if (visitedNodes[it->first]) {
            component.push_back(it->first);
        }
    }
    return component;
}

vector<vector<string>> Graph::connected_components(double const & threshold) {
    vector<vector<string>> components;
    unordered_set<string> unvisitedNodes;
    for (string node: nodes()) {
        unvisitedNodes.insert(node);
    }

    while (!unvisitedNodes.empty()) {
        string currLabel = *unvisitedNodes.begin();
        vector<string> component = componentBFS(currLabel, threshold);
        for (string node: component) {
            unvisitedNodes.erase(node);
        }
        components.push_back(component);
    }

    return components;
}


double Graph::smallest_connecting_threshold(string const & start_label, string const & end_label) {
    if (start_label == end_label) {
        return 0;
    }

    DisjointSet* ds = new DisjointSet(nodes());
    for (auto edge: edges) {
        double weight = get<0>(edge);
        string x = get<1>(edge);
        string y = get<2>(edge);

        ds->unionSets(x, y);
        if (ds->find(start_label) == ds->find(end_label)) {
            delete(ds);
            return weight;
        }
    }
    delete(ds);
    return -1;
}
