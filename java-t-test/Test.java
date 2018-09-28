import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Test {

    public static void main(String[] args) {
        String csvFile = "../height-data.csv";
        BufferedReader br = null;
        String line = "";
        String csvsSplitBy = ",";

        ArrayList<Double> males = new ArrayList<Double>();
        ArrayList<Double> females = new ArrayList<Double>();

        try {
            br = new BufferedReader(new FileReader (csvFile));
            br.readLine(); // skip headers
            while ((line = br.readLine()) != null) {
                // use comma as separator
                String[] height = line.split(csvsSplitBy);

                //System.out.println(height[0]);
                //System.out.println(height[1]);
                double m = Double.parseDouble(height[0]);
                double f = Double.parseDouble(height[1]);
                males.add(m);
                females.add(f);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    System.out.println("Males: " + males);
                    System.out.println("Females: " + females);
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}