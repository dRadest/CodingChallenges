import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Town implements Comparable<Town>{
    private long population;
    private long location;
    public Town(long pop, long loc){
        this.population = pop;
        this.location = loc;
    }
    public long getPopulation(){
        return this.population;
    }
    public long getLocation(){
        return this.location;
    }
    @Override
    public int compareTo(Town town) {
        if(this.getLocation() == town.getLocation()){
            return (int)(this.getPopulation() - town.getPopulation());
        }
        return (int)(this.getLocation() - town.getLocation());

    }
}

class Cloud implements Comparable<Cloud>{
    private long start;
    private long end;
    public Cloud(long s, long e){
        this.start = s;
        this.end = e;
    }
    public long getStart(){
        return this.start;
    }
    public long getEnd(){
        return this.end;
    }
    @Override
    public int compareTo(Cloud cloud) {
        if(this.getStart() == cloud.getStart()){
            return (int)(this.getEnd() - cloud.getEnd());
        }
        return (int)(this.getStart() - cloud.getStart());

    }
}



public class Solution {

    // clouds list
    static ArrayList<Cloud> clouds = new ArrayList<Cloud>();
    // towns list
    static ArrayList<Town> towns = new ArrayList<Town>();
    // town index
    static int t_idx;

    // helper method to count people before certain position
    static long count(long pos, boolean exc){
        long result = 0;
        if(exc){
            while(t_idx < towns.size() && towns.get(t_idx).getLocation() < pos){
                result += towns.get(t_idx).getPopulation();
                t_idx++;
            }
        }else{
            while(t_idx < towns.size() && towns.get(t_idx).getLocation() <= pos){
                result += towns.get(t_idx).getPopulation();
                t_idx++;
            }
        }
        return result;

    }

    // Complete the maximumPeople function below.
    static long maximumPeople(long[] p, long[] x, long[] y, long[] r) {
        // populate a list of clouds
        clouds.clear();
        for(int i=0; i<y.length; i++){
            Cloud cl = new Cloud(Math.max(y[i]-r[i], 0), y[i] + r[i]);
            clouds.add(cl);
        }
        // sort clouds by start ascending
        Collections.sort(clouds);
        // populate a list of towns
        towns.clear();
        for(int i=0; i<p.length; i++){
            Town tow = new Town(p[i], x[i]);
            towns.add(tow);
        }
        // sort towns by location ascending
        Collections.sort(towns);
        // add a ghost cloud
        long last_town_loc = towns.get(towns.size()-1).getLocation();
        long last_cloud_end = clouds.get(clouds.size()-1).getEnd();
        long ghost_loc = Math.max(last_town_loc, last_cloud_end) + 100;
        // add ghost cloud
        clouds.add(new Cloud(ghost_loc, ghost_loc));
        // end of the current cloud interval
        long cend = -10*9;
        // counter to check people covered by current cloud
        long covered = 0;
        // counter for people not covered by a cloud at all
        long uncovered = 0;
        // to hold max count
        long max_covered = 0;
        // town index
        t_idx = 0;

        // consider three cases
        for(int i=0; i<clouds.size(); i++){
            Cloud nextCloud = clouds.get(i);
            long nextStart = nextCloud.getStart();
            long nextEnd = nextCloud.getEnd();
            // next cloud starts after the end of previous cloud
            if(nextStart > cend){
                covered += count(cend, false);
                max_covered = Math.max(max_covered, covered);
                covered = 0;
                uncovered += count(nextStart, true);
                cend = nextEnd;
            // next cloud starts and ends before previous cloud
            } else if(nextStart <= cend && nextEnd < cend){
                covered += count(nextStart, true);
                long ignored = count(nextEnd, false);
            // next cloud starts before and ends after previous cloud
            } else if(nextStart <= cend && nextEnd >= cend){
                covered += count(nextStart, true);
                max_covered = Math.max(max_covered, covered);
                covered = 0;
                long ignored = count(cend, false);
                cend = nextEnd;
            }
        }
        return (max_covered + uncovered);


    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long[] p = new long[n];

        String[] pItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            long pItem = Long.parseLong(pItems[i]);
            p[i] = pItem;
        }

        long[] x = new long[n];

        String[] xItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            long xItem = Long.parseLong(xItems[i]);
            x[i] = xItem;
        }

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long[] y = new long[m];

        String[] yItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            long yItem = Long.parseLong(yItems[i]);
            y[i] = yItem;
        }

        long[] r = new long[m];

        String[] rItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            long rItem = Long.parseLong(rItems[i]);
            r[i] = rItem;
        }

        long result = maximumPeople(p, x, y, r);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
