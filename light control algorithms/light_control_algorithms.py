"""
Author: Sam Donnelly 
Project: Desktop Christmas Tree
Date Created: October 16, 2021
Date Last Modified: October 16, 2021

Purpose:
- Generate equations used to control light sequences in the Arduino Code


"""

# ---------------------------------------------------------------------------
# Import Libraries
# ---------------------------------------------------------------------------
from matplotlib import pyplot as plt
from math import pi

# ---------------------------------------------------------------------------
# Import Functions
# ---------------------------------------------------------------------------
from light_control_functions import sine_func, cosine_func

# ---------------------------------------------------------------------------
# File Locations
# ---------------------------------------------------------------------------


# ---------------------------------------------------------------------------
# Global Variables
# ---------------------------------------------------------------------------

# General 


# Function 0xB0 
T_B0   = 20000      # Sequence period 
T_B0_W = 0.3*T_B0   # Individual wave period 

PWM_B0_0 = [0]*T_B0
PWM_B0_1 = [0]*T_B0
PWM_B0_2 = [0]*T_B0
PWM_B0_3 = [0]*T_B0
time_B0  = [0]*T_B0

# Function 0xC0 
T_C0   = 50000
T_C0_W = 100

PWM_C0_0 = [0]*T_C0
PWM_C0_1 = [0]*T_C0
PWM_C0_2 = [0]*T_C0
PWM_C0_3 = [0]*T_C0
time_C0  = [0]*T_C0

t1  = T_C0*0.1000
t2  = T_C0*0.1010
t3  = T_C0*0.1020
t4  = T_C0*0.1030
t5  = T_C0*0.1040
t6  = T_C0*0.3000
t7  = T_C0*0.3200
t8  = T_C0*0.6000
t9  = T_C0*0.6005
t10 = T_C0*0.6010
t11 = T_C0*0.6015
t12 = T_C0*0.6020
t13 = T_C0*0.9970
t14 = T_C0*0.9980
t15 = T_C0*0.9990
t16 = T_C0

calc_C0 = 0

# ---------------------------------------------------------------------------
# Main Code
# --------------------------------------------------------------------------- 

# Function 0xB0
for i in range(T_B0):
    time_B0[i] = i

    if (i < 0.2*T_B0/8):
        PWM_B0_0[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((1*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
        PWM_B0_3[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((-1*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < 1.8*T_B0/8):
        PWM_B0_0[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((1*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < 2.2*T_B0/8):
        PWM_B0_0[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((1*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
        PWM_B0_1[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((3*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < 3.8*T_B0/8):
        PWM_B0_1[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((3*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < 4.2*T_B0/8):
        PWM_B0_1[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((3*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
        PWM_B0_2[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((5*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < 5.8*T_B0/8):
        PWM_B0_2[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((5*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < 6.2*T_B0/8):
        PWM_B0_2[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((5*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
        PWM_B0_3[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((7*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < 7.8*T_B0/8):
        PWM_B0_3[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((7*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
    
    elif (i < T_B0):
        PWM_B0_0[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((9*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)
        PWM_B0_3[i] = sine_func(127.5, 2*pi/T_B0_W, \
            2*pi*((7*T_B0-4*T_B0_W)/(8*T_B0_W)) + 90*pi/180, 127.5, i)


# Function 0xC0: Pumpkin Darth Vader Light Saber
for i in range(T_C0): 
    time_C0[i] = i

    if (i < t1):
        PWM_C0_0[i] = 0
        PWM_C0_1[i] = 0
        PWM_C0_2[i] = 0
        PWM_C0_3[i] = 0
    
    elif (i < t2):
        PWM_C0_0[i] = 255
        PWM_C0_1[i] = 0
        PWM_C0_2[i] = 0
        PWM_C0_3[i] = 0
    
    elif (i < t3):
        PWM_C0_0[i] = 255
        PWM_C0_1[i] = 255
        PWM_C0_2[i] = 0
        PWM_C0_3[i] = 0
    
    elif (i < t4):
        PWM_C0_0[i] = 255
        PWM_C0_1[i] = 255
        PWM_C0_2[i] = 255
        PWM_C0_3[i] = 0
   
    elif (i < t5):
        PWM_C0_0[i] = 255
        PWM_C0_1[i] = 255
        PWM_C0_2[i] = 255
        PWM_C0_3[i] = 255
    
    elif (i < t6):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = calc_C0
    
    elif (i < t7):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 150, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = calc_C0
    
    elif (i < t8):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = calc_C0
    
    elif (i < t9):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = 0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = calc_C0
    
    elif (i < t10):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = 0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = calc_C0
    
    elif (i < t11):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = 0
        PWM_C0_3[i] = calc_C0
    
    elif (i < t12):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = 0
    
    elif (i < t13):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = calc_C0
    
    elif (i < t14):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = calc_C0
        PWM_C0_3[i] = 0
    
    elif (i < t15):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = calc_C0
        PWM_C0_2[i] = 0
        PWM_C0_3[i] = 0
    
    elif (i < t16):
        calc_C0 = cosine_func(25, 2*pi/T_C0_W, 0, 230, i)
        PWM_C0_0[i] = calc_C0
        PWM_C0_1[i] = 0
        PWM_C0_2[i] = 0
        PWM_C0_3[i] = 0


# Function B0
fig_B0, ax_B0 = plt.subplots()
ax_B0.plot(time_B0, PWM_B0_0)
ax_B0.plot(time_B0, PWM_B0_1)
ax_B0.plot(time_B0, PWM_B0_2)
ax_B0.plot(time_B0, PWM_B0_3)

# Function C0 
fig_C0, ax_C0 = plt.subplots()
ax_C0.plot(time_C0, PWM_C0_0)
ax_C0.plot(time_C0, PWM_C0_1)
ax_C0.plot(time_C0, PWM_C0_2)
ax_C0.plot(time_C0, PWM_C0_3)

plt.show()

plt.close(fig_B0)
plt.close(fig_C0)




