import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Optional;

public class Exercise4 {

    private static void ppin(String text) {
        for (int ylines = 0; ylines < text.length(); ylines++) {
            for (int s_char = 0; s_char < text.length(); s_char++) {
                int char_pos = s_char - ylines;
                if (char_pos < 0) {
                    char_pos += text.length();
                }
                System.out.print(text.charAt(char_pos));
            }
            System.out.print("\n");
        }
    }

    public static void main(String[] args) {
        Optional<String> text;

        System.out.print("Enter a word: ");

        final BufferedReader inscanner = new BufferedReader(
            new InputStreamReader(System.in)
        );

        try {
            text = Optional.ofNullable(inscanner.readLine().trim());
        } catch (Exception e) {
            System.err.println("Input Error!!");
            return;
        }

        ppin(text.get().toUpperCase());
    }
}
