import java.util.*;

class Solution {
    public int[] solution(int[][] edges) {
        int[] answer = {0, 0, 0, 0};
        
        Node[] nodes = new Node[1000005];
        Set<Integer> indices = new TreeSet<>();
        
        for (int[] edge : edges) {
            if (nodes[edge[0]] == null)  {
                nodes[edge[0]] = new Node();
                indices.add(edge[0]);
            }
            
            if (nodes[edge[1]] == null) {
                nodes[edge[1]] = new Node();
                indices.add(edge[1]);
            }
            
            nodes[edge[0]].addDestination(nodes[edge[1]]);
            nodes[edge[1]].addSource(nodes[edge[0]]);
        }
        
        for (int i : indices) {
            Node node = nodes[i];
            if (node.indegree() == 0 && node.outdegree() > 1) { 
                answer[0] = i;
                break;
            }
        }
        
        Node generated = nodes[answer[0]];
        int graphSize = generated.removeEdges();
        nodes[answer[0]] = null;
        indices.remove(answer[0]);
        
        int stick = 0;
        for (int i : indices) {
            Node node = nodes[i];
            if (node.indegree() == 0) stick++;
        }
        
        answer[2] = stick;
        
        int eight = 0;
        for (int i : indices) {
            Node node = nodes[i];
            if (node.indegree() == 2 && node.outdegree() == 2) eight++;
        }
        
        answer[3] = eight;
        
        answer[1] = graphSize - stick - eight;
        return answer;
    }
}

class Node {
    private Set<Node> sources = new HashSet<>();
    private Set<Node> destinations = new HashSet<>();
    
    public void addSource(Node source) {
        sources.add(source);
    }
    
    public void addDestination(Node destination) {
        destinations.add(destination);
    }
    
    public void removeSource(Node source) {
        sources.remove(source);
    }
    
    public void removeDestination(Node destination) {
        destinations.remove(destination);
    }
    
    public int indegree() {
        return sources.size();
    }
    
    public int outdegree() {
        return destinations.size();
    }
    
    public int removeEdges() {
        int res = outdegree();
        for (Node destination : destinations) destination.removeSource(this);
        destinations = null;
        return res;
    }
}