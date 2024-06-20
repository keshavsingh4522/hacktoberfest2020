'''Python function to send mail'''

import smtplib
import os
from email.message import EmailMessage

print('\n')
EMAIL_ADDRESS = 'abc@gmail.com'  # Sender email address 
EMAIL_PASSWORD = 'password'  # Sender email id passwod

To = "pimov26202@sceath.com" # Reciever's email address

#for sending to different emails
contacts=[]

msg = EmailMessage()
msg['From'] = EMAIL_ADDRESS   # Sender email address
msg['To'] = To
     # Receiving email addresses

msg.set_content('This is a auto-generated email')
def add_excel(excel_filepath):
    msg['Subject'] = 'Input file'
    with open(excel_filepath, 'rb') as f:
        file_data = f.read()
        file_name=f.name
    msg.add_attachment(file_data,maintype='application',subtype='octet-stream',filename=file_name)
    

# ## adding any attachements by passing the file path in 
# def add_log_attachments(attachment_part,log_file):
#     # filenames = next(os.walk('Log'), (None, None, []))[2]
#     # for files in filenames:
#     #     with open(f'Log\{files}', 'rb') as f:
#     #         file_data = f.read()

#     #         file_name = f.name

#     with  open(f'Log\\{log_file}', 'rb') as f:
#         file_data = f.read()
#         file_name = f.name
#     attachment_part.add_attachment(file_data,maintype='log',subtype='octet-stream',filename=file_name)
  


def success_mail():
    del msg['Subject']
    msg['Subject'] = 'Successful execution'
    text_part, attachment_part = msg.iter_parts()
    text_part.add_alternative("""\
    <!DOCTYPE html>
    <html>
        <body>
            <h2 style="color:#68fd7f;">Process has been successfully executed </h2>
        </body>
    </html>
     """,subtype='html')
    # add_log_attachments(attachment_part,log_file)
 
   
def malfunction_mail():
    del msg['Subject']
    msg['Subject'] = 'Malfunction execution'
    text_part, attachment_part = msg.iter_parts()
    text_part.add_alternative("""\
    <!DOCTYPE html>
    <html>
        <body>
            <h2 style="color:#fd2626;">There's a bug in the code.Work on rectifying it </h2>
            <p>Refer to attach log files- </p>
        </body>
    </html>
     """,subtype='html')
    # add_log_attachments(attachment_part,log_file)
    
'''
Local server - python -m smtpd -c DebuggingServer -n localhost:3010
'''


def send_mail(): 
    with smtplib.SMTP_SSL('smtp.gmail.com',465,timeout=120) as smtp:
        try:
            smtp.login(EMAIL_ADDRESS,EMAIL_PASSWORD)

            smtp.send_message(msg)
        except Exception as e:
            print('Error in sending mail',e)
            print('Try again with correct credentials') 
            quit()   

send_mail()
# if __name__ == '__main__':
#     log_file = 'Master 18-02-2022 14.22.13 logfile.log'
#     success_mail(log_file)
#     send_mail()