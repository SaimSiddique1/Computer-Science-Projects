import json
import pandas as pd

# Load the JSON file (use the exact filename you provided)
with open("whitetail_deer_dataset (1) (1).json", "r") as f:
    data = json.load(f)

# Convert JSON data into a DataFrame
df = pd.DataFrame(data)

# Save as CSV with the required name
df.to_csv("whitetail_deer_dataset.csv", index=False)

print("Conversion complete. File saved as whitetail_deer_dataset.csv")