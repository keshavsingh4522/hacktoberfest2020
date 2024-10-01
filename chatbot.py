from chatterbot import ChatBot
 
chatbot = ChatBot("mybot",
        logic_adapters=[
        {
            "import_path": "chatterbot.logic.BestMatch",
            "statement_comparison_function": "chatterbot.comparisons.levenshtein_distance",
            "response_selection_method": "chatterbot.response_selection.get_first_response"
        },
        {
            'import_path': 'chatterbot.logic.LowConfidenceAdapter',
            'threshold': 0.65,
            'default_response': 'I am sorry, but I do not understand.'
        }
    ],
    trainer='chatterbot.trainers.ListTrainer')
 
 
########################################
###   TRAINING - run this just one time
########################################
 
 
chatbot.train([
    'Good morning!',
    'Good morning!',
    'How are you today?',
    'I am fine',
    'Do you like machine learning?',
    'Yes, I like machine learning'
])
 
 
chatbot.train([
    'Good morning!',
    'Good morning!'
  
])
 
chatbot.train([
    'Hello',
    'Hi there!'
  
])
 
 
chatbot.train([
    'Let us talk about current activities',
    'What are you working on now?',
    'I am just browsing Internet for news',
    'What a waste of time! Dont you have any other things to do?',
    'I am working on python script to make new chatbot',
    'This is great. Keep working on this'
])
 
 
chatbot.train(
    "chatterbot.corpus.english.greetings"
  
)
 
chatbot.train(
   "chatterbot.corpus.english.conversations"
)
 
 
 
from chatterbot.trainers import ListTrainer
 
conversation = [
    "Hello",
    "Hi there!",
    "How are you doing?",
    "I'm doing great.",
    "That is good to hear",
    "Thank you.",
    "You're welcome."
]
 
chatbot.set_trainer(ListTrainer)
chatbot.train(conversation)
 
########################################
###  END of  TRAINING
########################################
 
 
 
print ("USER: How are you doing?")
 
response = chatbot.get_response("How are you doing?")
print("BOT:" + str(response))
print ("USER: Hello")
 
response = chatbot.get_response("Hello")
print("BOT:" + str(response))
print ("USER: Good morning!")
 
response = chatbot.get_response("Good morning!")
print("BOT:" + str(response))
 
 
 
print ("USER: Do you like machine learning?")
 
response = chatbot.get_response("Do you like machine learning?")
print ("BOT:" + str(response))
print ("USER: How do I make a neural network?")
 
response = chatbot.get_response('How do I make a neural network?')
print("BOT" + str(response))
print ("USER: Let us talk about current activities")
 
response = chatbot.get_response("Let us talk about current activities")
print("BOT:"+str(response))
 
print ("USER: I am just browsing Internet for news")
 
response = chatbot.get_response("BOT: I am just browsing Internet for news")
print("BOT:" + str(response))
 
print ("USER: I am working on python script to make new chatbot")
 
response = chatbot.get_response("I am working on python script to make new chatbot")
print("BOT:"+str(response))
 
 
print ("USER: Bye")
 
response = chatbot.get_response("Bye")
print("BOT:" + str(response))