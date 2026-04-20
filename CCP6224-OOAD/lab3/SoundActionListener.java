import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SoundActionListener implements ActionListener {
  public void actionPerformed(ActionEvent e) {
    Toolkit.getDefaultToolkit().beep();
  }
}
