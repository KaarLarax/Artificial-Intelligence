#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 8; // Tamaño del tablero de ajedrez
const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Estructura para almacenar una posición en el tablero
struct Position {
    int x, y;
};

// Estructura para la cola de prioridad
struct Node {
    Position pos;
    int g; // Costo desde el punto inicial
    int h; // Heurística
    int f; // Costo total (g + h)

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Verifica si una posición está dentro del tablero
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Calcula la heurística (distancia de Chebyshev)
int heuristic(Position a, Position b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

// Implementación del algoritmo A*
vector<Position> aStar(Position start, Position end) {
    priority_queue<Node, vector<Node>, greater<Node>> openList;
    vector<vector<bool>> closedList(N, vector<bool>(N, false));
    vector<vector<Position>> cameFrom(N, vector<Position>(N));

    Node startNode = {start, 0, heuristic(start, end), heuristic(start, end)};
    openList.push(startNode);
    cameFrom[start.x][start.y] = {-1, -1};

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current.pos.x == end.x && current.pos.y == end.y) {
            vector<Position> path;
            Position step = end;
            while (!(step.x == start.x && step.y == start.y)) {
                path.push_back(step);
                step = cameFrom[step.x][step.y];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        if (closedList[current.pos.x][current.pos.y]) {
            continue;
        }
        closedList[current.pos.x][current.pos.y] = true;

        for (int i = 0; i < 8; ++i) {
            int newX = current.pos.x + dx[i];
            int newY = current.pos.y + dy[i];

            if (isValid(newX, newY) && !closedList[newX][newY]) {
                Node neighbor = { {newX, newY}, current.g + 1, heuristic({newX, newY}, end), current.g + 1 + heuristic({newX, newY}, end) };
                openList.push(neighbor);
                cameFrom[newX][newY] = current.pos;
            }
        }
    }
    return {}; // Retorna un camino vacío si no se encuentra un camino
}

int main() {
    Position start = {0, 0}; // Punto de inicio
    Position end = {7, 7}; // Punto final

    vector<Position> path = aStar(start, end);

    if (path.empty()) {
        cout << "No se encontró un camino." << endl;
    } else {
        cout << "Camino encontrado:" << endl;
        for (const auto& pos : path) {
            cout << "(" << pos.x << ", " << pos.y << ")" << endl;
        }
    }

    return 0;
}
