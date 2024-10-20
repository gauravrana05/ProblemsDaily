from jinja2 import Template

TEMPLATE = '''
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Test Jinja</title>
    <style>
        table {
            width: 50%;
            border-collapse: collapse;
            margin: 20px;
        }
        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }
        th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>

    <h1 style="margin:20px;">Basic HTML Table Example</h1>

    <table>
        <thead>
            <tr>
                <th>Item</th>
                <th>Quantity</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
          {% for i in data%}
            <tr>
            <td>{{ i['year']}} </td>
            <td>{{ i['awardee']}} </td>
            <td>{{ i['language']}} </td>
          {% endfor %}
        </tbody>
    </table>

</body>
</html>



'''


janipath_data = [
    {'year': 2020, 'awardee': 'John Doe', 'language': 'English'},
    {'year': 2021, 'awardee': 'Jane Smith', 'language': 'Spanish'},
    {'year': 2022, 'awardee': 'Raj Kumar', 'language': 'Hindi'},
    {'year': 2023, 'awardee': 'Maria Garcia', 'language': 'French'}
]
def main():
  template = Template(TEMPLATE)
  content = template.render(data = janipath_data)
  
  with open('index.html','w') as file:
    file.write(content)
    

if __name__ == "__main__":
  main()