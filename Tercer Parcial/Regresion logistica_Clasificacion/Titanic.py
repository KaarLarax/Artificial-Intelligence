import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

url = 'https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv'
data = pd.read_csv(url)

data['Sex'] = data['Sex'].map({'male' : 0, 'female' : 1})

print(data['Sex'])
print('_______________________________')
data['Embarked'] = data['Embarked'].map({'C' : 0, 'Q' : 1, 'S' : 2})

print(data['Embarked'])
print('_______________________________')
data.dropna(subset = ['Embarked'], inplace = True)

data['Age'].fillna(data['Age'].median(), inplace = True)
print(data['Age'])
print('_______________________________')
nulos = data.isnull().sum()

print(nulos)
print('_______________________________')
features = ['Pclass', 'Sex', 'Age', 'Embarked']

X = data[features]

y = data ['Survived']

X_train, X_test, y_train, y_test = train_test_split(X,y, test_size = 0.2, random_state = 42)

model = LogisticRegression(max_iter = 200)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
conf_matrix = confusion_matrix(y_test, y_pred)
class_report = classification_report(y_test, y_pred)

print(accuracy)
print('_______________________________')
print(conf_matrix)
print('_______________________________')
print(class_report)
print('_______________________________')