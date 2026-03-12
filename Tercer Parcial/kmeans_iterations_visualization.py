import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# Datos de ejemplo con dos atributos
X = np.array([
    [1.5, 2.5], [1, 1], [3, 3.5],
    [4.5, 5], [5, 4.5], [2.5, 2],
    [3.5, 4]
])

# Crear el modelo de K-means con k=2 (dos grupos)
kmeans = KMeans(n_clusters=2, init='random', n_init=1, max_iter=10, random_state=42)

# Configurar la figura para mostrar cada iteración
plt.figure(figsize=(8, 6))

# Ajustar el modelo de K-means y obtener la posición inicial de los centroides
for i in range(1, 11):
    kmeans.max_iter = i
    kmeans.fit(X)
    centroides = kmeans.cluster_centers_
    etiquetas = kmeans.labels_

    # Limpiar la gráfica para cada iteración
    plt.clf()

    # Graficar los puntos de datos con colores según su etiqueta
    colores = ['r', 'b']
    for j in range(len(X)):
        plt.scatter(X[j][0], X[j][1], color=colores[etiquetas[j]], s=50)

    # Dibujar los centroides
    plt.scatter(centroides[:, 0], centroides[:, 1], marker='x', s=200, c='k', label='Centroides')

    plt.title(f'K-means Iteración {i}')
    plt.xlabel('Atributo 1')
    plt.ylabel('Atributo 2')
    plt.legend()
    plt.grid()
    plt.pause(1)  # Pausa de un segundo para ver cada iteración

# Mostrar la figura final
plt.show()
