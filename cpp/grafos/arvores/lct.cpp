/* Baseado na implementacao do Sleator */
class Node {
public:
    int id;
    bool rev;
    Node *l, *r, *p;
    Node(){
      l = r = p = NULL;
      rev = false;
    }
    Node (int i) {
      id = i;
      l = r = p = NULL;
      rev = false;
    }

    // se eh raiz de splay tree
    bool isroot() {
      return p==NULL || (p->l != this && p->r != this);
    }
    
    /* If this node is flipped, we unflip it, and push the change
       down the tree, so that it represents the same thing. */
    void normalize() {
      if (rev) {
          rev = false;
          swap(l,r);
          
          if (l != NULL) l->rev ^= 1;
          if (r != NULL) r->rev ^= 1;
      }
      // Lazy propagation aqui
    }

    /* The tree structure has changed in the vicinity of this node
       (for example, if this node is linked to a different left
       child in a rotation).  This function fixes up the data fields
       in the node to maintain invariants. */
    void update() {
      // Node update aqui
      // Considerar vizinhos com o valor calculado
    }
};

namespace LinkCut{
  inline void connect(Node *ch, Node *p){
    if (ch != NULL)
      ch->p = p;
  }
  inline void connect(Node *ch, Node *p, bool isLeftChild) {
    connect(ch,p);
    if (isLeftChild)
      p->l = ch;
    else
      p->r = ch;
  }

  inline void rotate(Node * x) {
    Node *p = x->p;
    Node *g = p->p;
    bool isRootP = p->isroot();
    bool leftChildX = (x == p->l);

    // create 3 edges: (x.r(l),p), (p,x), (x,g)
    connect(leftChildX ? x->r : x->l, p, leftChildX);
    connect(p, x, !leftChildX);
    if(!isRootP)
      connect(x, g, p == g->l);
    else
      connect(x,g);
    p->normalize();
    p->update();
  }

  inline void splay(Node * x) {
    while (!x->isroot()) {
      Node * p = x->p;
      Node * g = p->p;
      if (!p->isroot())
        g->normalize();
      p->normalize();
      x->normalize();
      if (!p->isroot())
        rotate((x == p->l) == (p == g->l) ? p/*zig-zig*/ : x/*zig-zag*/);
      rotate(x);
    }
    x->normalize();
    x->update();
  }

    /* This makes node q the root of the virtual tree, and also q is the 
       leftmost node in its splay tree */
    inline Node* expose(Node *q) {
      Node *r = NULL;
      for (Node *p=q; p != NULL; p=p->p) {
          splay(p);
          
          p->l = r;
          r = p;
      };
      splay(q);
      return r;
    }

    /*
     * Para arvores genericas
     * */
    inline void makeRoot(Node *p){
      expose(p);
      p->rev = !p->rev;
      p->normalize();
    }

    /* assuming p and q are nodes in different trees and  
       that p is a root of its tree, this links p to q */ 
    inline void link(Node *p, Node *q) {
      makeRoot(p); // Quando arvore eh generica
      expose(p); // quando arvore eh rooteada
      
      expose(q);
      p->p = q;
    }

    /**
     * Metodo para arvore rooteada
     * */
    inline void cut(Node *p){
      expose(p);
      p->r->p = NULL;
      p->r = NULL;
    }

    /**
     * Metodo para arvore generica
     * */
    inline void cut(Node *p, Node *q){
      makeRoot(p);
      expose(q);
      assert(p->r != NULL);
      q->r->p = NULL;
      q->r = NULL;
    }

    /* this returns the id of the node that is the root of the tree containing p */
    inline int rootid(Node *p) {
      expose(p);
      while(p->r != NULL) p = p->r;
      splay(p);
      return p->id;
    }
};

Node * nodes[MAXN];
