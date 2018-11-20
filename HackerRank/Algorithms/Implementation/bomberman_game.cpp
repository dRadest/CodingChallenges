#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    long long unsigned n;
    std::cin >> r >> c >> n;
    vector<vector<bool> > map(r, vector<bool> (c));
	vector<vector<bool> > o(r, vector<bool> (c));
    
    // Read input
    for (int i=r*c; i--;){ 
		map[i/c][i%c] = ((std::cin >> std::ws).get() == 'O');
	}

	// Calc state
    if (!(n % 2)){
      for (int i=r*c; i--;){
		  map[i/c][i%c] = true;
	  }
	}else{
      for (int i=0, s = (n<8) ? (n-1)/2 : (n%4 + 3) / 2; i<s; i++) {
        for (int i=r*c; i--;){
			o[i/c][i%c] = map[i/c][i%c];
		}

        for (int i=r*c; i--;){
          map[i/c][i%c] = 
            !( o[i/c][i%c] || // Nothing on the cell
              // Left and up
              (i/c && o[i/c-1][i%c]) || (i%c && o[i/c][i%c-1]) || 
              // Right and bottom : (i/c + 1-r) is equivalent to (i/c != r-1)
              (i/c+1-r && o[i/c+1][i%c]) || (i%c+1-c && o[i/c][i%c+1])
			  );
		}
	  }
	}
    
    // Print output
    for (int i=r*c; i--;){
		std::cout << (map[i/c][i%c] ? "O" : ".") << (i%c ? "" : "\n");
	}


	return 0;
}