import numpy as np
import matplotlib.pyplot as plt

#n°37
#Classe 21
#Maya Meziane, Kanto Andriambololo-Nivo & Houda El Oijaji

#Entrer les paramètres
A        = float(input("Amplitude du cosinus A   = "))
C        = float(input("Amplitude du sinus C    = "))
f        = float(input("Fréquence du signal (Hz) f       = "))
phi      = float(input("Phase (radians) φ       = "))
duration = float(input("Durée du signal (s)     = "))
bits     = int(input("Profondeur de bits (par échantillon) = "))

#Étape 1: Signal continu
t_cont = np.linspace(0, duration, int(1000*duration), endpoint=False)
x_cont = A*np.cos(2*np.pi*f*t_cont+phi) + C*np.sin(2*np.pi*f*t_cont)
plt.figure()
plt.plot(t_cont, x_cont, color='orange')
plt.title('Étape 1 : Signal continu')
plt.xlabel('Temps (s)')
plt.ylabel('Amplitude')
plt.grid(True)
plt.savefig('etape1_signal_continu.png')
plt.close()

#Étape 2: Échantillonnage
Ts = 1/(2*f)  #période d'échantillonnage 
t_samp = np.arange(0, duration, Ts)
x_samp = A*np.cos(2*np.pi*f*t_samp+phi) + C*np.sin(2*np.pi*f*t_samp)
plt.figure()
plt.plot(t_cont, x_cont, color='gray', alpha=0.7, label='Signal continu')
plt.stem(
    t_samp, x_samp,
    linefmt='C1-', markerfmt='C1o', basefmt=" ",
    label='Échantillons'
)
plt.title('Étape 2 : Échantillonnage')
plt.xlabel('Temps (s)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)
plt.savefig('etape2_echantillonnage.png')
plt.close()

#Étape 3: Quantification

L = 2**bits
xmin, xmax = x_samp.min(), x_samp.max()
indices = np.round((x_samp - xmin)/(xmax - xmin)*(L-1)).astype(int)
x_quant = xmin + indices*(xmax - xmin)/(L-1)
# Calcul de l'erreur maximale de quantification
err_max = np.max(np.abs(x_samp - x_quant))
plt.figure()
plt.plot(t_cont, x_cont, color='gray', alpha=0.7, label='Signal continu')
plt.stem(
    t_samp, x_quant,
    linefmt='C2-', markerfmt='C2s', basefmt=" ",
   # label=f'Quantifié ({L} niveaux), err_max={err_max:.3f}'
)
plt.title('Étape 3 : Quantification')
plt.xlabel('Temps (s)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)
plt.savefig('etape3_quantification.png')
plt.close()
#print(f"Erreur maximale après quantification : ")

#Étape 4: Encodage binaire et taille
codes = [format(i, f'0{bits}b') for i in indices]
num_samples = len(indices)
total_bits = num_samples*bits
total_bytes = total_bits/8
print(f"Nombre d'échantillons : {num_samples}")
print(f"Taille encodée        : {total_bits} bits ({total_bytes:.2f} octets)")
print("Codes binaires        :", codes)

# Étape 5 : Reconstruction du signal
x_rec = np.interp(t_cont, t_samp, x_quant)
plt.figure()
plt.plot(t_cont, x_cont, 'orange', label='signal depart1')#debut
plt.plot(t_cont, x_rec, 'blue', linestyle='--', label='Reconstruit')#signal fin
plt.title('Étape 5 : Reconstruction')
plt.xlabel('Temps (s)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)
plt.savefig('etape5_reconstruction.png')
plt.close()

#test
print('PNG générés : step1_signal_continu.png, step2_echantillonnage.png, step3_quantification.png, step5_reconstruction.png')
