from sklearn import preprocessing
from sklearn.neighbors import KNeighborsClassifier

le = preprocessing.LabelEncoder()

cielo = ['soleado', 'soleado', 'cubierto', 'lluvioso', 'lluvioso', 'lluvioso',
         'cubierto', 'soleado', 'soleado', 'lluvioso', 'soleado',
         'cubierto', 'cubierto', 'lluvioso']
print(cielo)

temperatura = ['caluroso', 'caluroso', 'caluroso', 'suave', 'fresco', 'fresco', 'fresco', 'suave',
               'fresco', 'suave', 'suave', 'suave', 'caluroso', 'suave']
print(temperatura)

jugar = ['no', 'no', 'si', 'si', 'si', 'no', 'si', 'no',
         'si', 'si', 'si', 'si', 'si', 'no']
print(jugar)

cielo_cod = le.fit_transform(cielo)
print(cielo_cod)

temperatura_cod = le.fit_transform(temperatura)
print(temperatura_cod)

jugar_cod = le.fit_transform(jugar)
print(jugar_cod)

humedad = ['high', 'high', 'high', 'high', 'normal', 'normal', 'normal', 'high',
           'normal', 'normal', 'normal', 'high', 'normal', 'high']
humedad_cod = le.fit_transform(humedad)
print(humedad_cod)

windy = ['false', 'true', 'false', 'false', 'false', 'true', 'true', 'false', 'false',
         'false', 'true', 'true', 'false', 'true']
windy_cod = le.fit_transform(windy)
print(windy_cod)

features = list(zip(cielo_cod, temperatura_cod, humedad_cod, windy_cod))
print(features)

model = KNeighborsClassifier(n_neighbors = 3)
model.fit(features, jugar_cod)

print("Hola, Juan en que puedo ayudarte?")

val1 = int(input("Dime, Como esta el cielo?"))
val2 = int(input("Dime, Como esta la temperatura?"))
val3 = int(input("Dime, Como esta la humedad?"))
val4 = int(input("Dime, hay viento?"))

predict = model.predict([[val1, val2, val3, val4]])
print("Prediccion: ", predict)




