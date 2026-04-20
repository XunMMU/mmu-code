import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class SomethingWindow extends JFrame {
  public SomethingWindow() {
    super("This is my application");
    JPanel jp = new JPanel(new FlowLayout());
    add(jp);
    setSize(320, 150);
    setVisible(true);
  }

  public static void main(String[] args) {
    var window = new SomethingWindow();
    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
}
