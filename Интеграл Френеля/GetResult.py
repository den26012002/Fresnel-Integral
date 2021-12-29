import matplotlib.pyplot as plt
import numpy as np

amplitudes = np.loadtxt("resultAmplitudes.txt", dtype=np.complex)
intensities = np.abs(amplitudes) * np.abs(amplitudes)
plt.imshow(intensities)
plt.show()
