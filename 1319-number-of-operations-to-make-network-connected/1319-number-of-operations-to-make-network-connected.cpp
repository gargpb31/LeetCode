class Solution {
public:


    int find(vector<int> &parent, int i){
		if(parent[i]==i) return i;
		parent[i]=find(parent,parent[i]);
		return parent[i];
	
	}

    int makeConnected(int n, vector<vector<int>>& connections) {
        	vector<int> parent(n);
	vector<int> rank(n,0);
	for(int i=0; i<n; i++) parent[i]=i;
	
	
	int freedge=0;

	for(auto it : connections){
int rootf = find(parent,it[0]);
int roots= find(parent,it[1]);

if(rootf==roots) freedge++;
else {
	if(rank[rootf]>rank[roots]) parent[roots]=rootf;
	else if (rank[rootf]<rank[roots]) parent[rootf]=roots;
	else {
	parent[rootf]=roots;
	rank[rootf]++;
}

}
	
	}

	
	for(int i=0; i<n; i++) {
		parent[i]=find(parent,i);
	}
	
	int components=0;

	for(int i=0; i<n; i++){
if(parent[i]==i) components++;
	
	}

	if(components-1<=freedge) return components-1;
	return -1;

    }
};