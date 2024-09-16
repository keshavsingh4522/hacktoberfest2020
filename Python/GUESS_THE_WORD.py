import random

stages = ['''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
	  |
=========
''', '''
  +---+
  |   |
  O   |
 /|\  |
 /	|
	  |
=========
''', '''
  +---+
  |   |
  O   |
 /|\  |
	  |
	  |
=========
''', '''
  +---+
  |   |
  O   |
 /|   |
	  |
	  |
=========''', '''
  +---+
  |   |
  O   |
  |   |
	  |
	  |
=========
''', '''
  +---+
  |   |
  O   |
	  |
	  |
	  |
=========
''', '''
  +---+
  |   |
	  |
	  |
	  |
	  |
=========
''']

logo = ''' 
 _											 
| |											
| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  
| '_ \ / _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
| | | | (_| | | | | (_| | | | | | | (_| | | | |
|_| |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
					__/ |					  
				   |___/	'''

word_list = ['abruptly', 'absurd', 'abyss', 'affix', 'askew', 'avenue', 'awkward', 'axiom', 'azure', 'bagpipes', 'bandwagon', 'banjo', 'beekeeper', 'blizzard', 'boxcar', 'buffalo', 'buzzard', 'buzzing', 'buzzwords', 'caliph', 
'cobweb', 'cockiness', 'croquet', 'crypt', 'curacao', 'daiquiri', 'disavow', 'dizzying', 'duplex', 'dwarves', 'embezzle', 'equip', 'espionage', 'euouae', 'exodus', 'faking', 'fishhook', 'fixable', 'fjord', 
'flapjack', 'flopping', 'fluffiness', 'foxglove', 'frazzled', 'frizzled', 'fuchsia', 'funny', 'gabby', 'galaxy', 'galvanize', 'gazebo', 'giaour', 'gizmo', 'glowworm', 'glyph', 'gnostic', 'gossip', 
'grogginess', 'haiku', 'haphazard', 'hyphen', 'iatrogenic', 'icebox', 'injury', 'ivory', 'ivy', 'jackpot', 'jaundice', 'jawbreaker', 'jaywalk', 'jazziest', 'jazzy', 'jelly', 'jigsaw', 'jinx', 
'jiujitsu', 'jockey', 'jogging', 'joking', 'joyful', 'juicy', 'jukebox', 'jumbo', 'kayak', 'kazoo', 'keyhole', 'khaki', 'kiosk', 'kitsch', 'kiwifruit', 'klutz', 'knapsack', 'larynx', 'lengths', 
'lucky', 'luxury', 'lymph', 'marquis', 'matrix', 'megahertz', 'microwave', 'mnemonic', 'mystify', 'naphtha', 'nightclub', 'nowadays', 'numbskull', 'nymph', 'onyx', 'ovary', 'oxidize', 'oxygen', 'pajama', 
'peekaboo', 'phlegm', 'pixel', 'pizazz', 'pneumonia', 'polka', 'pshaw', 'psyche', 'puppy', 'puzzling', 'quartz', 'queue', 'quips', 'quixotic', 'quiz', 'quizzes', 'quorum', 'razzmatazz', 'rhubarb', 
'rhythm', 'rickshaw', 'schnapps', 'scratch', 'shiv', 'snazzy', 'sphinx', 'spritz', 'squawk', 'staff', 'strength', 'strengths', 'stretch', 'stronghold', 'stymied', 'subway', 'swivel', 'syndrome', 'thriftless', 
'thumbscrw', 'topaz', 'transcript', 'transgress', 'transplant', 'triphthong', 'twelfth', 'twelfths', 'unknown', 'unworthy', 'unzip', 'uptown', 'vaporize', 'vixen', 'vodka', 'voodoo', 'vortex', 'voyeurism', 
'walkway', 'waltz', 'wave', 'wavy', 'waxy', 'wellspring', 'wheezy', 'whiskey', 'whizzing', 'whomever', 'wimpy', 'witchcraft', 'wizard', 'woozy', 'wristwatch', 'wyvern', 'xylophone', 'yachtsman', 
'yippee', 'yoked', 'youthful', 'yummy', 'zephyr', 'zigzag', 'zigzagging', 'zilch', 'zipper', 'zodiac', 'zombie']

word=random.choice(word_list)
lives=6
display = []
for x in range(len(word)):
	display.append('_')
end_game=False
print(logo)
def p_display():
	for x in display:
		print(x,end=' ')
	print()
while end_game==False:
	letter=input("Guess a letter: ").lower()
	for x in range(len(word)):
		if word[x]==letter:
			display[x]=letter
	p_display()
	
	if letter not in word:
		lives-=1
	

		
	print(stages[lives])

	if '_' not in display:
			end_game=True
			print("You win")

	if lives==0:
		end_game=True
		print("You lose")
		print(f"Word: {word}")