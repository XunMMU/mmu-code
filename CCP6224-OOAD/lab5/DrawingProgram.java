import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Label;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class DrawingProgram extends JFrame implements MouseMotionListener {

    public DrawingProgram() {
        super("Painter");
        JPanel toolbar = new JPanel(new FlowLayout(FlowLayout.LEFT));
        toolbar.add(new Label("Drag mouse to draw"));
        toolbar.addMouseMotionListener(null);
        this.add(toolbar, BorderLayout.SOUTH);
        setSize(800, 600);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        // TODO Auto-generated method stub
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        // TODO Auto-generated method stub
    }

    public static void main(String[] a) {
        new DrawingProgram();
    }
}
