import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JLabel;

public class PictureActionListener implements ActionListener {
  public void actionPerformed(ActionEvent e) {
    JDialog dialog = new JDialog();
    dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
    try {
      dialog.add(new JLabel(new ImageIcon(ImageIO.read(getClass().getResourceAsStream("mmulogo.png")))));
    } catch (IllegalArgumentException iae) {
      dialog.add(new JLabel("Image does not exist"));
    } catch (IOException ex) {
      dialog.add(new JLabel("Couldn't load the image"));
    }
    dialog.pack();
    dialog.setLocationByPlatform(true);
    dialog.setVisible(true);
  }
}
