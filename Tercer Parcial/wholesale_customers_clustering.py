import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import warnings
import scipy.cluster.hierarchy as sch
from sklearn.preprocessing import normalize
from sklearn.cluster import AgglomerativeClustering



data = pd.read_csv('https://archive.ics.uci.edu/ml/machine-learning-databases/00292/Wholesale%20customers%20data.csv')

max = data.max()
min = data.min()

dat_scaled = normalize (data)
dat_scaled

plt.figure(figsize=(10, 7))
plt.title("Dendrograms")
dend = sch.dendrogram(sch.linkage(dat_scaled, method='ward'))
plt.axhline(y=6, color='r', linestyle='--')

cluster = AgglomerativeClustering(n_clusters=4, linkage='ward')
cluster.fit_predict(dat_scaled)

data_scaled = pd.DataFrame(dat_scaled, columns=data.columns)
plt.figure(figsize=(10, 7))
plt.scatter(data_scaled['Milk'], data_scaled['Grocery'], c=cluster.labels_)
plt.show()