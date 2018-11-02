import java.util.*;

// Write your Checker class here
class Checker implements Comparator {
    public int compare(Object o1, Object o2){
        Player p1 = (Player) o1;
        Player p2 = (Player) o2;
        // if two players have equal scores, compare names
        if(p1.score == p2.score){
        	/* String.compareTo() returns
        	* negative if p1.name lexicographically smaller than p2.name
        	* zero if they're equal
        	* positive if p1.name lexicographically greater than p2.name
        	*/
            return p1.name.compareTo(p2.name);
        }
        // order by decreasing score 
        return (p2.score - p1.score);
    }
}

class Player{
    String name;
    int score;
    
    Player(String name, int score){
        this.name = name;
        this.score = score;
    }
}

class Comparator {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Player[] player = new Player[n];
        Checker checker = new Checker();
        
        for(int i = 0; i < n; i++){
            player[i] = new Player(scan.next(), scan.nextInt());
        }
        scan.close();

        Arrays.sort(player, checker);
        for(int i = 0; i < player.length; i++){
            System.out.printf("%s %s\n", player[i].name, player[i].score);
        }
    }
}