#comment
from flask import Flask, request
from flask import render_template


app = Flask(__name__)

@app.route('/hello', methods= ['GET', 'POST'])
def hello_world():
  if request.method =="GET":
    return render_template("get_details.html")
  else:
    username = request.form['user_name']
    return render_template("display_details.html", display_name= username)

if __name__ == "__main__":
  app.debug=True
  app.run()