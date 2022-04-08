#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int, int>, int>
#define M first.first
#define C first.second
#define position second

set<pii> visited;
stack<pii> st;
pii parent[100][100][100];

pii missionary(pii state)
{
    state.M = state.M + state.position;
    state.position = -state.position;
    return state;
}
pii cannible(pii state)
{
    state.C = state.C + state.position;
    state.position = -state.position;
    return state;
}
pii missionaryAndCannible(pii state)
{
    state.C = state.C + state.position;
    state.M = state.M + state.position;
    state.position = -state.position;
    return state;
}
pii twoMissionary(pii state)
{
    state.M = state.M + (state.position * 2);
    state.position = -state.position;
    return state;
}
pii twoCannible(pii state)
{
    state.C = state.C + (state.position * 2);
    state.position = -state.position;
    return state;
}

bool possible(pii state)

{
    if (state.M < 0 || state.C < 0 || state.M > 3 || state.C > 3)
    {
        return false;
    }
    if (state.M > state.C)
    {
        if (state.C > 0)
        {
            return false;
        }
    }
    if (state.C > state.M)
    {
        if (state.C < 3)
        {
            return false;
        }
    }
    return true;
}

void solveMissionaryCannible(queue<pii> q) //

{
    if (q.size() == 0)
    {
        return;
    }
    pii state = q.front();
    q.pop();
    if (state.M == 0 and state.C == 0)
    {
        while (state.M != 3 || state.C != 3)
        {
            st.push(state);
            if (state.position == -1)
                state = parent[state.M][state.C][0];
            else
                state = parent[state.M][state.C][1];
        }
        st.push({{3, 3}, -1});
        return;
    }
    if (possible(missionary(state)) && visited.count(missionary(state)) == 0)
    {
        pii temp = missionary(state);
        q.push(temp);
        int i = temp.M;
        int j = temp.C;
        int k = temp.position;
        if (k == -1)
            k = 0;
        parent[i][j][k] = state;
        visited.insert(temp);
    }
    if (possible(cannible(state)) && visited.count(cannible(state)) == 0)
    {
        pii temp = cannible(state);
        q.push(temp);
        int i = temp.M;
        int j = temp.C;
        int k = temp.position;
        if (k == -1)
            k = 0;
        parent[i][j][k] = state;
        visited.insert(temp);
    }
    if (possible(missionaryAndCannible(state)) && visited.count(missionaryAndCannible(state)) == 0)
    {
        pii temp = missionaryAndCannible(state);
        q.push(temp);
        int i = temp.M;
        int j = temp.C;
        int k = temp.position;
        if (k == -1)
            k = 0;
        parent[i][j][k] = state;
        visited.insert(temp);
    }
    if (possible(twoMissionary(state)) && visited.count(twoMissionary(state)) == 0)
    {
        pii temp = twoMissionary(state);
        q.push(temp);
        int i = temp.M;
        int j = temp.C;
        int k = temp.position;
        if (k == -1)
            k = 0;
        parent[i][j][k] = state;
        visited.insert(temp);
    }
    if (possible(twoCannible(state)) && visited.count(twoCannible(state)) == 0)
    {
        pii temp = twoCannible(state);
        q.push(temp);
        int i = temp.M;
        int j = temp.C;
        int k = temp.position;
        if (k == -1)
            k = 0;
        parent[i][j][k] = state;
        visited.insert(temp);
    }
    solveMissionaryCannible(q);
}

int main()
{

    pii initialState = {{3, 3}, -1};
    queue<pii> q;
    q.push(initialState);
    visited.insert(initialState);
    solveMissionaryCannible(q);
    cout << endl
         << endl;

    cout << "state    ";
    while (!st.empty())
    {
        cout << "(" << st.top().M << ", " << st.top().C << ", " << st.top().position << ")     ";
        st.pop();
    }
    return 0;
}