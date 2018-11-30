import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Customer{
    private Integer id; 
    private Integer serveTime;
    public Customer(int id, int serveTime){
        this.id = id;
        this.serveTime = serveTime;
    }
    public Integer getId(){
        return this.id;
    }
    public Integer getServeTime(){
        return this.serveTime;
    }
}

public class Solution {

    // Complete the jimOrders function below.
    static int[] jimOrders(int[][] orders) {
        ArrayList<Customer> list = new ArrayList<Customer>();
        for (int i=0; i<orders.length; i++) {
            Customer curCustomer = new Customer(i+1, orders[i][0] + orders[i][1]);
            list.add(curCustomer);
        }
        list.sort((c1, c2) -> c1.getServeTime().compareTo(c2.getServeTime()));
        int[] result = new int[orders.length];
        for(int i=0; i<list.size(); i++){
            result[i] = list.get(i).getId();
        }
        return result;


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[][] orders = new int[n][2];

        for (int i = 0; i < n; i++) {
            String[] ordersRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int ordersItem = Integer.parseInt(ordersRowItems[j]);
                orders[i][j] = ordersItem;
            }
        }

        int[] result = jimOrders(orders);

        for (int i = 0; i < result.length; i++) {
            bufferedWriter.write(String.valueOf(result[i]));

            if (i != result.length - 1) {
                bufferedWriter.write(" ");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
