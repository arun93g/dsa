#include<bits/stdc++.h>

using namespace std;



void dfs(int num,list<int> adjacency[])
{
    stack<int> Stack;
    vector<bool> visited(8,false);  //this 8 is total number of nodes in graph

    Stack.push(num);

    while(!Stack.empty())
    {
        int num=Stack.top();
        Stack.pop();

        if(!visited[num])
        {
            cout<<num<<" ";
            visited[num]=true;
        }

        for(auto it:adjacency[num])
        {
            if(!visited[it])
                Stack.push(it);
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

       cout<<endl<<"Depth first search of the graph is : ";
       dfs(1,adjacency);
       cout<<endl;



    return 0;
}
