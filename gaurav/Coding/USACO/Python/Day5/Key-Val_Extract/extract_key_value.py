import json
import sys

def extract_data(data, key_to_extract):
    results = []
    response_data = data.get('responseData', [])
    response_data = data.get('dataList', response_data)

    for item in response_data:  
        extracted_value = item.get(key_to_extract, None)
        if extracted_value is not None:
            formatted_string = f"{extracted_value}\n"
            results.append(formatted_string)

    return results

# Main function
def main(input_file, output_file, key_to_extract):
    # Read the input JSON file
    with open(input_file, 'r') as file:
        data = json.load(file)

    results = extract_data(data, key_to_extract)

    with open(output_file, 'w') as file:
        file.writelines(results)

    print(f"Data has been written to {output_file}")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python script.py <input_file> <output_file> <key_to_extract>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    key_to_extract = sys.argv[3]

    main(input_file, output_file, key_to_extract)
