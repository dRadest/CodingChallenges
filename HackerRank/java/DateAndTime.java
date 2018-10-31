import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'findDay' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER month
     *  2. INTEGER day
     *  3. INTEGER year
     */

    public static String findDay(int month, int day, int year) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, --month, day, 0 /*hourOfDay*/, 0 /*minute*/);
        String daystr;
        switch (calendar.get(Calendar.DAY_OF_WEEK)){
            case Calendar.MONDAY:
                daystr = "MONDAY";
                break;
            case Calendar.TUESDAY:
                daystr = "TUESDAY";
                break;
            case Calendar.WEDNESDAY:
                daystr = "WEDNESDAY";
                break;
            case Calendar.THURSDAY:
                daystr = "THURSDAY";
                break;
            case Calendar.FRIDAY:
                daystr = "FRIDAY";
                break;
            case Calendar.SATURDAY:
                daystr = "SATURDAY";
                break;
            case Calendar.SUNDAY:
                daystr = "SUNDAY";
                break;
            default:
                daystr = "UNKNOWN";
                break;
        }
        return daystr;

    }

}

public class DateAndTime {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int month = Integer.parseInt(firstMultipleInput[0]);

        int day = Integer.parseInt(firstMultipleInput[1]);

        int year = Integer.parseInt(firstMultipleInput[2]);

        String res = Result.findDay(month, day, year);

        bufferedWriter.write(res);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}