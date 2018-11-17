import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class MinAvgWaitTime {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numOfCustomers = in.nextInt();
        Customer[] customers = new Customer[numOfCustomers];

        for (int i = 0; i < numOfCustomers; i++) {
            int orderTime = in.nextInt();
            int cookTime = in.nextInt();
            customers[i] = new Customer(orderTime, cookTime);
        }
        in.close();


        // sort customers by order time ascending
        Arrays.sort(customers, Comparator.comparingInt(o -> o.orderTime));

        // min heap with minimum cook time at the root
        Queue<Customer> waitTime = new PriorityQueue<>();
        long currentTime = 0L;
        long totalWaitTime = 0L;
        int index = 0;

        while (!waitTime.isEmpty() || index < customers.length) {
            while (index < customers.length && customers[index].orderTime <= currentTime) {
                waitTime.add(customers[index]);
                index++;
            }
            if (waitTime.isEmpty()) {
                currentTime = customers[index].orderTime;
                continue;
            }

            Customer served = waitTime.poll();
            currentTime += served.cookTime;
            totalWaitTime += currentTime - served.orderTime;
        }

        System.out.println(totalWaitTime / customers.length);
    }

    // helper class to hold info about customer's order and cook time
    static class Customer implements Comparable<Customer> {
        public int orderTime;
        public int cookTime;

        public Customer(int orderTime, int cookTime) {
            this.orderTime = orderTime;
            this.cookTime = cookTime;
        }

        // order customers by order time ascending
        @Override
        public int compareTo(Customer o) {
            if (this.cookTime > o.cookTime) {
                return this.orderTime;
            } else
                return -1;
        }
    }
}