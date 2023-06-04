import java.util.ArrayList;
import java.util.List;

public class Dijkstra {
    public int getShortestPath(Graph graph, int startNodeID, int endNodeID){
        try {
            Node start = graph.nodes.get(startNodeID);
            Node end = graph.nodes.get(endNodeID);
            dijkstra(graph, start);
            return end.dist;
        }
        catch (Exception e){
            return -1;
        }
    }
    private int minDistance(int dist[], Boolean sptSet[], int nodesCount) {
        int min = Integer.MAX_VALUE, min_index = -1;
        for (int v = 0; v < nodesCount; v++)
            if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        return min_index;
    }
    private void dijkstra(Graph graph, Node start){
        int nodesCount = graph.nodes.size();
        int src = start.id;

        int dist[] = new int[nodesCount];
        Boolean sptSet[] = new Boolean[nodesCount];

        for (int i = 0; i < nodesCount; i++) {
            dist[i] = Integer.MAX_VALUE;
            graph.nodes.get(i).dist = Integer.MAX_VALUE;
            sptSet[i] = false;
        }

        dist[src] = 0;
        graph.nodes.get(src).dist = 0;

        for (int i = 0; i < nodesCount - 1; i++) {
            int u = minDistance(dist, sptSet, nodesCount);

            sptSet[u] = true;

            for (int v = 0; v < nodesCount; v++) {
                int val = graph.nodes.get(u).getEdgeWeight(graph.nodes.get(v));
                if (!sptSet[v] && val != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + val < dist[v]){
                    dist[v] = dist[u] + val;
                    graph.nodes.get(v).dist = graph.nodes.get(u).dist + val;
                }
            }
        }
    }
}
