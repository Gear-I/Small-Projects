from tkinter import *
from tkinter import filedialog
import pyttsx3
import PyPDF2

window = Tk()
window.title('PDF To Audio Converter Version 1.0')
window.geometry('500x350')
window.iconbitmap('https://github.com/Gear-I/Small-Projects/blob/main/PDF%20To%20Audio/icons8-audiobook-64.ico')
window.config(bg="orange")

startingpagenumber = Entry(window)
startingpagenumber.place(relx=0.6,rely=0.1)
page1=Label(window,text=”Enter starting page number”)
page1.place(relx=0.02,rely=0.1)
label = Label(window, text=("select a book.")
label.place(relx=0.3,rely=0.2)


def file():
    path = filedialog.askopenfilename()
    book = open(path, 'rb')
    pdfreader = PyPDF2.PdfFileReader(book)
    pages = pdfreader.numPages
    speaker = pyttsx3.init()
    
    for i in range(int(startingpagenumber.get()), pages):
        page = pdfreader.getPage(i) 
        txt = page.extractText()
        speaker.say(txt)
        speaker.runAndWait()
 
B=Button(window, text=("Choose  the Book"), command=file)
B.place(relx=0.4,rely=0.3)
 
mainloop()
