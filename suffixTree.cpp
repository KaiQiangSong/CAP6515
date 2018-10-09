#include <iostream>
#include <string>
#include <map>

#include <cstdio>
#include <cstring>

using namespace std;

typedef map<char, Node*> MAP;

class Node
{
    private:
    int start, *end;
    MAP *childern;
    Node * suffixLink;
    public:
    Node():{
        start = 0, end = NULL;
        Children = new MAP;
        suffixLink = NULL;
    }
    int edgeLength()
    {
        return *end - start + 1;
    }
    static Node* newNode(int start, int *end)
    {
        Node *node = new Node;
        node -> start = start;
        node -> end = end;
        node -> suffixLink = NULL;
    }
};


typedef Node

class SuffixTree{
    private:
    
    Node* Root;
    Node* activeNode;
    int activeEdge; //Remember the start position of the String
    int activeLength; //Remember the length of the active edge
    int remainder;
    int leafEnd;
    
    public:
    
    SuffixTree():Root(NULL),activeNode(NULL), activeEdge(0), activeLength(0),remainder(0),leafEnd(-1){}
    
    void extend(int pos)
    {
        //Extend the end of the string
        leafEnd = pos;
        while (remainder > 0)
        {
            if (activeLength == 0)
                activeEdge = pos
            
            if ((activeNode -> children).empty())
            {
                
            }
        }
    }
    SuffixTree(char *)
};
