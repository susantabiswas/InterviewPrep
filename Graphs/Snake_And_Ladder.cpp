//Find the minimum number of dice throws to reach the end of snake and ladder board from the starting point
//a vertex has edges to next six vertices unless there is any ladder or snake in between
#include<iostream>
#include<list>
using namespace std;

struct Adj
{
	//vertex number
	int v;
	//for keeping the distance of vertex from the start
	int dist;
};

//gets the minimum dice throws
int getMinDiceThrows(int *moves,int n)
{
	bool visited[n];
	//make every vertex unvisited
	for (int i = 0; i < n; ++i)
	{
		visited[i]=false;
	}

	//make a queue for BFS
	list<Adj> queue;

	//starting point has a distance of 0 and vertex number 0
	Adj node;
	node.v=0;
	node.dist=0;
	queue.push_back(node);
	visited[0]=true;

	Adj u;
	//while the queue is not empty calcuate the number of dice throw
	while(!queue.empty())
	{
		u=queue.front();
		queue.pop_front();

        //work done when the end of the board is reached
        if(u.v==n-1)
            break;

        //now insert the adjacent vertices of 'u'
        for (int i = u.v+1;i<=(u.v+6) && i < n; ++i)
        {
            //if the node is not visited
            if(!visited[i])
            {
                Adj node;
                node.dist=u.dist+1;

                //in case there is a snake or a ladder
                if(moves[i]!=-1)
                    node.v=moves[i];
                else
                    node.v=i;

                queue.push_back(node);
                visited[i]=true;
            }
        }
    }

	return u.dist;
}

int main()
{
	int n = 30;
	//contains -1 if the i-th position doesn't have any ladder or snake
	//else contains the vertex number where the snake or ladder leads to
    int moves[n];
    for (int i = 0; i<n; i++)
        moves[i] = -1;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Min Dice throws: " << getMinDiceThrows(moves, n);
    return 0;
}
