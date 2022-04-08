#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> visited; // declaring a set of visited states as empty
stack<pair<int, int>> st;
pair<int, int> arr[100][100];

pair<int, int> fillFirstJug(pair<int, int> state, int jug1, int jug2) 
{
    return {jug1, state.second};
}
pair<int, int> fillSecondJug(pair<int, int> state, int jug1, int jug2) 
{
    return {state.first, jug2};
}
pair<int, int> emptyFirstJug(pair<int, int> state) 
{
    return {0, state.second};
}
pair<int, int> emptySecondJug(pair<int, int> state)
{
    return {state.first, 0};
}

pair<int, int> transferFirstToSecond(pair<int, int> state, int jug1, int jug2) {
    if (state.first <= (jug2 - state.second))
    {
        return {0, state.first + state.second};
    }
    else
    {
        return {(state.first + state.second - jug2), jug2};
    }
}

pair<int, int> transferSecondToFirst(pair<int, int> state, int jug1, int jug2) 
{

    visited.insert(state);
    if (state.second <= (jug1 - state.first))
    {
        return {state.first + state.second, 0};
    }
    else
    {
        return {jug1, (state.first + state.second - jug1)};
    }
}

void returnPath(pair<int, int> state, int target)
{

    if (state.first == target and state.second != 0)
    {
        st.push({target, 0});
    }
    else if (state.first != 0 and state.second == target)
    {
        st.push({0, target});
    }
    pair<int, int> temp = state;
    while (temp.first != 0 || temp.second != 0)
    {
        st.push(temp);
        temp = arr[temp.first][temp.second];
    }
    st.push({0, 0});
    return;
}

void getPath(int jug1, int jug2, int target, queue<pair<int, int>> q)
{

    pair<int, int> state = q.front();
    q.pop();
    visited.insert(state);

    if (state.first == target || state.second == target)
    {
        returnPath(state, target);
        return;
    }
    else
    {

        pair<int, int> ff = fillFirstJug(state, jug1, jug2);
        pair<int, int> fs = fillSecondJug(state, jug1, jug2);
        pair<int, int> ef = emptyFirstJug(state);
        pair<int, int> es = emptySecondJug(state);
        pair<int, int> tfs = transferFirstToSecond(state, jug1, jug2);
        pair<int, int> tsf = transferSecondToFirst(state, jug1, jug2);

        if (visited.count(ff) == 0)
        {
            q.push(ff);
            visited.insert(ff);
            arr[ff.first][ff.second] = state;
        }
        if (visited.count(fs) == 0)
        {
            q.push(fs);
            visited.insert(fs);
            arr[fs.first][fs.second] = state;
        }
        if (visited.count(ef) == 0)
        {
            q.push(ef);
            visited.insert(ef);
            arr[ef.first][ef.second] = state;
        }
        if (visited.count(es) == 0)
        {
            q.push(es);
            visited.insert(es);
            arr[es.first][es.second] = state;
        }
        if (visited.count(tfs) == 0)
        {
            q.push(tfs);
            visited.insert(tfs);
            arr[tfs.first][tfs.second] = state;
        }
        if (visited.count(tsf) == 0)
        {
            q.push(tsf);
            visited.insert(tsf);
            arr[tsf.first][tsf.second] = state;
        }
        getPath(jug1, jug2, target, q);
    }
}

int main()
{
    int jug1, jug2, target;
    queue<pair<int, int>> q;

    cout << endl
         << "Enter capacity of jug1 and jug2 : " << endl;
    cin >> jug1 >> jug2;

    cout << endl
         << "Enter target volume of water in either jug : " << endl;
    cin >> target;

    visited.insert({jug1, jug2});
    visited.insert({0, 0});
    q.push({0, 0});

    getPath(jug1, jug2, target, q);

    cout << "  jug1  "
         << "jug2" << endl;
    while (!st.empty())
    {
        cout << " (  " << st.top().first << " ,  " << st.top().second << "  )" << endl;
        st.pop();
    }


    return 0;
}