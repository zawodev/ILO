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
        private JButton addEdgeButton;
        private JButton newRandomGraphButton;
        private JButton newGraphButton;
        private JButton newExampleGraphButton;
        private JButton setStartEndButton;
        private JButton switchDirectedButton;
        private JFrame frame;
        private JPanel panel1;
        private JPanel panel2;
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
                graph.directed = !graph.directed;
                if(graph.directed) switchDirectedButton.setText("Zmień na Nieskierowany");
                else switchDirectedButton.setText("Zmień na Skierowany");
                printGraph();
            }
        }
        class CreateGraph implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                graph = new Graph();
                startNodeID = 0;
                endNodeID = 0;
                printGraph();
            }
        }
        class CreateExampleGraph implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){
                graph = new Graph();

                startNodeID = 0;
                endNodeID = 3;

                graph.addNode("0");
                graph.addNode("1");
                graph.addNode("2");
                graph.addNode("3");
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
                printGraph();
            }
        }
        private void printGraph(){
            textFieldID1.setText("");
            textFieldID2.setText("");
            textFieldWeight.setText("");
            textFieldName.setText("");
            textAreaOutput.setText("StartNode: " + startNodeID + ", EndNode: " + endNodeID + "\nDijkstra shortest path length: " + dijkstra.getShortestPath(graph, startNodeID, endNodeID) + "\n" + graph.toString());
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

            addEdgeButton = new JButton("Dodaj Nową Krawędź");
            addEdgeButton.addActionListener(new AddEdge());

            setStartEndButton = new JButton("Ustaw Start i End");
            setStartEndButton.addActionListener(new SetStartEnd());

            switchDirectedButton = new JButton("Zmień na Nieskierowany");
            switchDirectedButton.addActionListener(new SwitchDirected());

            newGraphButton = new JButton("Wyczyść Graf");
            newGraphButton.addActionListener(new CreateGraph());

            newExampleGraphButton = new JButton("Wyświetl Przykładowy Graf");
            newExampleGraphButton.addActionListener(new CreateExampleGraph());

            newRandomGraphButton = new JButton("Wylosuj Nowy Graf");
            newRandomGraphButton.addActionListener(new CreateRandomGraph());

            panel1 = new JPanel();
            panel1.setLayout(new GridLayout(1,8));
            panel1.add(labelName);
            panel1.add(textFieldName);
            panel1.add(labelID1);
            panel1.add(textFieldID1);
            panel1.add(labelID2);
            panel1.add(textFieldID2);
            panel1.add(labelWeight);
            panel1.add(textFieldWeight);

            panel2 = new JPanel();
            panel2.setLayout(new GridLayout(1,7));
            panel2.add(addNodeButton);
            panel2.add(addEdgeButton);
            panel2.add(setStartEndButton);
            panel2.add(switchDirectedButton);
            panel2.add(newGraphButton);
            panel2.add(newExampleGraphButton);
            panel2.add(newRandomGraphButton);


            frame = new JFrame("Drzewa BST oraz RBT");
            frame.setVisible(true);
            frame.setSize(1500,400);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setResizable(false);

            frame.add(textAreaOutput, BorderLayout.NORTH);
            frame.add(panel1, BorderLayout.CENTER);
            frame.add(panel2, BorderLayout.SOUTH);

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

        graph.addNode("0");
        graph.addNode("1");
        graph.addNode("2");
        graph.addNode("3");
        graph.connect(0, 3, 9);
        graph.connect(0, 1, 1);
        graph.connect(1, 2, 2);
        graph.connect(2, 3, 3);

        System.out.println("StartNode: " + startNodeID + ", EndNode: " + endNodeID);
        System.out.println(graph);
        System.out.println("Dijkstra shortest path length: " + dijkstra.getShortestPath(graph, startNodeID, endNodeID));

        gui.run();
    }
}