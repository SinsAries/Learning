import pandas as pd
from unidecode import unidecode

# Load the Excel file
excel_data = pd.read_excel("ds.xlsx", dtype=str)

# Function to remove Vietnamese accents
def remove_vietnamese_accents(df):
    return df.applymap(lambda x: unidecode(x) if isinstance(x, str) else x)

# Apply function to remove accents
excel_data_no_accents = remove_vietnamese_accents(excel_data)

# Save the result to a new CSV file
excel_data_no_accents.to_csv("Danh_sach_san_pham_no_accents.csv", index=False, encoding='utf-8')
