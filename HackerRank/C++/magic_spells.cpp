#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    /* using dynamic_cast to check if spell is of certain type
        call appropriate method to reveal its firepower */
    if (Fireball *p = dynamic_cast<Fireball*>(spell))
        p->revealFirepower();
    else if (Frostbite *p = dynamic_cast<Frostbite*>(spell))
        p->revealFrostpower();
    else if (Thunderstorm *p = dynamic_cast<Thunderstorm*>(spell))
        p->revealThunderpower();
    else if (Waterbolt *p = dynamic_cast<Waterbolt*>(spell))
        p->revealWaterpower();
    else{ // unknown spell
        // get unknown spell and journal entry
        string unknownSpell = spell->revealScrollName();
        string journalEntry = SpellJournal::journal;
    
        // their lengths + 1 are matrix dimensions
        int m = journalEntry.length() + 1;
        int n = unknownSpell.length() + 1;
        // declare (m x n) matrix
        int L[m][n];
        int i, j; 
        
        // initialize first row and column to 0
        for(i=0; i<m; i++) {
            L[i][0] = 0;
        }
        for(j=0; j<n; j++){
            L[0][j] = 0;
        }
        
        /* build L[m][n] in bottom-up fashion
         L[i][j] contains length of LCS of journalEntry[0...i-1] and unknownSpell[0...j-1] */
       for (i=1; i<m; i++) 
       { 
         for (j=1; j<n; j++) 
         { 
            // last characters match
           if (unknownSpell[j-1] == journalEntry[i-1]) 
             L[i][j] = L[i-1][j-1] + 1; 
       
           else 
             L[i][j] = max(L[i-1][j], L[i][j-1]); 
         } 
       } 
        /* L[m-1][n-1] contains length of LCS */
        cout << L[m-1][n-1] << endl;
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}