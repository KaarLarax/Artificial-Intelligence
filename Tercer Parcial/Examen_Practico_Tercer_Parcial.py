import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.decomposition import PCA

# Función para calcular la distancia euclidiana entre puntos
def euclidean_distance(a, b):
    return np.sqrt(np.sum((a - b) ** 2))

# Cargar el conjunto de datos Iris
data = load_iris()
X = data.data

# Inicialización de variables
k = 3  # Número de clusters
n_samples, n_features = X.shape

# Inicializar los centroides seleccionando aleatoriamente puntos de X
np.random.seed(0)
centroids = X[np.random.choice(n_samples, k, replace=False)]

# Almacenar los centroides para compararlos en cada iteración
prev_centroids = np.zeros_like(centroids)
iterations = 0

# Bucle hasta que los centroides no cambien (convergencia)
while not np.array_equal(centroids, prev_centroids):
    # Asignación de cada punto al cluster más cercano
    labels = np.zeros(n_samples, dtype=int)
    for i, sample in enumerate(X):
        distances = [euclidean_distance(sample, centroid) for centroid in centroids]
        labels[i] = np.argmin(distances)

    # Guardar los centroides anteriores y calcular nuevos centroides
    prev_centroids = centroids.copy()
    for j in range(k):
        cluster_points = X[labels == j]
        if len(cluster_points) > 0:
            centroids[j] = cluster_points.mean(axis=0)

    # Mostrar los centroides y las etiquetas en cada iteración
    print(f"Iteración {iterations + 1}")
    print("Centroides:")
    print(centroids)
    print("Etiquetas de los clusters:")
    print(labels)
    print("-" * 50)

    # Visualización de la iteración actual con PCA
    pca = PCA(2)
    X_pca = pca.fit_transform(X)
    centroids_pca = pca.transform(centroids)

    plt.figure(figsize=(8, 6))
    plt.scatter(X_pca[:, 0], X_pca[:, 1], c=labels, s=50, cmap="viridis")
    plt.scatter(centroids_pca[:, 0], centroids_pca[:, 1], c='red', s=200, marker='X', label='Centroides')
    plt.title(f"K-means Clustering - Iteración {iterations + 1}")
    plt.xlabel("Componente Principal 1")
    plt.ylabel("Componente Principal 2")
    plt.legend()
    plt.show()

    iterations += 1