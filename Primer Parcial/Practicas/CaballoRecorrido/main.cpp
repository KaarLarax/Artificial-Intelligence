// BY LARA 1424
// https://codeforces.com/profile/DarkoLaraSlowed
// https://github.com/KaarLarax
// https://www.youtube.com/@KaarLarax

#include <bits/stdc++.h>

// Namespaces
using namespace std;

// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;

// Macros
#define debug(x) cerr << #x << " = " << x << '\n'
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb emplace_back
#define edl '\n'

// Macros para iteraciones
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; --i)
#define each(x, a) for(auto &x : a)

// Utility Functions
template<class T>
bool chmax(T &A, T &&B) { return B > A ? A = B, true : false; }

template<class T>
bool chmin(T &A, T &&B) { return B < A ? A = B, true : false; }

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
void debug_vector(vector<T> &v) {
    cerr << "[ ";
    for (T &x: v) cerr << x << " ";
    cerr << "]" << edl;
}

// Constants
constexpr int64_t LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr array<int, 4> dx{1, 0, -1, 0};
constexpr array<int, 4> dy{0, 1, 0, -1};

// Funciones de entrada/salida
template<typename T>
void read(T &x) { cin >> x; }

template<typename T>
void read(vector<T> &v) { for (T &x: v) cin >> x; }

template<typename T>
void write(const T &x) { cout << x << '\n'; }

template<typename T>
void write_vector(const vector<T> &v) {
    for (const T &x: v) cout << x << ' ';
    cout << '\n';
}

set<pair<char, int>> visitado;
queue<pair<char, int>> recorrido;
bool meta;
pair<char, int> target;

bool validacion(pair<char, int> aux) {
    return !meta &&
    visitado.find(aux) == visitado.end() &&
    aux.first >= 'A' && aux.first <= 'H' &&
    aux.second >= 1 && aux.second <= 8;
}
void dfs(pair<char, int> casilla) {
    visitado.insert(casilla);
    if (casilla == target) {
        meta = true;
        recorrido.push(casilla);
        return;
    }
    pair<char, int> aux;
    aux = {casilla.first - 1, casilla.second - 2};
    if (validacion(aux)) {
        dfs(aux);
    }
    aux = {casilla.first - 1, casilla.second + 2};
    if (validacion(aux)) {
        dfs(aux);
    }
    aux = {casilla.first + 1, casilla.second + 2};
    if (validacion(aux)) {
        dfs(aux);
    }
    aux = {casilla.first + 1, casilla.second - 2};
    if (validacion(aux)) {
        dfs(aux);
    }
    aux = {casilla.first - 2, casilla.second - 1};
    if (validacion(aux)) {
        dfs(aux);
    }
    aux = {casilla.first - 2, casilla.second + 1};
    if (validacion(aux)) {
        dfs(aux);
    }
    aux = {casilla.first + 2, casilla.second + 1};
    if (validacion(aux)) {
        dfs(aux);
    }
    aux = {casilla.first + 2, casilla.second - 1};
    if (validacion(aux)) {
        dfs(aux);
    }
    if (meta) {
        recorrido.push(casilla);
    }
}

void bfs(pair<char, int> casilla) {
    
}

// Main funtion
int32_t main() {
    // Fast I/O Setup
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    target = {'A', 1};
    dfs({'C', 3});
    int contador = 0;
    while (!recorrido.empty()) {
        cout << recorrido.front().fi << ' ' << recorrido.front().se << edl;
        recorrido.pop();
        contador++;
    }
    debug(contador);
    return 0;
}