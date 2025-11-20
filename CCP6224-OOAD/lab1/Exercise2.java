import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.OptionalInt;

public class Exercise2 {

    private static enum ExitState {
        NORMAL,
        INVALID_ARGS,
        INVALID_INPUT,
        UNKNWON;

        public static Integer value(ExitState state) {
            switch (state) {
                case NORMAL:
                    return 0;
                case INVALID_ARGS:
                    return 1;
                case INVALID_INPUT:
                    return 2;
                case UNKNWON:
                    return 3;
                default:
                    return null;
            }
        }
    }

    private static void ppin(int range) {
        final int num_sig = (int) Math.log10(range) + 1;
        final String out_f_str = "%" + num_sig + "d ";
        final String spc_str = " ".repeat(num_sig) + " ";

        for (int y_cor = 0; y_cor < range; y_cor++) {
            for (int x_cor = 0; x_cor < range; x_cor++) {
                if (y_cor == 0) {
                    System.out.printf(out_f_str, x_cor + 1);
                    continue;
                }
                if (y_cor == range - 1) {
                    System.out.printf(out_f_str, y_cor - x_cor + 1);
                    continue;
                }
                if (x_cor == 0) {
                    System.out.printf(out_f_str, y_cor + 1);
                    continue;
                }
                if (x_cor == range - 1) {
                    System.out.printf(out_f_str, range - y_cor);
                    continue;
                }
                System.out.print(spc_str);
            }
            System.out.print("\n");
        }
    }

    public static void main(String args[]) {
        boolean override = false;
        boolean con = true;

        for (String arg : args) {
            switch (arg) {
                case "-h":
                case "--help":
                    break;
                case "--override":
                    override = true;
                    break;
                default:
                    System.err.println("Wrong args");
                    System.exit(ExitState.value(ExitState.INVALID_ARGS));
            }
        }

        final BufferedReader inscanner = new BufferedReader(
            new InputStreamReader(System.in)
        );

        while (con) {
            System.out.print("Enter an integer >0 and <21:");

            if (override) System.out.print(" (override)");

            System.out.print("\n");

            OptionalInt int_input;

            try {
                int_input = OptionalInt.of(
                    Integer.parseInt(inscanner.readLine())
                );
            } catch (NumberFormatException nfe) {
                System.err.println("Number pls");
                con = false;
                System.exit(ExitState.value(ExitState.INVALID_INPUT));
                continue;
            } catch (Exception e) {
                System.err.println("Error");
                con = false;
                System.exit(ExitState.value(ExitState.UNKNWON));
                continue;
            }

            if (
                (int_input.getAsInt() > 20 && !override) ||
                int_input.getAsInt() < 1
            ) {
                System.err.println("Wrong number range");
                con = false;
                System.exit(ExitState.value(ExitState.INVALID_INPUT));
            }

            ppin(int_input.getAsInt());
        }
    }
}
