# Importing flask module in the project is mandatory
# An object of Flask class is our WSGI application.
from flask import Flask
from flask import render_template
 
# Flask constructor takes the name of
# current module (__name__) as argument.
app = Flask(__name__)

@app.route('/')
@app.route('/index')
def index():
    users = [ 'Rosalia','Adrianna','Victoria' ]
    return render_template('index.html', title='Welcome', members=users)

# main driver function
if __name__ == '__main__':
    # run() method of Flask class runs the application
    # on the local development server.
    app.run()
