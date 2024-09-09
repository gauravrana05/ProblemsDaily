from pprint import pprint 
import json

# Function to extract IP address and hierarchyName
def extract_ip_and_hierarchy(data):
    results = []
    response_data = data.get('responseData', [])
    data_list = response_data.get('dataList', [])

    for item in data_list:      
        ip_address = item.get('ipAddress', None)
        
        owner_list = item.get('ownerList', [])
        if ip_address and owner_list:
            for owner in owner_list:
                hierarchy_name = owner.get('hierarchyName', None)
                if hierarchy_name:
                    # Format the string as required and add to results
                    formatted_string = f"{ip_address}  {hierarchy_name.capitalize()}\n"
                    results.append(formatted_string)
    
    return results

# Read the input JSON file
input_file = 'get_asset_data.json'
with open(input_file, 'r') as file:
    data = json.load(file)

# Extract IP addresses and hierarchy names
results = extract_ip_and_hierarchy(data)

# Write the results to an output text file
output_file = 'ip_hierarchy.txt'
with open(output_file, 'w') as file:
    file.writelines(results)

print(f"Data has been written to {output_file}")
