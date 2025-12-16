import matplotlib.pyplot as plt
import numpy as np

sizes, bubble, heap = np.loadtxt("results.csv", delimiter=',', unpack=True)

plt.plot(sizes, bubble, 'o-', label="Сортировка пузырьком")
plt.plot(sizes, heap, 's-', label="Пирамидальная сортировка")
plt.xlabel("Количество элементов")
plt.ylabel("Время (сек)")
plt.legend()
plt.grid(True)
plt.show()
