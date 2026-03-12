import graphviz

def generate_floating_point_automaton():
    dot = graphviz.Digraph()

    # Estados
    states = ['0', '1', '2', '3', '4', '5', '6', '7']
    for state in states:
        shape = 'doublecircle' if state in ['2', '4', '7'] else 'circle'
        dot.node(state, state, shape=shape)

    # Transiciones
    dot.edge('0', '1', label='+,-')
    dot.edge('0', '2', label='0-9')
    dot.edge('1', '2', label='0-9')
    dot.edge('2', '2', label='0-9')
    dot.edge('2', '3', label='.')
    dot.edge('3', '4', label='0-9')
    dot.edge('4', '4', label='0-9')
    dot.edge('2', '5', label='E,e')
    dot.edge('4', '5', label='E,e')
    dot.edge('5', '6', label='+,-')
    dot.edge('5', '7', label='0-9')
    dot.edge('6', '7', label='0-9')
    dot.edge('7', '7', label='0-9')

    return dot

# Generar y visualizar el autómata
automaton = generate_floating_point_automaton()
automaton.render('floating_point_automaton', format='png', cleanup=False)