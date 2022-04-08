#include <bits/stdc++.h>
using namespace std;

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
    while(true){
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

void print(string s)
{
    int k = 0;
    int pos, row, col;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            pos = i;
        }
    }
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')  ;
        else
        {
            str = str + s[i];
        }
    }
    s = str;

    row = pos / 3;
    col = pos % 3;
    cout << "\n";
    for (int i = 0; i < 14; i++)
    {
        cout << "\t";
        for (int j = 0; j < 29; j++)
        {
            if (i == 0)
            {
                cout << "_";
            }
            else if (i == 13)
            {
                if (j == 0 || j == 28)
                    cout << "|";
                else
                    cout << "_";
            }
            else if (j == 0 || j == 28)
            {
                cout << "|";
            }
            else if ((i >= row * 4 + 1 and i <= row * 4 + 4) and ((j >= col * 9 + 2 and j <= col * 9 + 8)))
            {
                cout << " ";
            }
            else if ((i - 4) % 4 == 0)
            {
                if (j > 1 and j < 9)
                {
                    if (j == 2 || j == 8)
                        cout << "|";
                    else
                        cout << "_";
                }
                else if (j > 10 and j < 18)
                {
                    if (j == 11 || j == 17)
                        cout << "|";
                    else
                        cout << "_";
                }
                else if (j > 19 and j < 27)
                {
                    if (j == 20 || j == 26)
                        cout << "|";
                    else
                        cout << "_";
                }
                else
                    cout << " ";
            }
            else if ((i - 1) % 4 == 0)
            {
                if (j > 1 and j < 9)
                {
                    cout << "_";
                }
                else if (j > 10 and j < 18)
                {
                    cout << "_";
                }
                else if (j > 19 and j < 27)
                {
                    cout << "_";
                }
                else
                    cout << " ";
            }
            else if (j == 2 || j == 8)
            {
                cout << "|";
            }
            else if (j == 11 || j == 17)
            {
                cout << "|";
            }
            else if (j == 20 || j == 26)
            {
                cout << "|";
            }
            else if ((i + 1) % 4 == 0 and (j + 4) % 9 == 0)
            {
                cout << s[k++];
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
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
    int sz = st.size();
    string c;
    getline(cin, c);
    while (!st.empty())
    {
        system("cls");
        print(st.top());
        getline(cin, c);
        st.pop();
    }
    if (sz != 0)
    {
        cout << "\nReached Goal Succesfully :) \n ";
    }
    else{
        cout <<"this is not possible";
    }
    
}