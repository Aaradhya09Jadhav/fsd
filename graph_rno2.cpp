#include<iostream>
using namespace std;
#define MAX_VAL 9999

struct gnode {
    int id;
    string username;
    gnode* next;
};

class graph {
    int n, edges, cost[20][20], visited[20];
    gnode* head[20];
    friend class Stack;

public:
    graph();
    void accept_graph();
    void display();
    void prims();
    void DFT_rec();
    void DFT_r(int r);
    void DFT_NR();
    void BFT_NR();
    void BFT_R(int v);
};

class Stack {
    int st[20];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int d) {
        top++;
        st[top] = d;
    }

    int pop() {
        int t = st[top];
        top--;
        return t;
    }

    int empty() {
        return (top == -1);
    }
};

class Queue {
    int st[20];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int d) {
        top++;
        st[top] = d;
    }

    int pop() {
        int t = st[top];
        top--;
        return t;
    }

    int empty() {
        return (top == -1);
    }
};

graph::graph() {
   
    for (int i = 0; i < 20; i++) {
        head[i] = nullptr;
    }
}

void graph::accept_graph()
{
    cout << "Enter no. of vertices: ";
    cin >> n;

    cout << "Enter No of edges: ";
    cin >> edges;

    int So, Des, Co;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = MAX_VAL;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter Sources & Destination & Cost: ";
        cin >> So >> Des >> Co;

        cost[So][Des] = Co;
        cost[Des][So] = Co;
    }
}

void graph::prims()
{
    int nearest[20], S, i, j, R[20][20], m = 0;
    cout << "Enter Start Vertex: ";
    cin >> S;

    nearest[S] = -1;

    for (i = 0; i < n; i++)
    {
        if (i != S)
        {
            nearest[i] = S;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        int min = MAX_VAL;

        for (int k = 0; k < n; k++)
        {
            if (nearest[k] != -1 && min > cost[k][nearest[k]])
            {
                min = cost[k][nearest[k]];
                j = k;
            }
        }

        R[m][0] = nearest[j];
        R[m][1] = j;
        m++;

        nearest[j] = -1; 
    }
}

void graph::DFT_rec()
{
    int r;
    cout << "Enter Start User ID: ";
    cin >> r;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[r] = 1;
    DFT_r(r);
}

void graph::DFT_r(int r)
{
    cout << r << " ";

    for (int i = 0; i < n; i++)
    {
        if (cost[r][i] != MAX_VAL && visited[i] == 0)
        {
            visited[i] = 1;
            DFT_r(i);
        }
    }
}

void graph::display() 
{
    gnode* temp;

    for (int i = 0; i < n; i++) {
        temp = head[i];
        cout << "\n " << head[i]->username << ": ";
        while (temp != nullptr) {
            cout << "-" << temp->username;
            temp = temp->next;
        }
        cout << endl;
    }
}

void graph::DFT_NR() {
    Stack S;
    int v;
    cout << "Enter Starting User ID: ";
    cin >> v;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    S.push(v);
    visited[v] = 1;

    while (!S.empty()) {
        v = S.pop();
        cout << v << " " << head[v]->username;

        gnode* temp = head[v]->next;
        while (temp != NULL) {
            if (visited[temp->id] == 0) {
                S.push(temp->id);
                visited[temp->id] = 1;
            }
            temp = temp->next;
        }
    }
}

void graph::BFT_NR() 
{
    Queue q;
    int v;
    cout << "Enter Starting User ID: ";
    cin >> v;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    q.push(v);
    visited[v] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " " << head[current]->username << "\n";

        gnode* temp = head[current]->next;
        while (temp != NULL) {
            int w = temp->id;
            if (!visited[w]) {
                q.push(w);
                visited[w] = 1;
            }
            temp = temp->next;
        }
    }
}

void graph::BFT_R(int v) {
    if (visited[v] == 0) {
        cout << v << " " << head[v]->username << "\n";
        visited[v] = 1;

        gnode* temp = head[v]->next;
        while (temp != NULL) {
            int w = temp->id;
            BFT_R(w);
            temp = temp->next;
        }
    }
}


int main()
{
    graph g;
    g.accept_graph();
    
    int X;
    cout<<"Choose\n1. DFT R\n2. DFT NR\n3. BFT R\n4. BFT NR";
    cin>>X;

    switch(X){

        case 1: g.DFT_rec(); 
                break;

        case 2: g.DFT_NR();
                break;

        case 3: g.BFT_R(0);
                 
                break;

        case 4: g.BFT_NR();
                break;

        default: exit(0);

    }

    return 0;
}


























