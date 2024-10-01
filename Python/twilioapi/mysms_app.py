from twilio.rest import Client 
 
account_sid = 'AC5650bf1d6228dcafa1c71d6e49133ed7' 
auth_token = '[AuthToken]' 
client = Client(account_sid, auth_token) 
 
message = client.messages.create(  
                              messaging_service_sid='MG4a538950f74a3138914524e6dd4cd77b', 
                              body='heyt',      
                              to='+918871024186' 
                          ) 
 
print(message.sid)