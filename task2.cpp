#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Node structure for the linked list
struct Node {
    int position;
    char letter;    // Stored in lowercase
    char part;      // f = first name, m = middle name, l = last name
    Node* next;    
};

// Class to store the full name as a linked list
class Full_Name {
private:
    Node* head;
    int size; 

public:
    // Constructor: start with an empty list
    Full_Name() {
        head = NULL;
        size = 0;
    }

    // Add a single letter to the end of the list
    void Add_element(char letter, char part) {
        Node* n = new Node;        // create a new node
        n->letter = tolower(letter);
        n->part = part;             
        n->next = NULL;

        size++;     // Increase size of the list
        n->position = size;  

        // If list is empty new node becomes head
        if (head == NULL) {
            head = n;
        } 
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = n;     // Add new node to the end
        }
    }

    // Add a whole word letter-by-letter
    void Add_word(string word, char part) {
        for (int i = 0; i < word.length(); i++) {
            if (!isspace(word[i])) {    // Ignore spaces
                Add_element(word[i], part);
            }
        }
    }

    // Print the full linked list
    void Print_list() {
        Node* temp = head;
        cout << "[";

        while (temp != NULL) {
            // Print each node as (position, 'letter', 'part')
            cout << "(" << temp->position << ", '" << temp->letter << "', '" << temp->part << "')";
            if (temp->next != NULL) cout << ", ";
            temp = temp->next;
        }

        cout << "]\n";
    }

    // Reconstruct and print the full name properly
    void Print_full_name() {
        string f = "", m = "", l = "";
        Node* temp = head;

        // Sort letters back into first, middle, last
        while (temp != NULL) {
            if (temp->part == 'f') f += temp->letter;
            else if (temp->part == 'm') m += temp->letter;
            else if (temp->part == 'l') l += temp->letter;
            temp = temp->next;
        }

        // Capitalise first letters
        if (f.length() > 0) f[0] = toupper(f[0]);
        if (m.length() > 0) m[0] = toupper(m[0]);
        if (l.length() > 0) l[0] = toupper(l[0]);

        // Print full name in normal format
        cout << f;
        if (m != "") cout << " " << m;
        cout << " " << l << "\n";
    }

    // Search for a letter and print all positions
    void Search_element(char letter) {
        letter = tolower(letter);
        Node* temp = head;
        bool found = false;

        // Search through list
        while (temp != NULL) {
            if (temp->letter == letter) {
                cout << temp->position << " ";  // Print positions
                found = true;
            }
            temp = temp->next;
        }

        if (!found) cout << "No occurrences";
        cout << "\n";
    }

    // Remove all nodes belonging to a chosen name part
    void Remove_word(char part) {
    // If the list is empty, nothing to do
    if (head == NULL) {
        return;
    }

    // Remove matching nodes at the head
    while (head != NULL && head->part == part) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // If list became empty after removing heads
    if (head == NULL) {
        return;
    }

    // Remove matching nodes in the rest of the list
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->part == part) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
        } else {
            current = current->next;
        }
    }

    // Reassign positions 1 -> size
    Node* temp = head;
    int newPos = 1;
    while (temp != NULL) {
        temp->position = newPos;
        newPos++;
        temp = temp->next;
    }
}
};

// Main program logic
int main() {
    Full_Name fn;
    string first, middle, last;

    // Ask user for names
    cout << "Enter first name: ";
    cin >> first;

    cout << "Enter middle name (or '-' if none): ";
    cin >> middle;

    cout << "Enter last name: ";
    cin >> last;

    // Add each name to the linked list
    fn.Add_word(first, 'f');
    if (middle != "-") fn.Add_word(middle, 'm');
    fn.Add_word(last, 'l');

    // Print initial state
    cout << "\nInitial list:\n";
    fn.Print_list();
    fn.Print_full_name();

    // Add an extra 'a' to the last name (as required)
    fn.Add_element('a', 'l');

    cout << "\nAfter adding 'a':\n";
    fn.Print_list();
    fn.Print_full_name();

    // Search the list for letter 'a'
    cout << "\nSearching for 'a':\n";
    fn.Search_element('a');

    // Final printing
    cout << "\nFinal list:\n";
    fn.Print_list();
    fn.Print_full_name();

    // Remove name example
    cout << "\nAfter removing a word:\n";
    fn.Remove_word('m');
    fn.Print_full_name();

    return 0;
}
