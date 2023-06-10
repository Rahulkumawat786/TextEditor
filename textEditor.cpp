#include <iostream>
using namespace std;

// doubly linked list node implementation
class Node
{
public:
    char ch;
    Node *prev;
    Node *next;

    // constructor for Node class
    Node(char ch)
    {
        this->ch = ch;
        prev = next = nullptr;
    }
};

// text editor class
class TextEditor
{
private:
    Node *cursor,*dummy;
    int len;

public:
    TextEditor()
    {
        dummy = new Node(' ');
        cursor = dummy;
        len = 0;
    }

    // add text to right of cursor
    void addText(string text)
    {
        for (char ch : text)
        {
            Node *nextnode = cursor->next;
            Node *newnode = new Node(ch);
            newnode->prev = cursor;
            newnode->next = nextnode;
            cursor->next = newnode;
            if (nextnode != nullptr)
            {
                nextnode->prev = newnode;
            }
            cursor = newnode;
            len++;
        }
    }

    // delete text from left of cursor
    void deleteText(int k){
        int cnt = 0;
        for(;cnt<k;cnt++){
            if(cursor==dummy){
                break;
            }
            Node* curr = cursor;
            cursor = curr->prev;
            if(cursor!=nullptr){
                cursor->next = curr->next;
            }
            if(curr->next!=nullptr){
                curr->next->prev = cursor;
            }
            delete(curr);
            len--;
        }
    }

    // shift cursor to left
    void cursorLeft(int k){
        for(int i=0;i<k;i++){
            if(cursor==dummy){
                break;
            }
            cursor = cursor->prev;
        }
    }

    // shift cursor to right
    void cursorRight(int k){
        for(int i=0;i<k;i++){
            if(cursor->next==nullptr){
                break;
            }
            cursor = cursor->next;
        }
    }

    // show the string written on text editor
    string showText(){
        Node* curr = dummy->next;
        string ans = "";
        while(curr!=nullptr){
            ans+=curr->ch;
            curr = curr->next;
        }
        return ans;
    }

    // destructor of text editor class
    ~TextEditor(){
        delete(dummy);
        cursor = nullptr;
        len = 0;
    }
};

// int main(){
//     TextEditor* texteditor = new TextEditor();
//     string ans;
//     ans = texteditor->showText();
//     cout<<ans<<endl;

//     texteditor->addText("Rahul Kumar");
//     ans = texteditor->showText();
//     cout<<ans<<endl;

//     texteditor->deleteText(6);
//     ans = texteditor->showText();
//     cout<<ans<<endl;

//     texteditor->addText(" Kumawat");
//     texteditor->cursorLeft(5);
//     texteditor->deleteText(4);
//     ans = texteditor->showText();
//     cout<<ans<<endl;
// }