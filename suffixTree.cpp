#include <iostream>
#include <string>
#include <map>

#include <cstdio>
#include <cstring>

using namespace std;

typedef map<char, Node*> MAP;

class Node
{
    public:
    int start, *end;
    MAP *childern;
    Node * suffixLink;

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
        return node
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
	char* S;
    
    public:
    
    SuffixTree():Root(NULL),activeNode(NULL), S(NULL), activeEdge(0), activeLength(0),remainder(0),leafEnd(-1){}
    
    inline void goDown()
    {
        Node* nextNode = activeNode -> children[S[activeEdge]];
        
        edgeLength = nextNode.edgeLength()
        if (activeLength >= edgeLength)
        {
            activeEdge += edgeLength;
            activeLength -= edgeLength;
            activeNode = nextNode;
        }
    }
    
    void extend(int pos)
    {
        //Extend the end of the string
        leafEnd = pos;
        Node* lastNode = NULL;
        if (activeLength == 0)
                activeEdge = pos;
        if (S[activeEdge+activeLength] != S[pos])
        {
            while (activeLength > 0)
			{
			    Node* nextNode = activeNode -> children[s[activeEdge]];
			    
			    //Create Internal Node
			    int * internalEnd = new int;
			    *internalEnd = activeEdge + activeLength - 1;
			    Node* internalNode = Node::newNode(nextNode->start, internalEnd)
			    
			    //Change Links
			    internalNode -> children[S[*internalEnd + 1]] = nextNode;
			    activeNode -> children[S[activeEdge]] = internalNode;
			    
			    //Create newNode
			    internalNode -> children[S[pos]] = Node::newNode(pos, &leafEnd);
			    
			    if (lastNode != NULL)
			    {
			        lastNode -> suffixLink = internalNode;
			    }
			    
			    lastNode = internalNode;
			    if (activeNode -> suffixLink == NULL)
			    {
			        // activeEdge_old - activeNode_old -> start = activeEdge_new - activeNode_new -> start
			        // activeEdge_new = activeEdge_old + (activeNode_new -> start - activeNode_old -> start)
			        //Node *linkNode = activeNode -> suffixLink;
			        //#activeEdge += linkNode -> start - activeNode -> start;
			        activeNode = activeNode -> suffixLink;
			    } else
			    {
			        activeEdge ++;
    			    activeLength --;
    			}
			}
        }
        if (activeNode -> children.find(S[pos]) == activeNode->children.end())
        {
			//Rule 2 (New leafNode under activeNode)
            activeNode -> children[S[pos]] = Node::newNode(pos, &leafEnd);
        } else 
        {
            activeLength += 1
            remainder += 1
            goDown()   
        }
        
        while (remainder > 0)
        {

            
			// No Child or No child going with s[pos] under the activeNode
            if ((activeNode -> children).empty() or (activeNode -> children.find(s[pos])) != (activeNode ->children.end()))
            {
				//Rule 2 (New leafNode under activeNode)
                activeNode -> children[s[pos]] = &Node::newNode(pos, &leafEnd);
				if (lastnewNode != NULL)
				{
                    lastNode -> SuffixLink = activeNode;
                    lastNewNode = NULL;
				}
            }
            // There is a child going with s[pos] under the activeNode
            else
            {
                
                if (goDown(next))
                {
                    continue;
                }
                if (s[next->start + activeLength] == s[pos])
                {
                    
                }
            }
        }
    }
    SuffixTree(char *)
};
