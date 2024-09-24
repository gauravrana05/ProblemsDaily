import requests

# List of JavaScript files to download
js_files = [
    'http://10.64.60.56:8080/ops/conf/commom.js',
    'http://10.64.60.56:8080/ops/conf/general.js',
    'http://10.64.60.56:8080/ops/conf/sorttable.js'
]

# Download each file
for js_file in js_files:
    response = requests.get(js_file)
    
    # Get the file name from the URL
    file_name = js_file.split('/')[-1]
    
    # Check if the request was successful
    if response.status_code == 200:
        # Save the content to a file
        with open(file_name, 'w', encoding='utf-8') as file:
            file.write(response.text)
        print(f"{file_name} downloaded successfully.")
    else:
        print(f"Failed to download {file_name}. Status code: {response.status_code}")