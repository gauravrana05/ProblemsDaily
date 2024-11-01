from jinja2 import Template

janipath_data = [
    {'year': 2020, 'awardee': 'John Doe', 'language': 'English'},
    {'year': 2021, 'awardee': 'Jane Smith', 'language': 'Spanish'},
    {'year': 2022, 'awardee': 'Raj Kumar', 'language': 'Hindi'},
    {'year': 2023, 'awardee': 'Maria Garcia', 'language': 'French'}
]
def main():
  with open("janapith.html.jinja2", 'r') as file:
    temp = file.read()
    template = Template(temp)
    content = template.render(data = janipath_data)
  
    with open('index.html','w') as file:
      file.write(content)
    

if __name__ == "__main__":
  main()