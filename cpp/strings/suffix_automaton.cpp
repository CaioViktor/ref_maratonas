#include <bits/stdc++.h>
#define MAXST 20001 // max 2*|w|-1
#define PRIMARY 1
#define SECONDARY 0
#define UNDEFINED -10
#define SOURCE 0
using namespace std;

typedef vector<int> vi;

struct DawgEdge {
	int dest;
	bool type;
	DawgEdge() { assert(false); }
	DawgEdge(bool) {}
};

struct DawgNode {
	int suffixPointer;
	vi endSet;
};

typedef map<char, DawgEdge> mcd;
typedef pair<char, DawgEdge> cd;

int stcount;
mcd edges[MAXST]; DawgNode nodes[MAXST];

int split(int parentState, int childState, char a) {
	int newChildState = stcount++;	
	edges[parentState][a].type = PRIMARY;
	edges[parentState][a].dest = newChildState;
	
	for (mcd::iterator ed = edges[childState].begin(), fim = edges[childState].end(); 
		 ed != fim; ++ed) {
			 DawgEdge newEdge = ed->second;
			 newEdge.type = SECONDARY;
			 edges[newChildState].insert(cd(ed->first, newEdge));
		}
	
	nodes[newChildState].suffixPointer = nodes[childState].suffixPointer;
	nodes[childState].suffixPointer = newChildState;
	
	int currentState = parentState;
	while (currentState != SOURCE) {
		currentState = nodes[currentState].suffixPointer;
		bool flag = false;
		for (mcd::iterator ed = edges[currentState].begin(), fim = edges[currentState].end(); 
		 ed != fim; ++ed) {
			if (ed->second.type == SECONDARY && ed->second.dest == childState) {
				flag = true;
				ed->second.dest = newChildState;
			}
		 }
		 if (!flag) break;
	}
	
	return newChildState;
}

int updateDawg(int currentSink, char a) {
	
	int newSink = stcount++;
	DawgEdge newEdge(true);
	newEdge.dest = newSink; newEdge.type = PRIMARY;
	edges[currentSink].insert(cd(a, newEdge));

	int currentState = currentSink, suffixState = UNDEFINED;
	
	while (currentState != SOURCE && suffixState == UNDEFINED) {
		
		currentState = nodes[currentState].suffixPointer;
		
		if (!edges[currentState].count(a)) {
			newEdge.dest = newSink; newEdge.type = SECONDARY;
			edges[currentState].insert(cd(a,newEdge));
		} else {
			DawgEdge e = edges[currentState][a];
			if (e.type == PRIMARY)
				suffixState = e.dest;
			else 
				suffixState = split(currentState, e.dest, a);		
		}
	}
	if (suffixState == UNDEFINED) 
		suffixState = SOURCE;
	
	nodes[newSink].suffixPointer = suffixState;	
	return newSink;
}

void supDawg(string word) {
	stcount = 1;
	for (int i=0; i<MAXST; i++)
		edges[i].clear(), nodes[i] = DawgNode();
	
	int currentSink = SOURCE;
	for (int i=0, len = word.length(); i<len; i++) {
		currentSink = updateDawg(currentSink, word[i]);
	}
}

inline void buildEndSets(string word) {
	int currState = 0, suffixState;
	for (int i=0, len = word.length(); i<len; i++) {
		currState = suffixState = edges[currState][word[i]].dest;
		while (suffixState != SOURCE) {
			nodes[suffixState].endSet.push_back(i+1);
			suffixState = nodes[suffixState].suffixPointer;
		}
	}
}
