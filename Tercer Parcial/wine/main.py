from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn import neighbors
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics
wine = datasets.load_wine()

print(wine)
print("-------------------------------------------------")
print(wine.DESCR)
print("-------------------------------------------------")
print(wine.feature_names)
print("-------------------------------------------------")
print(wine.target_names)
print("-------------------------------------------------")
print(wine.data[0:5])
print("-------------------------------------------------")
print(wine.target)
print("-------------------------------------------------")
print(wine.data.shape)
print("-------------------------------------------------")
print(wine.target.shape)
print("-------------------------------------------------")

X_train, X_test, y_train, y_test = train_test_split(wine.data, wine.target, test_size=0.3, random_state=40)
model = KNeighborsClassifier(n_neighbors=30)
model.fit(X_train, y_train)
y_predict = model.predict(X_test)

print("Acurracy: ", metrics.accuracy_score(y_test, y_predict))