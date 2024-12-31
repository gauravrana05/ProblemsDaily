import requests

# The URL of the file you want to download
url = 'http://10.64.60.56:8080/ops/ne_message.jsp'

# Send a GET request to the server
response = requests.get(url)

# Check if the request was successful (status code 200)
if response.status_code == 200:
    # Save the content to a file (e.g., ne_message.jsp or ne_message.html)
    with open('ne_message.jsp', 'w', encoding='utf-8') as file:
        file.write(response.text)
    print("Content downloaded and saved successfully.")
else:
    print(f"Failed to retrieve content. Status code: {response.status_code}")