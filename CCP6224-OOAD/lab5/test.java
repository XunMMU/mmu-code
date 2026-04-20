import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class test extends JFrame {

  // Coordinates of the brush
  private int x = -1;
  private int y = -1;

  // Simple drawing panel
  private class DrawArea extends JPanel {

    public DrawArea() {
      setBackground(Color.WHITE);
    }

    @Override
    protected void paintComponent(Graphics g) {
      super.paintComponent(g);

      // Draw a small circle at (x, y)
      g.setColor(Color.BLACK);
      g.fillOval(x, y, 10, 10);
    }
  }

  public test() {
    super("Step 1 - Basic Drawing");

    DrawArea canvas = new DrawArea();

    add(canvas, BorderLayout.CENTER);

    // Info label at bottom
    JPanel toolbar = new JPanel();

    toolbar.add(new JLabel("Drag mouse to draw (basic version)"));

    add(toolbar, BorderLayout.SOUTH);

    // Mouse dragging to move the dot
    canvas.addMouseMotionListener(new MouseMotionAdapter() {
      @Override
      public void mouseDragged(MouseEvent e) {
        x = e.getX();
        y = e.getY();
        canvas.repaint();
      }
    });
    setSize(800, 600);
    setLocationRelativeTo(null); // center on screen
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setVisible(true);
  }

  public static void main(String[] args) {
    new test();
  }

}
