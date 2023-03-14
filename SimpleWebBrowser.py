# importing neccessary libraries
import os
import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtWebEngineWidgets import *
from PyQt5.QtPrintSupport import *

# Creating Main Window for Browser

class MainWindow(QMainWindow):

	# Constructor
	def _init_(self, *args, **kwargs):
		super(MainWindow, self)._init_(*args, **kwargs)

		# Creating a Web Engine View
		self.broswer = QWebEngineView()

		# Default URL as Google
		self.browser.seturl(QUrl("https://google.com"))

		# adding action when url gets changed
		self.browser.urlchange.connect(self.update_urlbar)

		# adding action when loading is completed
		self.broswer.loadfinish.connect(self.update_title)

		# set broswer as central widget or main window 
		self.setCentralWidget(self.broswer)
		#Status Bar
		self.status = QStatusBar()
		#Adding Status to Main Window
		self.setStatusBar(self.status)

		#Toolbar for Navigation
		navtb = QToolBar("Navigation")

		#ToolBar to Main Window
		self.addtoolbar(navtb)

		 # adding actions to the tool bar
        # creating a action for back
          back_btn = QAction("Back", self)
 
        # setting status tip
          back_btn.setStatusTip("Back to previous page")
 
        # adding action to the back button
        # making browser go back
          back_btn.triggered.connect(self.browser.back)
 
          # adding this action to tool bar
          navtb.addAction(back_btn)
 
        # similarly for forward action
        next_btn = QAction("Forward", self)
        next_btn.setStatusTip("Forward to next page")
 
        # adding action to the next button
        # making browser go forward
        next_btn.triggered.connect(self.browser.forward)
        navtb.addAction(next_btn)
 
        # similarly for reload action
        reload_btn = QAction("Reload", self)
        reload_btn.setStatusTip("Reload page")
 
        # adding action to the reload button
        # making browser to reload
        reload_btn.triggered.connect(self.browser.reload)
        navtb.addAction(reload_btn)
 
        # similarly for home action
        home_btn = QAction("Home", self)
        home_btn.setStatusTip("Go home")
        home_btn.triggered.connect(self.navigate_home)
        navtb.addAction(home_btn)
 
        # adding a separator in the tool bar
        navtb.addSeparator()
 
        # creating a line edit for the url
        self.urlbar = QLineEdit()
 
        # adding action when return key is pressed
        self.urlbar.returnPressed.connect(self.navigate_to_url)
 
        # adding this to the tool bar
        navtb.addWidget(self.urlbar)
 
        # adding stop action to the tool bar
        stop_btn = QAction("Stop", self)
        stop_btn.setStatusTip("Stop loading current page")
 
        # adding action to the stop button
        # making browser to stop
        stop_btn.triggered.connect(self.browser.stop)
        navtb.addAction(stop_btn)
 
        # showing all the components
        self.show()
 
 
    # method for updating the title of the window
    def update_title(self):
        title = self.browser.page().title()
        self.setWindowTitle("% s - Geek Browser" % title)
 
 
    # method called by the home action
    def navigate_home(self):
 
        # open the google
        self.browser.setUrl(QUrl("http://www.google.com"))
 
    # method called by the line edit when return key is pressed
    def navigate_to_url(self):
 
        # getting url and converting it to QUrl object
        q = QUrl(self.urlbar.text())
 
        # if url is scheme is blank
        if q.scheme() == "":
            # set url scheme to html
            q.setScheme("http")
 
        # set the url to the browser
        self.browser.setUrl(q)
 
    # method for updating url
    # this method is called by the QWebEngineView object
    def update_urlbar(self, q):
 
        # setting text to the url bar
        self.urlbar.setText(q.toString())
 
        # setting cursor position of the url bar
        self.urlbar.setCursorPosition(0)
 
 
# creating a pyQt5 application
app = QApplication(sys.argv)
 
# setting name to the application
app.setApplicationName("Geek Browser")
 
# creating a main window object
window = MainWindow()
 
# loop
app.exec_()


