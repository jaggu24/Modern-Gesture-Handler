import numpy as np 
import pandas as pd
import time

# import matplotlib.pyplot as plt 

def estimate_coef(x, y): 
	# number of observations/points 
	n = np.size(x) 
	# mean of x and y vector 
	m_x, m_y = np.mean(x), np.mean(y) 
	# calculating cross-deviation and deviation about x 
	SS_xy = np.sum(y*x) - n*m_y*m_x 
	SS_xx = np.sum(x*x) - n*m_x*m_x 
	# calculating regression coefficients 
	b_1 = SS_xy / SS_xx 
	b_0 = m_y - b_1*m_x 
	
	return(b_0, b_1) 

def plot_regression_line(x, y, b): 
	# plotting the actual points as scatter plot 
	plt.scatter(x, y, color = "m", 
			marker = "o", s = 30) 
	# predicted response vector 
	y_pred = b[0] + b[1]*x 
	# plotting the regression line 
	plt.plot(x, y_pred, color = "g") 
	# putting labels 
	plt.xlabel('x') 
	plt.ylabel('y') 
	# function to show plot 
	plt.show() 
 # observations

def prediction(f):
	#Input List
	da=pd.DataFrame(f)

#Removing the Outliners
	w=list(da.quantile([0.75])[0])

	w1=list(da.quantile([0.25])[0])

	q=w[0]+1.5*(w[0]-w1[0])

	q1=w1[0]-1.5*(w[0]-w1[0])

	g=[i for i in f if(i>=q1 and i<=q)]

	y = np.array(g) 

	y1=np.array(list(range(1,len(g)+1)))

# estimating coefficients 
	b = estimate_coef(y1, y)


	# print("Estimated coefficients: Slope:",b[1]," Intercept:" ,b[0]) 

#Plot the line for estimation

# plot_regression_line(y1, y, b)  

#Finding the function with slope

	if (b[1]<0.1 and b[1]>-0.1) or b[1] == np.nan:
    
		return ("c")
	if b[1]>=0.1:
    	
		return("b")
	if b[1]<-0.1:
    	
		return("f")

	