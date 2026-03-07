padre(alberto, juan).
padre(alberto, luis).
padre(pedro, roberto).
padre(pedro, alberto).
nieto(X, Z) :- padre(Y, X), padre(Z, Y).
hermano(X, Y) :- padre(Z, X), padre(Z, Y), X \= Y.