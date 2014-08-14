// Nesse caso, busca o menor Y para um dado X. para buscar o maior, basta
// mudar o comparador na funcao query e inverter a ordenacao das linhas

struct line{
  ll m,b;
  line(){}
  line(ll m_, ll b_):m(m_), b(b_){ }
};

// testa se line 2 eh irrelevante
bool irrelevant(line l1, line l2, line l3){
  return (l1.b - l3.b)*(l2.m - l1.m) < (l1.b - l2.b)*(l3.m - l1.m);
}


line lines[MAX_L];
int hbl; // ultimo elemento de lines: inicializar com 0

void add_line(ll m, ll b){
  line curr(m,b);
  
  while(hbl >= 2 && irrelevant(lines[hbl-2],lines[hbl-1], curr)){
    hbl--;
  }
  lines[hbl++] = curr;
}

int pointer;
ll query(ll x){
  if(pointer >= hbl){
    pointer = hbl-1;
  }
  while(pointer < hbl-1 && lines[pointer+1].m*x + lines[pointer+1].b
    < lines[pointer].m*x + lines[pointer].b )  pointer++;

  return lines[pointer].m*x + lines[pointer].b;
}


// Exemplo:
hbl = pointer = 0;
for(int i = 0; i < n; i++){
  add_line(m[i],b[i]);
  query(x[i]);
}
