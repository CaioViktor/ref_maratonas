struct node{
  node * child[26];
  char letter;
  node(){
    for(int i = 0; i < 26; i++) child[i] = NULL;
  }
  node(char c){
    for(int i = 0; i < 26; i++) child[i] = NULL;
    letter = c;
  }
};

node * root;


node * nd_add(node *at, char c){
  if(at->child[c-'a'] == NULL){
    at->child[c-'a'] = new node(c);
  }
  
  return at->child[c-'a'];
}

void add_str(string s, node * root){
  node * curr = root;
  
  for(int i = 0; i < (int)s.size(); i++){
    curr = nd_add(curr, s[i]);
  }
}

// para criar uma trie nova
node * root = new node();
