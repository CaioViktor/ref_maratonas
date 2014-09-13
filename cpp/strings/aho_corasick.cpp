#define MAXS 10000 //Soma dos tamanhos de todas keywords
#define MAXC 26 //Numero de caracteres no alfabeto
#define LCHAR 'A' // Menor e menor caracteres do alfabeto
#define HCHAR 'Z'

/* Utilizacao:
    - keywords.push_back('keyword') ...
    - buildMatchingMachine();
    - currentState = 0;
    - para cada caractere do texto:
        currenState = findNextState(currentState, text[i])
    - out[currentState] eh a bitmask de todas keywords que
      estão 'matched' no estado atual. */

int out[MAXS], f[MAXS], g[MAXS][MAXC];
vector<int> keywords;

inline void buildMatchingMachine() {
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    int states = 1;

    for (int i = 0; i < keywords.size(); ++i) {
        int currentState = 0;
        for (int j = 0; j < keywords[i].size(); ++j) {
            int c = keywords[i][j] - LCHAR;
            if (g[currentState][c] == -1) {
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState] |= (1 << i);
    }

    for (int c = 0; c < MAXC; ++c) {
        if (g[0][c] == -1) {
            g[0][c] = 0;
        }
    }

    queue<int> q;
    for (int c = 0; c <= HCHAR - LCHAR; ++c) { 
        if (g[0][c] != -1 and g[0][c] != 0) {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= HCHAR - LCHAR; ++c) {
            if (g[state][c] != -1) {
                int failure = f[state];
                while (g[failure][c] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure];
                q.push(g[state][c]);
            }
        }
    }
}

inline int findNextState(int currentState, char nextInput) {
    int answer = currentState;
    int c = nextInput - LCHAR;
    while (g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}