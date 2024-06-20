from flask_restful import Resource, reqparse
from application.database import db
from application.models import User, Article
from flask_restful import fields, marshal_with
from application.validation import NotFoundError, BuisnessValidationError

output_fields = {
    "user_id": fields.Integer,
    "username": fields.String,
    "email": fields.String
}

create_user_parser = reqparse.RequestParser()
create_user_parser.add_argument('username')
create_user_parser.add_argument('email')

update_user_parser = reqparse.RequestParser()
update_user_parser.add_argument('email')

class UserAPI(Resource):
    @marshal_with(output_fields)
    def get(self, username):
        # getting the username
        print("GET method in User API: ", username)

        # querying the database
        user = db.session.query(User).filter(User.username == username).first()
        if user:
            # return a valid json
            return user

        else:
            # return 404 error
            raise NotFoundError(status_code=404)

    @marshal_with(output_fields)
    def put(self, username):
        args = update_user_parser.parse_args()
        email = args.get('email', None)
        if email is None:
            raise BuisnessValidationError(status_code=400, error_code='BE1002', error_message="email is required")

        if "@" not in email:
            raise BuisnessValidationError(status_code=400, error_code='BE1003', error_message="invalid email")

        user = db.session.query(User).filter(User.email == email).first()
        if user:
            raise BuisnessValidationError(status_code=400, error_code='BE1006', error_message="Duplicate Email")

        user = db.session.query(User).filter(User.username == username).first()
        if user is None:
            raise NotFoundError(status_code=404)

        user.email = email
        db.session.add(user)
        db.session.commit()
        return user


    def delete(self, username):
        # Check if the user exists
        user = db.session.query(User).filter(User.username == username).first()
        if user is None:
            raise NotFoundError(status_code=404)

        # If the user exists, check if there are any articles
        # If true, then throw error
        articles = Article.query.filter(Article.authors.any(User.username == username)).first()
        print(articles)

        if articles:
            raise BuisnessValidationError(status_code=400, error_code='BE1005', error_message="can't delete users as articles are written by user")

        # if no dependency, then delete
        db.session.delete(user)
        db.session.commit()

        return "", 200

    def post(self):
        args = create_user_parser.parse_args()
        username = args.get('username', None)
        email = args.get('email', None)

        if username is None:
            raise BuisnessValidationError(status_code=400, error_code='BE1001', error_message="username is required")

        if email is None:
            raise BuisnessValidationError(status_code=400, error_code='BE1002', error_message="email is required")

        if "@" not in email:
            raise BuisnessValidationError(status_code=400, error_code='BE1003', error_message="invalid email")

        user = db.session.query(User).filter((User.username == username) | (User.email == email)).first()
        if user:
            raise BuisnessValidationError(status_code=400, error_code='BE1004', error_message="Duplicate User!!!")

        new_user = User(username=username, email=email)
        db.session.add(new_user)
        db.session.commit()
        return "", 201
