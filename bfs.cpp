#include<bits/stdc++.h>

using namespace std;

void bfs(int num,list<int> adjacency[])
{
    queue<int> Queue;
    vector<bool> visited(8,false);

    Queue.push(num);

    while(!Queue.empty())
    {
        int num=Queue.front();
        Queue.pop();

        if(!visited[num])
        {
            visited[num]=true;
            cout<<num<<" ";
        }

        for(int it:adjacency[num])
        {
            if(!visited[it])
                 Queue.push(it);
        }
    }

}


int main()
{
    list<int> adjacency[]={
                      {},
                      {2,3,8},
                      {4},
                      {5},
                      {6},
                      {4,7,8},
                      {2},
                      {},
                      {},
                    };

    /*  list<int> adjacency[]={
                              {1,2},
                              {2},
                              {0,3},
                              {3},
                             };  */

         cout<<endl<<"the breadth first search for the graph is : ";
         bfs(2,adjacency);
         cout<<endl;
}
