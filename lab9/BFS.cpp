Node* BFS(G, root) {
    queue<*Node> explore;
    int prev[numNodes];
    for(int i = 0; i < numNodes; i++) {
        prev[i] = -1;
    }
    explore.push(root);
    mark(root);
    while(!explore.empty()) {
        Node *current = Q.top();
        Q.pop();
        for(adjacentEdges) {
            if(!edge(marked)) {
                explore.push;
                mark(edge);
            }
        }
        if(current == goal) {
            return current;
        }
    }
    return nullptr;
}
//dfs can just use a stack instead