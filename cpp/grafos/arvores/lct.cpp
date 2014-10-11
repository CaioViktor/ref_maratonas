/* Baseado na implementacao do Sleator */
class Node {
public:
    int s, my_s, id;
    Node *l, *r, *p;
    Node(){
      l = r = p = NULL;
    }
    Node (int c, int i) {
      id = i;
      s = my_s = c;
      l = r = p = NULL;
    }

    // se eh raiz de splay tree
    bool isroot() {
      return p==NULL || (p->l != this && p->r != this);
    }
    
    // "Push" a alteraçao para os filhos
    void normalize() {
      //if (flip) {
          //flip = false;
          //on = s-on;
          //my_flip = !my_flip;
          //if (l != NULL) l->flip = !l->flip;
          //if (r != NULL) r->flip = !r->flip;
      //}
    }

    /* The tree structure has changed in the vicinity of this node
       (for example, if this node is linked to a different left
       child in a rotation).  This function fixes up the data fields
       in the node to maintain invariants. */
    void update() {
      //s = my_s;
      //if (l != NULL) {
          //s += l->s;
      //}
      //if (r != NULL) {
          //s += r->s;
      //}
    }
};

namespace LinkCut{
    inline void rotR (Node *p) {
      Node *q = p->p;
      Node *r = q->p;
      q->normalize();
      p->normalize();
      if ((q->l=p->r) != NULL) q->l->p = q;
      p->r = q;
      q->p = p;
      if ((p->p=r) != NULL) {
          if (r->l == q) r->l = p;
          else if (r->r == q) r->r = p;
      }
      q->update();
    }

    inline void rotL (Node *p) {
      Node *q = p->p;
      Node *r = q->p;
      q->normalize();
      p->normalize();
      if ((q->r=p->l) != NULL) q->r->p = q;
      p->l = q;
      q->p = p;
      if ((p->p=r) != NULL) {
          if (r->l == q) r->l = p;
          else if (r->r == q) r->r = p;
      }
      q->update();
    }

    inline void splay(Node *p) {
      while (!p->isroot()) {
        Node *q = p->p;
        if (q->isroot()) {
          if (q->l == p) rotR(p); else rotL(p);
        } else {
          Node *r = q->p;
          if (r->l == q) {
            if (q->l == p) {rotR(q); rotR(p);}
            else {rotL(p); rotR(p);}
          } else {
              if (q->r == p) {rotL(q); rotL(p);}
              else {rotR(p); rotL(p);}
          }
        }
      }
      p->normalize(); // only useful if p was already a root.
      p->update();    // only useful if p was not already a root
    }

    /* This makes node q the root of the virtual tree, and also q is the 
       leftmost node in its splay tree */
    inline Node* expose(Node *q) {
      Node *r = NULL;
      for (Node *p=q; p != NULL; p=p->p) {
          splay(p);
          
          p->l = r;
          p->update();
          r = p;
      };
      splay(q);
      return r;
    }

    /* assuming p and q are nodes in different trees and  
       that p is a root of its tree, this links p to q */ 
    inline void link(Node *p, Node *q) {
      expose(p);
      //assert(p->r == NULL);
      expose(q);
      p->p = q;
    }

    inline void cut(Node *p){
      expose(p);
      p->r->p = NULL;
      p->r = NULL;
    }

    /* this returns the id of the node that is the root of the tree containing p */
    inline int rootid(Node *p) {
      expose(p);
      while(p->r != NULL) p = p->r;
      splay(p);
      return p->id;
    }
    
    inline int lca(Node *p, Node *q){
      expose(p);
      Node *r = expose(q);
      if(r == NULL) return q->id;
      return r->id;
    }
};

Node * nodes[MAXN];
