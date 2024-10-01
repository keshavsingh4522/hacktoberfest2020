import matplotlib.pyplot as plt

A=['eat', 'movie', 'study', 'play','daily_work','sleep']
T=[1,3,5,4,2,9]

plt.pie(T, labels=A,autopct= '%1.1f%%')
plt.title('Pie chart of daily activity.')
plt.show()
