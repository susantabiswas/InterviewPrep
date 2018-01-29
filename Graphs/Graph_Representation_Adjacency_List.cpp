//Graph representation using Adjacency List in the Directed Graph
#include<iostream>
using namespace std;

//for creating nodes
struct Node
{
	int data;
	Node *next=NULL;
};
//for creating the lists in the adjacency list
struct AdjList
{
    Node *head;
};

//creates a node for the linked list
Node *createNode(int data)
{
	try
	{
		Node *node=new Node;
		node->data=data;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory Full !";
		return NULL;
	}
}

//adds a node at the front of linked list
void addNode(Node **head,int data)
{
    Node *node=createNode(data);
    if(*head==NULL)
    {
        *head=node;
        return;
    }
    else
    {
        node->next=*head;
        *head=node;
        return;
    }
}

//allocates memory for a graph of 'v' vertices
void createGraph(AdjList g[],int v)
{
	for (int i = 0; i < v; ++i)
	{
		g[i].head=NULL;
	}
}

//creates an edge between 'u' and 'v'
//u-->v , u and v are the node indices
void createEdge(AdjList g[],int u,int v)
{
    addNode(&g[u].head,v);
}

//shows all the u-->v edges present in the graph
void showEdges(AdjList g[],int v)
{
    Node *temp=NULL;
    for(int i=0;i<v;i++)
    {//check whether there is any edge associated with the current vertex or not
        if(g[i].head!=NULL)
        {
            temp=g[i].head;
            while(temp)
            {
                cout<<temp->data;
                if(temp->next)
                    cout<<"-->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
}


int main()
{
	//for no. of vertices
	const int v=5;
	//for no. of edges
	int e=4;

	//create an array of Node with element equal top total number of vertices.
	AdjList g[v];
	createGraph(g,v);

	createEdge(g,1,2);
	createEdge(g,1,3);
	createEdge(g,1,4);
	createEdge(g,1,5);

    showEdges(g,v);
	return 0;
}
