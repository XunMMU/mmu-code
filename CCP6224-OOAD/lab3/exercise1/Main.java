package exercise1;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Main extends JFrame {
  private final JPanel panel = new JPanel();
  private final ArrayList<JButton> btnArr = new ArrayList<>();

  public Main() {
    this.btnArr.add(new JButton("Push me"));
    btnArr.get(btnArr.size() - 1).addActionListener(new Acting("A button was pushed!"));
    this.btnArr.add(new JButton("Click me"));
    btnArr.get(btnArr.size() - 1).addActionListener(new Acting("B button was clicked!"));
    this.btnArr.add(new JButton("Nothing"));
    for (int i = 0; i < 4; i++) {
      this.btnArr.add(new JButton(String.format("Button %d", i)));
      btnArr.get(btnArr.size() - 1).addActionListener(new Acting(String.format("Button %d was pressed!", i)));
    }
    for (var x : this.btnArr) {
      this.panel.add(x);
    }
    addImpl(this.panel, BorderLayout.CENTER, -1);
    // setSize(400, 400);
    pack();
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

  public static void main(String[] args) {
    new Main();
  }

}

class Acting implements ActionListener {
  private final String message;

  Acting(String x) {
    this.message = x;
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    JDialog x = new JDialog();
    x.add(new JLabel(this.message));
    x.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
    x.pack();
    x.setLocationByPlatform(true);
    x.setVisible(true);
  }
}
