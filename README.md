# CLI-Based Housing Data Analysis System  

This project is a Command Line Interface (CLI) program designed to read and analyze housing data from a CSV file. The system provides functionalities for descriptive analysis, data search, and sorting, making it a versatile tool for basic data exploration.

## Features  

### 1. Descriptive Analysis  
The program groups and summarizes data based on specific attributes, such as:  
- Location (primary and secondary)  
- Housing type  
- Number of rooms, bathrooms, and car parks  
- Area and price  
It calculates the frequency, maximum, minimum, and average values for each attribute.

### 2. Data Search  
Users can search for specific data points by column, such as location, housing type, or furnishing status. Partial matches and exact matches are supported for flexible searching.

### 3. Sorting & Filtering  
The system sorts data by selected criteria, helping users identify trends or patterns, such as grouping data by location or type of property.

## How It Works  

1. **Data Input:**  
   The program reads data from a CSV file named `file.csv`. Each row represents a housing entry with attributes like location, price, number of rooms, etc.  

2. **Descriptive Functions:**  
   The program analyzes data and provides a summary, including maximum, minimum, and average calculations.  

3. **Search and Sorting:**  
   Data is sorted based on the selected column, and users can search for entries matching their query.  

4. **User Interaction:**  
   Users interact with the program through a menu-driven interface:
   - Option 1: Analyze data based on a chosen column.
   - Option 2: Search data by specific criteria.
   - Option 0: Exit the program.  

## Technologies Used  
- **C Programming Language**  
- **File Handling** (via `stdio.h`) for reading CSV files  
- **Structs and Arrays** for efficient data management  

## How to Run  

1. Compile the program using a C compiler, for example:  
   ```bash
   gcc -o housing_analysis housing_analysis.c
