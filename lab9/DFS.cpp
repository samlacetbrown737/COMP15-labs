void DFS(G, vertex) {
    vertex->found = true;
    for(int  i = 0; i < adjacentEdges; i++) {
        if(!i->found) {
            i->found = true;
        }
        else {
            DFS(G, i);
        }
    }
}