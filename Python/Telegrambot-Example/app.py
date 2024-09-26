import random
import telebot
import requests
import time
import json
from telebot import types
import taucoin
import logging

# Define Bot Token 
bot_token = '803230102:AAGzBQnLQ8Axxw4DKtVVIZVgGelsS3LzM4s'

@bot.message_handler(commands=['start'])
def start(message):
    bot.reply_to(message, 'Welcome to the bot')

bot.polling(none_stop=True, interval=2, timeout=90)
