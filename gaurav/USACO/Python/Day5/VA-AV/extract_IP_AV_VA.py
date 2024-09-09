from pprint import pprint
import json
import sys

def extract_data(data, key_to_extract):
    results = ["   IP                 VA Score    AV Status\n"]
    response_data = data.get('responseData', [])
    response_data = response_data.get('dataList', response_data)

    for item in response_data:  
        result = []
        for i in key_to_extract:
            extracted_value = item.get(i, None)
            result.append(extracted_value)
        if result:
            formatted_string = ""
            for i in result:
                if i is None:
                    formatted_string += f"{'None':>15}\t"  # You can choose how to represent None
                else:
                    formatted_string += f"{i:>15}\t"
            formatted_string += "\n"
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
    if len(sys.argv) != 3:
        print("Usage: python script.py <input_file> <output_file> <key_to_extract>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    key_to_extract = ['ID', 'VASCORE', 'AVSTATUS']

    main(input_file, output_file, key_to_extract)
