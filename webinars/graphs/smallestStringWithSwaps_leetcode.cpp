class Solution {
public:
void dfs(int src,bool *visited,unordered_map<int,list<int> > &m,vector<int> &indices){
	visited[src]=true;
	indices.push_back(src);

	for(auto child:m[src]){
		if(!visited[child]){
			dfs(child,visited,m,indices);
		}
	}
}

string smallestStringWithSwaps(string s,vector<vector<int> > pairs){
	unordered_map<int,list<int> > m;

	for(int i=0;i<pairs.size();i++){
		m[pairs[i][0]].push_back(pairs[i][1]);
		m[pairs[i][1]].push_back(pairs[i][0]);
	}

	bool visited[100001] = {0};
	for(auto node:m)
	{
		if(!visited[node.first])
		{
			vector<int> indices;
			
			dfs(node.first,visited,m,indices);
			vector<char> characters;

			for(int i=0;i<indices.size();i++){
				characters.push_back(s[indices[i]]);
			}

			sort(characters.begin(),characters.end());
			sort(indices.begin(),indices.end());

			for(int i=0;i<characters.size();i++){
				s[indices[i]]=characters[i];
			}
		}
	}
	return s;
}

};