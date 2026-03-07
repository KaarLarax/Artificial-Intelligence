import numpy as np
from sklearn.preprocessing import StandardScaler, MinMaxScaler

# Datos de ejemplo
data = np.array([[1], [2], [3], [4], [5]]).astype(float)

# Estandarización
scaler_standard = StandardScaler()
standardized_data = scaler_standard.fit_transform(data)

print("Estandarización:")
print(standardized_data)

# Normalización
scaler_minmax = MinMaxScaler()
normalized_data = scaler_minmax.fit_transform(data)

print("\nNormalización:")
print(normalized_data)
