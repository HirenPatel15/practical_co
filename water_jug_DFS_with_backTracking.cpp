#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> visited; //declaring a set of visited states as empty
stack<pair<int, int>> st;	 // declareing a stack to keep track of path of goal state in recurtion


//  WE CAN DO FOLLOWING 6 OPERATIONS TO RACH A GOAL STATE.   FIIL, EMPTY, OR TRANSFER FOR BOTH JUG


pair<int, int> fillFirstJug(pair<int, int> state, int jug1, int jug2) // to fill first jug
{
	return {jug1, state.second};
}
pair<int, int> fillSecondJug(pair<int, int> state, int jug1, int jug2)// to fill second jug
{
	return {state.first, jug2};
}
pair<int, int> emptyFirstJug(pair<int, int> state)					  // to empty first jug 
{
	return {0, state.second};
}
pair<int, int> emptySecondJug(pair<int, int> state)					 // to empty second jug
{
	return {state.first, 0};
}

pair<int, int> transferFirstToSecond(pair<int, int> state, int jug1, int jug2) // to transfer water from first jug to second
{
	if (state.first <= (jug2 - state.second))
	{
		return {0, state.first + state.second};
	}
	else
	{
		return {(state.first + state.second - jug2), jug2};
	}
}

pair<int, int> transferSecondToFirst(pair<int, int> state, int jug1, int jug2) // to transfer water to second jug to first 
{
	if (state.second <= (jug1 - state.first))
	{
		return {state.first + state.second, 0};
	}
	else
	{
		return {jug1, (state.first + state.second - jug1)};
	}
}

bool getPath(pair<int, int> state, int jug1, int jug2, int target)
{


	
	visited.insert(state); // mark a state as visited



	if ((state.first == target) || (state.second == target)) // if reached to goal state then returns true
	{
		state.first==target? st.push({state.first,0}) : st.push({0,state.second});
		st.push(state);
		return true;
	}

// going through all possible path recursively

	if (visited.count(fillFirstJug(state, jug1, jug2)) == 0 && getPath(fillFirstJug(state, jug1, jug2), jug1, jug2, target))
	{
		st.push(state);
		return true;
	}
	if (visited.count(fillSecondJug(state, jug1, jug2)) == 0 && getPath(fillSecondJug(state, jug1, jug2), jug1, jug2, target))
	{
		st.push(state);
		return true;
	}
	if (visited.count(emptyFirstJug(state)) == 0 && getPath(emptyFirstJug(state), jug1, jug2, target))
	{
		st.push(state);
		return true;
	}
	if (visited.count(emptySecondJug(state)) == 0 && getPath(emptyFirstJug(state), jug1, jug2, target))
	{
		st.push(state);
		return true;
	}
	if (visited.count(transferFirstToSecond(state, jug1, jug2)) == 0 && getPath(transferFirstToSecond(state, jug1, jug2), jug1, jug2, target))
	{
		st.push(state);
		return true;
	}
	if (visited.count(transferSecondToFirst(state, jug1, jug2)) == 0 && getPath(transferSecondToFirst(state, jug1, jug2), jug1, jug2, target))
	{
		st.push(state);
		return true;
	}
	return false;
}

int main()
{
	int jug1, jug2, target;
	cout <<endl<< "Enter the capacity jug1 and jug2 : ";
	cin >> jug1 >> jug2;
	cout <<endl<< "Enter the target volume of the water in the jug : ";
	cin >> target;

	if(__gcd(jug1,jug2) != 1 and target%(__gcd(jug1,jug2))!=0){
		cout<<"Not possible to reach the goal state!!"<<endl;
		return 0;
	}
	visited.insert({jug1, jug2});

	getPath({0, 0}, jug1, jug2, target);
	cout<<endl<<"The path to reach a goal state is : "<<endl<<endl;
	while (!st.empty())
	{
		cout << st.top().first << " " << st.top().second << endl;
		st.pop();
	}

	return 0;
}