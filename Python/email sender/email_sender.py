import smtplib
from email.message import EmailMessage

email = EmailMessage()
# please enter your name
email['from'] = '' 
# please enter your email
email['to'] = ''
# please enter subject of email
email['subject'] = 'enter your subject'
# please enter your message
email.set_content('enter your message')

with smtplib.SMTP(host='smtp.gmail.com', port=587) as smtp:
	smtp.ehlo()
	smtp.starttls()
	# please enter login details
	smtp.login('email@gmail.com', 'password')
	smtp.send_message(email)
	print('all done')