#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class lru_cache {

  /*
   * capacity of the lru cache
   */
  int csize;
  
  /*
   * map to store the reference of key
   */
  unordered_map<int, list<pair<int, int>> :: iterator> ma;
  
  /*
   * stores the <key, value> pair of the cache
   */
  list<pair<int, int>> dq;

  public:

    /*
     * constructor
     */
    lru_cache (int size) {
    
      csize = size;
    }

    /*
     * returns the value of key if <key, value> pair 
     * is present in the cache. otherwise returns -1.
     */
    int get (int k) {
    
      if(ma.find(k) == ma.end())
        return -1;

      unordered_map<int, list<pair<int, int>> :: iterator> :: iterator itr;
      itr = ma.find(k);
      int value = itr->second->second;
      dq.erase(ma[k]);
      dq.push_front(make_pair(k, value));
      ma[k] = dq.begin();

      return value;
    }

    /*
     * stores the <key, value> pair if the cache is not full. 
     * otherwise, it evicts the least recently used <key, value>
     * pair before storing the <key, value> pair passed via put().
     */
    void put (int k, int v) {
    
      if(ma.find(k) == ma.end()) {
      
        if(dq.size() == csize) {
        
          int last = dq.back().first;
          dq.pop_back();
          ma.erase(last);
        }
      } else {
      
        dq.erase(ma[k]);
      }

      dq.push_front(make_pair(k, v));
      ma[k] = dq.begin();
    }

    /*
     * deletes the <key, value> pair from the cache if present
     */
    void delete_key (int k) {
    
      dq.erase(ma[k]);
      ma.erase(k);
    }

    /*
     * displays the <key, value> pairs in the cache
     */
    void display () {
    
      list<pair<int, int>> :: iterator itr;
      for(itr = dq.begin(); itr != dq.end(); itr++) {
      
        cout << itr->first << " " << itr->second << endl; 
      }
      cout << endl;
    }
};

int
main ()
{

  lru_cache ca(3);

  ca.put(0, 0);
  ca.display();
  
  ca.put(1, 1);
  ca.display();

  ca.put(2, 2);
  ca.display();

  ca.put(3, 3);
  ca.display();

  int val = ca.get(1);
  cout << "Value of 1 is: " << val << endl;
  ca.display();

  val = ca.get(100);
  cout << "Value of 100 is: " << val << endl;
  ca.display();

  ca.put(2, 2);
  val = ca.get(2);
  cout << "value of 2 is: " << val << endl;
  ca.display();

  val = ca.get(1);
  cout << "Value of 1 is: " << val << endl;
  ca.display();

  ca.put(INT_MAX, INT_MAX);
  ca.display();

  ca.put(INT_MIN, INT_MIN);
  ca.display();

  return 0;
}
