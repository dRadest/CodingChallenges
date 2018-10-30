#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

/******** solution **********/

// Least Recently Used policy implementation of Cache
class LRUCache : public Cache {
   public:
   // constructor that takes capacity as an argument
   LRUCache(int c) { 
      cp = c; 
   }
   // implementation of set()
   void set(int k,int v)
   {
      // pointer to node 
      Node *N;

      if(mp.empty()) //No nodes 
      {
         // create new node with key and value passed in set()
         N = new Node(k,v);
         // tail and head point to this node since there were none previously in map
         tail = head = N;
         // map the new node
         mp[k] = N;
            
         return;
      }

      // find iterator to node mapped to k (returns map::end if not found)
      auto it = mp.find(k);
            
      if(it != mp.end()) // node in hash table (move it to front)
      {
         it->second->value = v; // update value of the node
            
         if(head == it->second) //if the node is head
               return;
            
         /* let previous node of the current node point to the next node of the current node
            (i.e. eliminate current node from the linked list) */
         it->second->prev->next = it->second->next;
            
            if(tail == it->second) //if the node is tail
               tail = tail->prev; // move it one up
            else                   //node in between
               /* let next node of the current node point to the previous node of the current node
                  (i.e. eliminate the current node from the linked list) */
               it->second->next->prev = it->second->prev;
            
            // current node's next is head
            it->second->next = head;
            // current node's prev is NULL (i.e. put it at the beginning of the list)
            it->second->prev = NULL;
            // head's previous is current node
            head->prev = it->second;
            // head is current node
            head = it->second;
        }
        else // node not in hash table
        {
            N = new Node(head->prev,head,k,v); //new node (move it to front)
            head->prev = N; 
            head = N;
            mp[k] = N;
            
            // if capacity exceeded
            if(mp.size() > cp)
            {
               // remove the last node in linked list
               tail = tail->prev;
               mp.erase(tail->next->key);
               delete tail->next; 
               tail->next = NULL;
            }
            
        }

    }
    
    int get(int k)
    {
      // find the node
        auto it = mp.find(k);
        if(it != mp.end()) // found (return its value)
            return it->second->value;
        
        return -1;
    }
};

/********* locked *********/
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}