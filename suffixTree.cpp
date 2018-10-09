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
	char* s;
    
    public:
    
    SuffixTree():Root(NULL),activeNode(NULL), s(NULL), activeEdge(0), activeLength(0),remainder(0),leafEnd(-1){}
    
    int goDown(Node *nextNode)
    {
        edgeLength = nextNode.edgeLength()
        if (activeLength >= edgeLength)
        {
            activeEdge += edgeLength;
            activeLength -= edgeLength;
            activeNode = nextNode;
            return 1;
        }
        return 0;
    }
    
    void extend(int pos)
    {
        //Extend the end of the string
        leafEnd = pos;
        remainder ++;
        while (remainder > 0)
        {
            if (activeLength == 0)
                activeEdge = pos;
            
			// No Child or No child going with s[pos] under the activeNode
            if ((activeNode -> children).empty() or (activeNode -> children.find(s[pos])) != (activeNode ->children.end()))
            {
				//Rule 2 (New leafNode under activeNode)
                activeNode -> children[s[pos]] = Node::newNode(pos, &leafEnd);
				if (lastnewNode != NULL)
				{
                    lastNode -> SuffixLink = activeNode;
                    lastNewNode = NULL;
				}
            }
            // There is a child going with s[pos] under the activeNode
            else
            {
                Node* next = activeNode ->children[s[pos]];
                if (goDown(next))
                {
                    continue;
                }
            }
        }
    }
    SuffixTree(char *)
};
