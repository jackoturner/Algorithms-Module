#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

struct Node {
    int position;
    char letter; // lowercase
    char part;   // 'f' first, 'm' middle, 'l' last
    Node* next;
    Node(int pos, char c, char p) : position(pos), letter(c), part(p), next(nullptr) {}
};

class Full_Name {
private:
    Node* head;
    int size;

public:
    

}