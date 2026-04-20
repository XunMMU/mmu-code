import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFileChooser;

public class FileActionListener implements ActionListener {

    public void actionPerformed(ActionEvent e) {
        JFileChooser fc = new JFileChooser();
        int _r = fc.showOpenDialog(null);
    }
}
