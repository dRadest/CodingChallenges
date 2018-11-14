import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the truckTour function below.
     */
    static class PetrolStation{
        public int petrol;
        public int distance;
        public PetrolStation(int pet, int dis){
            this.petrol = pet;
            this.distance = dis;
        }
    }
    static int truckTour(int[][] petrolpumps) {
        int numps = petrolpumps.length;
        Queue<PetrolStation> route = new LinkedList<PetrolStation>();
        // add all petrol pumps to the queue
        for(int i=0; i<numps; i++){
            PetrolStation ps = new PetrolStation(petrolpumps[i][0], petrolpumps[i][1]);
            route.offer(ps);
        }
        int start = 0, passed = 0; // to keep track of pumps passed and where we started
        double petrol = 0; 
        while(passed < numps){
        	// poll the pump at the front of the queue
            PetrolStation ps = route.poll();
            // add the petrol from it to petrol available
            petrol += ps.petrol;
            // if enough petrol, we pass this pump
            if(petrol >= ps.distance){
                passed++;
                petrol -= ps.distance;
            }else { // start over at this pump
                start += passed + 1;
                passed = 0;
                petrol = 0;
            }
            route.offer(ps);
        }
        return start;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(scanner.nextLine().trim());

        int[][] petrolpumps = new int[n][2];

        for (int petrolpumpsRowItr = 0; petrolpumpsRowItr < n; petrolpumpsRowItr++) {
            String[] petrolpumpsRowItems = scanner.nextLine().split(" ");

            for (int petrolpumpsColumnItr = 0; petrolpumpsColumnItr < 2; petrolpumpsColumnItr++) {
                int petrolpumpsItem = Integer.parseInt(petrolpumpsRowItems[petrolpumpsColumnItr].trim());
                petrolpumps[petrolpumpsRowItr][petrolpumpsColumnItr] = petrolpumpsItem;
            }
        }

        int result = truckTour(petrolpumps);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
