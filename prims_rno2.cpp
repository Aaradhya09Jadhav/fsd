#include<iostream>
#include<vector>
using namespace std;

#define MAX_VAL 9999

class graph{
    int n, edges, cost[20][20];
    public:
        void accept_graph();
        void display_graph();
        int prims();

};

void graph::accept_graph(){
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>edges;

    int So,Des,Co;

    for (int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            cost[i][j]=MAX_VAL;

        }
    }

    for (int i=0;i<edges;i++){
        cout<<"Enter source, destination and cost: ";
        cin>>So>>Des>>Co;

        cost[So][Des]=Co;
        cost[Des][So]=Co;


    }
}

void graph::display_graph(){
    cout<<"The cost matrix is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<<"\t";

        }
        cout<<endl;
    }
}

int graph::prims()
{
    int start_v;
    int r = 0;
    int j;
    int mincost = 0;
    int min;
    int t[n - 1][3];
    int nearest[n];
    cout << "Enter starting vertex" << endl;
    cin >> start_v;
    nearest[start_v] = -1;
    for (int i = 0; i < n; i++)
    {
        if (i != start_v)
            nearest[i] = start_v;
    }

    for (int i = 0; i < n - 1; i++)
    {
        min = MAX_VAL;
        for (int k = 0; k < n; k++)
        {

            if (nearest[k] != -1 && cost[k][nearest[k]] < min)
            {
                j = k;
                min = cost[k][nearest[k]];
            }
        }
        t[r][0] = j;
        t[r][1] = nearest[j];
        t[r][2] = min;
        r = r + 1;
        mincost += cost[j][nearest[j]];
        nearest[j] = -1;

        for (int k = 0; k < n; k++)
        {
            if (nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j])
                nearest[k] = j;
        }
    }
    cout << "matrix" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int a = 0; a < 3; a++)
        {
            cout << t[i][a] << "\t";
        }
        cout << "\n";
    }
    return mincost;
}


int main(){
    graph g1;
    g1.accept_graph();
    g1.display_graph();
    int minC=g1.prims();
    cout<<"Minimum cost:"<<minC;

    return 0;
}








