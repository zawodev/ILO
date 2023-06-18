import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class Main {

    private static class GUI {
        private JLabel labelName;
        private JLabel labelID1;
        private JLabel labelID2;
        private JLabel labelWeight;
        private JTextField textFieldName;
        private JTextField textFieldID1;
        private JTextField textFieldID2;
        private JTextField textFieldWeight;
        private JTextArea textAreaOutput;
        private JButton addNodeButton;
        private JButton removeNodeButton;
        private JButton addEdgeButton;
        private JButton newRandomGraphButton;
        private JButton newGraphButton;
        private JButton newExampleGraphButton;
        private JButton newRNGGraphButton;
        private JButton newGGGraphButton;
        private JButton setStartEndButton;
        private JButton switchDirectedButton;
        private JFrame frame;
        private JPanel inputPanel;
        private JPanel buttonPanel;
        private DrawGraph drawGraphComponent;
        class AddNode implements ActionListener {
            @Override
            public void actionPerformed(ActionEvent e){
                try {
                    String name = textFieldName.getText();
                    graph.addNode(name);
                    printGraph();
                }
                catch (Exception exception){
                    exception.printStackTrace();
                }
            }
        }
        class AddEdge implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                try {
                    int id1 = Integer.parseInt(textFieldID1.getText());
                    int id2 = Integer.parseInt(textFieldID2.getText());
                    int weight = Integer.parseInt(textFieldWeight.getText());
                    graph.connect(id1, id2, weight);
                    printGraph();
                }
                catch (Exception exception){
                    exception.printStackTrace();
                }
            }
        }
        class SetStartEnd implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                try {
                    int id1 = Integer.parseInt(textFieldID1.getText());
                    int id2 = Integer.parseInt(textFieldID2.getText());
                    startNodeID = id1;
                    endNodeID = id2;
                    printGraph();
                }
                catch (Exception exception){
                    exception.printStackTrace();
                }
            }
        }
        class SwitchDirected implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                graph.setDirected(!graph.directed);
                directedButtonFix();
                printGraph();
            }
        }
        public void directedButtonFix(){
            if(graph.directed) switchDirectedButton.setText("Zmień na Nieskierowany");
            else switchDirectedButton.setText("Zmień na Skierowany");
        }
        class CreateGraph implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                graph = new Graph();
                directedButtonFix();
                startNodeID = 0;
                endNodeID = 0;
                printGraph();
            }
        }
        class CreateRNGGraph implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                //int nodeCount = random.nextInt(1, 11);
                //startNodeID = random.nextInt(0, nodeCount);
                //endNodeID = random.nextInt(0, nodeCount);
                //graph = new Graph(nodeCount, 10, false);
                graph.setDirected(false); //probably useless

                graph = convertRNG();
                graph.setDirected(false);
                directedButtonFix();

                printGraph();
            }
        }
        public Graph convertRNG(){
            Graph outputGraph = new Graph();

            for (int i = 0; i < graph.nodes.size(); i++) {
                outputGraph.addNode("N" + i);
            }

            for (int i = 0; i < graph.nodes.size(); i++) {
                for (int j = 0; j < graph.nodes.size(); j++) {
                    int dist_ij = graph.nodes.get(i).getEdgeWeight(graph.nodes.get(j));
                    if(CCC(i, j, dist_ij)) outputGraph.connect(graph.nodes.get(i).id, graph.nodes.get(j).id, dist_ij);
                }
            }
            return outputGraph;
        }
        private boolean CCC(int i, int j, int dist_ij){
            for (int x = 0; x < graph.nodes.size(); x++) {
                int dist_ix = graph.nodes.get(i).getEdgeWeight(graph.nodes.get(x));
                int dist_xj = graph.nodes.get(x).getEdgeWeight(graph.nodes.get(j));
                if (dist_xj * dist_ix * dist_ij != 0){
                    if (Math.max(dist_ix, dist_xj) < dist_ij) return false;
                }
            }
            return true;
        }
        class CreateGGGraph implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                graph = new Graph();
                directedButtonFix();

                printGraph();
            }
        }
        class CreateExampleGraph implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                graph = new Graph();
                directedButtonFix();

                startNodeID = 0;
                endNodeID = 3;

                graph.addNode("N0");
                graph.addNode("N1");
                graph.addNode("N2");
                graph.addNode("N3");
                graph.addNode("N4");
                graph.connect(0, 3, 9);
                graph.connect(0, 1, 1);
                graph.connect(1, 2, 2);
                graph.connect(2, 3, 3);

                printGraph();
            }
        }
        class CreateRandomGraph implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                int nodeCount = random.nextInt(1, 11);
                startNodeID = random.nextInt(0, nodeCount);
                endNodeID = random.nextInt(0, nodeCount);
                graph = new Graph(nodeCount, 20, graph.directed);
                directedButtonFix();
                printGraph();
            }
        }
        private void printGraph(){
            textFieldID1.setText("");
            textFieldID2.setText("");
            textFieldWeight.setText("");
            textFieldName.setText("");
            dijkstra.run(graph, startNodeID, endNodeID);
            textAreaOutput.setText("StartNode: " + startNodeID + ", EndNode: " + endNodeID + "\nDijkstra shortest path length: " + dijkstra.getShortestPathLength() + "\nDijkstra Shortest Path: " + dijkstra.shortestPath + "\nGraph: " + graph.toString());
            drawGraphComponent.draw();
            //panel3 = new DrawCircleFrame(graph.nodes.size());
            //panel3.repaint();
        }
        public void run(){
            textAreaOutput = new JTextArea();
            textAreaOutput.setRows(19);
            textAreaOutput.setEditable(false);

            labelName = new JLabel("Name", SwingConstants.CENTER);
            labelID1 = new JLabel("ID1", SwingConstants.CENTER);
            labelID2 = new JLabel("ID2", SwingConstants.CENTER);
            labelWeight = new JLabel("Weight", SwingConstants.CENTER);

            textFieldName = new JTextField();
            textFieldID1 = new JTextField();
            textFieldID2 = new JTextField();
            textFieldWeight = new JTextField();

            addNodeButton = new JButton("Dodaj Nowy Węzęł");
            addNodeButton.addActionListener(new AddNode());

            removeNodeButton = new JButton("Usun Węzęł"); //asjuhsdahigdfaighjdifahgiohgiad
            removeNodeButton.addActionListener(new AddNode());

            addEdgeButton = new JButton("Dodaj Nową Krawędź");
            addEdgeButton.addActionListener(new AddEdge());

            setStartEndButton = new JButton("Ustaw Start i End");
            setStartEndButton.addActionListener(new SetStartEnd());

            switchDirectedButton = new JButton("Zmień na Nieskierowany");
            switchDirectedButton.addActionListener(new SwitchDirected());

            newGraphButton = new JButton("Wyczyść Graf");
            newGraphButton.addActionListener(new CreateGraph());

            newRNGGraphButton = new JButton("Nowy Graf RNG");
            newRNGGraphButton.addActionListener(new CreateRNGGraph());

            newGGGraphButton = new JButton("Nowy Graf GG");
            newGGGraphButton.addActionListener(new CreateGGGraph());

            newExampleGraphButton = new JButton("Wyświetl Przykładowy Graf");
            newExampleGraphButton.addActionListener(new CreateExampleGraph());

            newRandomGraphButton = new JButton("Wylosuj Nowy Graf");
            newRandomGraphButton.addActionListener(new CreateRandomGraph());

            inputPanel = new JPanel();
            inputPanel.setLayout(new GridLayout(1,8));
            inputPanel.add(labelName);
            inputPanel.add(textFieldName);
            inputPanel.add(labelID1);
            inputPanel.add(textFieldID1);
            inputPanel.add(labelID2);
            inputPanel.add(textFieldID2);
            inputPanel.add(labelWeight);
            inputPanel.add(textFieldWeight);

            drawGraphComponent = new DrawGraph();

            buttonPanel = new JPanel();
            buttonPanel.setLayout(new GridLayout(2,5));
            buttonPanel.add(addNodeButton);
            buttonPanel.add(removeNodeButton);
            buttonPanel.add(addEdgeButton);
            buttonPanel.add(setStartEndButton);
            buttonPanel.add(switchDirectedButton);
            buttonPanel.add(newGraphButton);
            buttonPanel.add(newRNGGraphButton);
            buttonPanel.add(newGGGraphButton);
            buttonPanel.add(newExampleGraphButton);
            buttonPanel.add(newRandomGraphButton);


            frame = new JFrame("Dijkstra");
            frame.setVisible(true);
            frame.setSize(1500,800);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setResizable(true);

            frame.add(textAreaOutput, BorderLayout.WEST);
            frame.add(inputPanel, BorderLayout.NORTH);
            frame.add(buttonPanel, BorderLayout.SOUTH);
            frame.add(drawGraphComponent, BorderLayout.CENTER);

            printGraph();
        }
    }
    public static Graph graph = new Graph();
    public static int startNodeID = 0;
    public static int endNodeID = 3;
    public static Random random = new Random();
    public static Dijkstra dijkstra = new Dijkstra();
    public static GUI gui = new GUI();

    public static void main(String[] args) {

        graph.setDirected(false);
        graph.addNode("N0");
        graph.addNode("N1");
        graph.addNode("N2");
        graph.addNode("N3");
        graph.connect(0, 2, 8);
        graph.connect(2, 3, 5);
        graph.connect(3, 0, 5);
        graph.connect(1, 0, 3);

        dijkstra.run(graph, startNodeID, endNodeID);
        System.out.println("StartNode: " + startNodeID + ", EndNode: " + endNodeID);
        System.out.println(graph);
        System.out.println("Dijkstra shortest path length: " + dijkstra.getShortestPathLength());
        System.out.println("Dijkstra shortest path: " + dijkstra.shortestPath);

        gui.run();
    }
}