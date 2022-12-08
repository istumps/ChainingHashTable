#include <iostream> 
#include <list>
#include <cstring>


using namespace std;
 
class Hash
{
    int BUCKET;    
    list<int> *table;
public:
    Hash(int V);  
 
    
    void insertItem(int key);
 
   
    void deleteItem(int key);
 
    
    int hashFunction(int key) {
        return (key % BUCKET);
    }
 
    void displayHash();
};
 
Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}
 
void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}
 
void Hash::deleteItem(int key)
{
 
  int index = hashFunction(key);
 

  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }

  if (i != table[index].end())
    table[index].erase(i);
}
 

void Hash::displayHash() {
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}
 
int main()
{
    int size = 11; 
  Hash h(size);
    
 cout << "Case 1: No Collison\n"; 

    h.insertItem(1); 
    h.insertItem(2);
    h.insertItem(3); 
    h.insertItem(4); 
    h.insertItem(5); 
    h.insertItem(6);   
    h.insertItem(7); 
    h.insertItem(8);
    h.insertItem(9); 
    h.insertItem(10); 
    h.insertItem(11);

    h.displayHash();
     
  for(int i = 0; i <= size; i++){
  h.deleteItem(i);    
  }

cout << "Case 2: Collison solved with Chaining\n";

    h.insertItem(1); 
    h.insertItem(3);
    h.insertItem(23); 
    h.insertItem(10); 
    h.insertItem(5); 
    h.insertItem(14);   
    h.insertItem(17); 
    h.insertItem(8);
    h.insertItem(127); 
    h.insertItem(54); 
    h.insertItem(27); ;
  h.displayHash();
 
  return 0;
}