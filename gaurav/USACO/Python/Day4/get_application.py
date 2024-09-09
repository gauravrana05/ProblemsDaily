# Define file paths
file1_path = 'ip_hierarchy.txt'
file2_path = 'ip_project.txt'
output_file_path = 'fms_ip_applications.txt'

# Function to read the first file and create a mapping of IP addresses to application names
def load_ip_to_application_mapping(file_path):
    ip_to_app_map = {}
    with open(file_path, 'r') as file:
        for line in file:
            parts = line.strip().split('  ')
            if len(parts) == 2:
                ip_address, application = parts
                ip_to_app_map[ip_address.strip()] = application.strip()
    return ip_to_app_map

# Function to process the second file and append the application names
def add_applications_to_ips(file1_map, file2_path, output_file_path):
    with open(file2_path, 'r') as file2, open(output_file_path, 'w') as output_file:
        for line in file2:
            ip_address = line.strip()
            application = file1_map.get(ip_address, "Unknown Application")
            output_file.write(f"{ip_address}  {application}\n")

# Load IP to application mapping from the first file
ip_to_app_map = load_ip_to_application_mapping(file1_path)

# Add applications to IPs from the second file and save the results to the output file
add_applications_to_ips(ip_to_app_map, file2_path, output_file_path)

print(f"Output has been written to {output_file_path}")
