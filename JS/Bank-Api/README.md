# Bank System Simulator

Practicing MongoDB + Nodejs API using a simple bank systems. 


## Installation

If you want to test it locally, you can follow the following steps to install and run it successfully.

#### Requirements:

- Git installed
- Node.js installed

#### Steps

First, clone the repository:
```git clone https://github.com/mablds/simple-bank-system.git ```

Then install it using the dependecy manager of your preference like NPM:
```npm install```

## Usage

This API is public and hosted by Heroku for education purposes. So if you are interest to test it without clone and run locally, feel free to play around consulting this Documentation.

## Routes

There are just few routes that were created to study about APIs and how to deal with NoSQL databases.

### Home
```
- URL: '/'
- HTTP Method: GET
- Params: None
- Headers: None
```

___
### Bank Queries

#### Requests:
| Methods |Rotas|Admin|Action|Expected response|Status Code|
|:----------:|:-----:|:----:|:---:|:-----:|:----:|
|GET         |/bank|✔️|List of all bank accounts|Bank accounts array|200|
|GET         |/bank/:account||Get the informations about an specific account|User object|200|
|POST|        /bank/create||Create a bank account|Bank Account created| 201|
|POST|      /bank/deposit||Deposit a value to the account informed| Value deposited |200|
|POST|      /bank/withdraw||Withdraw a value of an account informed| Value withdrawed |200|
|PUT|      /bank/transfer||Transfer a value between accounts informed| Value transfered |200|
|DELETE      |/bank/delete|✔️|Delete an bank account| Bank Account deleted |202|

___
#### How to authenticate:
```
Route: /auth
Method: POST,
AdminPrivilege: false,
Header: --,
Body: {
        email: teste@teste.com,
        password: "teste"
    }
```

#### How to get all Account's info:
```
Route: /bank
Method: GET,
AdminPrivilege: true,
Params: Account number
Header: --,
Body: --
```

#### How to get an Account's info:
```
Route: /bank/:account
Method: GET,
AdminPrivilege: false,
Params: Account number
Header: x-access-token: token,
Body: --
```


___
#### How to create a Bank Account:
```
Route: /bank/create
Method: POST,
AdminPrivilege: false,
Header: --,
Body: {
    "owner": "teste",
    "email": "agoodemail@emailcompany.com",
    "password": "teste"
}
```

___
#### How to deposit to a Bank Account:
```
Route: /bank/deposit
Method: POST,
AdminPrivilege: false,
Header: --,
Body: {
    "account": 000,
    "value": 3000
}
```

___
#### How to withdraw of a Bank Account:
```
Route: /bank/withdraw
Method: POST,
AdminPrivilege: false,
Header: x-access-token: token,
Body: {
    "owner": "teste",
    "account": 000,
    "value": 3000
}
```

___
#### How to transfer between accounts:
```
Route: /bank/transfer
Method: PUT,
AdminPrivilege: false,
Header: x-access-token: token,
Body: {
    "outAccount": 7233,
    "incAccount": 265,
    "value": 1000
}
```
___
#### How to delete accounts:
```
Route: /bank/delete
Method: DELETE,
AdminPrivilege: true,
Header: x-access-token: token,
Body: {
    "account": 0000,
}
```
___
