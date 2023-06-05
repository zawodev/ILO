import javax.swing.*;
import java.awt.*;

public class DrawCircleFrame extends JPanel {

    private int numPoints = 10;  // Liczba punktów
    private int thickness = 30;
    private int radius = 150;   // Promień koła
    private int centerX = 250;  // Współrzędna x środka koła
    private int centerY = 250;  // Współrzędna y środka koła

    public DrawCircleFrame(int numPoints) {
        //setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.numPoints = numPoints;
        setSize(500, 500);
        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(Color.RED);

        // Oblicz kąt między punktami
        double angle = 2 * Math.PI / numPoints;

        for (int i = 0; i < numPoints; i++) {
            // Oblicz współrzędne punktu
            int x = (int) (centerX + radius * Math.cos(i * angle));
            int y = (int) (centerY + radius * Math.sin(i * angle));

            // Narysuj punkt jako kółko
            g.fillOval(x, y, thickness, thickness);
        }
    }
    private void drawLine(Graphics g) {
        g.setColor(Color.BLUE);
        g.drawLine(point1.x, point1.y, point2.x, point2.y);
    }

    public static void main(String[] args) {
        //SwingUtilities.invokeLater(() -> new CirclePoints());
    }
}
