The program shows the implementation of LRU (Least Recently Used) cache. The following methods are provided:
  1. get (int k) -> returns the value associated with the key else returns -1.
  2. put (int k, int v) -> inserts the <key, value> pair in the cache if it is not full, else
                           it evicts the least recently used <key, value> pair before 
                           inserting the <key, value> pair passed via put().
  3. delete (int k) -> deletes the <key, value> pair from the cache if present
  4. display () -> displays the <key, value> pairs present in the cache

Data structures: 
  1. unordered_map<int, list<pair<int, int>> :: iterator> -> the map stores the refernce to the key
  2. list<pair<int, int>> -> stores the <key, value> pair

Time complexity: 
  1. get -> O(1) 
            The map stores the refernce to the key and thus getting a pointer to key in list 
            become an O(1) operation. Once we have the pointer, we get the value in O(1) time.
            Therefore, time complexity of get method is O(1).
  2. put -> O(1)
            If the key is present in the cache then we erase the entry in list using refernce from 
            the map. This takes O(1) time. Inserting the pair to the front of the list and in the 
            map is also O(1) time. Hnce, time complexity is O(1).
  3. delete -> O(1)
               We need to erase the entry from the list which will take O(1) time as we have a refernce 
               to the key stored in the map. Deleting the entry from the map also takes O(1) time. This 
               result in O(1) time complexity.
  4. display -> O(k), where k is the number of elements in the cache
                We iterate over the list with k elements. Hence, time complexity is O(k).
