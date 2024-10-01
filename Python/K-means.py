import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

X=-2 *np.random.rand(100,2)
X1 = 1+ 2 * np.random.rand(50,2)
X[50:100, :] = X1

Kmean = KMeans(n_clusters=2)
Kmean.fit(X)
Kmean.cluster_centers_
Kmean.labels_
#array([[-0.94665068,-0.97138368], [2.01559419,2.02597093]])

sample_test = np.array([-3.0,-3.0])
second_test=sample_test.reshape(1,-1)
Kmean.predict(second_test)
plt.scatter(X[ : , 0], X[ :, 1], s=50, c = 'b')
plt.scatter(-0.94665068,-0.97138368, s=200,c='g', marker='s')
plt.scatter(2.01559419,2.02597093,s=200,c='r', marker='s' )
plt.show()
