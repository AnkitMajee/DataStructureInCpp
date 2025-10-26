import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load the CSV file
df = pd.read_csv('results.csv')

# Display the first few rows to understand the structure of the data
print(df.head())

# Function to plot performance of sorting algorithms based on input size
def plot_sorting_algorithms(df):
    plt.figure(figsize=(12, 8))
    
    for column in df.columns[1:]:
        plt.plot(df['InputSize'], df[column], label=column)

    plt.xlabel('Input Size')
    plt.ylabel('Time (seconds)')
    plt.title('Performance of Sorting Algorithms')
    plt.legend()
    plt.grid(True)
    plt.show()

# Call the function to plot the graph
plot_sorting_algorithms(df)