/*#include<iostream>
using namespace std;
#define MAX_VAL 9999

struct gnode {
    int id;
    string username;
    gnode* next;
};

class graph
{
    int n, edges, cost[20][20], visited[20];
    gnode* head[20];

public:
    graph();
    void accept_graph();
    void display();
    void prims();
    void DFT_rec();
    void DFT_r(int r);
};

graph::graph() {
   
    for (int i = 0; i < 20; i++) {
        head[i] = nullptr;
    }
}

void graph::accept_graph()
{
    cout << "Enter no. of vertices: ";
    cin >> n;

    cout << "Enter No of edges: ";
    cin >> edges;

    int So, Des, Co;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = MAX_VAL;
        }
    }

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter Source: ";
        cin >> So;
		cout<<"Enter destination:";
		cin>>Des;
		cout<<"Enter cost:";
		cin>>Co;

        cost[So][Des] = Co;
        cost[Des][So] = Co;
    }
}

void graph::prims()
{
    int nearest[20], S, i, j, R[20][20], m = 0;
    cout << "Enter Start Vertex: ";
    cin >> S;

    nearest[S] = -1;

    for (i = 0; i < n; i++)
    {
        if (i != S)
        {
            nearest[i] = S;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        int min = MAX_VAL;

        for (int k = 0; k < n; k++)
        {
            if (nearest[k] != -1 && min > cost[k][nearest[k]])
            {
                min = cost[k][nearest[k]];
                j = k;
            }
        }

        R[m][0] = nearest[j];
        R[m][1] = j;
        m++;

        nearest[j] = -1; 
    }
}

void graph::DFT_rec()
{
    int r;
    cout << "Enter Start User ID: ";
    cin >> r;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[r] = 1;
    DFT_r(r);
}

void graph::DFT_r(int r)
{
    cout << r << " ";

    for (int i = 0; i < n; i++)
    {
        if (cost[r][i] != MAX_VAL && visited[i] == 0)
        {
            visited[i] = 1;
            DFT_r(i);
        }
    }
}

void graph::display() 
{
    gnode* temp;

    for (int i = 0; i < n; i++) {
        temp = head[i];
        cout << "\n " << head[i]->username << ": ";
        while (temp != nullptr) {
            cout << "-" << temp->username;
            temp = temp->next;
        }
        cout << endl;
    }
}



int main()
{
    graph g;
    g.accept_graph();
    // g.display();
    g.DFT_rec(); 

    return 0;
}

int ch;
switch(ch){
	int x;
	case 1:
		g.DFT(r);
	case 2:
		g.DFT_nonrec(r)
	

}




















#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class gnode
{
    int vertex;
    gnode *next;
    friend class graph;
};

class graph
{
private:
    gnode *head[20];
    int n;
    int visit[20];

public:
    graph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            head[i] = new gnode;
            head[i]->vertex = i;
            head[i]->next = NULL;
        }
    }

    void create();
    void dft_r();
    void dft_r(int v);
    void dft_nr(int v);
    void bfs(int v);
    void DFT_nonrec();
    ~graph(); 
};

class Stack{
    int st[20];
    int top=-1;
    public :
        void push(int d) {
            top++;
            st[top]=d;
        }
        int pop(){
            int t = st[top];
            top--;
            return t;
        }
        int empty(){
            if (top==-1){
                return 1;
            }
            else {
                return 0;
            }
        }
        int top_element(){
            return st[top];
        }
};

void graph::create()
{
    int v;
    char ch;
    for (int i = 0; i < n; i++)
    {
        gnode *temp = head[i];
        do
        {
            cout << "Enter vertex adjacent to " << head[i]->vertex << ": ";
            cin >> v;
            if (v == i)
            {
                cout << "Not allowed";
            }
            else
            {
                gnode *curr = new gnode;
                curr->vertex = v;
                curr->next = NULL;
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Are there more adjacent nodes? ";
            cin >> ch;

        } while (ch == 'y');
    }
}

void graph::dft_r()
{
    int v;
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }
    cout << "Enter the starting node: ";
    cin >> v;
    dft_r(v);
}


void graph::dft_r(int v)
{
    cout << v << "\n";
    visit[v] = 1;
    gnode *temp = head[v]->next;
    while (temp != NULL)
    {
        int w = temp->vertex;
        if (!visit[w])
        {
            dft_r(w);
        }
        temp = temp->next;
    }
}

void graph::dft_nr(int v)
{
    Stack s;
    s.push(v);
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }
    while (!s.empty())
    {
        int current = s.top_element();
        s.pop();
        if (!visit[current])
        {
            cout << current << "\n";
            visit[current] = 1;
            gnode *temp = head[current]->next;
            stack<int> tempStack;
            while (temp != NULL)
            {
                int w = temp->vertex;
                if (!visit[w])
                {
                    tempStack.push(w);
                }
                temp = temp->next;
            }
            while (!tempStack.empty())
            {
                s.push(tempStack.top());
                tempStack.pop();
            }
        }
    }
}

graph::~graph()
{
    for (int i = 0; i < n; i++)
    {
        gnode *current = head[i];
        while (current != NULL)
        {
            gnode *temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int main()
{
    graph g;
    g.create();
    cout << "DFT Recursive: \n";
    g.dft_r();
    cout << "DFT Non-Recursive: \n";
    g.dft_nr(0); 
    return 0;
}














#include<iostream>
using namespace std;
#define MAX_VAL 9999

class graph
{
    int n, edges, cost[20][20];
    public:
    void accept_graph();
    void display_graph();
    void prims();
	void DFT_rec();
	void DFT_r();
};

void graph :: accept_graph()
{
    cout<<"Enter no. of vertices: ";
    cin>>n;

    cout<<"Enter No of edges: ";
    cin>>edges;

    int So, Des, Co;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<edges; j++)
        {
            cost[i][j]= MAX_VAL;
        }
    }
    
    for(int i =0; i<edges; i++)
    {
        cout<<"Enter Sources & Destination & Cost: ";
        cin>>So>>Des>>Co;

        cost[So][Des] = Co;
        cost[Des][So] = Co;
    }

        
}

void graph :: prims()
{
    int nearest[20],S,i,j, R[20][20], m=0;
    cout<<"Enter Start Vertex: ";
    cin>>S;

    nearest[S]=-1;

    for(i = 0; i<n; i++)
    {
        if(i!=S)
        {
            nearest[i] = S;
        }
    }

    for(i=0;i<n-1;i++)
    {
        int min=MAX_VAL;

        for(int k=0; k<n; k++)
        {
            if(nearest[k]!=-1 && min>cost[k][nearest[k]])
            {
                min=cost[k][nearest[k]];
                j=k;
            }
        }

        R[m][0]=nearest[j];
        

    }
}

void graph :: DFT_rec(){
	int r;
	cout<<"Enter start user ID";
	cin>>r;

	for(int i=0;i<n;i++){
		visited[i]=0;
		visited[r]=1;
		DFT_r(r);

	}
}

void graph :: DFT_r(int r){
	cout<<r<<head[r]->name;
	temp=head[v]->next;
	if(visited[temp->id]==0){

	}
}





#include <iostream>
using namespace std;

class gnode
{
public:
    int id;
    string username;
    gnode *next;

    gnode()
    {
        id = 0;
        username = "";
        next = nullptr;
    }
    friend class graph;
};

class graph
{
public:
    int n;
    gnode *head[10];

    graph()
    {
        n = 0;
        cout << "Enter the number of users: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            head[i] = new gnode;
            head[i]->id = i;
            cout << "Enter the name for user " << i << " : ";
            cin >> head[i]->username;
        }
    }

    void create();
    void display();
    void dfs_r();
    void dfs_r(int, int *);
};

void graph::create()
{
    char d;
    int id;
    gnode *temp, *current;
    for (int i = 0; i < n; i++)
    {
        temp = head[i];
        cout << "--------------------------------------------" << endl;
        cout << "Enter the friends of " << head[i]->username << ":" << endl;
        do
        {
            cout << "Enter the id of the friend: ";
            cin >> id;
            if (id == head[i]->id)
            {
                cout << "A user cannot be their own friend!!!" << endl;
            }
            else
            {
                current = new gnode;
                current->id = id;
                cout << "Enter the name of the friend: ";
                cin >> current->username;
                temp->next = current;
                temp = temp->next;
            }
            cout << "Do you want to add another friend? (Y/N): ";
            cin >> d;
        } while (d == 'Y' || d == 'y');
    }
}

void graph::display()
{
    gnode *temp;
    for (int i = 0; i < n; i++)
    {
        temp = head[i];
        cout << "\nFriends of " << head[i]->username << ": ";
        while (temp != nullptr)
        {
            cout << "-" << temp->username;
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    graph g;
    g.create();
    g.display();
    return 0;
}












#include <iostream>
using namespace std;

class node{
	int user_id;
	string username;
	node *next;
	};
	
class graph{
	int n;
	node *head[20];
	public:
		void create();
		void display();
		}
		
	void graph::create(){
		cout<<"Enter number of user";
		cin>>n;
		for(int i=0;i<n;i++){
			head[i]=new node;
			cout<<"Enter number of users: "<<i+1;
			}
		}

*/

