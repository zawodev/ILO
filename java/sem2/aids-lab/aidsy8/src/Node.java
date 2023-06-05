import java.util.ArrayList;
import java.util.List;

public class Node {
    public Node(int id, String name){
        this.id = id;
        this.name = name;
        outEdges = new ArrayList<>();
        inEdges = new ArrayList<>();
        path = new ArrayList<>();
    }
    public void connectTo(Node node, int weight){
        Edge edge = new Edge(this, node, weight);

        for (Edge _edge : outEdges){
            if(_edge.compareTo(edge) == 0){
                outEdges.remove(_edge);
                break;
            }
        }
        for (Edge _edge : inEdges){
            if(_edge.compareTo(edge) == 0){
                inEdges.remove(_edge);
                break;
            }
        }

        //if(inEdges.contains(edge)) inEdges.remove(edge);

        this.outEdges.add(edge);
        node.inEdges.add(edge);
    }
    public int getEdgeWeight(Node node){
        for(Edge edge : outEdges){
            if(edge.endNode == node) return edge.weight;
        }
        return 0;
    }
    public String toString(){
        return name;
    }
    public int id;
    public String name;
    public List<Node> path;
    public int dist;
    public List<Edge> outEdges;
    public List<Edge> inEdges;
}
