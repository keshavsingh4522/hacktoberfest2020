import aiml
import os 
import requests


def chat():
    kernel = aiml.Kernel()
    kernel.verbose(0)
    kernel.setBotPredicate("name", "Nicole")
    kernel.setPredicate('name', 'Raj')

    if os.path.isfile("bot_brain.brn"):
        kernel.bootstrap(brainFile="bot_brain.brn")
    else:
        kernel.bootstrap(learnFiles="startup.xml", commands="LOAD AIML B")
        kernel.saveBrain("bot_brain.brn")

    print("Session Initiated. Type your message.")
    while True:
        excitation = input('')
        response = kernel.respond(excitation)
        if excitation == 'EXIT' or excitation == 'exit' or excitation == 'Exit' or excitation == 'EXit' or excitation =='EXIt'
        else:
            print('>>> '+response)
            kernel.saveBrain("bot_brain.brn")
    print("Session Ended Successfully!")


if __name__ == '__main__':
    chat()
