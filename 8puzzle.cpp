#include <bits/stdc++.h>
using namespace std;

#define pi= 3.14 ;
struct grid
{
    string s = "";
    int pos = 0;
};

set<string> visited;
stack<string> st;
unordered_map<string, string> parent;
string start_state = "";

grid up(grid grd)
{
    if (grd.pos > 2)
    {
        swap(grd.s[grd.pos], grd.s[grd.pos - 3]);
        grd.pos -= 3;
    }
    return grd;
}
grid down(grid grd)
{
    if (grd.pos < 6)
    {
        swap(grd.s[grd.pos], grd.s[grd.pos + 3]);
        grd.pos += 3;
    }
    return grd;
}
grid left(grid grd)
{
    if (grd.pos % 3 != 0)
    {
        swap(grd.s[grd.pos], grd.s[grd.pos - 1]);
        grd.pos--;
    }
    return grd;
}
grid right(grid grd)
{
    if ((grd.pos + 1) % 3 != 0)
    {
        swap(grd.s[grd.pos], grd.s[grd.pos + 1]);
        grd.pos++;
    }
    return grd;
}

void solvePuzzle(queue<grid> q)
{
    while (true)
    {
        if (q.size() == 0)
        {
            return;
        }
        grid g = q.front();
        q.pop();
        if (g.s == "123456780")
        {
            string temp = g.s;
            while (temp != start_state)
            {
                st.push(temp);
                temp = parent[temp];
            }
            st.push(start_state);
            return;
        }
        grid Up = up(g);
        grid Down = down(g);
        grid Left = left(g);
        grid Right = right(g);

        if (visited.count(Up.s) == 0)
        {
            q.push(Up);
            visited.insert(Up.s);
            parent[Up.s] = g.s;
        }
        if (visited.count(Down.s) == 0)
        {
            q.push(Down);
            visited.insert(Down.s);
            parent[Down.s] = g.s;
        }
        if (visited.count(Left.s) == 0)
        {
            q.push(Left);
            visited.insert(Left.s);
            parent[Left.s] = g.s;
        }
        if (visited.count(Right.s) == 0)
        {
            q.push(Right);
            visited.insert(Right.s);
            parent[Right.s] = g.s;
        }
    }
}
int main()
{
    vector<vector<int>> v;
    string S;
    int Pos = 0;
    for (int i = 0; i < 3; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            S = S + to_string(v[i][j]);
            if (v[i][j] == 0)
            {
                Pos = (i * 3 + j);
            }
        }
    }

    grid g;
    start_state = S;
    g.s = S;
    g.pos = Pos;
    queue<grid> q;
    q.push(g);
    visited.insert(g.s);
    solvePuzzle(q);
    if (st.size() == 0)
    {
        cout << "\nThere is no possible solution for given Combination!\n"
             << endl;
        return 0;
    }
    while (!st.empty())
    {
        string str = st.top();
        for (int i = 0; i < 3; i++)
        {
            cout << "\t\t\t";
            for (int j = 0; j < 3; j++)
            {
                if (str[3 * i + j] != '0')
                    cout << str[3 * i + j] << "   ";
                else
                    cout << "_   ";
            }
            cout << endl
                 << endl;
        }
        st.pop();
        cout << "\n\n";
    }
    if (st.size() == 0)
    {
        cout << "\n\t\t\t\t\t\t\t\tReached Goal State Succesfully!"
             << "\n\n\n";
    }
}