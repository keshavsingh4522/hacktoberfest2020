#Reconhece a voz se falar em Ingles e escreve na tela o que foi dito

import speech_recognition as sr # Importando o Speech Recognition

def main(): # Classe principal
 
    r = sr.Recognizer() # Definindo o Recognizer
 
    with sr.Microphone() as source: # Configurando Microfone
        r.adjust_for_ambient_noise(source)  # Criamos um objeto reconhecedor, também para remover ruídos
 
        print("Por favor, fale algo e aguarde...") # Impreme texto para saber quando falar algo
 
        audio = r.listen(source) # O Audio é reconhecido e guardado na variavel para ser impressa
 
        print("Escrevendo agora... ") # Imprime texto para saber que esta escrevendo o que foi dito
 
        # Reconhecer fala usando o google, aqui ele reconhece o que você falou e escreve na tela
        try:
            print("Voce falou: \n" + r.recognize_google(audio))  # Reconhecendo o discurso usando o Google Speech
            print("Escrito com sucesso! \n ") # Mensagem de Feedback para saber se funcionou

        except Exception as e:
            print("Error :  " + str(e)) # Caso dê erro

        # Escreve audio
 
        with open("recorded.wav", "wb") as f:  # Aqui vamos gravar o áudio
            f.write(audio.get_wav_data())
 
#if _name_ == "_main_":
main()

