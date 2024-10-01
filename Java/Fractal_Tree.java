import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;


public class Fractal_Tree extends JPanel {

    private static final long serialVersionUID = 1L;

    public Fractal_Tree() {
    }

    private void drawTree(Graphics g, int x1, int y1, double angle, int depth) {
        if (depth == 0) return;
        int x2 = x1 + (int) (Math.cos(Math.toRadians(angle)) * depth * 12.0);
        int y2 = y1 + (int) (Math.sin(Math.toRadians(angle)) * depth * 12.0);
        g.drawLine(x1, y1, x2, y2);
        drawTree(g, x2, y2, angle - 20, depth - 1);
        drawTree(g, x2, y2, angle + 20, depth - 1);
    }

    @Override
    public void paintComponent(Graphics g) {
        g.setColor(Color.DARK_GRAY);
        drawTree(g, getWidth() / 2, getHeight(), -90, 10);
    }

    public static void main(String... args) {
        final JFrame frame = new JFrame("Fractal Tree");
        SwingUtilities.invokeLater(new Runnable() {

            @Override
            public void run() {
                frame.setContentPane(new Fractal_Tree());
                frame.setSize(1000, 700);
                frame.setLocationRelativeTo(null);
                frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                frame.setResizable(true);
                frame.setVisible(true);
            }
        });
    }
}

