#include <iostream>
#include <string>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

class Node;
typedef map<char, Node*> MAP;

class Node
{
	public:
	int start, *end, id;
	MAP children;
	Node * suffixLink;
	

	Node():start(0), end(NULL), suffixLink(NULL), children(MAP()){
	}
	int edgeLength()
	{
		return *end - start + 1;
	}
	static Node* newNode(int start, int *end, Node* Root)
	{
		static int number = 0;
		Node *node = new Node;
		node -> start = start;
		node -> end = end;
		node -> suffixLink = Root;
		node -> id = number;
		number += 1;
		cout << "New Node " << node ->id << endl;
		cout << "START " << node ->start << endl; 
		return node;
	}
};


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
	
	SuffixTree():Root(NULL),activeNode(NULL), S(NULL), activeEdge(-1), activeLength(0),remainder(0),leafEnd(-1){}
	
	int goDown(Node* nextNode)
	{
		//Node* nextNode = activeNode -> children[S[activeEdge]];
		int edgeLength = nextNode->edgeLength();
		if (activeLength >= edgeLength)
		{
			activeEdge += edgeLength;
			activeLength -= edgeLength;
			activeNode = nextNode;
			return 1;
		}
		return 0;
	}

	void CheckPrint(char *s)
	{
		cout << s << endl;
		if (activeNode == NULL)
			cout << "ERROR" << endl;
		else{
			cout << activeNode -> id << endl;
			cout << activeNode -> start << " " <<  *(activeNode -> end) << endl;
			cout << activeEdge << " " << activeLength << " " << remainder << endl;
		}
	}
	
	void extend(int pos)
	{
		//Extend the end of the string
		leafEnd = pos;
		Node* lastNode = NULL;
		
		
		remainder ++;
		Node* lastInternalNode = NULL;
		while (remainder > 0)
		{
			if (activeLength == 0)
				activeEdge = pos;
			
			//There is no outgoing Edge from activeNode starting with activeNode
			if ((activeNode -> children).find(S[activeEdge]) == (activeNode -> children).end())
			{
				cout << "RULE 2: CREAT NEW BRANCH OF LEAF NODE" << endl;

				activeNode -> children[S[activeEdge]] = Node::newNode(pos, &leafEnd, Root);
				if (lastInternalNode != NULL)
				{
					lastInternalNode -> suffixLink = activeNode;
					lastInternalNode = NULL;
				}
			} else
			{
				Node* nextNode = activeNode -> children[S[activeEdge]];
				if (goDown(nextNode))
				{
					cout << "GO DOWN" << endl;
					continue;
				}
				if ( S[nextNode ->start + activeLength] == S[pos])
				{
					cout << "RULE 3: Already in the Tree, MARK and GOON" << endl;

					if ((lastInternalNode != NULL) && (activeNode != Root))
					{
						lastInternalNode -> suffixLink = activeNode;
						lastInternalNode = NULL;
					}
					activeLength ++;
					CheckPrint("\nSTEP");
					break;
				}

				cout << "RULE 2: CREAT NEW BRANCH AND SPLIT" << endl;
				//Create Internal Node
				int* internalEnd = new int;
				*internalEnd = nextNode -> start +activeLength - 1;
				Node* internalNode = Node::newNode(nextNode -> start, internalEnd, Root);
				nextNode -> start = *internalEnd + 1;

				//Change the Link
				internalNode -> children[S[pos]] = Node::newNode(pos, &leafEnd, Root);
				internalNode -> children[S[nextNode -> start]] = nextNode;
				activeNode -> children[S[activeEdge]] = internalNode;

				if (lastInternalNode != NULL)
					lastInternalNode -> suffixLink = internalNode;
				
				lastInternalNode = internalNode;
			}
			remainder --;
			if ((activeNode == Root) && (activeLength > 0))
			{
				activeLength -= 1;
				activeEdge = pos - remainder + 1;
			} else if (activeNode != Root)
			{
				activeNode = activeNode -> suffixLink;
			}
			CheckPrint("\nSTEP");
		}
	}
	SuffixTree(char* text){
		cout << "Using Construct Method" << endl;
		S = text;
		int *t = new int;
		*t = -1;
		Root = Node::newNode(-1, t, NULL);

		activeNode = Root;
		
		activeEdge = -1;
		activeLength = 0;
		remainder = 0;

		int L = strlen(S);
		for (int i = 0; i < L; ++ i)
		{
			cout << "Extending " << i << " " << S[i] << endl;
			extend(i);
			cout << endl;
		}
	};
};

int main()
{
	char * a="xabxababxba$";

	SuffixTree T(a);

	printf("%s\n",a);
	cout << a << endl;
	return 0;
}