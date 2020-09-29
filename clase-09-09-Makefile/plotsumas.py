import numpy as np
import matplotlib.pyplot as plt

datax, datay = np.loadtxt("sumas.txt", unpack = True)

fig, ax = plt.subplots()
ax.plot(datax, datay, 'r-o', label="Data")
ax.legend()
ax.set_xlabel("Numero de terminos")
ax.set_ylabel("Delta %")

fig.savefig("fig.pdf")
