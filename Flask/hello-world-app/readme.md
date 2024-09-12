# Flask example
Simple Flask app which renders a template with a list of data 


## Installation

Install with pip:

```
$ pip install -r requirements.txt
```

## Flask Configuration

#### Example

```
app = Flask(__name__)
app.config['DEBUG'] = True
```
### Configuring From Files

#### Example Usage

```
app = Flask(__name__ )
app.config.from_pyfile('config.Development.cfg')
```

#### cfg example

```

##Flask settings
DEBUG = True  # True/False
TESTING = False

##SWAGGER settings
SWAGGER_DOC_URL = '/api'

....


```
 
## Run Flask
### Run flask for develop
```
$ python app.py
```
In flask, Default port is `5000`
