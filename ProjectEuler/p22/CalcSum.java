import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.FileReader;

public class CalcSum {
    public static void main(String[] args) {
        String line = "";
        String csv_file = "word_vals.csv";
        BigInteger result = BigInteger.ZERO;

        try (BufferedReader reader = new BufferedReader(new FileReader(csv_file))) {
            for (Integer pos=1; (line = reader.readLine()) != null; pos++ ) {
                    BigInteger pos_val = new BigInteger( pos.toString() );
                    BigInteger word_val = new BigInteger( line.trim() );
                    result = result.add( word_val.multiply(pos_val) );

                    System.out.println (pos_val + " x " + word_val + " -> " + result);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println (result.toString());
    }
}
